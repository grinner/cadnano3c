#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QUndoStack>
#include <QVector>
#include <QJsonObject>
#include <QHash>
#include <QMultiHash>
#include <QSet>
#include "common.h"
class CNObject;
#include "model/cnobject.h"
//#include "model/part/part.h"
//#include "model/assembly/assembly.h"
//#include "model/strand/strand.h"

// adhoc tuple (strand_id, (is_selected_low, is_selected_high))
typedef QPair<CNObject *, endpts_select_t> strand_select_t;

typedef QHash<CNObject *, strand_select_t> CNStrandSelectHash_t;

class Document : public QObject
{
    Q_OBJECT
public:

    Document();
//    Document(const QString &name, int level, ClassType classType);


    QString filename() const;
    void setFilename(const QString &name);

    QUndoStack * undoStack();
    const QVector<CNObject *>& parts();
    const QVector<CNObject *>& assemblies();

    void addPartToList(CNObject *part);
    void removePartFromList(CNObject *part);

    uint getUUID();
    void recycleUUID(uint id);

    CNObject * selectedPart();
    void setSelectedPart(CNObject *part);

    void addToSelection(CNObject *, endpts_select_t value);
    bool removeFromSelection(CNObject *obj);
    void clearSelections();

    void addStrandToSelection(CNObject *strand, endpts_select_t value);
    bool removeStrandFromSelection(CNObject *strand);

    QSet<CNObject *> &selectedOligos();



    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
private:
    QString m_filename;
    QUndoStack m_undostack;
    QVector<CNObject *> m_assemblies;
    QVector<CNObject *> m_parts;

    QVector<uint> m_used_ids;
    uint m_id_counter;

    QSet<CNObject *> m_selected_oligos;

//    CNController m_controller;
    CNObject * m_selected_part;
    QHash<CNObject *, CNStrandSelectHash_t> m_selection_dict;
    // assume no dupes and you can use a multihash
    QMultiHash<uint, strand_select_t> m_selection_dict2;

    CNStrandSelectHash_t m_selection_changed_dict;

signals:
    void documentPartAddedSignal(QObject *, CNObject *); // doc, part
    void documentSelectedChangedSignal();
    void documentSelectionFilterChangedSignal();
    void documentResetViewSignal();
    void documentClearSelectionSignal();

};

#endif // DOCUMENT_H
