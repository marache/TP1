#ifndef FILE_H
#define FILE_H

#include "Element.h"

class Folder;

class File Q_DECL_FINAL : public Element
{
    Q_OBJECT
    File(const QString &name, int size, Folder &parent);
    int _size;
public:
    virtual int getSize() const { return _size; }
    friend class Folder;

signals:

public slots:
};

#endif // FILE_H
