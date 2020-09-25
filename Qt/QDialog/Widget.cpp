#include "Widget.h"
#include "InfoDialog.h"
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, [=] {
		InfoDialog* info = new InfoDialog(this);
		int result = info->exec();
		//info->show() --> show non modal dialog
		//info->raise() --> move dialog to the front of all widgets
		//info->activateWindow() --> focus on dialog

		if (result == QDialog::Accepted) {
			QPushButton* showInfo = new QPushButton("Show Info", this);
			ui.verticalLayout->addWidget(showInfo);
			connect(showInfo, &QPushButton::clicked, [=] {
				QMessageBox::information(this, "Info", info->pos() + info->fav(), QMessageBox::Ok);
				ui.verticalLayout->removeWidget(showInfo);
				delete showInfo;
			});
		}
	});
	
}

Widget::~Widget() {

}