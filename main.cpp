#include "lissajous.h"
#include <QApplication>
#include "DarkStyle/framelesswindow/framelesswindow.h"
#include "DarkStyle/DarkStyle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new DarkStyle);

    FramelessWindow framelessWindow;


    Lissajous *lissajous = new Lissajous;
    framelessWindow.setWindowTitle("Lissajous Curve");
    framelessWindow.setContent(lissajous);
    framelessWindow.show();

    return a.exec();
}
