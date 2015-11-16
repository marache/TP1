#ifndef PARTITION_H
#define PARTITION_H

#include "Folder.h"

class Partition Q_DECL_FINAL : public Folder
{
    Partition(const QString& name, Size capacity);
    ~Partition() = default;
    int capacity;
public:
    static Partition& instance(const QString &name = QStringLiteral("C:"), Size capacity = 1024*1024*1024);
    virtual Size getCapacity() const;
};

#endif // PARTITION_H
