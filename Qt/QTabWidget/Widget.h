#pragma once

#include <QtWidgets/QWidget>
#include <random>
#include "ui_Widget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);
	QString randStr(std::mt19937& engine);
	~Widget();
private:
	Ui::WidgetClass ui;
};