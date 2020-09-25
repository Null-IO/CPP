#include "Widget.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	
	connect(ui.getExistingDirectory, &QPushButton::clicked, [&] {
		QString dir = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
		QMessageBox::information(this, "Dir", "Chosen dir: " + dir);
	});

	connect(ui.getOpenFileName, &QPushButton::clicked, [&] {
		QString dir = QFileDialog::getOpenFileName(this, tr("Open file"), "/home", tr("Images (*.png *.jpg)"));
		QMessageBox::information(this, "Dir", "Opened dir: " + dir);
	});

	connect(ui.getOpenFileNames, &QPushButton::clicked, [&] {
		auto dirs = QFileDialog::getOpenFileNames(this, "Select one or more files to open", "/home", "Images (*.png *.jpg);;Text files (*.txt);;XML files (*.xml)");
		QString dir = "";
		for (auto& d : dirs)
			dir.append(d + "\n");
		
		QMessageBox::information(this, "Dir", "Chosen dirs: " + dir);
	
	});
	connect(ui.getSaveFileName, &QPushButton::clicked, [&] {
		QString dir = QFileDialog::getSaveFileName(this, tr("Save file"), "/home", tr("Images (*.png *.jpg)"));
		QMessageBox::information(this, "Dir", "Saved dir: " + dir);
	});
}

Widget::~Widget() {

}