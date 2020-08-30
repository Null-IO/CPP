#pragma once

#include <QtWidgets/QWidget>
#include "ui_PushWidget.h"

class PushWidget : public QWidget{
    Q_OBJECT

public:
    PushWidget(QWidget *parent = Q_NULLPTR);

private:
	static int timesPressed;
    Ui::PushWidgetClass ui;
private slots:
	void changeText();
};
