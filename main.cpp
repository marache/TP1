#include "Partition.h"
#include "File.h"

#include <QCoreApplication>

#include <QDebug>

#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Folder& root{ Partition::instance() };
    root.addFile(QStringLiteral ("autoexec.bat"), 5000);
    Folder* r1{ root.addFolder(QStringLiteral ("winnt")) };
    r1->addFile(QStringLiteral ("win.ini"), 300);
    r1->addFile(QStringLiteral ("system.ini"), 7000);
    r1->addFolder(QStringLiteral("system32"));
    Folder* r2{ root.addFolder(QStringLiteral("temp")) };
    r2->addFile(QStringLiteral("tmp1.dat"), 645);
    auto file = r2->addFile(QStringLiteral("myDoc.txt"), 10000);

    qDebug() << root.getSize() << "octets";
    delete r1->getElement (QStringLiteral("win.ini"));
    qDebug() << root.getSize() << "octets";
    qDebug() << root.getSize() << "octets";
    qDebug() << file->getAbsolutePath();





    return a.exec();
}

