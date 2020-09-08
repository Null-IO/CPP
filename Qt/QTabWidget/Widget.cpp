#include "Widget.h"
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	
	QWidget* widget = new QWidget(this);
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(new QPushButton("Button", this));
	QPushButton* button2 = new QPushButton("Button2", this);
	layout->addWidget(button2);
	widget->setLayout(layout);
	ui.tabWidget->addTab(widget, "Custom Tab");

	ui.tabWidget->insertTab(1, widget, "Custom Tab"); //Moves tab to 2nd position

	connect(button2, &QPushButton::clicked, [=] {
		QMessageBox::information(this, "Info", "Custom tab button", QMessageBox::Ok);
	});

	connect(ui.confirmButton, &QPushButton::clicked, [=] {
		QList<QRadioButton*> list { ui.cppRadio, ui.pyRadio, ui.goRadio };
		for (auto& it : list)
			if (it->isChecked()) {
				QMessageBox::information(this, "Info", "Language: \"" + it->text() + "\"", QMessageBox::Ok);
				return;
			}
		QMessageBox::critical(this, "Info", "Nothing selected", QMessageBox::Ok);
	});

	connect(ui.getButton, &QPushButton::clicked, [=] {
		QString str = ui.textEdit->toPlainText();
		if(str.count() != 0)
			QMessageBox::information(this, "Info", "Text:\n" + str, QMessageBox::Ok);
		else
			QMessageBox::critical(this, "Info", "TextEdit is empty", QMessageBox::Ok);
	});
}

Widget::~Widget() {

}