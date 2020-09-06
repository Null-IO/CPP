#include "Widget.h"
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(ui.pushButton1);
	layout->addWidget(ui.pushButton2);
	layout->addWidget(ui.pushButton3);
	layout->addWidget(ui.pushButton4);
	layout->addWidget(ui.pushButton5);
	setLayout(layout);
}

Widget::~Widget() {

}