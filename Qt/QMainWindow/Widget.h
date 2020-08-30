#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow {
	Q_OBJECT
private:
	QSize sizeHint() const { return QSize(300, 200); }
public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow();
};

//#include <QtWidgets/QWidget>
//#include "ui_Widget.h"
//
//class Widget : public QWidget
//{
//	Q_OBJECT
//
//public:
//	Widget(QWidget *parent = Q_NULLPTR);
//private:
//	Ui::WidgetClass ui;
//};