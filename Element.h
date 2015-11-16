#ifndef ELEMENT_H
#define ELEMENT_H

#include "LocalTypes.h"

#include <QObject>
#include <QTextStream>

class Folder;

class Element : public QObject
{
    Q_OBJECT

public:
    QString getAbsolutePath() const;
    virtual Size getSize() const =0;

    void display(QTextStream& ts, const QString& tab=QStringLiteral("") );
    virtual void on_element_displayed(QTextStream& ts, const QString& tab) { Q_UNUSED(ts); Q_UNUSED(tab);}

signals:

public slots:

protected:
    explicit Element(const QString &name, Folder *parent = nullptr);
};

#endif // ELEMENT_H
