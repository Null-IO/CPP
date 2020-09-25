#include "Widget.h"
#include "infoDialog.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	
	connect(ui.pushButton, &QPushButton::clicked, [&] {
		infoDialog* dialog = new infoDialog(this);
		dialog->exec();
	});
}

Widget::~Widget() {

}