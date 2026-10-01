#include "CollidableMovableItem.h"
#include <QGraphicsScene> // <-- **新增此行**
#include <QGraphicsItem>  // <-- 确保也包含了 QGraphicsItem

CollidableMovableItem::CollidableMovableItem(const QRectF& rect, const QColor& color)
    : QGraphicsRectItem(rect), m_originalColor(color)
{
    // 启用拖动和选中标志
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    // 设置画刷（填充颜色）
    setBrush(m_originalColor);
    // 初始画笔（边框）
    setPen(QPen(Qt::black));
}

void CollidableMovableItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // 如果是左键按下，记录起始位置
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->pos(); // 记录鼠标在 item 局部坐标系中的位置
    }
    // 调用基类的处理，保持选中状态等功能
    QGraphicsRectItem::mousePressEvent(event);
}

void CollidableMovableItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // 如果是左键拖动
    if (event->buttons() & Qt::LeftButton) {
        // 计算新的位置
        QPointF newPos = pos() + (event->pos() - m_dragStartPos);
        // 调用 setPos 并触发 itemChange
        setPos(newPos);
    }
    // 调用基类的处理
    QGraphicsRectItem::mouseMoveEvent(event);
}

void CollidableMovableItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // 释放时，检查一次碰撞状态
    updateCollisionState();
    // 调用基类的处理
    QGraphicsRectItem::mouseReleaseEvent(event);
}

QVariant CollidableMovableItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionHasChanged) {
        // 位置改变后，检查碰撞
        updateCollisionState();
    }
    return QGraphicsRectItem::itemChange(change, value);
}

void CollidableMovableItem::updateCollisionState()
{
    bool isCurrentlyColliding = false;

    // 获取所有与此 item 碰撞的 item
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

    // 遍历碰撞列表
    for (QGraphicsItem *item : collidingItems) {
        // 确保不要与自己检测碰撞
        if (item != this) {
            // 确保 item 是 CollidableMovableItem 类型
            if (dynamic_cast<CollidableMovableItem*>(item)) {
                isCurrentlyColliding = true;
                break; // 发现碰撞即可停止
            }
        }
    }

    // 更新碰撞状态和颜色
    if (isCurrentlyColliding && !m_isColliding) {
        // 从不碰撞 -> 碰撞
        setBrush(Qt::red);
        m_isColliding = true;
        qDebug() << "Collision detected!";
    } else if (!isCurrentlyColliding && m_isColliding) {
        // 从碰撞 -> 不碰撞
        setBrush(m_originalColor);
        m_isColliding = false;
        qDebug() << "Collision ended.";
    }

    // 如果正在碰撞，持续保持红色
    if (m_isColliding) {
        setBrush(Qt::red);
    } else {
        setBrush(m_originalColor);
    }
}
