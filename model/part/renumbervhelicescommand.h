#ifndef RENUMBERVHELICESCOMMAND_H
#define RENUMBERVHELICESCOMMAND_H

#include <QVector>
#include "model/part/part.h"
#include "model/vhelix/vhelix.h"
#include "common.h"

class RenumberVirtualHelicesCommand : public QUndoCommand {
public:
    RenumberVirtualHelicesCommand(Part *part, QVector<coord_t> &coord_list);
    virtual void redo();
    virtual void undo();

private:
    Part *m_part;
    QVector<VirtualHelix *> m_vhs;
    QVector<uint> m_old_numbers;
};


#endif // RENUMBERVHELICESCOMMAND_H
