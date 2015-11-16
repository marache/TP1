#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>

class Folder;

class Element : public QObject
{
    Q_OBJECT

public:
    QString getAbsolutePath() const;
    virtual int getSize() const =0;
signals:

public slots:

protected:
    explicit Element(const QString &name, Folder *parent = nullptr);
};

#endif // ELEMENT_H
