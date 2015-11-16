#ifndef PARTITION_H
#define PARTITION_H

#include "Folder.h"

class Partition Q_DECL_FINAL : public Folder
{
    Partition(const QString& name, int capacity);
    ~Partition() = default;
    int capacity;
public:
    static Partition& instance();
    virtual int getCapacity() const;
};

#endif // PARTITION_H
