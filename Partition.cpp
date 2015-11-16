#include "Partition.h"


Partition::Partition(const QString &name, Size capacity) :
    Folder { name,0 },
    capacity{ capacity }
{
}

Partition &Partition::instance(const QString &name, Size capacity)
{
    static Partition partition {name, capacity};
    return partition;
}

Size Partition::getCapacity() const
{
    return capacity;
}
