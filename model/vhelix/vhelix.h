#ifndef VHELIX_H
#define VHELIX_H

#include <QVector>
#include <QUndoStack>

#include "model/cnobject.h"
#include "model/part/part.h"

class VirtualHelix : public CNObject
{
    Q_OBJECT
public:
    enum StrandType {
        Staple, Scaffold
    };

    VirtualHelix();
    VirtualHelix( Part *part, uint row, uint column);
//    ~VirtualHelix();

    bool isDrawn5to3(StrandType ss_idx);
    bool isEvenParity();

    Part *part();
    void setPart(Part *new_part);

    uint number();
    void setNumber(uint number);

    QVector<uint> & scaffoldStrandSet();
    QVector<uint> & stapleStrandSet();

    QUndoStack *undoStack();

    bool scaffoldIsOnTop();

    QVector<uint> & getStrandSetByIdx(uint idx);

    QVector<uint> & getStrandSetByType(StrandType strand_type);

    uint indexOfRightmostNonemptyBase();

    void remove(bool use_undostack=true);

private:
    QVector<uint> m_strands;    // array of strand id's
    Part *m_part;
    Document *m_doc;

    QVector<uint> m_scaffold_ss;
    QVector<uint> m_staple_ss;
    uint m_number;
    coord_t m_coord;

    uint maxNonZeroIdx(QVector<uint> &ss);

signals:
    void virtualHelixRemovedSignal(QObject *);  // self
    void virtualHelixNumberChangedSignal(QObject *, uint); // self, num
};

#endif // VHELIX_H
