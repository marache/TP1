#include "Element.h"
#include "Folder.h"

#include <cassert>

QString Element::getAbsolutePath() const
{
    QString path;
    if(parent())
    {
        path = qobject_cast<Element*>(parent())->getAbsolutePath() + QStringLiteral("/");
    }

    path += objectName();

    return path;
}

void Element::display(QTextStream &ts, const QString &tab)
{
    ts << tab << metaObject()->className() << " : " << objectName();
    on_element_displayed(ts,tab);
    ts << "\n";
}

Element::Element(const QString &name, Folder *parent) : QObject(parent)
{
    setObjectName(name);
    if (parent)
    {
        connect(this, &QObject::destroyed, parent, &Folder::invalidateSize);
    }
}

