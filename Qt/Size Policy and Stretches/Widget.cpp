#include "Widget.h"
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	//look at Widget.ui
}

Widget::~Widget() {

}