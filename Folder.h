#ifndef FOLDER_H
#define FOLDER_H

#include "Element.h"

class File;
class Shortcut;

class Folder : public Element
{
    Q_OBJECT
    mutable Size size {-1};
    void invalidateSize();
protected:
    explicit Folder(const QString& name, Folder *parent = 0);
    virtual void on_element_displayed(QTextStream &ts, const QString &tab);
public:
    Folder* addFolder(const QString &name);
    File* addFile(const QString &name, Size size);
    Shortcut* addLink(const QString &name, Element &element);

    Element *getElement(const QString &name) const;

    virtual Size getSize() const;

    friend class Element;
signals:
};

#endif // FOLDER_H
