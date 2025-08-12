#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <qgslayertree.h>
#include <qgslayertreegroup.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mQGisProject = new QgsProject();
    QgsProject::setInstance(mQGisProject);

    mMapCanvas = new QgsMapCanvas();
    mMapCanvas->setProject(mQGisProject);
    mMapCanvas->setDestinationCrs(QgsCoordinateReferenceSystem::fromEpsgId(4326));
    ui->gridLayoutMapCanvas->addWidget(mMapCanvas);

    /**********Layer Tree****/
    mLayerTreeView = new QgsLayerTreeView();
    // mLayerTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    // mLayerTreeView->setDragDropMode(QAbstractItemView::DragDrop);
    // mLayerTreeView->setAcceptDrops(true);
    mLayerTreeView->setMaximumWidth(200);
    mLayerTreeView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    ui->splitter->setStretchFactor(0, 0);
    ui->splitter->setStretchFactor(1, 1);

    mLayerTree = mQGisProject->layerTreeRoot();

    QgsLayerTreeModel *layerTreeModel = new QgsLayerTreeModel(mQGisProject->layerTreeRoot());
    layerTreeModel->setFlag(QgsLayerTreeModel::ShowLegendAsTree, true); // This shows the legend as a tree
    layerTreeModel->setFlag(QgsLayerTreeModel::AllowNodeReorder, true); // Allows reordering of nodes
    layerTreeModel->setFlag(QgsLayerTreeModel::AllowNodeChangeVisibility, true); // Enables checkboxes for layer visibility
    layerTreeModel->setFlag(QgsLayerTreeModel::AllowNodeRename);
    mLayerTreeView->setModel(layerTreeModel);

    mLayerTreeMapCanvasBridge = new QgsLayerTreeMapCanvasBridge(mQGisProject->layerTreeRoot(), mMapCanvas);

    ui->gridLayoutLayerTree->addWidget(mLayerTreeView);

    // Create actions with icons
    mActionPan = new QAction(QIcon(":/images/pan.png"), "Pan", this);
    mActionZoomIn = new QAction(QIcon(":/images/ZoomIn.png"), "Zoom In", this);
    mActionZoomOut = new QAction(QIcon(":/images/ZoomOut.png"), "Zoom Out", this);
    mActionZoomPrev = new QAction(QIcon(":/images/ZoomLast.png"), "Zoom Prev", this);
    mActionZoomPrev->setDisabled(true);
    mActionZoomNext = new QAction(QIcon(":/images/ZoomNext.png"), "Zoom Next", this);
    mActionZoomNext->setDisabled(true);

    connect( mMapCanvas, &QgsMapCanvas::zoomLastStatusChanged, mActionZoomPrev, &QAction::setEnabled );
    connect( mMapCanvas, &QgsMapCanvas::zoomNextStatusChanged, mActionZoomNext, &QAction::setEnabled );

    mPanTool = new QgsMapToolPan(mMapCanvas);
    mZoomInTool = new QgsMapToolZoom(mMapCanvas, false);    // false = in
    mZoomOutTool = new QgsMapToolZoom(mMapCanvas, true);    // true = out

    // Add actions to the toolbar
    ui->toolBarMapTools->addAction(mActionPan);
    ui->toolBarMapTools->addAction(mActionZoomIn);
    ui->toolBarMapTools->addAction(mActionZoomOut);
    ui->toolBarMapTools->addAction(mActionZoomPrev);
    ui->toolBarMapTools->addAction(mActionZoomNext);

    connect(mActionPan, &QAction::triggered, [this](){mMapCanvas->setMapTool(mPanTool);});

    connect(mActionZoomIn, &QAction::triggered, [this](){mMapCanvas->setMapTool(mZoomInTool);});

    connect(mActionZoomOut, &QAction::triggered, [this](){mMapCanvas->setMapTool(mZoomOutTool);});

    connect(mActionZoomNext, &QAction::triggered, [this](){mMapCanvas->zoomToNextExtent();});

    connect(mActionZoomPrev, &QAction::triggered, [this](){mMapCanvas->zoomToPreviousExtent();});

    addLayer();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addLayer()
{
    QString strLayerPath(SHAPE_FILE_PATH);
    strLayerPath.append("world.shp");

    QgsVectorLayer *vectorLayer = new QgsVectorLayer(strLayerPath, QFileInfo(strLayerPath).fileName(), "ogr");

    if(vectorLayer->isValid())
    {
        mLayers.append(vectorLayer);
        mMapCanvas->setExtent(vectorLayer->extent());
        mQGisProject->addMapLayer(vectorLayer);
        mMapCanvas->setLayers(mLayers);
        mMapCanvas->refresh();
        qDebug() << "Layer is vaild" << vectorLayer->error().message();
    }
    else{
        qDebug() << "Layer is not vaild" << vectorLayer->error().message();

    }
}
