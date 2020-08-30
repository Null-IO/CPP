//Basic Qt GUI
//requires Qt and Qt tools for VS
#include "PushWidget.h"
#include "stdafx.h"
#include <sstream>
#include <string>

int PushWidget::timesPressed = 0;

PushWidget::PushWidget(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	//1)String Notation
	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(changeText()));
	//2)Functor Notation
	connect(ui.pushButton, &QPushButton::clicked, this, &PushWidget::changeText);
	//3)Functor + Lambda Notation
	/*connect(ui.pushButton, &QPushButton::clicked, [=] {
		//Code that modifies specific widget goes here
	});*/
}

void PushWidget::changeText() {
	std::ostringstream outstr;
	outstr << ++timesPressed;
	std::string msg = "You pressed button " + outstr.str() + " times";
	ui.label->setText(msg.c_str());
}
