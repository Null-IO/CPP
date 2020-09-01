#include "Widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	QLabel* firstName = new QLabel("Firstname:", this);
	firstName->setMinimumSize(70, 50);
	firstName->move(10, 10);

	QLineEdit* firstNameLine = new QLineEdit(this);
	firstNameLine->setMinimumSize(200, 50);
	firstNameLine->move(100, 10);
	firstNameLine->setPlaceholderText("Dwight");

	QLabel* lastName = new QLabel("Lastname:", this);
	lastName->setMinimumSize(70, 50);
	lastName->move(10, 70);

	QLineEdit* lastNameLine = new QLineEdit(this);
	lastNameLine->setMinimumSize(200, 50);
	lastNameLine->move(100, 70);
	lastNameLine->setPlaceholderText("Schrute");

	QLabel* Age = new QLabel("Age:", this);
	Age->setMinimumSize(70, 50);
	Age->move(10, 130);

	QLineEdit* AgeLine = new QLineEdit(this);
	AgeLine->setMinimumSize(200, 50);
	AgeLine->move(100, 130);
	AgeLine->setPlaceholderText("41");
	//AgeLine->setText() -> changes text inside LineEdit

	QPushButton* button = new QPushButton("Submit", this);
	button->move(150, 250);
	
	connect(button, &QPushButton::clicked, [=] {
		QString first_name = firstNameLine->text();
		QString last_name = lastNameLine->text();
		QString age = AgeLine->text();

		if (!first_name.isEmpty() && !last_name.isEmpty() && !age.isEmpty())
			QMessageBox::information(this, "submitted", "Firstname: " + first_name + "\nLastname: " + last_name + "\nAge: " + age);
		else
			QMessageBox::critical(this, "Error", "Please fill out all of the fields");

	});
}

Widget::~Widget() {

}