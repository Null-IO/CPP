#include "InfoDialog.h"

InfoDialog::InfoDialog(QWidget *parent) : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint) { //Grays out Close button and deletes ? mark
	ui.setupUi(this);

	connect(ui.OkPushButton, &QPushButton::clicked, [&] {
		QString lineEdit = ui.posLineEdit->text();
		if (lineEdit.count() != 0)
			position = "Position: " + lineEdit + "\n";
		else
			position = "Position: N/A\n";
		
		QList<QRadioButton*> radios{ ui.winRadioButton, ui.lnxRadioButton, ui.macRadioButton };
		favOS = "Favourite OS: N/A\n";
		for (auto& it : radios)
			if (it->isChecked())
				favOS = "Favourite OS: " + it->text() + "\n";

		accept();
	});
	connect(ui.cancelPushButton, &QPushButton::clicked, [&] {
		reject();
	});
}

const QString& InfoDialog::pos() const {
	return position;
}

const QString& InfoDialog::fav() const {
	return favOS;
}

InfoDialog::~InfoDialog()
{
}
