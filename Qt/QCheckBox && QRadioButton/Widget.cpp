#include "Widget.h"
#include <QButtonGroup>
#include <QMessageBox>

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);

	QButtonGroup* buttonGroup = new QButtonGroup(this);
	buttonGroup->addButton(ui.windowsCheckbox);
	buttonGroup->addButton(ui.linuxCheckbox);
	buttonGroup->addButton(ui.macCheckbox);
	buttonGroup->setExclusive(true); //sets exclusivity
	static bool wasRevealed = false;

	connect(ui.okButton, &QPushButton::clicked, [=] {
		if (wasRevealed) {
			QMessageBox::critical(this, "Results", "You have cheated :@", QMessageBox::Ok);
			return;
		}

		unsigned int correctAns = 0;
		QString str = "Choose OS -> ";
		if (ui.macCheckbox->isChecked()) {
			str += "Correct answer\n";
			correctAns++;
		}
		else
			str += "Incorrect answer\n";

		str += "Choose GPU manufacturers -> ";
		if (ui.NvidiaCheckBox->isChecked() && ui.AMDCheckbox->isChecked()) {
			str += "Correct answer\n";
			correctAns++;
		}
		else
			str += "Incorrect answer\n";

		str += "Select valid programming language -> ";
		if (ui.CppRadio->isChecked()) {
			str += "Correct answer\n";
			correctAns++;
		}
		else
			str += "Incorrect answer\n";

		if (correctAns == 0)
			str = "You have got everything incorrect :(";
		else if (correctAns == 3)
			str = "You have got everything right :)";

		QMessageBox::information(this, "Results", str, QMessageBox::Ok);
	});

	connect(ui.revealButton, &QPushButton::clicked, [&] {
		ui.macCheckbox->setChecked(true);
		if (ui.IBMCheckbox->isChecked())
			ui.IBMCheckbox->setChecked(false);
		if (ui.IntelCheckbox->isChecked())
			ui.IntelCheckbox->setChecked(false);
		
		ui.NvidiaCheckBox->setChecked(true);
		ui.AMDCheckbox->setChecked(true);
		ui.CppRadio->setChecked(true);
		wasRevealed = true;
	});
}

Widget::~Widget() {

}