#ifndef VHELIX_H
#define VHELIX_H

#include <QVector>

#include "cnobject.h"
#include "part.h"

class VirtualHelix : public CNObject
{
    Q_OBJECT
public:
    enum StrandType {
        Staple, Scaffold
    };

    VirtualHelix();
    VirtualHelix( Part *part, uint row, uint column);

    bool isDrawn5to3(StrandType ss_idx);
    bool isEvenParity();

    CNObject *part();

    void setNumber();

private:
    QVector<uint> m_strands;    // array of strand id's
    CNObject *m_part;
    Document *m_doc;
    QVector<uint> m_scaffold_ss;
    QVector<uint> m_staple_ss;
    uint m_number;
    coord_t m_coord;

signals:
    virtualHelixRemovedSignal(QObject *);  // self
    virtualHelixNumberChangedSignal(QObject *, uint); // self, num
}

#endif // VHELIX_H
