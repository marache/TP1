#ifndef FOLDER_H
#define FOLDER_H

#include "Element.h"

class File;

class Folder Q_DECL_FINAL : public Element
{
    Q_OBJECT
    explicit Folder(const QString& name, Folder *parent = 0);
    mutable int size {-1};
public:
    static Folder &getRoot();

    Folder* addFolder(const QString &name);
    File* addFile(const QString &name, int size);

    Element *getElement(const QString &name) const;

    virtual int getSize() const;

signals:

public slots:
    void invalidateSize();
};

#endif // FOLDER_H
