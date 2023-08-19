#include "MouseDragger.h"

#include <QtWidgets/QApplication>
#include <QMouseEvent>

MouseDragger::MouseDragger(QWidget *targetWidget)
    : QObject(targetWidget), 
    m_targetWidget(targetWidget), 
    m_isDragging(false)
{
    m_targetWidget->setMouseTracking(true);
    m_targetWidget->installEventFilter(this);
}

bool MouseDragger::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == m_targetWidget) 
    {
        if (event->type() == QEvent::MouseButtonPress) 
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton) 
            {
                m_isDragging = true;
                m_dragOffset = mouseEvent->pos();
                m_targetWidget->setCursor(Qt::OpenHandCursor);
            }
        }
        else if (event->type() == QEvent::MouseMove) 
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (m_isDragging)
            {
                QPoint newPos = mouseEvent->globalPosition().toPoint() - m_dragOffset;
                m_targetWidget->move(newPos);
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease) 
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton) 
            {
                m_isDragging = false;
                m_targetWidget->setCursor(Qt::ArrowCursor);
            }
        }
    }

    return QObject::eventFilter(obj, event);
}