#include "Widget.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	//Adding button
	QPushButton* button = new QPushButton("Hello", this);
	setCentralWidget(button);
	
	//Declaring Quit action
	QAction* quitAction = new QAction("Quit");
	connect(quitAction, &QAction::triggered, [=] {
		QApplication::quit();
	});

	//Adding menu bar
	QMenu* fileMenu = menuBar()->addMenu("File");
	fileMenu->addAction(quitAction);
	menuBar()->addMenu("Edit");
	menuBar()->addMenu("Window");
	menuBar()->addMenu("Settings");
	menuBar()->addMenu("Help");

	//Adding status bar
	statusBar()->showMessage("I will disappear in 3 seconds", 3000); //After 3000ms status bar message will disappear
}

MainWindow::~MainWindow() {

}