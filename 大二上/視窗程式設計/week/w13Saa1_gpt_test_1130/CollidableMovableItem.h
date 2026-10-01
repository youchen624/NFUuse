#ifndef COLLIDABLEMOVABLEITEM_H
#define COLLIDABLEMOVABLEITEM_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class CollidableMovableItem : public QGraphicsRectItem
{
public:
    // 构造函数：接受矩形大小和颜色
    CollidableMovableItem(const QRectF& rect, const QColor& color);

protected:
    // 重新实现鼠标按下事件
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    // 重新实现鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    // 重新实现鼠标释放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    // 重新实现 itemChange 用于处理位置变化时的逻辑（如碰撞检测）
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    QPointF m_dragStartPos; // 记录拖动开始时的局部坐标
    QColor m_originalColor; // 记录原始颜色
    bool m_isColliding = false; // 记录是否正在碰撞

    // 检查并更新碰撞状态
    void updateCollisionState();
};

#endif // COLLIDABLEMOVABLEITEM_H
