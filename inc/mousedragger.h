#ifndef MOUSEDRAGGER_H
#define MOUSEDRAGGER_H

#include <QObject>
#include <QWidget>
#include <QMenu>

class MouseDragger : public QObject
{
    Q_OBJECT

public:
    explicit MouseDragger(QWidget *targetWidget);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QWidget *m_targetWidget;
    bool m_isDragging;
    QPoint m_dragOffset;
    QMenu *m_menu;
};

#endif // MOUSEDRAGGER_H