#include "document.h"

void Document::Document() : QObject(), m_id_counter(0) {
//   app.documentWasCreatedSignal();
}

QUndoStack Document::undoStack() { return m_undostack; }
QVector<CNPart> Document::parts() { return m_parts; }
QVector<CNAssembly> Document::assemblies() { return m_assemblies; }
CNPart * Document::selectedPart() { return m_selected_part; }

void Document::addToSelection(QObject *obj, value) {
    m_selection_dict[obj] = value;
    m_selected_changed_dict[obj] = value;
}

uint Document::getUUID() {
    if (m_used_ids.empty()) {
        return m_id_counter++;
    } else {
        return m_used_ids.pop_back();
    }
}

void Document::recycleUUID(uint id) {
    m_used_ids.push_back(id);
}

bool Document::removeFromSelection(CNObject *obj) {
        if (m_selection_dict.contains(*obj)) {
            m_selection_dict.remove(*obj);
            m_selected_changed_dict[*obj] = qMakePair(false, false);
            return true;
        } else {
            return false;
        }
}

void Document::clearSelections() {

}

void Document::addStrandToSelection(CNObject *strand, endpts_select_t value) {
       CNObject *sS = strand.strandSet();
       if (!m_selection_dict.contains(*sS)) {
           m_selection_dict.insert(*sS, new CNStrandSelectHash_t());
       }
       m_selection_dict.value(*sS)[*strand] = value;
       m_selected_changed_dict[*strand] = value;
}

bool Document::removeStrandFromSelection(CNObject *strand) {
    CNObject *sS = strand.strandSet();
    if (m_selection_dict.contains(*sS)) {
        CNStrandSelectHash_t *temp = m_selection_dict.value(*sS);
        if (temp->contains(*strand)) {
            temp->remove(*strand);
            if (temp->empty()) {
                delete temp;    // free memory
                m_selection_dict.remove(*sS);
            }
            m_selected_changed_dict[*strand] = qMakePair(false, false);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

QSet<CNObject> * Document::selectedOligos() {
    m_selected_oligos.clear();
}
