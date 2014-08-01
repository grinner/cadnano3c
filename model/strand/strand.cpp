#include "strand.h"

Strand::Strand(CNObject *parent) :
    CNObject(parent)
{
}

Strand::strandSet() {
    return m_strandset;
}
