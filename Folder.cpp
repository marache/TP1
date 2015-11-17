#include "Partition.h"
#include "File.h"
#include "Shortcut.h"

#include <QException>
#include <QDebug>

Folder *Folder::addFolder(const QString &name)
{
    Q_ASSERT(!name.isEmpty());
    Q_ASSERT(findChildren<Element*>(name,Qt::FindDirectChildrenOnly).empty());

    return new Folder(name, this);
}

File *Folder::addFile(const QString &name, Size size)
{
    if (getElement(name))
        QException().raise();

    if ((Partition::instance().getSize() + size) > Partition::instance().getCapacity())
         QException().raise();

    invalidateSize();

    return new File(name, size, *this);
}

Shortcut *Folder::addLink(const QString &name, Element &element)
{
    if (getElement(name))
        QException().raise();

    return new Shortcut(name, element, *this);
}

Element *Folder::getElement(const QString &name) const
{
    return findChild<Element *>(name,Qt::FindDirectChildrenOnly);
}

Size Folder::getSize() const
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
    // qDebug() << "[DEBUG] invalidatingSize " << objectName();
    size = -1;
    if(parent())
    {
        qobject_cast<Folder*>(parent())->invalidateSize();
    }
}

Folder::Folder(const QString &name, Folder *parent) :
    Element { name, parent }
{
}

void Folder::on_element_displayed(QTextStream &ts, const QString &tab)
{
    ts << "\n";
    for(Element *o : findChildren<Element *>(QString(),Qt::FindDirectChildrenOnly))
    {
       o->display(ts,tab + "  ");
    }
}

