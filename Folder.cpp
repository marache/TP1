#include "Partition.h"
#include "File.h"

#include <QException>

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
        QException().raise();

    if ((Partition::instance().getSize() + size) > Partition::instance().getCapacity())
         QException().raise();

    File *f = new File(name, size, *this);
    connect(f, &QObject::destroyed, this, &Folder::invalidateSize);

    return f;
}

Element *Folder::getElement(const QString &name) const
{
    return findChild<Element *>(name,Qt::FindDirectChildrenOnly);
}

int Folder::getSize() const
{
    if (size == -1)
    {
        size = 0;
        for(File *o : findChildren<File *>())
        {
            size += o->getSize();
        }
    }
    return size;
}

void Folder::invalidateSize()
{
    size = -1;
    if(parent())
    {
        qobject_cast<Folder*>(parent())->invalidateSize();
    }
}

Folder::Folder(const QString &name, Folder *parent)  : Element(name, parent)
{
}

