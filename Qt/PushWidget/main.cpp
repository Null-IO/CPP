#include "PushWidget.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PushWidget w;
    w.show();
    return a.exec();
}
