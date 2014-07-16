#ifndef VHELIX_H
#define VHELIX_H

#include <QVector>

#include "cnobject.h"
#include "part.h"

class VirtualHelix : public CNObject
{
    Q_OBJECT
public:
    VirtualHelix();
    VirtualHelix( Part *part, uint row, uint column);

    CNObject *part();

    void setNumber();

private:
    QVector<uint> m_strands;    // array of strand id's
    CNObject * m_part;
    Document *m_doc;
    StrandSet *m_scaffold_ss;
    StrandSet *m_staple_ss;
    uint m_number;
    coord_t m_coord;

signals:
    virtualHelixRemovedSignal(QObject *);  // self
    virtualHelixNumberChangedSignal(QObject *, uint); // self, num
}

#endif // VHELIX_H
