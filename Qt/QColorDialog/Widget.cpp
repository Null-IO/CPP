#include "Widget.h"
#include <QFontDialog>
#include <QMessageBox>
#include <QColorDialog>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	ui.label->setAutoFillBackground(true);

	connect(ui.textButton, &QPushButton::clicked, [&] {
		QPalette palette = ui.label->palette(); //Get palatte of label
		QColor color = palette.color(QPalette::WindowText); //Get colour of text inside label
		QColor chosenColour = QColorDialog::getColor(color, this, "Choose Color"); //Colour Dialog

		if (chosenColour.isValid()) { //If user hasn't pressed "Cancel button"
			palette.setColor(QPalette::WindowText, chosenColour);
			ui.label->setPalette(palette);
		}
	});

	connect(ui.bgroundButton, &QPushButton::clicked, [&] {
		QPalette palette = ui.label->palette();
		QColor color = palette.color(QPalette::Window);
		QColor chosenColour = QColorDialog::getColor(color, this, "Choose Color");

		if (chosenColour.isValid()) {
			palette.setColor(QPalette::Window, chosenColour);
			ui.label->setPalette(palette);
		}
	});

	connect(ui.fontButton, &QPushButton::clicked, [&] {
		bool ok = false;
		QFont font = QFontDialog::getFont(&ok, this);
		ok ? ui.label->setFont(font) : QMessageBox::information(this, "Info", "User Canceled Dialog");
	});
}

Widget::~Widget() {

}