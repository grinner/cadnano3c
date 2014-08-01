#ifndef PART_H
#define PART_H

#include <QObject>
#include "common.h"
#include "model/document/document.h"
#include "model/cnobject.h"

class Part : public CNObject {
    Q_OBJECT
public:
    explicit Part(Document *doc);
    bool isEvenParity(coord_t);

    uint getVHID();
    void recycleVHID(uint id);

    void _removeVirtualHelix(CNObject *virtual_helix);
    void _recycleHelixIDNumber(uint id_num);
    void _addVirtualHelix(CNObject *virtual_helix);
    void _reserveHelixIDNumber(bool is_parity_even, int requested_id_num=-1);


private:
    QHash<CNObject, CNObject> strands_dict;
    QVector<uint> m_used_ids;
    uint m_id_counter;

signals:
    void partActiveSliceIndexSignal(QObject *, int); // self, index
    void partActiveSliceResizeSignal(QObject *); // self
    void partDimensionsChangedSignal(QObject *); // self
    void partInstanceAddedSignal(QObject *); // self
    void partParentChangedSignal(QObject *); // self
    void partPreDecoratorSelectedSignal(QObject *, int, int, int);  // row,col,idx
    void partRemovedSignal(QObject *); // self
    void partStrandChangedSignal(QObject *, QObject *); // self, virtualHelix
    void partVirtualHelixAddedSignal(QObject *, QObject *); // self, virtualhelix
    void partVirtualHelixRenumberedSignal(QObject *, coord_t); // self, coord
    void partVirtualHelixResizedSignal(QObject *, coord_t); //self, coord
    void partVirtualHelicesReorderedSignal(QObject *, QObject *); // self, list of coords
    void partHideSignal(QObject *);
    void partActiveVirtualHelixChangedSignal(QObject *, QObject *);
    void partModAddedSignal(QObject *, QObject *, QObject *);
    void partModRemovedSignal(QObject *, QObject *);
    void partModChangedSignal(QObject *, QObject *, QObject *);
};

#endif // PART_H
