#include "readmaus.h"

#include "JsonCppStreamer/IRStream.hh"


ReadMAUS::ReadMAUS()
{
}

ReadMAUS::~ReadMAUS(){
}



void ReadMAUS::setup_plots(){
    tof0_hSlab_0_pmt_diff = new TH1F("tof0_hSlab_0_pmt_diff", "tof0_hSlab_0_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_1_pmt_diff = new TH1F("tof0_hSlab_1_pmt_diff", "tof0_hSlab_1_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_2_pmt_diff = new TH1F("tof0_hSlab_2_pmt_diff", "tof0_hSlab_2_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_3_pmt_diff = new TH1F("tof0_hSlab_3_pmt_diff", "tof0_hSlab_3_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_4_pmt_diff = new TH1F("tof0_hSlab_4_pmt_diff", "tof0_hSlab_4_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_5_pmt_diff = new TH1F("tof0_hSlab_5_pmt_diff", "tof0_hSlab_5_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_6_pmt_diff = new TH1F("tof0_hSlab_6_pmt_diff", "tof0_hSlab_6_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_7_pmt_diff = new TH1F("tof0_hSlab_7_pmt_diff", "tof0_hSlab_7_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_8_pmt_diff = new TH1F("tof0_hSlab_8_pmt_diff", "tof0_hSlab_8_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_hSlab_9_pmt_diff = new TH1F("tof0_hSlab_9_pmt_diff", "tof0_hSlab_9_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_0_pmt_diff = new TH1F("tof0_vSlab_0_pmt_diff", "tof0_vSlab_0_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_1_pmt_diff = new TH1F("tof0_vSlab_1_pmt_diff", "tof0_vSlab_1_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_2_pmt_diff = new TH1F("tof0_vSlab_2_pmt_diff", "tof0_vSlab_2_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_3_pmt_diff = new TH1F("tof0_vSlab_3_pmt_diff", "tof0_vSlab_3_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_4_pmt_diff = new TH1F("tof0_vSlab_4_pmt_diff", "tof0_vSlab_4_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_5_pmt_diff = new TH1F("tof0_vSlab_5_pmt_diff", "tof0_vSlab_5_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_6_pmt_diff = new TH1F("tof0_vSlab_6_pmt_diff", "tof0_vSlab_6_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_7_pmt_diff = new TH1F("tof0_vSlab_7_pmt_diff", "tof0_vSlab_7_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_8_pmt_diff = new TH1F("tof0_vSlab_8_pmt_diff", "tof0_vSlab_8_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof0_vSlab_9_pmt_diff = new TH1F("tof0_vSlab_9_pmt_diff", "tof0_vSlab_9_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);

    tof1_hSlab_0_pmt_diff = new TH1F("tof1_hSlab_0_pmt_diff", "tof1_hSlab_0_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_hSlab_1_pmt_diff = new TH1F("tof1_hSlab_1_pmt_diff", "tof1_hSlab_1_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_hSlab_2_pmt_diff = new TH1F("tof1_hSlab_2_pmt_diff", "tof1_hSlab_2_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_hSlab_3_pmt_diff = new TH1F("tof1_hSlab_3_pmt_diff", "tof1_hSlab_3_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_hSlab_4_pmt_diff = new TH1F("tof1_hSlab_4_pmt_diff", "tof1_hSlab_4_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_hSlab_5_pmt_diff = new TH1F("tof1_hSlab_5_pmt_diff", "tof1_hSlab_5_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_hSlab_6_pmt_diff = new TH1F("tof1_hSlab_6_pmt_diff", "tof1_hSlab_6_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_0_pmt_diff = new TH1F("tof1_vSlab_0_pmt_diff", "tof1_vSlab_0_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_1_pmt_diff = new TH1F("tof1_vSlab_1_pmt_diff", "tof1_vSlab_1_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_2_pmt_diff = new TH1F("tof1_vSlab_2_pmt_diff", "tof1_vSlab_2_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_3_pmt_diff = new TH1F("tof1_vSlab_3_pmt_diff", "tof1_vSlab_3_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_4_pmt_diff = new TH1F("tof1_vSlab_4_pmt_diff", "tof1_vSlab_4_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_5_pmt_diff = new TH1F("tof1_vSlab_5_pmt_diff", "tof1_vSlab_5_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);
    tof1_vSlab_6_pmt_diff = new TH1F("tof1_vSlab_6_pmt_diff", "tof1_vSlab_6_pmt_diff;PMT0 - PMT1 (ns)", 100, -2.0, 2.0);

    tof0_hSlab_0_pmt0 = new TH2F("tof0_hSlab_0_pmt0", "tof0_hSlab_0_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_1_pmt0 = new TH2F("tof0_hSlab_1_pmt0", "tof0_hSlab_1_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_2_pmt0 = new TH2F("tof0_hSlab_2_pmt0", "tof0_hSlab_2_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_3_pmt0 = new TH2F("tof0_hSlab_3_pmt0", "tof0_hSlab_3_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_4_pmt0 = new TH2F("tof0_hSlab_4_pmt0", "tof0_hSlab_4_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_5_pmt0 = new TH2F("tof0_hSlab_5_pmt0", "tof0_hSlab_5_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_6_pmt0 = new TH2F("tof0_hSlab_6_pmt0", "tof0_hSlab_6_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_7_pmt0 = new TH2F("tof0_hSlab_7_pmt0", "tof0_hSlab_7_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_8_pmt0 = new TH2F("tof0_hSlab_8_pmt0", "tof0_hSlab_8_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_9_pmt0 = new TH2F("tof0_hSlab_9_pmt0", "tof0_hSlab_9_pmt0;PMT0 charge ;x (mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_0_pmt0 = new TH2F("tof0_vSlab_0_pmt0", "tof0_vSlab_0_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_1_pmt0 = new TH2F("tof0_vSlab_1_pmt0", "tof0_vSlab_1_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_2_pmt0 = new TH2F("tof0_vSlab_2_pmt0", "tof0_vSlab_2_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_3_pmt0 = new TH2F("tof0_vSlab_3_pmt0", "tof0_vSlab_3_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_4_pmt0 = new TH2F("tof0_vSlab_4_pmt0", "tof0_vSlab_4_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_5_pmt0 = new TH2F("tof0_vSlab_5_pmt0", "tof0_vSlab_5_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_6_pmt0 = new TH2F("tof0_vSlab_6_pmt0", "tof0_vSlab_6_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_7_pmt0 = new TH2F("tof0_vSlab_7_pmt0", "tof0_vSlab_7_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_8_pmt0 = new TH2F("tof0_vSlab_8_pmt0", "tof0_vSlab_8_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_9_pmt0 = new TH2F("tof0_vSlab_9_pmt0", "tof0_vSlab_9_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);

    tof1_hSlab_0_pmt0 = new TH2F("tof1_hSlab_0_pmt0", "tof1_hSlab_0_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_1_pmt0 = new TH2F("tof1_hSlab_1_pmt0", "tof1_hSlab_1_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_2_pmt0 = new TH2F("tof1_hSlab_2_pmt0", "tof1_hSlab_2_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_3_pmt0 = new TH2F("tof1_hSlab_3_pmt0", "tof1_hSlab_3_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_4_pmt0 = new TH2F("tof1_hSlab_4_pmt0", "tof1_hSlab_4_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_5_pmt0 = new TH2F("tof1_hSlab_5_pmt0", "tof1_hSlab_5_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_6_pmt0 = new TH2F("tof1_hSlab_6_pmt0", "tof1_hSlab_6_pmt0;PMT0 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_0_pmt0 = new TH2F("tof1_vSlab_0_pmt0", "tof1_vSlab_0_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_1_pmt0 = new TH2F("tof1_vSlab_1_pmt0", "tof1_vSlab_1_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_2_pmt0 = new TH2F("tof1_vSlab_2_pmt0", "tof1_vSlab_2_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_3_pmt0 = new TH2F("tof1_vSlab_3_pmt0", "tof1_vSlab_3_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_4_pmt0 = new TH2F("tof1_vSlab_4_pmt0", "tof1_vSlab_4_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_5_pmt0 = new TH2F("tof1_vSlab_5_pmt0", "tof1_vSlab_5_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_6_pmt0 = new TH2F("tof1_vSlab_6_pmt0", "tof1_vSlab_6_pmt0;PMT0 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);

    tof0_hSlab_0_pmt1 = new TH2F("tof0_hSlab_0_pmt1", "tof0_hSlab_0_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_1_pmt1 = new TH2F("tof0_hSlab_1_pmt1", "tof0_hSlab_1_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_2_pmt1 = new TH2F("tof0_hSlab_2_pmt1", "tof0_hSlab_2_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_3_pmt1 = new TH2F("tof0_hSlab_3_pmt1", "tof0_hSlab_3_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_4_pmt1 = new TH2F("tof0_hSlab_4_pmt1", "tof0_hSlab_4_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_5_pmt1 = new TH2F("tof0_hSlab_5_pmt1", "tof0_hSlab_5_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_6_pmt1 = new TH2F("tof0_hSlab_6_pmt1", "tof0_hSlab_6_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_7_pmt1 = new TH2F("tof0_hSlab_7_pmt1", "tof0_hSlab_7_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_8_pmt1 = new TH2F("tof0_hSlab_8_pmt1", "tof0_hSlab_8_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_hSlab_9_pmt1 = new TH2F("tof0_hSlab_9_pmt1", "tof0_hSlab_9_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_0_pmt1 = new TH2F("tof0_vSlab_0_pmt1", "tof0_vSlab_0_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_1_pmt1 = new TH2F("tof0_vSlab_1_pmt1", "tof0_vSlab_1_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_2_pmt1 = new TH2F("tof0_vSlab_2_pmt1", "tof0_vSlab_2_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_3_pmt1 = new TH2F("tof0_vSlab_3_pmt1", "tof0_vSlab_3_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_4_pmt1 = new TH2F("tof0_vSlab_4_pmt1", "tof0_vSlab_4_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_5_pmt1 = new TH2F("tof0_vSlab_5_pmt1", "tof0_vSlab_5_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_6_pmt1 = new TH2F("tof0_vSlab_6_pmt1", "tof0_vSlab_6_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_7_pmt1 = new TH2F("tof0_vSlab_7_pmt1", "tof0_vSlab_7_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_8_pmt1 = new TH2F("tof0_vSlab_8_pmt1", "tof0_vSlab_8_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);
    tof0_vSlab_9_pmt1 = new TH2F("tof0_vSlab_9_pmt1", "tof0_vSlab_9_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 10, -200.0, 200.0);

    tof1_hSlab_0_pmt1 = new TH2F("tof1_hSlab_0_pmt1", "tof1_hSlab_0_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_1_pmt1 = new TH2F("tof1_hSlab_1_pmt1", "tof1_hSlab_1_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_2_pmt1 = new TH2F("tof1_hSlab_2_pmt1", "tof1_hSlab_2_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_3_pmt1 = new TH2F("tof1_hSlab_3_pmt1", "tof1_hSlab_3_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_4_pmt1 = new TH2F("tof1_hSlab_4_pmt1", "tof1_hSlab_4_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_5_pmt1 = new TH2F("tof1_hSlab_5_pmt1", "tof1_hSlab_5_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_hSlab_6_pmt1 = new TH2F("tof1_hSlab_6_pmt1", "tof1_hSlab_6_pmt1;PMT1 charge ;x(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_0_pmt1 = new TH2F("tof1_vSlab_0_pmt1", "tof1_vSlab_0_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_1_pmt1 = new TH2F("tof1_vSlab_1_pmt1", "tof1_vSlab_1_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_2_pmt1 = new TH2F("tof1_vSlab_2_pmt1", "tof1_vSlab_2_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_3_pmt1 = new TH2F("tof1_vSlab_3_pmt1", "tof1_vSlab_3_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_4_pmt1 = new TH2F("tof1_vSlab_4_pmt1", "tof1_vSlab_4_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_5_pmt1 = new TH2F("tof1_vSlab_5_pmt1", "tof1_vSlab_5_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
    tof1_vSlab_6_pmt1 = new TH2F("tof1_vSlab_6_pmt1", "tof1_vSlab_6_pmt1;PMT1 charge ;y(mm)", 250, 0.0, 5000.0, 7, -200.0, 200.0);
   }

void ReadMAUS::print_plots(){
    TCanvas c("canvas", "canvas", 900, 250);
    tof0_hSlab_0_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_1_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_2_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_3_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_4_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_5_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_6_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_7_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_8_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_hSlab_9_pmt_diff->Draw("hist");
    c.Print("test.pdf(");

    tof0_vSlab_0_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_1_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_2_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_3_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_4_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_5_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_6_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_7_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_8_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof0_vSlab_9_pmt_diff->Draw("hist");
    c.Print("test.pdf(");

    tof1_hSlab_0_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_hSlab_1_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_hSlab_2_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_hSlab_3_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_hSlab_4_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_hSlab_5_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_hSlab_6_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_0_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_1_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_2_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_3_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_4_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_5_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    tof1_vSlab_6_pmt_diff->Draw("hist");
    c.Print("test.pdf(");
    c.Clear();

    c.Divide(2, 1);
    c.cd(1);
    tof0_hSlab_0_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_0_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_1_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_1_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_2_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_2_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_3_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_3_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_4_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_4_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_5_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_5_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_6_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_6_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_7_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_7_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_8_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_8_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_hSlab_9_pmt0->Draw("colz");
    c.cd(2);
    tof0_hSlab_9_pmt1->Draw("colz");
    c.Print("test.pdf(");

    c.cd(1);
    tof0_vSlab_0_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_0_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_1_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_1_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_2_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_2_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_3_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_3_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_4_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_4_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_5_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_5_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_6_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_6_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_7_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_7_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_8_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_8_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof0_vSlab_9_pmt0->Draw("colz");
    c.cd(2);
    tof0_vSlab_9_pmt1->Draw("colz");
    c.Print("test.pdf(");


    c.cd(1);
    tof1_hSlab_0_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_0_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_hSlab_1_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_1_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_hSlab_2_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_2_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_hSlab_3_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_3_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_hSlab_4_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_4_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_hSlab_5_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_5_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_hSlab_6_pmt0->Draw("colz");
    c.cd(2);
    tof1_hSlab_6_pmt1->Draw("colz");
    c.Print("test.pdf(");

    c.cd(1);
    tof1_vSlab_0_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_0_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_vSlab_1_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_1_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_vSlab_2_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_2_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_vSlab_3_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_3_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_vSlab_4_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_4_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_vSlab_5_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_5_pmt1->Draw("colz");
    c.Print("test.pdf(");
    c.cd(1);
    tof1_vSlab_6_pmt0->Draw("colz");
    c.cd(2);
    tof1_vSlab_6_pmt1->Draw("colz");

    c.Print("test.pdf)");
}



void ReadMAUS::Read(QString fileToOpen, double min_tof, double max_tof){
    // start reading data:

    setup_slab_offset_calc();

    setup_plots();

    std::cerr << "Entered ReadMAUS::Read()\n";
    MAUS::Data data;
    irstream infile(fileToOpen.toStdString().c_str(), "Spill");
    std::cerr << "About to iterate over events\n";

    double time_of_flight;
    int all_particle_count = 0;
    int accepted_particle_count = 0;

    // iterate over events:
    while(infile >> readEvent != NULL){
        infile >> branchName("data") >> data;
        spill = data.GetSpill();

        if(spill != NULL && spill->GetDaqEventType() == "physics_event"){
            /*
             * We've found a spill that contains some data. Next we iterate over
             * all of the different event types and put the interesting information
             * into our ROOT file
             */

            for(size_t i = 0; i < spill->GetReconEvents()->size(); ++i){
                reset_particle_variables();
                all_particle_count++;

                tof_event = (*spill->GetReconEvents())[i]->GetTOFEvent();

                if(tof_event != NULL){
                    hit_at_TOF0 = particle_at_TOF0();
                    hit_at_TOF1 = particle_at_TOF1();
                    //std::cerr << "hit_at_TOF0 = " << hit_at_TOF0 << " and hit_at_TOF1 = " << hit_at_TOF1 << "\n";
                } // finished iterating over TOF events

                // check if this event is from an electron, muon or pion according
                // to its time of flight

                if(hit_at_TOF0 == true && hit_at_TOF1 == true){
                    time_of_flight = TOF1_hitTime - TOF0_hitTime;
                    //std::cerr << "   --> tof = " << time_of_flight << "\n";
                    if(time_of_flight >= min_tof && time_of_flight <= max_tof){
                        // accept this particle
                        accept_particle();
                        accepted_particle_count++;
                    }
                }

            } // done iterating over the event
        }// done iterating over the spill
    } // done iterating over data

    print_info(all_particle_count, accepted_particle_count);
    correct_for_TOF_offsets();
    //print_plots();
}

void ReadMAUS::reset_particle_variables(){
    /*
     * We want to avoid 'double counting' a particle if, for example, we have a new
     * x (mm) hit but have old information about a y (mm) hit when keeping only
     * slab hit data
     *
     * By setting double variables to TMath::Infinity(), we have an easy way of identifying them later
     * in further analysis code.  Ints get set to -1.
     */
    reset_tof0_variables();
    reset_tof1_variables();
}


void ReadMAUS::reset_tof0_variables(){
    hit_at_TOF0 = false;
    TOF0_x = TMath::Infinity();
    TOF0_y = TMath::Infinity();
    TOF0_hSlab_tminus = TMath::Infinity();
    TOF0_hSlab_tplus = TMath::Infinity();
    TOF0_hSlab = -1;
    TOF0_vSlab = -1;
}

void ReadMAUS::reset_tof1_variables(){
    hit_at_TOF1 = false;
    TOF1_x = TMath::Infinity();
    TOF1_y = TMath::Infinity();
    TOF1_hSlab_tminus = TMath::Infinity();
    TOF1_hSlab_tplus = TMath::Infinity();
    TOF1_hSlab = -1;
    TOF1_vSlab = -1;
}

bool ReadMAUS::particle_at_TOF0(){
    /*
     * 1. Loop over TOF space points
     *    a. Get horizontal and x (mm) numbers
     *
     * 2. Loop over TOF slab hits
     *    a. If horizontal and x (mm)s == slabs from space points, get PMT times
     */

    MAUS::TOFEventSlabHit slab_hits = tof_event->GetTOFEventSlabHit();
    MAUS::TOFEventSpacePoint space_points = tof_event->GetTOFEventSpacePoint();

    MAUS::TOFSlabHit tof0_slab_hits;
    MAUS::TOFSpacePoint tof0_space_points;


    int horizontalHit, verticalHit;
    bool good_particle;


    // 1. Loop over TOF0 space points:
    for(size_t i = 0; i < space_points.GetTOF0SpacePointArray().size(); ++i){
        reset_tof0_variables();  // each new space point should be a new set of slab hits
        good_particle = false;
        horizontalHit = -1;
        verticalHit = -1;

        tof0_space_points = space_points.GetTOF0SpacePointArray()[i];

        TOF0_hSlab = tof0_space_points.GetHorizSlab(); // returns slabs oriented horizontally
        TOF0_vSlab = tof0_space_points.GetVertSlab();   // returns slabs oriented vertically

        TOF0_x = tof0_space_points.GetGlobalPosX();
        TOF0_y = tof0_space_points.GetGlobalPosY();
        calc_slab_offset(0, TOF0_x, TOF0_y);

        TOF0_hitTime = tof0_space_points.GetTime();

        //std::cout << "At TOF0, spacepoint with horizontal slab " << TOF0_hSlab << " and vertical slab " << TOF0_vSlab << "\n";

        // 2. Loop over slab hits and look for matches:
        for(size_t j = 0; j < slab_hits.GetTOF0SlabHitArray().size(); ++j){
            tof0_slab_hits = slab_hits.GetTOF0SlabHitArray()[j];

            if(tof0_slab_hits.IsHorizontal()){
                // y (mm) hit
                horizontalHit = tof0_slab_hits.GetSlab();
                //TOF0_hSlab_tminus = tof0_slab_hits.GetPmt0().GetTime();
                //TOF0_hSlab_tplus = tof0_slab_hits.GetPmt1().GetTime();

                TOF0_hSlab_tplus = tof0_slab_hits.GetPmt0().GetTime();
                TOF0_hSlab_tminus = tof0_slab_hits.GetPmt1().GetTime();

                tof0_hSlab_pmt0_charge = tof0_slab_hits.GetPmt0().GetCharge();
                tof0_hSlab_pmt1_charge = tof0_slab_hits.GetPmt1().GetCharge();

                //std::cout << "   --> potential horizontal slab hit: " << horizontalHit << "\n";

            }
            else if(tof0_slab_hits.IsVertical()){
                verticalHit = tof0_slab_hits.GetSlab();
                //TOF0_vSlab_tminus = tof0_slab_hits.GetPmt1().GetTime();
                //TOF0_vSlab_tplus = tof0_slab_hits.GetPmt0().GetTime();

                TOF0_vSlab_tplus = tof0_slab_hits.GetPmt1().GetTime();
                TOF0_vSlab_tminus = tof0_slab_hits.GetPmt0().GetTime();

                tof0_vSlab_pmt0_charge = tof0_slab_hits.GetPmt0().GetCharge();
                tof0_vSlab_pmt1_charge = tof0_slab_hits.GetPmt1().GetCharge();

                //std::cout << "   --> potential vertical slab hit: " << verticalHit << "\n";
            }
            else{
                std::cerr << "Warning: Unusual plane hits at TOF0. Proceed with caution.\n";
            }

            if((TOF0_hSlab == horizontalHit) && (TOF0_vSlab == verticalHit) && (TOF0_hSlab != -1) && (TOF0_vSlab != -1)){
                // we have a pixel that agrees between space points and slab hits
                good_particle = true;
                return good_particle;
            }
        }
    }
//    }
    return false;
}





bool ReadMAUS::particle_at_TOF1(){
    /*
     * 1. Loop over TOF space points
     *    a. Get horizontal and x (mm) numbers
     *
     * 2. Loop over TOF slab hits
     *    a. If horizontal and x (mm)s == slabs from space points, get PMT times
     */

    MAUS::TOFEventSlabHit slab_hits = tof_event->GetTOFEventSlabHit();
    MAUS::TOFEventSpacePoint space_points = tof_event->GetTOFEventSpacePoint();

    MAUS::TOFSlabHit tof1_slab_hits;
    MAUS::TOFSpacePoint tof1_space_points;


    int horizontalHit, verticalHit;
    bool good_particle;

    // 1. Loop over TOF1 space points:
    for(size_t i = 0; i < space_points.GetTOF1SpacePointArray().size(); ++i){
        reset_tof1_variables();  // each new space point should be a new set of slab hits
        good_particle = false;
        horizontalHit = -1;
        verticalHit = -1;

        tof1_space_points = space_points.GetTOF1SpacePointArray()[i];

        TOF1_hSlab = tof1_space_points.GetHorizSlab(); // returns slabs oriented horizontally
        TOF1_vSlab = tof1_space_points.GetVertSlab();   // returns slabs oriented vertically

        TOF1_x = tof1_space_points.GetGlobalPosX();
        TOF1_y = tof1_space_points.GetGlobalPosY();
        calc_slab_offset(1, TOF1_x, TOF1_y);

        TOF1_hitTime = tof1_space_points.GetTime();

        // 2. Loop over slab hits and look for matches:
        for(size_t j = 0; j < slab_hits.GetTOF1SlabHitArray().size(); ++j){
            tof1_slab_hits = slab_hits.GetTOF1SlabHitArray()[j];

            if(tof1_slab_hits.IsHorizontal()){
                // y (mm) hit
                horizontalHit = tof1_slab_hits.GetSlab();
                TOF1_hSlab_tminus = tof1_slab_hits.GetPmt1().GetTime();
                TOF1_hSlab_tplus = tof1_slab_hits.GetPmt0().GetTime();

                tof1_hSlab_pmt0_charge = tof1_slab_hits.GetPmt0().GetCharge();
                tof1_hSlab_pmt1_charge = tof1_slab_hits.GetPmt1().GetCharge();
            }
            else if(tof1_slab_hits.IsVertical()){
                verticalHit = tof1_slab_hits.GetSlab();
                TOF1_vSlab_tminus = tof1_slab_hits.GetPmt0().GetTime();
                TOF1_vSlab_tplus = tof1_slab_hits.GetPmt1().GetTime();

                tof1_vSlab_pmt0_charge = tof1_slab_hits.GetPmt0().GetCharge();
                tof1_vSlab_pmt1_charge = tof1_slab_hits.GetPmt1().GetCharge();
            }
            else{
                std::cerr << "Warning: Unusual plane hits at TOF1. Proceed with caution.\n";
            }

            if((TOF1_hSlab == horizontalHit) && (TOF1_vSlab == verticalHit) && (TOF1_hSlab != -1) && (TOF1_vSlab != -1)){
                // we have a pixel that agrees between space points and slab hits
                good_particle = true;
                return good_particle;
            }
        }
    }
    return false;
}


void ReadMAUS::accept_particle(){
    // the currently defined particle has hit both TOF0 and TOF1 and passed
    // the time of flight cuts.  We want to store this particle info so that
    // we can use it for calibrations

    QVector<double> tof0_hSlab_particle, tof0_vSlab_particle;
    QVector<double> tof1_hSlab_particle, tof1_vSlab_particle;

    // When we try to calibrate, we take a horizontal (vertical) slab and use
    // the PMT times to calculate an x (y) position.  We then compare this value
    // to the pixel x (y) coordinate.
    //
    // Therefore, y (mm) calibrations require an x-pixel coordinate and
    // x (mm) calibrations require a y-pixel coordinate
    //
    // Store data for calibration as (Pixel coordinate, PMT0 time, PMT1 time, slab width)

    double tof0_slab_width = 40.0; // mm
    double tof1_slab_width = 60.0; // mm

    tof0_hSlab_particle << TOF0_x << TOF0_hSlab_tminus << TOF0_hSlab_tplus << tof0_slab_width;
    tof0_vSlab_particle << TOF0_y << TOF0_vSlab_tminus << TOF0_vSlab_tplus << tof0_slab_width;

    tof1_hSlab_particle << TOF1_x << TOF1_hSlab_tminus << TOF1_hSlab_tplus << tof1_slab_width;
    tof1_vSlab_particle << TOF1_y << TOF1_vSlab_tminus << TOF1_vSlab_tplus << tof1_slab_width;

    // now fill in appropriate QVectors
    fill_tof0(tof0_hSlab_particle, tof0_vSlab_particle);
    fill_tof1(tof1_hSlab_particle, tof1_vSlab_particle);

    all_particles << tof0_hSlab_particle << tof0_vSlab_particle << tof1_hSlab_particle << tof1_vSlab_particle;
}

QVector<QVector<double> > ReadMAUS::getAllParticles(){
    return all_particles;
}

void ReadMAUS::fill_tof0(QVector<double> hSlab_particle, QVector<double> vSlab_particle){




    // fill y (mm)s first:
    if(TOF0_hSlab == 0){
        TOF0_hSlab_0 << hSlab_particle;

        tof0_hSlab_0_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_0_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_0_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 1){
        TOF0_hSlab_1 << hSlab_particle;

        tof0_hSlab_1_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_1_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_1_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 2){
        TOF0_hSlab_2 << hSlab_particle;

        tof0_hSlab_2_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_2_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_2_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 3){
        TOF0_hSlab_3 << hSlab_particle;

        tof0_hSlab_3_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_3_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_3_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 4){
        TOF0_hSlab_4 << hSlab_particle;

        tof0_hSlab_4_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_4_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_4_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 5){
        TOF0_hSlab_5 << hSlab_particle;

        tof0_hSlab_5_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_5_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_5_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 6){
        TOF0_hSlab_6 << hSlab_particle;

        tof0_hSlab_6_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_6_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_6_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 7){
        TOF0_hSlab_7 << hSlab_particle;

        tof0_hSlab_7_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_7_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_7_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 8){
        TOF0_hSlab_8 << hSlab_particle;

        tof0_hSlab_8_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_8_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_8_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }
    else if(TOF0_hSlab == 9){
        TOF0_hSlab_9 << hSlab_particle;

        tof0_hSlab_9_pmt_diff->Fill(TOF0_hSlab_tminus - TOF0_hSlab_tplus);
        tof0_hSlab_9_pmt0->Fill(tof0_hSlab_pmt0_charge, TOF0_x);
        tof0_hSlab_9_pmt1->Fill(tof0_hSlab_pmt1_charge, TOF0_x);
    }


    // next, x (mm)s:
    if(TOF0_vSlab == 0){
        TOF0_vSlab_0 << vSlab_particle;

        tof0_vSlab_0_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_0_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_0_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 1){
        TOF0_vSlab_1 << vSlab_particle;

        tof0_vSlab_1_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_1_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_1_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 2){
        TOF0_vSlab_2 << vSlab_particle;

        tof0_vSlab_2_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_2_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_2_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 3){
        TOF0_vSlab_3 << vSlab_particle;

        tof0_vSlab_3_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_3_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_3_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 4){
        TOF0_vSlab_4 << vSlab_particle;

        tof0_vSlab_4_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_4_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_4_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 5){
        TOF0_vSlab_5 << vSlab_particle;

        tof0_vSlab_5_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_5_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_5_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 6){
        TOF0_vSlab_6 << vSlab_particle;

        tof0_vSlab_6_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_6_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_6_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 7){
        TOF0_vSlab_7 << vSlab_particle;

        tof0_vSlab_7_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_7_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_7_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 8){
        TOF0_vSlab_8 << vSlab_particle;

        tof0_vSlab_8_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_8_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_8_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
    else if(TOF0_vSlab == 9){
        TOF0_vSlab_9 << vSlab_particle;

        tof0_vSlab_9_pmt_diff->Fill(TOF0_vSlab_tminus - TOF0_vSlab_tplus);
        tof0_vSlab_9_pmt0->Fill(tof0_vSlab_pmt0_charge, TOF0_y);
        tof0_vSlab_9_pmt1->Fill(tof0_vSlab_pmt1_charge, TOF0_y);
    }
}


void ReadMAUS::fill_tof1(QVector<double> hSlab_particle, QVector<double> vSlab_particle){
    // fill y (mm)s first:
    if(TOF1_hSlab == 0){
        TOF1_hSlab_0 << hSlab_particle;

        tof1_hSlab_0_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_0_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_0_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }
    else if(TOF1_hSlab == 1){
        TOF1_hSlab_1 << hSlab_particle;

        tof1_hSlab_1_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_1_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_1_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }
    else if(TOF1_hSlab == 2){
        TOF1_hSlab_2 << hSlab_particle;

        tof1_hSlab_2_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_2_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_2_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }
    else if(TOF1_hSlab == 3){
        TOF1_hSlab_3 << hSlab_particle;

        tof1_hSlab_3_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_3_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_3_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }
    else if(TOF1_hSlab == 4){
        TOF1_hSlab_4 << hSlab_particle;

        tof1_hSlab_4_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_4_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_4_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }
    else if(TOF1_hSlab == 5){
        TOF1_hSlab_5 << hSlab_particle;

        tof1_hSlab_5_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_5_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_5_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }
    else if(TOF1_hSlab == 6){
        TOF1_hSlab_6 << hSlab_particle;

        tof1_hSlab_6_pmt_diff->Fill(TOF1_hSlab_tminus - TOF1_hSlab_tplus);
        tof1_hSlab_6_pmt0->Fill(tof1_hSlab_pmt0_charge, TOF1_x);
        tof1_hSlab_6_pmt1->Fill(tof1_hSlab_pmt1_charge, TOF1_x);
    }


    // next, x (mm)s:
    if(TOF1_vSlab == 0){
        TOF1_vSlab_0 << vSlab_particle;

        tof1_vSlab_0_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_0_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_0_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
    else if(TOF1_vSlab == 1){
        TOF1_vSlab_1 << vSlab_particle;

        tof1_vSlab_1_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_1_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_1_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
    else if(TOF1_vSlab == 2){
        TOF1_vSlab_2 << vSlab_particle;

        tof1_vSlab_2_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_2_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_2_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
    else if(TOF1_vSlab == 3){
        TOF1_vSlab_3 << vSlab_particle;

        tof1_vSlab_3_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_3_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_3_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
    else if(TOF1_vSlab == 4){
        TOF1_vSlab_4 << vSlab_particle;

        tof1_vSlab_4_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_4_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_4_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
    else if(TOF1_vSlab == 5){
        TOF1_vSlab_5 << vSlab_particle;

        tof1_vSlab_5_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_5_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_5_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
    else if(TOF1_vSlab == 6){
        TOF1_vSlab_6 << vSlab_particle;

        tof1_vSlab_6_pmt_diff->Fill(TOF1_vSlab_tminus - TOF1_vSlab_tplus);
        tof1_vSlab_6_pmt0->Fill(tof1_vSlab_pmt0_charge, TOF1_y);
        tof1_vSlab_6_pmt1->Fill(tof1_vSlab_pmt1_charge, TOF1_y);
    }
}


void ReadMAUS::print_info(int total_particles, int accepted_particles){

    std::cerr << "Finished reading ROOT file.  \n"
              << "   Total number of events: " << total_particles << "\n"
              << "   Events within accepted time-of-flight: " << accepted_particles << "\n\n"
              << "TOF0 horizontal hits: \n";
    std::cerr << "   0, " << TOF0_hSlab_0.size() << " hits\n"
              << "   1, " << TOF0_hSlab_1.size() << " hits\n"
              << "   2, " << TOF0_hSlab_2.size() << " hits\n"
              << "   3, " << TOF0_hSlab_3.size() << " hits\n"
              << "   4, " << TOF0_hSlab_4.size() << " hits\n"
              << "   5, " << TOF0_hSlab_5.size() << " hits\n"
              << "   6, " << TOF0_hSlab_6.size() << " hits\n"
              << "   7, " << TOF0_hSlab_7.size() << " hits\n"
              << "   8, " << TOF0_hSlab_8.size() << " hits\n"
              << "   9, " << TOF0_hSlab_9.size() << " hits\n";
    std::cerr << "TOF0 vertical hits: \n"
              << "   0, " << TOF0_vSlab_0.size() << " hits\n"
              << "   1, " << TOF0_vSlab_1.size() << " hits\n"
              << "   2, " << TOF0_vSlab_2.size() << " hits\n"
              << "   3, " << TOF0_vSlab_3.size() << " hits\n"
              << "   4, " << TOF0_vSlab_4.size() << " hits\n"
              << "   5, " << TOF0_vSlab_5.size() << " hits\n"
              << "   6, " << TOF0_vSlab_6.size() << " hits\n"
              << "   7, " << TOF0_vSlab_7.size() << " hits\n"
              << "   8, " << TOF0_vSlab_8.size() << " hits\n"
              << "   9, " << TOF0_vSlab_9.size() << " hits\n\n";
    std::cerr << "TOF1 horizontal hits: \n"
              << "   0, " << TOF1_hSlab_0.size() << " hits\n"
              << "   1, " << TOF1_hSlab_1.size() << " hits\n"
              << "   2, " << TOF1_hSlab_2.size() << " hits\n"
              << "   3, " << TOF1_hSlab_3.size() << " hits\n"
              << "   4, " << TOF1_hSlab_4.size() << " hits\n"
              << "   5, " << TOF1_hSlab_5.size() << " hits\n"
              << "   6, " << TOF1_hSlab_6.size() << " hits\n";
    std::cerr << "TOF1 vertical hits: \n"
              << "   0, " << TOF1_vSlab_0.size() << " hits\n"
              << "   1, " << TOF1_vSlab_1.size() << " hits\n"
              << "   2, " << TOF1_vSlab_2.size() << " hits\n"
              << "   3, " << TOF1_vSlab_3.size() << " hits\n"
              << "   4, " << TOF1_vSlab_4.size() << " hits\n"
              << "   5, " << TOF1_vSlab_5.size() << " hits\n"
              << "   6, " << TOF1_vSlab_6.size() << " hits\n";
}

QVector<QVector<double> > ReadMAUS::getTOF0HorizontalSlab(int slabNumber){
    if(slabNumber == 0){
        return TOF0_hSlab_0;
    }
    else if(slabNumber == 1){
        return TOF0_hSlab_1;
    }
    else if(slabNumber == 2){
        return TOF0_hSlab_2;
    }
    else if(slabNumber == 3){
        return TOF0_hSlab_3;
    }
    else if(slabNumber == 4){
        return TOF0_hSlab_4;
    }
    else if(slabNumber == 5){
        return TOF0_hSlab_5;
    }
    else if(slabNumber == 6){
        return TOF0_hSlab_6;
    }
    else if(slabNumber == 7){
        return TOF0_hSlab_7;
    }
    else if(slabNumber == 8){
        return TOF0_hSlab_8;
    }
    else if(slabNumber == 9){
        return TOF0_hSlab_9;
    }
    else{
        std::cerr << "Requested y (mm) number, " << slabNumber << ", does not exist at TOF0.\n";
    }
}

QVector<QVector<double> > ReadMAUS::getTOF0VerticalSlab(int slabNumber){
    if(slabNumber == 0){
        return TOF0_vSlab_0;
    }
    else if(slabNumber == 1){
        return TOF0_vSlab_1;
    }
    else if(slabNumber == 2){
        return TOF0_vSlab_2;
    }
    else if(slabNumber == 3){
        return TOF0_vSlab_3;
    }
    else if(slabNumber == 4){
        return TOF0_vSlab_4;
    }
    else if(slabNumber == 5){
        return TOF0_vSlab_5;
    }
    else if(slabNumber == 6){
        return TOF0_vSlab_6;
    }
    else if(slabNumber == 7){
        return TOF0_vSlab_7;
    }
    else if(slabNumber == 8){
        return TOF0_vSlab_8;
    }
    else if(slabNumber == 9){
        return TOF0_vSlab_9;
    }
    else{
        std::cerr << "Requested x (mm) number, " << slabNumber << ", does not exist at TOF0.\n";
    }
}

QVector<QVector<double> > ReadMAUS::getTOF1HorizontalSlab(int slabNumber){
    if(slabNumber == 0){
        return TOF1_hSlab_0;
    }
    else if(slabNumber == 1){
        return TOF1_hSlab_1;
    }
    else if(slabNumber == 2){
        return TOF1_hSlab_2;
    }
    else if(slabNumber == 3){
        return TOF1_hSlab_3;
    }
    else if(slabNumber == 4){
        return TOF1_hSlab_4;
    }
    else if(slabNumber == 5){
        return TOF1_hSlab_5;
    }
    else if(slabNumber == 6){
        return TOF1_hSlab_6;
    }
    else{
        std::cerr << "Requested y (mm) number, " << slabNumber << ", does not exist at TOF0.\n";
    }
}

QVector<QVector<double> > ReadMAUS::getTOF1VerticalSlab(int slabNumber){
    if(slabNumber == 0){
        return TOF1_vSlab_0;
    }
    else if(slabNumber == 1){
        return TOF1_vSlab_1;
    }
    else if(slabNumber == 2){
        return TOF1_vSlab_2;
    }
    else if(slabNumber == 3){
        return TOF1_vSlab_3;
    }
    else if(slabNumber == 4){
        return TOF1_vSlab_4;
    }
    else if(slabNumber == 5){
        return TOF1_vSlab_5;
    }
    else if(slabNumber == 6){
        return TOF1_vSlab_6;
    }
    else{
        std::cerr << "Requested x (mm) number, " << slabNumber << ", does not exist at TOF0.\n";
    }
}



void ReadMAUS::setup_slab_offset_calc(){
    TOF0_x_offset = TMath::Infinity();
    TOF0_y_offset = TMath::Infinity();

    TOF1_x_offset = TMath::Infinity();
    TOF1_y_offset = TMath::Infinity();
}


void ReadMAUS::calc_slab_offset(int TOF, double globalPosition_x, double globalPosition_y){

    // want to find the offset that's closest to zero
    //
    // for TOF0, the central slabs (in a TOF-centric coordinate system) are at +/- 20mm
    // for TOF1, the center slab is at 0mm

    double x_val, y_val;

    if(TOF == 1){
        // TOF1 is the easier comparison, we just look for the smallest absolute value
        x_val = TMath::Abs(globalPosition_x);
        y_val = TMath::Abs(globalPosition_y);

        if(x_val < TMath::Abs(TOF1_x_offset)){
            TOF1_x_offset = globalPosition_x;
        }

        if(y_val < TMath::Abs(TOF1_y_offset)){
            TOF1_y_offset = globalPosition_y;
        }
    }

    if(TOF == 0){
        if(globalPosition_x < 0.0){
            x_val = globalPosition_x + 20.0;
        }
        else{
            x_val = globalPosition_x - 20.0;
        }

        if(globalPosition_y < 0.0){
            y_val = globalPosition_y + 20.0;
        }
        else{
            y_val = globalPosition_y - 20.0;
        }

      //  std::cerr << "x = " << globalPosition_x << " and x_val = " << x_val << "\n";


        if(TMath::Abs(x_val) < TMath::Abs(TOF0_x_offset)){
            TOF0_x_offset = x_val;
        }

        if(TMath::Abs(y_val) < TMath::Abs(TOF0_y_offset)){
            TOF0_y_offset = y_val;
        }
    }
}

QVector<double> ReadMAUS::getTOFOffset(int TOF){
    QVector<double> offsets;
    if(TOF == 0){
        offsets << TOF0_x_offset << TOF0_y_offset;
    }
    else{
        offsets << TOF1_x_offset << TOF1_y_offset;
    }

    return offsets;
}

void ReadMAUS::correct_for_TOF_offsets(){
    QVector<QVector<double> > tmp_slab_data;

    tmp_slab_data = TOF0_hSlab_0;
    TOF0_hSlab_0.clear();
    TOF0_hSlab_0 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_1;
    TOF0_hSlab_1.clear();
    TOF0_hSlab_1 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_2;
    TOF0_hSlab_2.clear();
    TOF0_hSlab_2 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_3;
    TOF0_hSlab_3.clear();
    TOF0_hSlab_3 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_4;
    TOF0_hSlab_4.clear();
    TOF0_hSlab_4 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_5;
    TOF0_hSlab_5.clear();
    TOF0_hSlab_5 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_6;
    TOF0_hSlab_6.clear();
    TOF0_hSlab_6 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_7;
    TOF0_hSlab_7.clear();
    TOF0_hSlab_7 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_8;
    TOF0_hSlab_8.clear();
    TOF0_hSlab_8 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_hSlab_9;
    TOF0_hSlab_9.clear();
    TOF0_hSlab_9 = correct_slab(tmp_slab_data, TOF0_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_0;
    TOF0_vSlab_0.clear();
    TOF0_vSlab_0 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_1;
    TOF0_vSlab_1.clear();
    TOF0_vSlab_1 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_2;
    TOF0_vSlab_2.clear();
    TOF0_vSlab_2 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_3;
    TOF0_vSlab_3.clear();
    TOF0_vSlab_3 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_4;
    TOF0_vSlab_4.clear();
    TOF0_vSlab_4 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_5;
    TOF0_vSlab_5.clear();
    TOF0_vSlab_5 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_6;
    TOF0_vSlab_6.clear();
    TOF0_vSlab_6 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_7;
    TOF0_vSlab_7.clear();
    TOF0_vSlab_7 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_8;
    TOF0_vSlab_8.clear();
    TOF0_vSlab_8 = correct_slab(tmp_slab_data, TOF0_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF0_vSlab_9;
    TOF0_vSlab_9.clear();
    TOF0_vSlab_9 = correct_slab(tmp_slab_data, TOF0_y_offset);






    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_0;
    TOF1_hSlab_0.clear();
    TOF1_hSlab_0 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_1;
    TOF1_hSlab_1.clear();
    TOF1_hSlab_1 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_2;
    TOF1_hSlab_2.clear();
    TOF1_hSlab_2 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_3;
    TOF1_hSlab_3.clear();
    TOF1_hSlab_3 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_4;
    TOF1_hSlab_4.clear();
    TOF1_hSlab_4 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_5;
    TOF1_hSlab_5.clear();
    TOF1_hSlab_5 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_hSlab_6;
    TOF1_hSlab_6.clear();
    TOF1_hSlab_6 = correct_slab(tmp_slab_data, TOF1_x_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_0;
    TOF1_vSlab_0.clear();
    TOF1_vSlab_0 = correct_slab(tmp_slab_data, TOF1_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_1;
    TOF1_vSlab_1.clear();
    TOF1_vSlab_1 = correct_slab(tmp_slab_data, TOF1_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_2;
    TOF1_vSlab_2.clear();
    TOF1_vSlab_2 = correct_slab(tmp_slab_data, TOF1_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_3;
    TOF1_vSlab_3.clear();
    TOF1_vSlab_3 = correct_slab(tmp_slab_data, TOF1_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_4;
    TOF1_vSlab_4.clear();
    TOF1_vSlab_4 = correct_slab(tmp_slab_data, TOF1_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_5;
    TOF1_vSlab_5.clear();
    TOF1_vSlab_5 = correct_slab(tmp_slab_data, TOF1_y_offset);

    tmp_slab_data.clear();
    tmp_slab_data = TOF1_vSlab_6;
    TOF1_vSlab_6.clear();
    TOF1_vSlab_6 = correct_slab(tmp_slab_data, TOF1_y_offset);


}


QVector<QVector<double> > ReadMAUS::correct_slab(QVector<QVector<double> > slabData, double offset){
    QVector<QVector<double> > corrected_slab_data;
    QVector<double> particle;
    QVector<double> corrected_particle;
    double a, t_minus, t_plus, slab_width;

    for(int i = 0; i < slabData.size(); i++){
        particle.clear();
        corrected_particle.clear();

        particle = slabData.at(i);

        a = particle.at(0);
        t_minus = particle.at(1);
        t_plus = particle.at(2);
        slab_width = particle.at(3);

        a = a - offset;

        corrected_particle << a << t_minus << t_plus << slab_width;
        corrected_slab_data << corrected_particle;
    }
    return corrected_slab_data;
}
