#ifndef ADDPARTCOMMAND_H
#define ADDPARTCOMMAND_H

#include <QUndoCommand>
#include "model/document/document.h"
#include "model/part/part.h"

class AddPartCommand : public QUndoCommand
{
public:
    AddPartCommand(Document *doc, Part *part);
    virtual void redo();
    virtual void undo();
private:
    Document *m_doc;
    Part *m_part;
};

#endif // ADDPARTCOMMAND_H
