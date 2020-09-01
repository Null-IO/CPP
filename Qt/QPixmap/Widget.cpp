#include "Widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, [=] {
		QPixmap dwightMap(":/Widget/dwight.jpg");
		ui.DwightIMG->setPixmap(dwightMap.scaled(400, 400));
	});
}
