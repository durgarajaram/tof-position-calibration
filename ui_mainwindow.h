/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_inputFile;
    QToolButton *btn_inputFile;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *dbl_min_tof;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QDoubleSpinBox *dbl_max_tof;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_calibrationDescription1;
    QLineEdit *line_outputFile;
    QToolButton *btn_outputFile;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_close;
    QPushButton *btn_go;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(564, 387);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        line_inputFile = new QLineEdit(centralWidget);
        line_inputFile->setObjectName(QStringLiteral("line_inputFile"));

        horizontalLayout->addWidget(line_inputFile);

        btn_inputFile = new QToolButton(centralWidget);
        btn_inputFile->setObjectName(QStringLiteral("btn_inputFile"));

        horizontalLayout->addWidget(btn_inputFile);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        dbl_min_tof = new QDoubleSpinBox(centralWidget);
        dbl_min_tof->setObjectName(QStringLiteral("dbl_min_tof"));
        dbl_min_tof->setValue(27);

        horizontalLayout_3->addWidget(dbl_min_tof);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dbl_max_tof = new QDoubleSpinBox(centralWidget);
        dbl_max_tof->setObjectName(QStringLiteral("dbl_max_tof"));
        dbl_max_tof->setValue(40);

        horizontalLayout_3->addWidget(dbl_max_tof);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_calibrationDescription1 = new QLabel(centralWidget);
        label_calibrationDescription1->setObjectName(QStringLiteral("label_calibrationDescription1"));

        horizontalLayout_2->addWidget(label_calibrationDescription1);

        line_outputFile = new QLineEdit(centralWidget);
        line_outputFile->setObjectName(QStringLiteral("line_outputFile"));

        horizontalLayout_2->addWidget(line_outputFile);

        btn_outputFile = new QToolButton(centralWidget);
        btn_outputFile->setObjectName(QStringLiteral("btn_outputFile"));

        horizontalLayout_2->addWidget(btn_outputFile);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout_5->addWidget(btn_close);

        btn_go = new QPushButton(centralWidget);
        btn_go->setObjectName(QStringLiteral("btn_go"));

        horizontalLayout_5->addWidget(btn_go);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 564, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(btn_close, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calibrate TOF Slabs", 0));
        label->setText(QApplication::translate("MainWindow", "Input MAUS File:", 0));
        line_inputFile->setText(QApplication::translate("MainWindow", "$MAUS_ROOT_DIR/bin/particles.root", 0));
        btn_inputFile->setText(QApplication::translate("MainWindow", "...", 0));
        label_2->setText(QApplication::translate("MainWindow", "Min TOF", 0));
        label_3->setText(QApplication::translate("MainWindow", "Max TOF", 0));
        label_calibrationDescription1->setText(QApplication::translate("MainWindow", "Calibration Output File:", 0));
        line_outputFile->setText(QApplication::translate("MainWindow", "../CalibrationFiles/test.dat", 0));
        btn_outputFile->setText(QApplication::translate("MainWindow", "...", 0));
        btn_close->setText(QApplication::translate("MainWindow", "Close", 0));
        btn_go->setText(QApplication::translate("MainWindow", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
