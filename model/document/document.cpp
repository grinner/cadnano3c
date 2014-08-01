#include "document.h"

Document::Document() : QObject(), m_id_counter(0) {
//   app.documentWasCreatedSignal();
//    m_undostack(this);
    m_undostack.setUndoLimit(10);
}

QUndoStack *Document::undoStack() { return &m_undostack; }
const QVector<CNObject *>& Document::parts() { return m_parts; }
const QVector<CNObject *> &Document::assemblies() { return m_assemblies; }
CNObject * Document::selectedPart() { return m_selected_part; }

void Document::setSelectedPart(CNObject *part) {
    m_selected_part = part;
}

void Document::addToSelection(CNObject *obj, endpts_select_t value) {
//    m_selection_dict[obj] = value;
//    m_selected_changed_dict[obj] = value;
}

uint Document::getUUID() {
    if (m_used_ids.empty()) {
        return m_id_counter++;
    } else {
        uint ret = m_used_ids.last();
        m_used_ids.pop_back();
        return ret;
    }
}

void Document::recycleUUID(uint id) {
    m_used_ids.push_back(id);
}

bool Document::removeFromSelection(CNObject *obj) {
//        if (m_selection_dict.contains(obj)) {
//            m_selection_dict.remove(obj);
//            m_selected_changed_dict[obj] = qMakePair(false, false);
//            return true;
//        } else {
//            return false;
//        }
}

void Document::clearSelections() {

}

void Document::addStrandToSelection(CNObject *strand, endpts_select_t value) {
//       CNObject *sS = (CNObject *) strand->strandSet();
//       if (!m_selection_dict.contains(sS)) {
//           m_selection_dict.insert(sS, new CNStrandSelectHash_t());
//       }
//       m_selection_dict.value(sS)[strand] = value;
//       m_selected_changed_dict[strand] = value;
}

bool Document::removeStrandFromSelection(CNObject *strand) {
//    CNObject *sS = (CNObject *) strand->strandSet();
//    if (m_selection_dict.contains(sS)) {
//        CNStrandSelectHash_t *temp = m_selection_dict.value(sS);
//        if (temp->contains(strand)) {
//            temp->remove(strand);
//            if (temp->empty()) {
//                delete temp;    // free memory
//                m_selection_dict.remove(sS);
//            }
//            m_selected_changed_dict[strand] = qMakePair(false, false);
//            return true;
//        } else {
//            return false;
//        }
//    } else {
//        return false;
//    }
}

QSet<CNObject *> &Document::selectedOligos() {
    m_selected_oligos.clear();
    return m_selected_oligos;
}

void Document::addPartToList(CNObject *part) {
    m_parts.push_back(part);
}

void Document::removePartFromList(CNObject *part) {
       emit documentClearSelectionSignal();
       int idx = m_parts.indexOf(part);
       if (idx < 0) {
           // not there
       } else {
           m_parts.remove(idx);
       }
}
