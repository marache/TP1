#include "Folder.h"
#include "File.h"

#include <QException>

Folder &Folder::getRoot()
{
    static Folder root(QStringLiteral("c:"));
    return root;
}

Folder *Folder::addFolder(const QString &name)
{
    Q_ASSERT(!name.isEmpty());
    Q_ASSERT(findChildren<Element*>(name,Qt::FindDirectChildrenOnly).empty());

    Folder * f = new Folder(name, this);
    return f;
}

File *Folder::addFile(const QString &name, int size)
{
    if (getElement(name))
        QException.raise();

    return new File(name, size, *this);
}

Element *Folder::getElement(const QString &name) const
{
    return findChild<Element *>(name,Qt::FindDirectChildrenOnly);
}

int Folder::getSize() const
{
    int size {0};
    for(QObject *o : findChildren<File *>())
    {
        size += qobject_cast<Element *>(o)->getSize();
    }
    return size;
}

Folder::Folder(const QString &name, Folder *parent)  : Element(name, parent)
{
}

