#include "cnobject.h"

void CNObject::CNObject(Document *doc) : m_document(old_uuid), m_uuid(doc->getUUID()) {
}

Document * CNObject::document() { return m_document; }

uint CNObject::uuid() { return m_uuid; }
