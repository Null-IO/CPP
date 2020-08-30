//requires Qt and Qt tools for VS
#include "SliderProgress.h"
#include "stdafx.h"

SliderProgress::SliderProgress(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	//1)String Notation
	//connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), ui.progressBar, SLOT(setValue(int)));
	//2)Functor Notation
	connect(ui.horizontalSlider, &QSlider::valueChanged, ui.progressBar, &QProgressBar::setValue);
	//3)Functor + Lambda Notation
	/*connect(ui.horizontalSlider, &QSlider::valueChanged, [=] {
		ui.progressBar->setValue(ui.horizontalSlider->value());
	});*/
}
