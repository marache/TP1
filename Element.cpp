#include "Element.h"

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

Element::Element(const QString &name, QObject *parent) : QObject(parent)
{
    setObjectName(name);
}

