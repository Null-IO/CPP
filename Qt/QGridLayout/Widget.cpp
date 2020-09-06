#include "Widget.h"
#include <QGridLayout>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);

	QGridLayout* layout = new QGridLayout(this); //"this" applies grid layout and to widget itself
	//First row
	layout->addWidget(ui.button1, 0, 0);
	layout->addWidget(ui.button2, 0, 1);
	layout->addWidget(ui.button3, 0, 2, 2, 1); //Will take 2 rows and 1 column(vertical policy set to Preferred)

	//Second row
	layout->addWidget(ui.button4, 1, 0);
	layout->addWidget(ui.button5, 1, 1);

	//Third row
	layout->addWidget(ui.button7, 2, 0, 1, 2); //Will take 1 row and 2 columns
	layout->addWidget(ui.button9, 2, 2);
}

Widget::~Widget() {

}