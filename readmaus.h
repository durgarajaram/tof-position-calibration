#ifndef ReadMAUS_H
#define ReadMAUS_H

#include <iostream>
#include "string.h"
#include <TFile.h>
#include <TTree.h>
#include <QString>
#include "TMath.h"
#include <QVector>


#include <DataStructure/Spill.hh>
#include <DataStructure/TOFEvent.hh>
#include <DataStructure/Data.hh>
#include <DataStructure/ReconEvent.hh>
#include <DataStructure/SciFiEvent.hh>
#include <DataStructure/SciFiTrack.hh>
#include <DataStructure/SciFiTrackPoint.hh>
#include <DataStructure/SciFiSpacePoint.hh>
#include <DataStructure/SciFiStraightPRTrack.hh>
#include <DataStructure/SciFiCluster.hh>
#include <DataStructure/SciFiDigit.hh>
#include <DataStructure/SciFiChannelId.hh>
#include <DataStructure/Hit.hh>
#include <DataStructure/Track.hh>
#include <DataStructure/ThreeVector.hh>

#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>

class ReadMAUS
{
public:
    ReadMAUS();
    ~ReadMAUS();

    void Read(QString fileToOpen, double min_tof, double max_tof);

    QVector<QVector<double> > getTOF0HorizontalSlab(int slabNumber);
    QVector<QVector<double> > getTOF0VerticalSlab(int slabNumber);

    QVector<QVector<double> > getTOF1HorizontalSlab(int slabNumber);
    QVector<QVector<double> > getTOF1VerticalSlab(int slabNumber);

    QVector<QVector<double> > getAllParticles();

    QVector<double> getTOFOffset(int TOF);

private:
    MAUS::Spill *spill;
    MAUS::TOFEvent *tof_event;

    //int all_particle_count;
    //int accepted_particle_count;

    TFile *dataFile;

    TH1F* tof0_hSlab_0_pmt_diff;
    TH1F* tof0_hSlab_1_pmt_diff;
    TH1F* tof0_hSlab_2_pmt_diff;
    TH1F* tof0_hSlab_3_pmt_diff;
    TH1F* tof0_hSlab_4_pmt_diff;
    TH1F* tof0_hSlab_5_pmt_diff;
    TH1F* tof0_hSlab_6_pmt_diff;
    TH1F* tof0_hSlab_7_pmt_diff;
    TH1F* tof0_hSlab_8_pmt_diff;
    TH1F* tof0_hSlab_9_pmt_diff;
    TH1F* tof0_vSlab_0_pmt_diff;
    TH1F* tof0_vSlab_1_pmt_diff;
    TH1F* tof0_vSlab_2_pmt_diff;
    TH1F* tof0_vSlab_3_pmt_diff;
    TH1F* tof0_vSlab_4_pmt_diff;
    TH1F* tof0_vSlab_5_pmt_diff;
    TH1F* tof0_vSlab_6_pmt_diff;
    TH1F* tof0_vSlab_7_pmt_diff;
    TH1F* tof0_vSlab_8_pmt_diff;
    TH1F* tof0_vSlab_9_pmt_diff;
    TH1F* tof1_hSlab_0_pmt_diff;
    TH1F* tof1_hSlab_1_pmt_diff;
    TH1F* tof1_hSlab_2_pmt_diff;
    TH1F* tof1_hSlab_3_pmt_diff;
    TH1F* tof1_hSlab_4_pmt_diff;
    TH1F* tof1_hSlab_5_pmt_diff;
    TH1F* tof1_hSlab_6_pmt_diff;
    TH1F* tof1_vSlab_0_pmt_diff;
    TH1F* tof1_vSlab_1_pmt_diff;
    TH1F* tof1_vSlab_2_pmt_diff;
    TH1F* tof1_vSlab_3_pmt_diff;
    TH1F* tof1_vSlab_4_pmt_diff;
    TH1F* tof1_vSlab_5_pmt_diff;
    TH1F* tof1_vSlab_6_pmt_diff;


    TH2F* tof0_hSlab_0_pmt0;
    TH2F* tof0_hSlab_1_pmt0;
    TH2F* tof0_hSlab_2_pmt0;
    TH2F* tof0_hSlab_3_pmt0;
    TH2F* tof0_hSlab_4_pmt0;
    TH2F* tof0_hSlab_5_pmt0;
    TH2F* tof0_hSlab_6_pmt0;
    TH2F* tof0_hSlab_7_pmt0;
    TH2F* tof0_hSlab_8_pmt0;
    TH2F* tof0_hSlab_9_pmt0;
    TH2F* tof0_vSlab_0_pmt0;
    TH2F* tof0_vSlab_1_pmt0;
    TH2F* tof0_vSlab_2_pmt0;
    TH2F* tof0_vSlab_3_pmt0;
    TH2F* tof0_vSlab_4_pmt0;
    TH2F* tof0_vSlab_5_pmt0;
    TH2F* tof0_vSlab_6_pmt0;
    TH2F* tof0_vSlab_7_pmt0;
    TH2F* tof0_vSlab_8_pmt0;
    TH2F* tof0_vSlab_9_pmt0;

    TH2F* tof1_hSlab_0_pmt0;
    TH2F* tof1_hSlab_1_pmt0;
    TH2F* tof1_hSlab_2_pmt0;
    TH2F* tof1_hSlab_3_pmt0;
    TH2F* tof1_hSlab_4_pmt0;
    TH2F* tof1_hSlab_5_pmt0;
    TH2F* tof1_hSlab_6_pmt0;
    TH2F* tof1_vSlab_0_pmt0;
    TH2F* tof1_vSlab_1_pmt0;
    TH2F* tof1_vSlab_2_pmt0;
    TH2F* tof1_vSlab_3_pmt0;
    TH2F* tof1_vSlab_4_pmt0;
    TH2F* tof1_vSlab_5_pmt0;
    TH2F* tof1_vSlab_6_pmt0;




    TH2F* tof0_hSlab_0_pmt1;
    TH2F* tof0_hSlab_1_pmt1;
    TH2F* tof0_hSlab_2_pmt1;
    TH2F* tof0_hSlab_3_pmt1;
    TH2F* tof0_hSlab_4_pmt1;
    TH2F* tof0_hSlab_5_pmt1;
    TH2F* tof0_hSlab_6_pmt1;
    TH2F* tof0_hSlab_7_pmt1;
    TH2F* tof0_hSlab_8_pmt1;
    TH2F* tof0_hSlab_9_pmt1;
    TH2F* tof0_vSlab_0_pmt1;
    TH2F* tof0_vSlab_1_pmt1;
    TH2F* tof0_vSlab_2_pmt1;
    TH2F* tof0_vSlab_3_pmt1;
    TH2F* tof0_vSlab_4_pmt1;
    TH2F* tof0_vSlab_5_pmt1;
    TH2F* tof0_vSlab_6_pmt1;
    TH2F* tof0_vSlab_7_pmt1;
    TH2F* tof0_vSlab_8_pmt1;
    TH2F* tof0_vSlab_9_pmt1;

    TH2F* tof1_hSlab_0_pmt1;
    TH2F* tof1_hSlab_1_pmt1;
    TH2F* tof1_hSlab_2_pmt1;
    TH2F* tof1_hSlab_3_pmt1;
    TH2F* tof1_hSlab_4_pmt1;
    TH2F* tof1_hSlab_5_pmt1;
    TH2F* tof1_hSlab_6_pmt1;
    TH2F* tof1_vSlab_0_pmt1;
    TH2F* tof1_vSlab_1_pmt1;
    TH2F* tof1_vSlab_2_pmt1;
    TH2F* tof1_vSlab_3_pmt1;
    TH2F* tof1_vSlab_4_pmt1;
    TH2F* tof1_vSlab_5_pmt1;
    TH2F* tof1_vSlab_6_pmt1;



    double tof0_hSlab_pmt0_charge, tof0_vSlab_pmt0_charge;
    double tof1_hSlab_pmt0_charge, tof1_vSlab_pmt0_charge;

    double tof0_hSlab_pmt1_charge, tof0_vSlab_pmt1_charge;
    double tof1_hSlab_pmt1_charge, tof1_vSlab_pmt1_charge;


    void setup_plots();
    void print_plots();

    void setup_slab_offset_calc();
    void calc_slab_offset(int TOF, double globalPosition_x, double globalPosition_y);
    void correct_for_TOF_offsets();
    QVector<QVector<double> >correct_slab(QVector<QVector<double> > slabData, double offset);
    double TOF0_x_offset, TOF0_y_offset;
    double TOF1_x_offset, TOF1_y_offset;

    double TOF0_x, TOF0_y; // (x, y) positions of hits
    double TOF0_hSlab_tminus, TOF0_hSlab_tplus, TOF0_vSlab_tminus, TOF0_vSlab_tplus; // PMT time at TOF0
    int TOF0_hSlab, TOF0_vSlab;
    double TOF0_hitTime; // time TOF0 was hit, for time-of-flight calculations

    double TOF1_x, TOF1_y;
    double TOF1_hSlab_tminus, TOF1_hSlab_tplus, TOF1_vSlab_tminus, TOF1_vSlab_tplus; // PMT time at TOF1
    int TOF1_hSlab, TOF1_vSlab; // slabs hit in TOF0 and TOF1
    double TOF1_hitTime;

    void reset_particle_variables();

    void reset_tof0_variables();
    void reset_tof1_variables();

    bool particle_at_TOF0();
    bool particle_at_TOF1();
    bool hit_at_TOF0, hit_at_TOF1;
    void accept_particle();
    void fill_tof0(QVector<double> hSlab_particle, QVector<double> vSlab_particle);
    void fill_tof1(QVector<double> hSlab_particle, QVector<double> vSlab_particle);
    void print_info(int total_particles, int accepted_particles);

    QVector<QVector<double> > TOF0_hSlab_0;
    QVector<QVector<double> > TOF0_hSlab_1;
    QVector<QVector<double> > TOF0_hSlab_2;
    QVector<QVector<double> > TOF0_hSlab_3;
    QVector<QVector<double> > TOF0_hSlab_4;
    QVector<QVector<double> > TOF0_hSlab_5;
    QVector<QVector<double> > TOF0_hSlab_6;
    QVector<QVector<double> > TOF0_hSlab_7;
    QVector<QVector<double> > TOF0_hSlab_8;
    QVector<QVector<double> > TOF0_hSlab_9;

    QVector<QVector<double> > TOF0_vSlab_0;
    QVector<QVector<double> > TOF0_vSlab_1;
    QVector<QVector<double> > TOF0_vSlab_2;
    QVector<QVector<double> > TOF0_vSlab_3;
    QVector<QVector<double> > TOF0_vSlab_4;
    QVector<QVector<double> > TOF0_vSlab_5;
    QVector<QVector<double> > TOF0_vSlab_6;
    QVector<QVector<double> > TOF0_vSlab_7;
    QVector<QVector<double> > TOF0_vSlab_8;
    QVector<QVector<double> > TOF0_vSlab_9;

    QVector<QVector<double> > TOF1_hSlab_0;
    QVector<QVector<double> > TOF1_hSlab_1;
    QVector<QVector<double> > TOF1_hSlab_2;
    QVector<QVector<double> > TOF1_hSlab_3;
    QVector<QVector<double> > TOF1_hSlab_4;
    QVector<QVector<double> > TOF1_hSlab_5;
    QVector<QVector<double> > TOF1_hSlab_6;

    QVector<QVector<double> > TOF1_vSlab_0;
    QVector<QVector<double> > TOF1_vSlab_1;
    QVector<QVector<double> > TOF1_vSlab_2;
    QVector<QVector<double> > TOF1_vSlab_3;
    QVector<QVector<double> > TOF1_vSlab_4;
    QVector<QVector<double> > TOF1_vSlab_5;
    QVector<QVector<double> > TOF1_vSlab_6;

    QVector<QVector<double> > all_particles;



};

#endif // ReadMAUS_H
