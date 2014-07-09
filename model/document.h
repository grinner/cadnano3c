#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QUndoStack>
#include <QUndoCommand>
#include <QSet>
#include <QVector>
#include <QList>

class Document : public QObject
{
public:
    Document();

    QUndoStack undoStack();
    QVector<QObject> parts();
    QVector<QObject> assemblies();
    QObject selectedPart();
    void addToSelection(QObject &obj, int value);
    void removeFromSelection(QObject &obj);
    void clearSelections();
    void addStrandToSelection(QObject &strand, int value);
    void removeStrandFromSelection(QObject &strand);
    QSet selectedOligos();
    void clearAllSelected();
    bool isModelSelected();
    bool isModelStrandSelected();
    int getSelectedValue(QObject &obj);
    int getSelectedStrandValue(QObject &strand);
    QList sortedSelectedStrands(QObject strand_set);
    QObject getSelectionBounds();
    void deleteSelection(bool use_undostack=true);
    void paintSelection(QColor &scafColor, QColor &stapColor, bool use_undostack=true);
    void resizeSelection(qreal delta, bool use_undostack=true);
    void updateSelection();
    void resetViews();
    void addHoneyCombPart();
    void addSquarePart();
    void removeAllParts();
    void removePart(QObject &part);
    QObject controller();
    void setController(QObject &controller);
    void setSelectedPart(QObject new_part);

protected:
    // void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QUndoStack undostack;
    QVector<QObject> parts;
    QVector<QObject> assemblies;
    QObject controller;
    QObject selected_part;
    QObject selection_dict;
    QObject selection_change_dict;
    void addPart(QObject part, bool use_undostack=true);
};

class AddPartCommand: public QUndoCommand
{
public:
    AddPartCommand(Document doc, QObject part);
    ~AddPartCommand();
    QObject part();
    /* data */
    Document doc;
    QObject part;
};

#endif // DOCUMENT_H