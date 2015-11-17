#include "Shortcut.h"
#include "Folder.h"
#include <QException>

Shortcut::Shortcut(const QString &name, Element &element, Folder &parent) :
    Element(name, &parent),
    link(&element)
{
    if (element.metaObject() == this->metaObject())
        QException().raise();
}

void Shortcut::on_element_displayed(QTextStream &ts, const QString &)
{
    ts << " --> " << (link ? link->getAbsolutePath() : QStringLiteral("Nothing")) << endl;
}

