#include <QApplication>
#include "desktopgo.h"

#include <QWindow>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    DesktopGo go;
    go.show();
    return app.exec();
}