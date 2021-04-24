#include "QWorking.h"
#include "stdafx.h"

void QWorking::on_tabWidget_currentChanged(const int index) {
	for (auto& i : this->buttons)
		i->setProperty("pagematches", false);
	
	this->buttons[index]->setProperty("pagematches", true);

	for (auto& i : this->buttons)
		i->style()->polish(i);
}

QWorking::QWorking(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	this->buttons = { ui.pushButton, ui.pushButton2, ui.pushButton3 };

	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &QWorking::on_tabWidget_currentChanged);
}
