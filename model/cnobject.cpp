#include "cnobject.h"

void CNObject::CNObject(Document *doc) : QObject(doc), m_document(doc), m_uuid(doc->getUUID()) {
}

void CNObject::CNObject(CNObject *parent) : QObject(parent), m_document(parent->document()), m_uuid(m_document->getUUID()) {
}


Document * CNObject::document() { return m_document; }

uint CNObject::uuid() { return m_uuid; }
