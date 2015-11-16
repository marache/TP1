#include "File.h"
#include "Folder.h"

File::File(const QString &name, int size, Folder &parent) : Element(name, &parent)
{
    _size = size;
}

