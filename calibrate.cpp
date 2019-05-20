#include "calibrate.h"

Calibrate::Calibrate()
{
    c_eff_min = 120.0;   // mm/ns...
    c_eff_max = 190.0;   // mm/ns...
    c_eff_step = 0.01;

    delta_min = -0.9;    // ns
    delta_max = 0.9;     // ns
    delta_step = 0.01;

    calibrated_global_c_eff = 132.5; // starting value

    read = new ReadMAUS();
}


void Calibrate::MakeCalibration(QString input_filename, QString output_calibration_filename,
                                double minimum_tof, double maximum_tof){
    std::cerr << "Initialising variables prior to making a new calibration...\n";

    outputCalibrationFileName = output_calibration_filename;
    getSlabData(input_filename, minimum_tof, maximum_tof);
    std::cerr << "Read slab data.\n";

    setup_plots();

    //calibrateTOF0();
    //calibrateTOF1();
    calibratingTOF0 = true;
    calibratingTOF1 = false;

    //globalCalibration();


    calibratingTOF0 = true;
    calibratingTOF1 = false;
    calibrateTOF0Delta();

    calibratingTOF0 = false;
    calibratingTOF1 = true;
    calibrateTOF1Delta();

    globalCalibration();

    calibratingTOF0 = true;
    calibratingTOF1 = false;
    calibrateTOF0Delta();

    calibratingTOF0 = false;
    calibratingTOF1 = true;
    calibrateTOF1Delta();


    printCalibration(output_calibration_filename);
    print_plots();
}


void Calibrate::getSlabData(QString input_filename, double min_tof, double max_tof){
    std::cerr << "Getting slab data\n";
    read->Read(input_filename, min_tof, max_tof);

    QVector<double> TOF0_offset = read->getTOFOffset(0);
    QVector<double> TOF1_offset = read->getTOFOffset(1);

    std::cerr << "\n\nFound TOF0 is offset by (x, y) = " << TOF0_offset.at(0) << ", " << TOF0_offset.at(1) << "\n"
              << "Found TOF1 is offset by (x, y) = " << TOF1_offset.at(0) << ", " << TOF1_offset.at(1) << "\n\n\n";
}



bool Calibrate::particleInSlab(double c_eff, double delta, QVector<double> slabData){

    /*
     * Slab data has the form (for a horizontal slab):
     *          slabData << x pixel coordinate << PMT0 time << PMT1 time << slab width;
     */
    double pixel = slabData.at(0); // pixel co-ordinate
    double tminus = slabData.at(1);
    double tplus = slabData.at(2);

    double width = slabData.at(3);

    double a = 0.5*c_eff*(tminus - tplus + delta);

    double diff = a - pixel;

    double a_min = -0.5*width;
    double a_max = 0.5*width;

    if(diff >= a_min && diff <= a_max){
        return true;
    }
    else{
        return false;
    }
}






double Calibrate::minimise(const double *par){
    /*
     * This function gets called by TMinuit.  We want to find the best values of c_eff (par[0])
     * and delta (par[1]) that maximise the number of particles within a region of a slab.
     *
     * The current slab data is stored as a QList<QVector<double> > current_slab_data.
     *
     * Given the current values of c & d, iterate through the particle data in the slab
     * and tally up the number of particles that fit within the allowed pixel window.
     *
     * The best values will have a fraction close to 1, so we minimise 1-fraction.
     */

    bool good = false;
    double total_particles = 0.0;
    double particles_within_slab = 0.0;
    double fraction = 0.0;

    double c_eff = par[0];
    double delta = par[1];

    QVector<double> current_particle;

    for(int i = 0; i < current_slab_data.size(); i++){
        current_particle.clear();
        current_particle = current_slab_data.at(i);

        good = particleInSlab(c_eff, delta, current_particle);
        if(good){
            particles_within_slab += 1.0;
        }
        total_particles += 1.0;
    }

    fraction = particles_within_slab / total_particles;
    return (1.0 - fraction)*(1.0 - fraction);
    //return fraction;
}




double Calibrate::global_minimise(const double *par){
    /*
     * This function gets called by TMinuit.  We want to find the best values of c_eff (par[0])
     * that maximise the number of particles within a region of a slab.
     *
     * The current slab data is stored as a QList<QVector<double> > current_slab_data.
     *
     * Given the current values of c & d, iterate through the particle data in the slab
     * and tally up the number of particles that fit within the allowed pixel window.
     *
     * The best values will have a fraction close to 1, so we minimise 1-fraction.
     */

    bool good = false;
    double total_particles = 0.0;
    double particles_within_slab = 0.0;
    double fraction = 0.0;

    double c_eff = par[0];
    double delta;


    QVector<double> current_particle;

    for(int i = 0; i < current_slab_data.size(); i++){
        current_particle.clear();
        current_particle = current_slab_data.at(i);
        delta = current_particle.at(4);

        good = particleInSlab(c_eff, delta, current_particle);
        if(good){
            particles_within_slab += 1.0;
        }
        total_particles += 1.0;
    }

    fraction = particles_within_slab / total_particles;
    double result = (1.0 - fraction)*(1.0 - fraction);
    return result;
    //return fraction;
}


double Calibrate::delta_minimise(const double *par){
    /*
     * This function gets called by TMinuit.  We want to find the best values of c_eff (par[0])
     * that maximise the number of particles within a region of a slab.
     *
     * The current slab data is stored as a QList<QVector<double> > current_slab_data.
     *
     * Given the current values of c & d, iterate through the particle data in the slab
     * and tally up the number of particles that fit within the allowed pixel window.
     *
     * The best values will have a fraction close to 1, so we minimise 1-fraction.
     */

    bool good = false;
    double total_particles = 0.0;
    double particles_within_slab = 0.0;
    double fraction = 0.0;

    double c_eff = calibrated_global_c_eff;
    double delta = par[0];


    QVector<double> current_particle;

    for(int i = 0; i < current_slab_data.size(); i++){
        current_particle.clear();
        current_particle = current_slab_data.at(i);
        //delta = current_particle.at(4);

        good = particleInSlab(c_eff, delta, current_particle);
        if(good){
            particles_within_slab += 1.0;
        }
        total_particles += 1.0;
    }

    fraction = particles_within_slab / total_particles;
    double result = (1.0 - fraction)*(1.0 - fraction);
    return result;
}


double Calibrate::getFraction(double c_eff, double delta){
    bool good = false;
    double total_particles = 0.0;
    double particles_within_slab = 0.0;

    for(int i = 0; i < current_slab_data.size(); i++){
        good = particleInSlab(c_eff, delta, current_slab_data.at(i));
        if(good){
            particles_within_slab += 1.0;
        }
        total_particles += 1.0;
    }

    return particles_within_slab/total_particles;
}




void Calibrate::calibrateTOF0(){
    for(int i = 0; i < 10; i++){
        std::cerr << "Calibrating horizontal and vertical TOF0 slabs: " << i << "\n";
        calibrateTOF0Slab(i, true); // calibrate a horizontal slab
        calibrateTOF0Slab(i, false); // calibrate a vertical slab
    }
}

void Calibrate::calibrateTOF1(){
    for(int i = 0; i < 7; i++){
        std::cerr << "Calibrating horizontal and vertical TOF1 slabs: " << i << "\n";
        calibrateTOF1Slab(i, true); // calibrate a horizontal slab
        calibrateTOF1Slab(i, false); // calibrate a vertical slab
    }
}



void Calibrate::calibrateTOF0Delta(){
    for(int i = 0; i < 10; i++){
        std::cerr << "Calibrating horizontal and vertical TOF0 slabs: " << i << "\n";
        if(i == 2){
            delta_min = 0.4;
            delta_max = 1.4;
        }
        else if(i == 3){
            delta_min = 0.4;//0.5;
            delta_max = 1.4;//1.5;
        }
        else if(i == 4 || i == 5){
            delta_min = 0.3;//0.4;
            delta_max = 1.5;//1.4;
        }
        else if(i == 6){
            delta_min = 0.5;//0.4;
            delta_max = 1.5;//1.4;
        }
        else if(i == 7){
            delta_min = -2.5;//-2.5;
            delta_max = 2.5;//1.0;
        }
        else{
            delta_min = 0.4;
            delta_max = 1.4;
        }
        calibrateTOF0SlabDelta(i, true); // calibrate a horizontal slab

        if(i == 0){
            delta_min = -0.6;//-0.5;
            delta_max = 0.0;//0.0;
        }
        else if(i == 1){
            delta_min = -0.6;//-0.5;
            delta_max = -0.1;//-0.1;
        }
        else if(i == 2){
            delta_min = -10.0;
            delta_max = 10.0;
        }
        else if(i == 3){
            delta_min = -0.5;
            delta_max = -0.1;
        }
        else if(i == 4){
            delta_min = -0.6;//-0.5;
            delta_max = -0.1;//-0.1;
        }
        else if(i == 5){
            delta_min = -0.5;//-0.5;
            delta_max = 0.1;//-0.1;
        }
        else if(i == 6){
            delta_min = -10.0;
            delta_max = 10.0;
        }
        else{
            delta_min = -10.0;
            delta_max = 10.0;
        }
        calibrateTOF0SlabDelta(i, false); // calibrate a vertical slab
    }
}

void Calibrate::calibrateTOF1Delta(){
    for(int i = 0; i < 7; i++){
        std::cerr << "Calibrating horizontal and vertical TOF1 slabs: " << i << "\n";

        if(i == 0 || i == 1 || i == 2 || i == 4 || i == 5 || i == 6){
            delta_min = -0.1;//-0.09;
            delta_max = 0.1;//0.09;
        }
        else if(i == 3){
            delta_min = -0.1;//-0.09;
            delta_max = 0.1;//0.09;
        }
        else{
            delta_min = -0.09;
            delta_max = 0.09;
        }
        calibrateTOF1SlabDelta(i, true); // calibrate a horizontal slab

        if(i == 0){
            delta_min = -0.1;
            delta_max = 0.1;
        }
        else if(i == 1){
            delta_min = -0.1;
            delta_max = 0.1;
        }
        else if(i == 2 || i == 4 || i == 5 || i == 6){
            delta_min = -0.1;
            delta_max = 0.1;
        }
        else if(i == 3){
            delta_min = -0.1;
            delta_max = 0.1;
        }
        else{
            delta_min = -0.1;
            delta_max = 0.1;
        }
        calibrateTOF1SlabDelta(i, false); // calibrate a vertical slab
    }
}



void Calibrate::calibrateTOF0Slab(int slab, bool isHorizontal){
    current_slab_data.clear();
    if(isHorizontal){
        current_slab_data = read->getTOF0HorizontalSlab(slab);
    }
    else{
        current_slab_data = read->getTOF0VerticalSlab(slab);
    }

    QVector<double> results;
    results = doMinimisation();
    double fraction = getFraction(results.at(0), results.at(1));

    setCalibrationConstants(results.at(0), results.at(1), fraction, 0, slab, isHorizontal);
}


void Calibrate::calibrateTOF1Slab(int slab, bool isHorizontal){
    current_slab_data.clear();
    if(isHorizontal){
        current_slab_data = read->getTOF1HorizontalSlab(slab);
    }
    else{
        current_slab_data = read->getTOF1VerticalSlab(slab);
    }

    QVector<double> results;
    results = doMinimisation();
    double fraction = getFraction(results.at(0), results.at(1));

    setCalibrationConstants(results.at(0), results.at(1), fraction, 1, slab, isHorizontal);
}




void Calibrate::calibrateTOF0SlabDelta(int slab, bool isHorizontal){
    current_slab_data.clear();
    if(isHorizontal){
        std::cerr << "\nHorizontal slab " << slab << ": " << "delta_min = " << delta_min << ", delta_max = " << delta_max << "\n";
        current_slab_data = read->getTOF0HorizontalSlab(slab);
    }
    else{
        std::cerr << "\nVertical slab " << slab << ": " << "delta_min = " << delta_min << ", delta_max = " << delta_max << "\n";
        current_slab_data = read->getTOF0VerticalSlab(slab);
    }


    QVector<double> current_calibration_constants = getTOF0SlabConstants(slab, isHorizontal);
    double current_delta;
    if(current_calibration_constants.isEmpty()){
        current_delta = 0.0;
    }
    else{
        current_delta = current_calibration_constants.at(1);
    }


    QVector<double> results;
    results = doDeltaMinimisation(current_delta);

    double fraction = getFraction(calibrated_global_c_eff, results.at(1));
    setCalibrationConstants(calibrated_global_c_eff, results.at(1), fraction, 0, slab, isHorizontal);

}


void Calibrate::calibrateTOF1SlabDelta(int slab, bool isHorizontal){
    current_slab_data.clear();
    if(isHorizontal){
        std::cerr << "\nHorizontal slab " << slab << ": " << "delta_min = " << delta_min << ", delta_max = " << delta_max << "\n";
        current_slab_data = read->getTOF1HorizontalSlab(slab);
    }
    else{
        std::cerr << "\nVertical slab " << slab << ": " << "delta_min = " << delta_min << ", delta_max = " << delta_max << "\n";
        current_slab_data = read->getTOF1VerticalSlab(slab);
    }

    QVector<double> current_calibration_constants = getTOF1SlabConstants(slab, isHorizontal);
    double current_delta;
    if(current_calibration_constants.isEmpty()){
        current_delta = 0.0;
    }
    else{
        current_delta = current_calibration_constants.at(1);
    }

    QVector<double> results;
    results = doDeltaMinimisation(current_delta);
    double fraction = getFraction(calibrated_global_c_eff, results.at(1));
    setCalibrationConstants(calibrated_global_c_eff, results.at(1), fraction, 1, slab, isHorizontal);
}



QVector<double> Calibrate::getTOF0SlabConstants(int slab, bool isHorizontal){
    if(isHorizontal){
        if(slab == 0){
            return calib_TOF0_hSlab0;
        }
        else if(slab == 1){
            return calib_TOF0_hSlab1;
        }
        else if(slab == 2){
            return calib_TOF0_hSlab2;
        }
        else if(slab == 3){
            return calib_TOF0_hSlab3;
        }
        else if(slab == 4){
            return calib_TOF0_hSlab4;
        }
        else if(slab == 5){
            return calib_TOF0_hSlab5;
        }
        else if(slab == 6){
            return calib_TOF0_hSlab6;
        }
        else if(slab == 7){
            return calib_TOF0_hSlab7;
        }
        else if(slab == 8){
            return calib_TOF0_hSlab8;
        }
        else{
            return calib_TOF0_hSlab9;
        }
    }
    else{
        if(slab == 0){
            return calib_TOF0_vSlab0;
        }
        else if(slab == 1){
            return calib_TOF0_vSlab1;
        }
        else if(slab == 2){
            return calib_TOF0_vSlab2;
        }
        else if(slab == 3){
            return calib_TOF0_vSlab3;
        }
        else if(slab == 4){
            return calib_TOF0_vSlab4;
        }
        else if(slab == 5){
            return calib_TOF0_vSlab5;
        }
        else if(slab == 6){
            return calib_TOF0_vSlab6;
        }
        else if(slab == 7){
            return calib_TOF0_vSlab7;
        }
        else if(slab == 8){
            return calib_TOF0_vSlab8;
        }
        else{
            return calib_TOF0_vSlab9;
        }
    }
}


QVector<double> Calibrate::getTOF1SlabConstants(int slab, bool isHorizontal){
    if(isHorizontal){
        if(slab == 0){
            return calib_TOF1_hSlab0;
        }
        else if(slab == 1){
            return calib_TOF1_hSlab1;
        }
        else if(slab == 2){
            return calib_TOF1_hSlab2;
        }
        else if(slab == 3){
            return calib_TOF1_hSlab3;
        }
        else if(slab == 4){
            return calib_TOF1_hSlab4;
        }
        else if(slab == 5){
            return calib_TOF1_hSlab5;
        }
        else{
            return calib_TOF1_hSlab6;
        }
    }
    else{
        if(slab == 0){
            return calib_TOF1_vSlab0;
        }
        else if(slab == 1){
            return calib_TOF1_vSlab1;
        }
        else if(slab == 2){
            return calib_TOF1_vSlab2;
        }
        else if(slab == 3){
            return calib_TOF1_vSlab3;
        }
        else if(slab == 4){
            return calib_TOF1_vSlab4;
        }
        else if(slab == 5){
            return calib_TOF1_vSlab5;
        }
        else {
            return calib_TOF1_vSlab6;
        }
    }
}











void Calibrate::globalCalibration(){
    current_slab_data.clear();
    current_slab_data = construct_global_particles();
    std::cerr << "Constructed list of particles.\n";
    calibrated_global_c_eff = doGlobalMinimisation();
    std::cerr << "Best speed of light is: " << calibrated_global_c_eff << "\n";
}

QVector<QVector<double> > Calibrate::construct_global_particles(){
    QVector<QVector<double> > global_data;
    QVector<QVector<double> > tmp_data;
    QVector<double> tmp_calib;

    if(calibratingTOF0){
        for(int i = 0; i < 10; i++){
            if(i == 3 || i == 4 || i == 5 || i == 6){
                tmp_data.clear();
                tmp_calib.clear();
                tmp_data = read->getTOF0HorizontalSlab(i);
                tmp_calib = getTOF0SlabConstants(i, true);
                global_data << append_calibration_info(tmp_data, tmp_calib);
            }
        }
        for(int i = 0; i < 10; i++){
            if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6){
                tmp_data.clear();
                tmp_calib.clear();
                tmp_data = read->getTOF0VerticalSlab(i);
                tmp_calib = getTOF0SlabConstants(i, false);
                global_data << append_calibration_info(tmp_data, tmp_calib);
            }
        }
    }
    if(calibratingTOF1){
        for(int i = 0; i < 7; i++){
            if(i == 2 || i == 3 || i == 4){
                tmp_data.clear();
                tmp_calib.clear();
                tmp_data = read->getTOF1HorizontalSlab(i);
                tmp_calib = getTOF1SlabConstants(i, true);
                global_data << append_calibration_info(tmp_data, tmp_calib);
            } // excluding TOF1 horizontal slab 4
        }
        for(int i = 0; i < 7; i++){
            if(i == 2 || i == 3 || i == 4 || i == 5){
                tmp_data.clear();
                tmp_calib.clear();
                tmp_data = read->getTOF1VerticalSlab(i);
                tmp_calib = getTOF1SlabConstants(i, false);
                global_data << append_calibration_info(tmp_data, tmp_calib);
            }
        }
    }
    return global_data;
}

QVector<QVector<double> > Calibrate::append_calibration_info(QVector<QVector<double> > slab_data, QVector<double> calib_data){
    QVector<double> current_particle;
    QVector<QVector<double> > particles_to_return;
    for(int i = 0; i < slab_data.size(); i++){
        current_particle.clear();
        current_particle = slab_data.at(i);

        if(!calib_data.isEmpty()){
            current_particle << calib_data.at(1); // add delta to the current particle QVector
        }
        else{
            current_particle << 0.0; // set delta to 0.0 if no previous calibrations have been done
        }
        particles_to_return << current_particle;
    }
    return particles_to_return;
}





double Calibrate::doGlobalMinimisation(){
    ROOT::Math::Minimizer* min =
          ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
    min->SetMaxFunctionCalls(100000000); // for Minuit/Minuit2
    min->SetMaxIterations(1000000);  // for GSL
    min->SetTolerance(0.001);
    min->SetPrintLevel(0);

    ROOT::Math::Functor f(this,&Calibrate::global_minimise,1);
    min->SetFunction(f);
    min->SetVariable(0, "c_eff", 135.2, c_eff_step);
    min->SetVariableLimits(0, c_eff_min, c_eff_max);

    min->Minimize();

    std::cerr << "Completed minimisation...\n";
    const double *res = min->X();
    std::cerr << "Retrieved minimisation variables...\n";

    //std::cerr << "GLOBAL STATUS = " << min->Status()<< "\n";

    return res[0];
}



QVector<double> Calibrate::doDeltaMinimisation(double current_delta){
    ROOT::Math::Minimizer* min =
          ROOT::Math::Factory::CreateMinimizer("Minuit2", "Combined");
    min->SetMaxFunctionCalls(100000000); // for Minuit/Minuit2
    min->SetMaxIterations(1000000);  // for GSL
    min->SetTolerance(0.001);
    min->SetPrintLevel(0);

    ROOT::Math::Functor f(this,&Calibrate::delta_minimise,1);
    min->SetFunction(f);
    min->SetVariable(0, "delta", current_delta, delta_step);
    min->SetVariableLimits(0, delta_min, delta_max);
  /*  if(calibratingTOF0){
        min->SetVariableLimits(0, -0.4, -0.01);
    }
    if(calibratingTOF1){
        min->SetVariableLimits(0, -1.0, 1.0);
    }
*/
    std::cerr << ".. starting minimisation...";

    min->Minimize();
    const double *res = min->X();

    std::cerr << "minimisation completed...";

    QVector<double> result;
    result << calibrated_global_c_eff << res[0];
    return result;
}





QVector<double> Calibrate::doMinimisation(){
    ROOT::Math::Minimizer* min =
          ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
    min->SetMaxFunctionCalls(100000000); // for Minuit/Minuit2
    min->SetMaxIterations(1000000);  // for GSL
    min->SetTolerance(0.001);
    min->SetPrintLevel(0);

    ROOT::Math::Functor f(this,&Calibrate::minimise,2);
    min->SetFunction(f);
    min->SetVariable(0, "c_eff", calibrated_global_c_eff, c_eff_step);
    min->SetVariable(1, "delta", 0.0, delta_step);

    min->Minimize();
    const double *res = min->X();

    QVector<double> result;
    result << res[0] << res[1];
    return result;
}



void Calibrate::setCalibrationConstants(double c_eff, double delta, double fraction, int TOF, int slab, bool isHorizontal){
    if(isHorizontal){
        // set horizontal slab calibrations
        if(TOF == 0){
            if(slab == 0){
                calib_TOF0_hSlab0.clear();
                calib_TOF0_hSlab0 << c_eff << delta << fraction;
            }
            else if(slab == 1){
                calib_TOF0_hSlab1.clear();
                calib_TOF0_hSlab1 << c_eff << delta << fraction;
            }
            else if(slab == 2){
                calib_TOF0_hSlab2.clear();
                calib_TOF0_hSlab2 << c_eff << delta << fraction;
            }
            else if(slab == 3){
                calib_TOF0_hSlab3.clear();
                calib_TOF0_hSlab3 << c_eff << delta << fraction;
            }
            else if(slab == 4){
                calib_TOF0_hSlab4.clear();
                calib_TOF0_hSlab4 << c_eff << delta << fraction;
            }
            else if(slab == 5){
                calib_TOF0_hSlab5.clear();
                calib_TOF0_hSlab5 << c_eff << delta << fraction;
            }
            else if(slab == 6){
                calib_TOF0_hSlab6.clear();
                calib_TOF0_hSlab6 << c_eff << delta << fraction;
            }
            else if(slab == 7){
                calib_TOF0_hSlab7.clear();
                calib_TOF0_hSlab7 << c_eff << delta << fraction;
            }
            else if(slab == 8){
                calib_TOF0_hSlab8.clear();
                calib_TOF0_hSlab8 << c_eff << delta << fraction;
            }
            else if(slab == 9){
                calib_TOF0_hSlab9.clear();
                calib_TOF0_hSlab9 << c_eff << delta << fraction;
            }
        }
        else if(TOF == 1){
            if(slab == 0){
                calib_TOF1_hSlab0.clear();
                calib_TOF1_hSlab0 << c_eff << delta << fraction;
            }
            else if(slab == 1){
                calib_TOF1_hSlab1.clear();
                calib_TOF1_hSlab1 << c_eff << delta << fraction;
            }
            else if(slab == 2){
                calib_TOF1_hSlab2.clear();
                calib_TOF1_hSlab2 << c_eff << delta << fraction;
            }
            else if(slab == 3){
                calib_TOF1_hSlab3.clear();
                calib_TOF1_hSlab3 << c_eff << delta << fraction;
            }
            else if(slab == 4){
                calib_TOF1_hSlab4.clear();
                calib_TOF1_hSlab4 << c_eff << delta << fraction;
            }
            else if(slab == 5){
                calib_TOF1_hSlab5.clear();
                calib_TOF1_hSlab5 << c_eff << delta << fraction;
            }
            else if(slab == 6){
                calib_TOF1_hSlab6.clear();
                calib_TOF1_hSlab6 << c_eff << delta << fraction;
            }
        }

    }
    else{
        // set horizontal slab calibrations
        if(TOF == 0){
            if(slab == 0){
                calib_TOF0_vSlab0.clear();
                calib_TOF0_vSlab0 << c_eff << delta << fraction;
            }
            else if(slab == 1){
                calib_TOF0_vSlab1.clear();
                calib_TOF0_vSlab1 << c_eff << delta << fraction;
            }
            else if(slab == 2){
                calib_TOF0_vSlab2.clear();
                calib_TOF0_vSlab2 << c_eff << delta << fraction;
            }
            else if(slab == 3){
                calib_TOF0_vSlab3.clear();
                calib_TOF0_vSlab3 << c_eff << delta << fraction;
            }
            else if(slab == 4){
                calib_TOF0_vSlab4.clear();
                calib_TOF0_vSlab4 << c_eff << delta << fraction;
            }
            else if(slab == 5){
                calib_TOF0_vSlab5.clear();
                calib_TOF0_vSlab5 << c_eff << delta << fraction;
            }
            else if(slab == 6){
                calib_TOF0_vSlab6.clear();
                calib_TOF0_vSlab6 << c_eff << delta << fraction;
            }
            else if(slab == 7){
                calib_TOF0_vSlab7.clear();
                calib_TOF0_vSlab7 << c_eff << delta << fraction;
            }
            else if(slab == 8){
                calib_TOF0_vSlab8.clear();
                calib_TOF0_vSlab8 << c_eff << delta << fraction;
            }
            else if(slab == 9){
                calib_TOF0_vSlab9.clear();
                calib_TOF0_vSlab9 << c_eff << delta << fraction;
            }
        }
        else if(TOF == 1){
            if(slab == 0){
                calib_TOF1_vSlab0.clear();
                calib_TOF1_vSlab0 << c_eff << delta << fraction;
            }
            else if(slab == 1){
                calib_TOF1_vSlab1.clear();
                calib_TOF1_vSlab1 << c_eff << delta << fraction;
            }
            else if(slab == 2){
                calib_TOF1_vSlab2.clear();
                calib_TOF1_vSlab2 << c_eff << delta << fraction;
            }
            else if(slab == 3){
                calib_TOF1_vSlab3.clear();
                calib_TOF1_vSlab3 << c_eff << delta << fraction;
            }
            else if(slab == 4){
                calib_TOF1_vSlab4.clear();
                calib_TOF1_vSlab4 << c_eff << delta << fraction;
            }
            else if(slab == 5){
                calib_TOF1_vSlab5.clear();
                calib_TOF1_vSlab5 << c_eff << delta << fraction;
            }
            else if(slab == 6){
                calib_TOF1_vSlab6.clear();
                calib_TOF1_vSlab6 << c_eff << delta << fraction;
            }
        }
    }
}

void Calibrate::printCalibration(QString outputFile){

    QFile file(outputFile);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QTextStream out(&file);

    out << "Calibration results for TOF0:\n";
    out << "Horizontal slabs (slab, c_eff, delta, fraction within slab):\n";
    out << "0\t" << calib_TOF0_hSlab0.at(0) << "\t" << calib_TOF0_hSlab0.at(1) << "\t" << calib_TOF0_hSlab0.at(2) << "\n";
    out << "1\t" << calib_TOF0_hSlab1.at(0) << "\t" << calib_TOF0_hSlab1.at(1) << "\t" << calib_TOF0_hSlab1.at(2) << "\n";
    out << "2\t" << calib_TOF0_hSlab2.at(0) << "\t" << calib_TOF0_hSlab2.at(1) << "\t" << calib_TOF0_hSlab2.at(2) << "\n";
    out << "3\t" << calib_TOF0_hSlab3.at(0) << "\t" << calib_TOF0_hSlab3.at(1) << "\t" << calib_TOF0_hSlab3.at(2) << "\n";
    out << "4\t" << calib_TOF0_hSlab4.at(0) << "\t" << calib_TOF0_hSlab4.at(1) << "\t" << calib_TOF0_hSlab4.at(2) << "\n";
    out << "5\t" << calib_TOF0_hSlab5.at(0) << "\t" << calib_TOF0_hSlab5.at(1) << "\t" << calib_TOF0_hSlab5.at(2) << "\n";
    out << "6\t" << calib_TOF0_hSlab6.at(0) << "\t" << calib_TOF0_hSlab6.at(1) << "\t" << calib_TOF0_hSlab6.at(2) << "\n";
    out << "7\t" << calib_TOF0_hSlab7.at(0) << "\t" << calib_TOF0_hSlab7.at(1) << "\t" << calib_TOF0_hSlab7.at(2) << "\n";
    out << "8\t" << calib_TOF0_hSlab8.at(0) << "\t" << calib_TOF0_hSlab8.at(1) << "\t" << calib_TOF0_hSlab8.at(2) << "\n";
    out << "9\t" << calib_TOF0_hSlab9.at(0) << "\t" << calib_TOF0_hSlab9.at(1) << "\t" << calib_TOF0_hSlab9.at(2) << "\n";

    out << "Vertical slabs (slab, c_eff, delta, fraction within slab):\n";
    out << "0\t" << calib_TOF0_vSlab0.at(0) << "\t" << calib_TOF0_vSlab0.at(1) << "\t" << calib_TOF0_vSlab0.at(2) << "\n";
    out << "1\t" << calib_TOF0_vSlab1.at(0) << "\t" << calib_TOF0_vSlab1.at(1) << "\t" << calib_TOF0_vSlab1.at(2) << "\n";
    out << "2\t" << calib_TOF0_vSlab2.at(0) << "\t" << calib_TOF0_vSlab2.at(1) << "\t" << calib_TOF0_vSlab2.at(2) << "\n";
    out << "3\t" << calib_TOF0_vSlab3.at(0) << "\t" << calib_TOF0_vSlab3.at(1) << "\t" << calib_TOF0_vSlab3.at(2) << "\n";
    out << "4\t" << calib_TOF0_vSlab4.at(0) << "\t" << calib_TOF0_vSlab4.at(1) << "\t" << calib_TOF0_vSlab4.at(2) << "\n";
    out << "5\t" << calib_TOF0_vSlab5.at(0) << "\t" << calib_TOF0_vSlab5.at(1) << "\t" << calib_TOF0_vSlab5.at(2) << "\n";
    out << "6\t" << calib_TOF0_vSlab6.at(0) << "\t" << calib_TOF0_vSlab6.at(1) << "\t" << calib_TOF0_vSlab6.at(2) << "\n";
    out << "7\t" << calib_TOF0_vSlab7.at(0) << "\t" << calib_TOF0_vSlab7.at(1) << "\t" << calib_TOF0_vSlab7.at(2) << "\n";
    out << "8\t" << calib_TOF0_vSlab8.at(0) << "\t" << calib_TOF0_vSlab8.at(1) << "\t" << calib_TOF0_vSlab8.at(2) << "\n";
    out << "9\t" << calib_TOF0_vSlab9.at(0) << "\t" << calib_TOF0_vSlab9.at(1) << "\t" << calib_TOF0_vSlab9.at(2) << "\n";

    out << "Calibration results for TOF1:\n";
    out << "Horizontal slabs (slab, c_eff, delta, fraction within slab):\n";
    out << "0\t" << calib_TOF1_hSlab0.at(0) << "\t" << calib_TOF1_hSlab0.at(1) << "\t" << calib_TOF1_hSlab0.at(2) << "\n";
    out << "1\t" << calib_TOF1_hSlab1.at(0) << "\t" << calib_TOF1_hSlab1.at(1) << "\t" << calib_TOF1_hSlab1.at(2) << "\n";
    out << "2\t" << calib_TOF1_hSlab2.at(0) << "\t" << calib_TOF1_hSlab2.at(1) << "\t" << calib_TOF1_hSlab2.at(2) << "\n";
    out << "3\t" << calib_TOF1_hSlab3.at(0) << "\t" << calib_TOF1_hSlab3.at(1) << "\t" << calib_TOF1_hSlab3.at(2) << "\n";
    out << "4\t" << calib_TOF1_hSlab4.at(0) << "\t" << calib_TOF1_hSlab4.at(1) << "\t" << calib_TOF1_hSlab4.at(2) << "\n";
    out << "5\t" << calib_TOF1_hSlab5.at(0) << "\t" << calib_TOF1_hSlab5.at(1) << "\t" << calib_TOF1_hSlab5.at(2) << "\n";
    out << "6\t" << calib_TOF1_hSlab6.at(0) << "\t" << calib_TOF1_hSlab6.at(1) << "\t" << calib_TOF1_hSlab6.at(2) << "\n";

    out << "Vertical slabs (slab, c_eff, delta, fraction within slab):\n";
    out << "0\t" << calib_TOF1_vSlab0.at(0) << "\t" << calib_TOF1_vSlab0.at(1) << "\t" << calib_TOF1_vSlab0.at(2) << "\n";
    out << "1\t" << calib_TOF1_vSlab1.at(0) << "\t" << calib_TOF1_vSlab1.at(1) << "\t" << calib_TOF1_vSlab1.at(2) << "\n";
    out << "2\t" << calib_TOF1_vSlab2.at(0) << "\t" << calib_TOF1_vSlab2.at(1) << "\t" << calib_TOF1_vSlab2.at(2) << "\n";
    out << "3\t" << calib_TOF1_vSlab3.at(0) << "\t" << calib_TOF1_vSlab3.at(1) << "\t" << calib_TOF1_vSlab3.at(2) << "\n";
    out << "4\t" << calib_TOF1_vSlab4.at(0) << "\t" << calib_TOF1_vSlab4.at(1) << "\t" << calib_TOF1_vSlab4.at(2) << "\n";
    out << "5\t" << calib_TOF1_vSlab5.at(0) << "\t" << calib_TOF1_vSlab5.at(1) << "\t" << calib_TOF1_vSlab5.at(2) << "\n";
    out << "6\t" << calib_TOF1_vSlab6.at(0) << "\t" << calib_TOF1_vSlab6.at(1) << "\t" << calib_TOF1_vSlab6.at(2) << "\n";

    file.close();

}


void Calibrate::setup_plots(){
    plot_tof0_hSlab_0 = new TH1F("plot_tof0_hSlab_0", "TOF0, Hslab 0; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_1 = new TH1F("plot_tof0_hSlab_1", "TOF0, Hslab 1; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_2 = new TH1F("plot_tof0_hSlab_2", "TOF0, Hslab 2; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_3 = new TH1F("plot_tof0_hSlab_3", "TOF0, Hslab 3; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_4 = new TH1F("plot_tof0_hSlab_4", "TOF0, Hslab 4; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_5 = new TH1F("plot_tof0_hSlab_5", "TOF0, Hslab 5; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_6 = new TH1F("plot_tof0_hSlab_6", "TOF0, Hslab 6; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_7 = new TH1F("plot_tof0_hSlab_7", "TOF0, Hslab 7; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_8 = new TH1F("plot_tof0_hSlab_8", "TOF0, Hslab 8; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_hSlab_9 = new TH1F("plot_tof0_hSlab_9", "TOF0, Hslab 9; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_0 = new TH1F("plot_tof0_vSlab_0", "TOF0, Vslab 0; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_1 = new TH1F("plot_tof0_vSlab_1", "TOF0, Vslab 1; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_2 = new TH1F("plot_tof0_vSlab_2", "TOF0, Vslab 2; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_3 = new TH1F("plot_tof0_vSlab_3", "TOF0, Vslab 3; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_4 = new TH1F("plot_tof0_vSlab_4", "TOF0, Vslab 4; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_5 = new TH1F("plot_tof0_vSlab_5", "TOF0, Vslab 5; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_6 = new TH1F("plot_tof0_vSlab_6", "TOF0, Vslab 6; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_7 = new TH1F("plot_tof0_vSlab_7", "TOF0, Vslab 7; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_8 = new TH1F("plot_tof0_vSlab_8", "TOF0, Vslab 8; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof0_vSlab_9 = new TH1F("plot_tof0_vSlab_9", "TOF0, Vslab 9; y_pmt - y_pixel (mm)",500, -100.0, 100.0);

    plot_tof1_hSlab_0 = new TH1F("plot_tof1_hSlab_0", "TOF1, Hslab 0; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_hSlab_1 = new TH1F("plot_tof1_hSlab_1", "TOF1, Hslab 1; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_hSlab_2 = new TH1F("plot_tof1_hSlab_2", "TOF1, Hslab 2; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_hSlab_3 = new TH1F("plot_tof1_hSlab_3", "TOF1, Hslab 3; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_hSlab_4 = new TH1F("plot_tof1_hSlab_4", "TOF1, Hslab 4; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_hSlab_5 = new TH1F("plot_tof1_hSlab_5", "TOF1, Hslab 5; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_hSlab_6 = new TH1F("plot_tof1_hSlab_6", "TOF1, Hslab 6; x_pmt - x_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_0 = new TH1F("plot_tof1_vSlab_0", "TOF1, Vslab 0; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_1 = new TH1F("plot_tof1_vSlab_1", "TOF1, Vslab 1; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_2 = new TH1F("plot_tof1_vSlab_2", "TOF1, Vslab 2; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_3 = new TH1F("plot_tof1_vSlab_3", "TOF1, Vslab 3; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_4 = new TH1F("plot_tof1_vSlab_4", "TOF1, Vslab 4; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_5 = new TH1F("plot_tof1_vSlab_5", "TOF1, Vslab 5; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
    plot_tof1_vSlab_6 = new TH1F("plot_tof1_vSlab_6", "TOF1, Vslab 6; y_pmt - y_pixel (mm)",500, -100.0, 100.0);
}

void Calibrate::print_plots(){
    fillTOF0Plots();
    fillTOF1Plots();

    TCanvas* c = new TCanvas("c", "c", 900, 400);
    c->Divide(2, 1);

    c->cd(1);
    plot_tof0_hSlab_0->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_0->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_1->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_1->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_2->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_2->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_3->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_3->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_4->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_4->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_5->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_5->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_6->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_6->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_7->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_7->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_8->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_8->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof0_hSlab_9->Draw("hist");
    c->cd(2);
    plot_tof0_vSlab_9->Draw("hist");
    c->Print("test.pdf(");


    c->cd(1);
    plot_tof1_hSlab_0->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_0->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof1_hSlab_1->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_1->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof1_hSlab_2->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_2->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof1_hSlab_3->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_3->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof1_hSlab_4->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_4->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof1_hSlab_5->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_5->Draw("hist");
    c->Print("test.pdf(");

    c->cd(1);
    plot_tof1_hSlab_6->Draw("hist");
    c->cd(2);
    plot_tof1_vSlab_6->Draw("hist");
    c->Print("test.pdf)");
}

QVector<double> Calibrate::calculate_residuals(QVector<QVector<double> > slab_data, QVector<double> calib_data){
    double c_eff = calib_data.at(0);
    double delta = calib_data.at(1);

    double t_minus, t_plus, pixel, calib_pos;
    QVector<double> residuals;
    QVector<double> particle;
    for(int i = 0; i < slab_data.size(); i++){
        particle.clear();
        particle = slab_data.at(i);

        pixel = particle.at(0);
        t_minus = particle.at(1);
        t_plus = particle.at(2);

        calib_pos = 0.5*c_eff*(t_minus - t_plus + delta);
        residuals << calib_pos - pixel;
    }
    return residuals;
}

void Calibrate::fillTOF0Plots(){
    // fill TOF0 horizontal slabs first...
    QVector<double> residuals;

    for(int slab = 0; slab < 10; slab++){
        residuals.clear();
        residuals = calculate_residuals(read->getTOF0HorizontalSlab(slab), getTOF0SlabConstants(slab, true));
        for(int i = 0; i < residuals.size(); i++){
            if(slab == 0){
                plot_tof0_hSlab_0->Fill(residuals.at(i));
            }
            else if(slab == 1){
                plot_tof0_hSlab_1->Fill(residuals.at(i));
            }
            else if(slab == 2){
                plot_tof0_hSlab_2->Fill(residuals.at(i));
            }
            else if(slab == 3){
                plot_tof0_hSlab_3->Fill(residuals.at(i));
            }
            else if(slab == 4){
                plot_tof0_hSlab_4->Fill(residuals.at(i));
            }
            else if(slab == 5){
                plot_tof0_hSlab_5->Fill(residuals.at(i));
            }
            else if(slab == 6){
                plot_tof0_hSlab_6->Fill(residuals.at(i));
            }
            else if(slab == 7){
                plot_tof0_hSlab_7->Fill(residuals.at(i));
            }
            else if(slab == 8){
                plot_tof0_hSlab_8->Fill(residuals.at(i));
            }
            else{
                plot_tof0_hSlab_9->Fill(residuals.at(i));
            }
        }
    }

    for(int slab = 0; slab < 10; slab++){
        residuals.clear();
        residuals = calculate_residuals(read->getTOF0VerticalSlab(slab), getTOF0SlabConstants(slab, false));
        for(int i = 0; i < residuals.size(); i++){
            if(slab == 0){
                plot_tof0_vSlab_0->Fill(residuals.at(i));
            }
            else if(slab == 1){
                plot_tof0_vSlab_1->Fill(residuals.at(i));
            }
            else if(slab == 2){
                plot_tof0_vSlab_2->Fill(residuals.at(i));
            }
            else if(slab == 3){
                plot_tof0_vSlab_3->Fill(residuals.at(i));
            }
            else if(slab == 4){
                plot_tof0_vSlab_4->Fill(residuals.at(i));
            }
            else if(slab == 5){
                plot_tof0_vSlab_5->Fill(residuals.at(i));
            }
            else if(slab == 6){
                plot_tof0_vSlab_6->Fill(residuals.at(i));
            }
            else if(slab == 7){
                plot_tof0_vSlab_7->Fill(residuals.at(i));
            }
            else if(slab == 8){
                plot_tof0_vSlab_8->Fill(residuals.at(i));
            }
            else{
                plot_tof0_vSlab_9->Fill(residuals.at(i));
            }
        }
    }


}


void Calibrate::fillTOF1Plots(){
    // fill TOF1 horizontal slabs first...
    QVector<double> residuals;

    for(int slab = 0; slab < 7; slab++){
        residuals.clear();
        residuals = calculate_residuals(read->getTOF1HorizontalSlab(slab), getTOF1SlabConstants(slab, true));
        for(int i = 0; i < residuals.size(); i++){
            if(slab == 0){
                plot_tof1_hSlab_0->Fill(residuals.at(i));
            }
            else if(slab == 1){
                plot_tof1_hSlab_1->Fill(residuals.at(i));
            }
            else if(slab == 2){
                plot_tof1_hSlab_2->Fill(residuals.at(i));
            }
            else if(slab == 3){
                plot_tof1_hSlab_3->Fill(residuals.at(i));
            }
            else if(slab == 4){
                plot_tof1_hSlab_4->Fill(residuals.at(i));
            }
            else if(slab == 5){
                plot_tof1_hSlab_5->Fill(residuals.at(i));
            }
            else{
                plot_tof1_hSlab_6->Fill(residuals.at(i));
            }
        }
    }

    for(int slab = 0; slab < 7; slab++){
        residuals.clear();
        residuals = calculate_residuals(read->getTOF1VerticalSlab(slab), getTOF1SlabConstants(slab, false));
        for(int i = 0; i < residuals.size(); i++){
            if(slab == 0){
                plot_tof1_vSlab_0->Fill(residuals.at(i));
            }
            else if(slab == 1){
                plot_tof1_vSlab_1->Fill(residuals.at(i));
            }
            else if(slab == 2){
                plot_tof1_vSlab_2->Fill(residuals.at(i));
            }
            else if(slab == 3){
                plot_tof1_vSlab_3->Fill(residuals.at(i));
            }
            else if(slab == 4){
                plot_tof1_vSlab_4->Fill(residuals.at(i));
            }
            else if(slab == 5){
                plot_tof1_vSlab_5->Fill(residuals.at(i));
            }
            else {
                plot_tof1_vSlab_6->Fill(residuals.at(i));
            }
        }
    }
}
