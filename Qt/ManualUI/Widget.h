#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);

private:
	Ui::WidgetClass ui;
	QSize sizeHint() const { return QSize(250, 250); }; //Function for specifying window size

private slots:
	void buttonClicked();
};
