#include "Widget.h"
#include <QFontDialog>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	
	connect(ui.pushButton, &QPushButton::clicked, [&] {
		bool ok = false;
		QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
		ok ? ui.textEdit->setFont(font) : QMessageBox::information(this, "Info", "User Canceled Dialog");
	});
}

Widget::~Widget() {

}