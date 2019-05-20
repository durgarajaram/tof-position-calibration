#ifndef CALIBRATE_H
#define CALIBRATE_H

#include "QString"
#include "TTree.h"
#include "TFile.h"
#include "QVector"
#include "QList"
#include "QListIterator"
#include "QFile"
#include "QTextStream"
#include <iostream>

#include "TCanvas.h"
#include "TH1F.h"
#include "TMath.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "readmaus.h"

class Calibrate
{
public:
    Calibrate();

    void MakeCalibration(QString input_filename, QString output_calibration_filename, double minimum_tof, double maximum_tof);



private:
    ReadMAUS* read;

    TFile* outputFile;
    QString outputFileName;

    QString outputCalibrationFileName;

    double c_eff_min, c_eff_max, c_eff_step;
    double delta_min, delta_max, delta_step;

    void getSlabData(QString input_filename, double min_tof, double max_tof); //d

    bool particleInSlab(double c_eff, double delta, QVector<double> slabData); //d
    double getFraction(double c_eff, double delta);


    // functions for TMinuit minimisation:
    double doGlobalMinimisation();
    QVector<double> doMinimisation();
    QVector<double> doDeltaMinimisation(double current_delta);
    double minimise(const double* par); //d
    double global_minimise(const double* par); //d
    double delta_minimise(const double* par);


    QVector<QVector<double> > current_slab_data;

    void calibrateTOF0(); //d
    void calibrateTOF1(); //d
    void calibrateTOF0Slab(int slab, bool isHorizontal); // d
    void calibrateTOF1Slab(int slab, bool isHorizontal); //d

    void calibrateTOF0Delta(); //d
    void calibrateTOF1Delta(); //d
    void calibrateTOF0SlabDelta(int slab, bool isHorizontal); //d
    void calibrateTOF1SlabDelta(int slab, bool isHorizontal); //d

    void globalCalibration(); //d

    void setCalibrationConstants(double c_eff, double delta, double fraction, int TOF, int slab, bool isHorizontal);
    void printCalibration(QString outputFile);

    QVector<double> calib_TOF0_hSlab0;
    QVector<double> calib_TOF0_hSlab1;
    QVector<double> calib_TOF0_hSlab2;
    QVector<double> calib_TOF0_hSlab3;
    QVector<double> calib_TOF0_hSlab4;
    QVector<double> calib_TOF0_hSlab5;
    QVector<double> calib_TOF0_hSlab6;
    QVector<double> calib_TOF0_hSlab7;
    QVector<double> calib_TOF0_hSlab8;
    QVector<double> calib_TOF0_hSlab9;

    QVector<double> calib_TOF0_vSlab0;
    QVector<double> calib_TOF0_vSlab1;
    QVector<double> calib_TOF0_vSlab2;
    QVector<double> calib_TOF0_vSlab3;
    QVector<double> calib_TOF0_vSlab4;
    QVector<double> calib_TOF0_vSlab5;
    QVector<double> calib_TOF0_vSlab6;
    QVector<double> calib_TOF0_vSlab7;
    QVector<double> calib_TOF0_vSlab8;
    QVector<double> calib_TOF0_vSlab9;

    QVector<double> calib_TOF1_hSlab0;
    QVector<double> calib_TOF1_hSlab1;
    QVector<double> calib_TOF1_hSlab2;
    QVector<double> calib_TOF1_hSlab3;
    QVector<double> calib_TOF1_hSlab4;
    QVector<double> calib_TOF1_hSlab5;
    QVector<double> calib_TOF1_hSlab6;

    QVector<double> calib_TOF1_vSlab0;
    QVector<double> calib_TOF1_vSlab1;
    QVector<double> calib_TOF1_vSlab2;
    QVector<double> calib_TOF1_vSlab3;
    QVector<double> calib_TOF1_vSlab4;
    QVector<double> calib_TOF1_vSlab5;
    QVector<double> calib_TOF1_vSlab6;

    double calibrated_global_c_eff;

    QVector<double> getTOF0SlabConstants(int slab, bool isHorizontal); //d
    QVector<double> getTOF1SlabConstants(int slab, bool isHorizontal); //d
    QVector<QVector<double> > construct_global_particles(); //d
    bool calibratingTOF0, calibratingTOF1;
    QVector<QVector<double> > append_calibration_info(QVector<QVector<double> > slab_data, QVector<double> calib_data); //d


    void setup_plots();
    void print_plots();
    void fillTOF0Plots();
    void fillTOF1Plots();
    QVector<double> calculate_residuals(QVector<QVector<double> > slab_data, QVector<double> calib_data);
    TH1F* plot_tof0_hSlab_0;
    TH1F* plot_tof0_hSlab_1;
    TH1F* plot_tof0_hSlab_2;
    TH1F* plot_tof0_hSlab_3;
    TH1F* plot_tof0_hSlab_4;
    TH1F* plot_tof0_hSlab_5;
    TH1F* plot_tof0_hSlab_6;
    TH1F* plot_tof0_hSlab_7;
    TH1F* plot_tof0_hSlab_8;
    TH1F* plot_tof0_hSlab_9;
    TH1F* plot_tof0_vSlab_0;
    TH1F* plot_tof0_vSlab_1;
    TH1F* plot_tof0_vSlab_2;
    TH1F* plot_tof0_vSlab_3;
    TH1F* plot_tof0_vSlab_4;
    TH1F* plot_tof0_vSlab_5;
    TH1F* plot_tof0_vSlab_6;
    TH1F* plot_tof0_vSlab_7;
    TH1F* plot_tof0_vSlab_8;
    TH1F* plot_tof0_vSlab_9;

    TH1F* plot_tof1_hSlab_0;
    TH1F* plot_tof1_hSlab_1;
    TH1F* plot_tof1_hSlab_2;
    TH1F* plot_tof1_hSlab_3;
    TH1F* plot_tof1_hSlab_4;
    TH1F* plot_tof1_hSlab_5;
    TH1F* plot_tof1_hSlab_6;
    TH1F* plot_tof1_vSlab_0;
    TH1F* plot_tof1_vSlab_1;
    TH1F* plot_tof1_vSlab_2;
    TH1F* plot_tof1_vSlab_3;
    TH1F* plot_tof1_vSlab_4;
    TH1F* plot_tof1_vSlab_5;
    TH1F* plot_tof1_vSlab_6;




};

#endif // CALIBRATE_H
