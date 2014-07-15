#ifndef CNOBJECT_H
#define CNOBJECT_H

#include <QObject>
#include "document.h"

class CNObject : public QObject
{
    Q_OBJECT
public:
    CNObject(Document *);
    uint uuid();
    Document * document();

private:
    uint m_uuid;
    Document *m_document;
};

inline bool operator==(const CNObject &cno1, const CNObject &cno2)
{
    return cno1.uuid() == cno2.uuid();
}

inline uint qHash(const CNObject &key)
{
    return qHash(key.uuid());
}

#endif // CNOBJECT_H
