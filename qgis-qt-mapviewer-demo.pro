QT       += core gui widgets xml

DEFINES += QT_DEPRECATED_WARNINGS

TARGET = qgis-qt-mapviewer-demo

UI_DIR = ./ui
MOC_DIR = ./moc
OBJECTS_DIR = ./obj

CONFIG += c++17

# ---------------------------
# Linux specific settings
# ---------------------------

unix {
    # QGIS includes and libs (Linux)
    INCLUDEPATH += /usr/include/qgis
    LIBS += -L/usr/lib \
        -lqgis_core -lqgis_gui -lqgis_3d -lqgis_analysis -lqgis_app \
        -lgdal -lgsl -lgslcblas
}

# ---------------------------
# Windows (MSVC) specific settings
# ---------------------------

win32 {

    # Root path to OSGeo4W install
    OSGEO4W_ROOT = C:/OSGeo4W

    # Include and library paths
    INCLUDEPATH += $$OSGEO4W_ROOT/apps/qgis-qt6-dev/include
    INCLUDEPATH += $$OSGEO4W_ROOT/apps/gdal-dev/include

    INCLUDEPATH += $$OSGEO4W_ROOT/include

    LIBS += -L$$OSGEO4W_ROOT/apps/qgis-qt6-dev/lib
    LIBS += -L$$OSGEO4W_ROOT/apps/gdal-dev/lib
    LIBS += -L$$OSGEO4W_ROOT/lib

    # QGIS libraries (Windows)
    LIBS += -lqgis_core -lqgis_gui
    LIBS += -lgdal
}

SOURCES += \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    mainwindow.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

