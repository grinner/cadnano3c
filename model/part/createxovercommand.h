#ifndef CREATEXOVERCOMMAND_H
#define CREATEXOVERCOMMAND_H

#include <QUndoCommand>
#include "model/part/part.h"
#include "model/strand/strand.h"
#include "model/oligo/oligo.h"

class CreateXoverCommand : public QUndoCommand
{
public:
    CreateXoverCommand(Part *part,
                       Strand *strand5p, uint strand5p_idx,
                       Strand *strand3p, uint strand3p_idx,
                       bool update_oligo=true);
    virtual void redo();
    virtual void undo();

private:
    Part *m_part;
    Strand *m_strand5p;
    uint m_strand5p_idx;
    Strand *m_strand3p;
    uint m_strand3p_idx;

    Oligo *m_old_oligo_3p;
    bool m_update_oligo;
};

#endif // CREATEXOVERCOMMAND_H
