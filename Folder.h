#ifndef FOLDER_H
#define FOLDER_H

#include "Element.h"

class File;

class Folder Q_DECL_FINAL : public Element
{
    Q_OBJECT
public:
    static Folder &getRoot();

    Folder* addFolder(const QString &name);
    File* addFile(const QString &name, int size);

    Element *getElement(const QString &name) const;

    virtual int getSize() const;

signals:

public slots:

protected:
    explicit Folder(const QString& name, Folder *parent = 0);
};

#endif // FOLDER_H
