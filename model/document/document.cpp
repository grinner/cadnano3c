#include "document.h"

void Document::Document() : QObject(), m_id_counter(0) {
//   app.documentWasCreatedSignal();
    m_undostack(this);
    m_undostack.setUndoLimit(10);
}

QUndoStack *Document::undoStack() { return &m_undostack; }
const QVector<Part>& Document::parts() { return m_parts; }
const QVector<Assembly>& Document::assemblies() { return m_assemblies; }
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

void Document::addStrandToSelection(Strand *strand, endpts_select_t value) {
       CNObject *sS = strand->strandSet();
       if (!m_selection_dict.contains(*sS)) {
           m_selection_dict.insert(*sS, new CNStrandSelectHash_t());
       }
       m_selection_dict.value(*sS)[*strand] = value;
       m_selected_changed_dict[*strand] = value;
}

bool Document::removeStrandFromSelection(Strand *strand) {
    CNObject *sS = strand->strandSet();
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

void Document::addPartToList(Part *part) {
    m_parts.push_back(part);
}

void Document::removePartFromList(Part *part) {
       emit documentClearSelectionsSignal(this);
       int idx = m_parts.indexOf(part);
       if (idx < 0) {
           // not there
       } else {
           m_parts.remove(idx);
       }
}
