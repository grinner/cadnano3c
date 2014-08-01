#include "strand.h"

Strand::Strand(CNObject *parent) :
    CNObject(parent)
{
}

QVector<uint> *Strand::strandSet() {
    return m_strandset;
}
