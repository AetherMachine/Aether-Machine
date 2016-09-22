#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTimer>
#include "GraphicsEngine.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GraphicsEngine graphicsEngine(400, 400);

    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&] {
        auto image = graphicsEngine.toImage();
        //image.save(&process, "bmp");
        ui->centralOpenGLWidget->setImage(image);
        ui->centralOpenGLWidget->animate();
    });
    timer->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
