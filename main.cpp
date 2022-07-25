#include "gesturewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestureWidget w;
    w.showFullScreen();

    return a.exec();
}
