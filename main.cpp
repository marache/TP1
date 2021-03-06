#include "Partition.h"
#include "File.h"

#include <QCoreApplication>

#include <QDebug>

#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Folder& root{ Partition::instance(QStringLiteral("C:")) };
    root.addFile(QStringLiteral ("autoexec.bat"), 5000);
    Folder* r1{ root.addFolder(QStringLiteral ("winnt")) };
    r1->addFile(QStringLiteral ("win.ini"), 300);
    r1->addFile(QStringLiteral ("system.ini"), 7000);
    r1->addFolder(QStringLiteral("system32"));
    Folder* r2{ root.addFolder(QStringLiteral("temp")) };
    r2->addFile(QStringLiteral("tmp1.dat"), 645);
    auto file = r2->addFile(QStringLiteral("myDoc.txt"), 10000);

    r2->addLink(QStringLiteral("racourci vers myDoc.txt"), *file);

    qDebug() << root.getSize() << "octets";
    delete r1->getElement (QStringLiteral("win.ini"));
    qDebug() << root.getSize() << "octets";
    qDebug() << file->getAbsolutePath();

    QTextStream ts(stderr);
    root.display(ts);
    ts.flush();

    delete file;
    qDebug() << root.getSize() << "octets";


    root.display(ts);
    ts.flush();

    return a.exec();
}

