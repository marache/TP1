#ifndef FILE_H
#define FILE_H

#include "Element.h"

class Folder;

class File Q_DECL_FINAL : public Element
{
    Q_OBJECT
public:
    virtual int getSize() const { return _size; }

signals:

public slots:

private:
    friend class Folder;
    File(const QString &name, int size, Folder &parent);
    int _size;
};

#endif // FILE_H
