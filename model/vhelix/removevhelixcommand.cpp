#include "removevhelixcommand.h"

RemoveVirtualHelixCommand::RemoveVirtualHelixCommand(Part *part, VirtualHelix *vh)
    : m_part(part), m_vh(vh)
{
    m_id_num = vh->number();
    // is the number even or odd?  Assumes a valid idNum, row,col combo
    m_is_parity_even = (m_id_num % 2) == 0;
    setText("Delete VirtualHelix");
}

virtual void RemoveVirtualHelixCommand::redo() {
     m_part->_removeVirtualHelix(vh);
     m_part->_recycleHelixIDNumber(m_id_num);
     // clear out part references
     emit m_vh->virtualHelixRemovedSignal(m_vh);
     emit m_part->partActiveSliceResizeSignal(m_part);
     // vh->setPart(0);
     // vh->setNumber(0);
}

virtual void RemoveVirtualHelixCommand::undo() {
    m_vh->setPart(m_part);
    m_part->_addVirtualHelix(m_vh);
    // vh.setNumber(m_id_num);
    if (!m_vh->number()) {
        m_part->_reserveHelixIDNumber(m_is_parity_even, requested_id_num=id_num);
    }
    emit m_part->partVirtualHelixAddedSignal(m_part, m_vh);
    emit m_part->partActiveSliceResizeSignal(m_part);
}
