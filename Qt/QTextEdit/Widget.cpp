#include "Widget.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	setWindowTitle("QTextEdit");
	QFont labelFont("Times", 10, QFont::Bold);
	QLabel* mLabel = new QLabel("This is textEdit", this);
	mLabel->setFont(labelFont);
	mLabel->move(15, 25);

	QTextEdit* textEdit = new QTextEdit(this);
	//textEdit->setMinimumSize()
	textEdit->move(15, 55);

	QPushButton* copy = new QPushButton("Copy", this);
	copy->setMinimumSize(50, 25);
	copy->move(15, 250);
	connect(copy, &QPushButton::clicked, [=] {
		textEdit->copy();
	});

	QPushButton* cut = new QPushButton("Cut", this);
	cut->setMinimumSize(50, 25);
	cut->move(100, 250);
	connect(cut, &QPushButton::clicked, [=] {
		textEdit->cut();
	});

	QPushButton* paste = new QPushButton("Paste", this);
	paste->setMinimumSize(50, 25);
	paste->move(185, 250);
	connect(paste, &QPushButton::clicked, [=] {
		textEdit->paste();
	});

	QPushButton* undo = new QPushButton("Undo", this);
	undo->setMinimumSize(50, 25);
	undo->move(15, 280);
	connect(undo, &QPushButton::clicked, [=] {
		textEdit->undo();
	});

	QPushButton* redo = new QPushButton("Redo", this);
	redo->setMinimumSize(50, 25);
	redo->move(100, 280);
	connect(redo, &QPushButton::clicked, [=] {
		textEdit->redo();
	});

	QPushButton* plainText = new QPushButton("Plain text", this);
	plainText->setMinimumSize(50, 25);
	plainText->move(15, 310);
	connect(plainText, &QPushButton::clicked, [=] {
		textEdit->setPlainText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus condimentum leo sed elit ultricies, id molestie est aliquet. Sed auctor ex sed neque sagittis maximus. Donec id efficitur augue, sit amet blandit est.");
	});

	QPushButton* html = new QPushButton("Html", this);
	html->setMinimumSize(50, 25);
	html->move(100, 310);
	connect(html, &QPushButton::clicked, [=] {
		textEdit->setHtml("<h1>Office personal</h1><p>Office has 14 employees:</p><ul><li>Michael</li><li>Dwight</li><li>Jim</li><li>Pam</li><li>Stanley</li><li>Phyllis</li><li>Creed</li><li>Kevin</li><li>Oscar</li><li>Angela</li><li>Meredith</li><li>Kelly</li><li>Ryan</li><li>Toby</li></ul>");
	});

	QPushButton* plainTextGrabber = new QPushButton("Grab plain text", this);
	plainTextGrabber->setMinimumSize(70, 25);
	plainTextGrabber->move(15, 340);
	connect(plainTextGrabber, &QPushButton::clicked, [=] {
		QMessageBox::information(this, "Plain text:", textEdit->toPlainText(), QMessageBox::Ok);
	});

	QPushButton* HtmlGrabber = new QPushButton("Grab html", this);
	HtmlGrabber->setMinimumSize(50, 25);
	HtmlGrabber->move(100, 340);
	connect(HtmlGrabber, &QPushButton::clicked, [=] {
		QMessageBox::information(this, "Html:", textEdit->toHtml(), QMessageBox::Ok);
	});
}

Widget::~Widget() {

}