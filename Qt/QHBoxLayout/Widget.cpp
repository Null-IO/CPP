#include "Widget.h"
#include "stdafx.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);

	//Can be done in Qt designer also
	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(ui.oneButton);
	layout->addWidget(ui.twoButton);
	layout->addWidget(ui.threeButton);
	layout->addWidget(ui.fourButton);
	layout->addWidget(ui.fiveButton);
	setLayout(layout); //Applying layout

}
