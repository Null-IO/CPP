#pragma once

#include <QDialog>
#include "ui_InfoDialog.h"

class InfoDialog : public QDialog {
	Q_OBJECT

public:
	InfoDialog(QWidget *parent = Q_NULLPTR);
	const QString& pos() const;
	const QString& fav() const;
	~InfoDialog();
private:
	Ui::InfoDialog ui;
	QString position;
	QString favOS;
};
