#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QWorking.h"

class QWorking : public QMainWindow
{
	Q_OBJECT

public:
	QWorking(QWidget *parent = Q_NULLPTR);

private:
	QVector<QWidget*> buttons;
	Ui::QWorkingClass ui;

private slots:
	void on_tabWidget_currentChanged(const int index);
};
