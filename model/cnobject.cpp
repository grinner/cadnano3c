#include "cnobject.h"

CNObject::CNObject(Document *doc) : QObject(doc), m_document(doc) {
    m_uuid = doc->getUUID();
}

CNObject::CNObject(CNObject *parent) : QObject(parent), m_document(parent->document()) {
    m_uuid = m_document->getUUID();
}

Document * CNObject::document() { return m_document; }

void CNObject::setDocument(Document *doc) {
    m_document = doc;
}

uint CNObject::uuid() const { return m_uuid; }

QUndoStack * CNObject::undoStack() {
    return m_document->undoStack();
}
