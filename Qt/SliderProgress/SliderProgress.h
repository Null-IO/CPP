#pragma once

#include <QtWidgets/QWidget>
#include "ui_SliderProgress.h"

class SliderProgress : public QWidget {
	Q_OBJECT

public:
	SliderProgress(QWidget *parent = Q_NULLPTR);

private:
	Ui::SliderProgressClass ui;
};
