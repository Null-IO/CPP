#include "mainwindow.h"
#include <QDebug>

void MainWindow::resizeEvent(QResizeEvent *event) {
    qDebug() << "Old size:" << event->oldSize() << ", Newsize:" << event->size();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        this->close();
    }
    qDebug() << event->text() << "has been pressed";
}

void MainWindow::keyRealeaseEvent(QKeyEvent *event) {
    qDebug() << event->text() << "has been released";
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "Position: " << event->pos();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Mouse pressed:" << event->button();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Mouse released:" << event->button();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //Important!
    this->setMouseTracking(true);
    ui.centralwidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
}
