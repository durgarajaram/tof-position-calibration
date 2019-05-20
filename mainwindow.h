#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStringList>
#include "calibrate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void choose_open_file();
    void choose_save_file();

    void go();


private:
    Ui::MainWindow *ui;

    Calibrate calibration;

    void setup();
};

#endif // MAINWINDOW_H
