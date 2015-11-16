#ifndef FOLDER_H
#define FOLDER_H

#include "Element.h"

class File;

class Folder : public Element
{
    Q_OBJECT
    mutable int size {-1};
    void invalidateSize();
protected:
    explicit Folder(const QString& name, Folder *parent = 0);

public:
    Folder* addFolder(const QString &name);
    File* addFile(const QString &name, int size);

    Element *getElement(const QString &name) const;

    virtual int getSize() const;

    friend class Element;
signals:
};

#endif // FOLDER_H
