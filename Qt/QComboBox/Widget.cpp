#include "Widget.h"
#include <QButtonGroup>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	
	ui.comboBox->addItem("Earth");
	ui.comboBox->addItem("Mars");
	ui.comboBox->addItem("Jupiter");
	ui.comboBox->addItem("Saturn");
	ui.comboBox->addItem("Uranus");
	ui.comboBox->addItem("Neptune");
	ui.comboBox->addItem("Pluto");

	connect(ui.capture, &QPushButton::clicked, [=] {
		QMessageBox::information(this, "Info", "Captured value: \"" + ui.comboBox->currentText() + "\"", QMessageBox::Ok);
	});

	connect(ui.set, &QPushButton::clicked, [=] {
		ui.comboBox->setCurrentIndex(6);
	});

	connect(ui.get, &QPushButton::clicked, [=] {
		QList<QString> list;
		for (size_t i = 0; i < ui.comboBox->count(); i++)
			list.append(ui.comboBox->itemText(i));
		
		QString contents = "";
		for (size_t i = 0; i < list.count(); i++)
			contents += list.at(i) + "\n";

		QMessageBox::information(this, "Contents", "Contents are:\n" + contents, QMessageBox::Ok);
	});
}

Widget::~Widget() {

}