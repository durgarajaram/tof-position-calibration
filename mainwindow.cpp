#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setup(){
    //calibration = Calibrate();

    connect(ui->btn_inputFile, SIGNAL(clicked()), SLOT(choose_open_file()));
    connect(ui->btn_outputFile, SIGNAL(clicked()), SLOT(choose_save_file()));

    connect(ui->btn_go, SIGNAL(clicked()), SLOT(go()));
}




void MainWindow::choose_open_file(){
    QStringList filenames;
    QFileDialog dialog(this);
    dialog.setDirectory(ui->line_inputFile->text());
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setNameFilter(tr("ROOT Files (*.root)"));
    if(dialog.exec()){
        filenames = dialog.selectedFiles();
    }
    if(!filenames.empty()){
        ui->line_inputFile->setText(filenames.first());
    }
}

void MainWindow::choose_save_file(){
    QStringList filenames;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setDirectory(ui->line_outputFile->text());
    dialog.setNameFilter(tr("ROOT Files (*.root)"));
    if(dialog.exec()){
        filenames = dialog.selectedFiles();
    }

    if(!filenames.empty()){
        ui->line_outputFile->setText(filenames.first());
    }
}





void MainWindow::go(){
    calibration.MakeCalibration(ui->line_inputFile->text(), ui->line_outputFile->text(), ui->dbl_min_tof->value(), ui->dbl_max_tof->value());
}

