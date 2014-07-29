#include "vhelix.h"

bool VirtualHelix::isDrawn5to3(StrandType ss_idx) {
    bool isScaf = ss_idx == Scaffold;
    bool isEven = isEvenParity();
    return isEven == isScaf;
}

bool VirtualHelix::isEvenParity() {
    return m_part->isEvenParity(m_coord);
}


CNObject *VirtualHelix::part(){
    return m_part;
}

void VirtualHelix::setPart(CNObject *new_part) {
    m_part = new_part;
    setParent(new_part);
}

uint VirtualHelix::number() {
    return m_number;
}

void VirtualHelix::setNumber(uint number) {
    m_number = number;
}

QVector<uint> & VirtualHelix::scaffoldStrandSet() {
    return m_scaffold_ss;
}

QVector<uint> & VirtualHelix::stapleStrandSet() {
    return m_staple_ss;
}

QUndoStack * VirtualHelix::undoStack() {
    return m_part->undoStack();
}

bool VirtualHelix::scaffoldIsOnTop() {
    return isEvenParity();
}

QVector<uint> & VirtualHelix::getStrandSetByIdx(uint idx) {
    /* This is a path-view-specific accessor
     * idx == 0 means top strand
     * idx == 1 means bottom strand
     */
     if (idx == 0) {
        if (isEvenParity()) {
            return m_scaffold_ss;
        } else {
            return m_staple_ss;
        }
    } else {
        if (isEvenParity()) {
            return m_staple_ss;
        } else {
            return m_scaffold_ss;
        }
    }
}

QVector<uint> & VirtualHelix::getStrandSetByType(StrandType strand_type) {
    if (strand_type == Scaffold ) {
        return m_scaffold_ss;
    } else {
        return m_staple_ss;
    }
}

uint VirtualHelix::maxNonZeroIdx(QVector<uint> & ss) {
    uint max_idx = 0;
    for (int i = 0; i < ss.size(); ++i) {
        if (ss.at(i) != 0 ) {
            max_idx = i;
        }
    }
    return max_idx;
}

uint VirtualHelix::indexOfRightmostNonemptyBase() {
    uint a = maxNonZeroIdx(m_scaffold_ss);
    uint b = maxNonZeroIdx(m_staple_ss);
    return std::max(a,b);
}

void VirtualHelix::remove(bool use_undostack=true) {
    QUndoStack *us = undoStack();
    if (use_undostack) {
        us->beginMacro("Delete Virtual Helix");
    }
    QUndoCommand c = RemoveVirtualHelixCommand(m_part, this);
    if (use_undostack) {
        us->push(c);
        us->endMacro();
    } else {
        c.redo();
    }
}
