#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//! QT Headers
#include <QMainWindow>

//! QGIS Headers
#include <qgsmapcanvas.h>
#include <qgslayertreeview.h>
#include <qgslayertreemodel.h>
#include <qgslayertreemapcanvasbridge.h>

#include <qgsvectorlayer.h>
#include <qgsmaptool.h>
#include <qgsmaptoolpan.h>
#include <qgsmaptoolzoom.h>

#define SHAPE_FILE_PATH "./shapefiles/"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QgsProject *mQGisProject;
    QgsMapCanvas *mMapCanvas;

    QgsMapTool *mPanTool;
    QgsMapTool *mZoomInTool;
    QgsMapTool *mZoomOutTool;

    QList<QgsMapLayer*> mLayers;
    QgsLayerTreeView *mLayerTreeView;
    QgsLayerTree* mLayerTree;
    QgsLayerTreeMapCanvasBridge *mLayerTreeMapCanvasBridge;    

    QAction *mActionPan;
    QAction *mActionZoomIn;
    QAction *mActionZoomOut;
    QAction *mActionZoomPrev;
    QAction *mActionZoomNext;

    void addLayer();
};
#endif // MAINWINDOW_H
