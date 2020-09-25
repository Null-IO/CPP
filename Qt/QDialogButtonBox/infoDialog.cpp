#include "infoDialog.h"
#include <QAbstractButton>
#include <QMessageBox>

infoDialog::infoDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	connect(ui.buttonBox, &QDialogButtonBox::clicked, [&](QAbstractButton* button) {
		QDialogButtonBox::StandardButton stdbutton = ui.buttonBox->standardButton(button);

		switch (stdbutton) {
		case QDialogButtonBox::Ok:
			accept();
			break;
		case QDialogButtonBox::Cancel:
			reject();
			break;
		case QDialogButtonBox::Yes:
			QMessageBox::information(this, "Info", "Yes button pressed");
			break;
		case QDialogButtonBox::Open:
			QMessageBox::information(this, "Info", "Open button pressed");
			break;
		case QDialogButtonBox::Save:
			QMessageBox::information(this, "Info", "Save button pressed");
			break;
		default:
			break;
		}
	});
}

infoDialog::~infoDialog()
{
}
