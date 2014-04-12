#include <QApplication>
#include "buffer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Buffer w;
    w.show();
    
    return a.exec();
}
