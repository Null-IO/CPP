#include "Widget.h"
#include <QButtonGroup>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);

	QList<QCheckBox*> list;
	list.append(ui.checkBox);
	list.append(ui.checkBox2);
	list.append(ui.checkBox3);


	connect(ui.check, &QPushButton::clicked, [=] {
		for (auto& it : list) {
			if (!it->isChecked())
				it->setChecked(true);
		}
	});

	connect(ui.uncheck, &QPushButton::clicked, [=] {
		for (auto& it : list) {
			if (it->isChecked())
				it->setChecked(false);
		}
	});

}

Widget::~Widget() {

}