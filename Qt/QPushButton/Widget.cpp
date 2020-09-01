#include "Widget.h"
#include <QPushButton>
#include <QFont>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	setWindowTitle("QPushButton");
	QFont buttonFont("Times", 10, QFont::Bold);
	QPushButton* button = new QPushButton("Click", this);
	button->setFont(buttonFont);
	button->setMinimumSize(75, 75);
	connect(button, &QPushButton::clicked, [=] {
		QMessageBox::information(this, "Info", "Button clicked", QMessageBox::Ok);
	});

	QPushButton* button2 = new QPushButton("Release", this);
	button2->setFont(buttonFont);
	button2->setMinimumSize(75, 75);
	button2->move(80, 0);
	connect(button2, &QPushButton::released, [=] {
		QMessageBox::information(this, "Info", "Button released", QMessageBox::Ok);
	});

	QPushButton* button3 = new QPushButton("Press", this);
	button3->setFont(buttonFont);
	button3->setMinimumSize(75, 75);
	button3->move(160, 0);
	connect(button3, &QPushButton::pressed, [=] {
		QMessageBox::information(this, "Info", "Button pressed", QMessageBox::Ok);
	});
}

Widget::~Widget() {

}