#include "Partition.h"


Partition::Partition(const QString &name, int capacity) :
    Folder(name,0),
    capacity(capacity)
{
}

Partition::~Partition()
{
}

Partition &Partition::instance()
{
    static Partition partition { QStringLiteral("C:"), 123456 };
    return partition;
}

int Partition::getCapacity() const
{
    return capacity;
}
