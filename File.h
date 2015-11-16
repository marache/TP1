#ifndef FILE_H
#define FILE_H

#include "Element.h"

class Folder;

class File Q_DECL_FINAL : public Element
{
    Q_OBJECT
    File(const QString &name, Size size, Folder &parent);
    Size size;
public:
    virtual Size getSize() const { return size; }
    friend class Folder;

signals:

public slots:
};

#endif // FILE_H
