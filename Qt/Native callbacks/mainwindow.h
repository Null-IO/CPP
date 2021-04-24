#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QDebug>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //QWidget's virtual function overidden here
    void resizeEvent(QResizeEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyRealeaseEvent(QKeyEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    ~MainWindow();

private:
    Ui::MainWindow ui;
};
#endif // MAINWINDOW_H
