#include "Widget.h"
#include <QMessageBox>
#include <vector>

std::random_device seed;
std::mt19937 engine(seed());

QString Widget::randStr(std::mt19937& engine) {
	QString randS = "";
	size_t randLen = std::uniform_int_distribution<int>(15, 30)(engine);
	for (size_t i = 0; i < randLen; i++) {
		std::vector<int> randNums;
		randNums.push_back(std::uniform_int_distribution<int>(65, 90)(engine));
		randNums.push_back(std::uniform_int_distribution<int>(97, 122)(engine));
		randNums.push_back(std::uniform_int_distribution<int>(48, 57)(engine));
		randS.append(static_cast<char>(randNums[std::uniform_int_distribution<int>(0, 2)(engine)]));
	}
	return randS;
}

Widget::Widget(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	ui.listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

	connect(ui.addItem, &QPushButton::clicked, [&] {
		ui.listWidget->addItem(randStr(engine));
		ui.listWidget->scrollToBottom();
	});

	connect(ui.deleteItem, &QPushButton::clicked, [=] {
		QList<QListWidgetItem*> items = ui.listWidget->selectedItems();
		if (items.count() == 0) {
			ui.listWidget->scrollToTop();
			ui.listWidget->takeItem(0);
		}
		else
			qDeleteAll(items);
	});

	connect(ui.selectItems, &QPushButton::clicked, [=] {
		QString sItems = "";
		QList<QListWidgetItem*> items = ui.listWidget->selectedItems();
		for (size_t i = 0; i < items.count(); i++)
			sItems += items[i]->text() + "\n";
		
		if(items.count() == 0)
			QMessageBox::information(this, "Info", "Nothing is selected");
		else
			QMessageBox::information(this, "Info", "Selected items:\n" + sItems);
	});
}

Widget::~Widget() {

}