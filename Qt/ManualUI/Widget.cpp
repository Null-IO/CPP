#include "Widget.h"
#include "stdafx.h"
#include <QLabel>
#include <QFont>
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {
	setWindowTitle("Test"); //Setting title of a window
	QPalette Palette;
	Palette.setColor(QPalette::Window, Qt::yellow); //Setting background colour to gray
	Palette.setColor(QPalette::WindowText, Qt::red); //Setting colour to red for label(QPalette::WindowText for widgets)
	
	QFont labelFont("Times", 15, QFont::Bold); //Creating font
	
	QLabel* ql = new QLabel("label", this); //Creating label
	ql->setFont(labelFont); //Setting font for label
	ql->setPalette(Palette);
	ql->setAutoFillBackground(true); //Background colour for label
	ql->move(50, 50); //Moving label
	
	QPushButton* button = new QPushButton(this);
	button->setText("Click Me");
	button->setFont(labelFont);
	button->setPalette(Palette);

	connect(button, &QPushButton::clicked, this, &Widget::buttonClicked);
}

void Widget::buttonClicked() {
	QMessageBox::information(this, "Alert", "You clicked on button"); //Static function for invoking message box
}