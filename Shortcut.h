#ifndef SHORTCUT_H
#define SHORTCUT_H

#include "Element.h"

#include <QPointer>

class Shortcut Q_DECL_FINAL : public Element
{
    Q_OBJECT
    QPointer<Element> link;
    Shortcut(const QString& name, Element &element, Folder &parent);
    virtual Size getSize() const { return 0; }
    void on_element_displayed(QTextStream &ts, const QString &);
public:
    friend class Folder;
};

#endif // SHORTCUT_H
