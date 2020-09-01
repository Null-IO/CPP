#include "Widget.h"
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	QPushButton* button = new QPushButton("Button", this);
	button->move(200, 200);
	connect(button, &QPushButton::clicked, [=] {
		//Long and dark way
		/*
		QMessageBox messageBox(this);
		messageBox.setMinimumSize(200, 150); //set minimum size for message box
		messageBox.setWindowTitle("Message Title");
		messageBox.setText("Something happened");
		messageBox.setInformativeText("Do you want to do something about it?");
		messageBox.setIcon(QMessageBox::Question);
		messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel); //set buttons for message box
		messageBox.setDefaultButton(QMessageBox::Cancel);
		
		int response = messageBox.exec(); //Shows message box
		*/

		//More shorter way
		int response = QMessageBox::critical(this, "Message title", "Something happened. Do you want to do something about it?", QMessageBox::Yes | QMessageBox::Cancel);

		if (response == QMessageBox::Yes) {
			QMessageBox alert(QMessageBox::Information, "Alert", "User clicked on \"Ok\"", QMessageBox::Ok);
			alert.exec();
		} else if (response == QMessageBox::Cancel) {
			QMessageBox alert(QMessageBox::Critical, "Alert", "User clicked on \"Cancel\"", QMessageBox::Ok);
			alert.exec();
		}
	});
}

Widget::~Widget() {

}