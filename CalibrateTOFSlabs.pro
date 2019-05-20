#-------------------------------------------------
#
# Project created by QtCreator 2015-08-05T10:10:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalibrateTOFSlabs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calibrate.cpp \
    readmaus.cpp

HEADERS  += mainwindow.h \
    calibrate.h \
    readmaus.h

FORMS    += mainwindow.ui

LIBS += -L/home/vicki/WorkPrograms/maus/third_party/build/root/lib -lCint -lCore -lMathCore
LIBS += -lMathMore -lHist -lTree -lMatrix -lRIO -lThread
LIBS += -lGui -lRIO -lNet -lGraf -lGraf3d -lGpad -lRint -lPostscript -lPhysics -lThread -pthread -lm -ldl -rdynamic
LIBS += -L/home/vicki/WorkPrograms/maus/src/common_cpp -lMausCpp
LIBS += -L/home/vicki/WorkPrograms/maus/third_party/install/lib
LIBS += -ljson -lPhysics
LIBS += -lCLHEP
LIBS += -lG4geometry -lG4graphics_reps -lG4materials -lG4particles
LIBS += -lG4processes -lG4run -lG4event -lG4global -lG4intercoms
LIBS += -lG4modeling -lG4tracking -lG4visHepRep -lG4VRML -lG4digits_hits
LIBS += -lG4FR -lG4physicslists -lG4vis_management -lG4clhep -lG4track -lG4zlib


INCLUDEPATH += /home/vicki/WorkPrograms/maus/third_party/build/root/include/


INCLUDEPATH += /home/vicki/WorkPrograms/maus/src/common_cpp
INCLUDEPATH += /home/vicki/WorkPrograms/maus/
INCLUDEPATH += /home/vicki/WorkPrograms/maus/src/legacy
INCLUDEPATH += /home/vicki/WorkPrograms/maus/third_party/install/include

DEPENDPATH +=/home/vicki/work/root/include
