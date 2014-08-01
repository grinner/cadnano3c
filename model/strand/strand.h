#ifndef STRAND_H
#define STRAND_H

#include "model/cnobject.h"
#include "model/vhelix/vhelix.h"

class Strand : public CNObject
{
    Q_OBJECT
public:
    explicit Strand(CNObject *parent = 0);
    QVector<uint> * strandSet();
private:
    QVector<uint> *m_strandset;
signals:

public slots:

};

#endif // STRAND_H
