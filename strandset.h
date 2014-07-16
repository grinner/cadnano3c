#ifndef STRANDSET_H
#define STRANDSET_H

#include "cnobject.h"
#include "vhelix.h"

class StrandSet : public CNObject
{
    Q_OBJECT
public:
    enum StrandType {
        Staple, Scaffold
    };

    StrandSet();
    StrandSet( StrandType strand_type, VirtualHelix virtual_helix);

private:
    QVector<uint> m_strands;    // array of strand id's
signals:
    void strandsetStrandAddedSignal(QObject, QObject);
}
#endif // STRANDSET_H
