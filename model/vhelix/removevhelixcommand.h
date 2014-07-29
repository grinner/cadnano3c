#ifndef REMOVEVHELIXCOMMAND_H
#define REMOVEVHELIXCOMMAND_H

#include <QUndoCommand>
#include "vhelix.h"
#include "model/part/part.h"

class RemoveVirtualHelixCommand : public QUndoCommand {
public:
    RemoveVirtualHelixCommand(Part *part, VirtualHelix *vh);
    virtual void redo();
    virtual void undo();

private:
    Part *m_part;
    VirtualHelix *m_vh;
    uint m_id_num;
    bool m_is_parity_even;
};

#endif // REMOVEVHELIXCOMMAND_H
