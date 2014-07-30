#ifndef ADDPARTCOMMAND_H
#define ADDPARTCOMMAND_H

#include <QUndoCommand>

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
