#include "File.h"
#include "Folder.h"

File::File(const QString &name, Size size, Folder &parent) :
    Element { name, &parent},
    size {size}
{
    size = size;
}

