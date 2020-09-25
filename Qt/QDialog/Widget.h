#pragma once

#include <QtWidgets/QWidget>
#include <random>
#include "ui_Widget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);
	~Widget();
private:
	Ui::WidgetClass ui;
};