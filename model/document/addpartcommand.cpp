#include "addpartcommand.h"

AddPartCommand::AddPartCommand(Document *doc, Part *part) :
    m_doc(doc), m_part(part)
{
}

void AddPartCommand::redo() {
    if (m_doc->parts() == 0) {
        m_doc->addPartToList(m_part);
        m_part->setDocument(m_doc);
        m_doc->setSelectedPart(m_part);
        emit m_doc->documentPartAddedSignal(m_doc, m_part);
     }
}

void AddPartCommand::undo() {
    m_doc->removePartFromList(m_part);
    m_part->setDocument(0);
    m_doc->setSelectedPart(0);
    emit m_part.partRemovedSignal(m_part);
}
