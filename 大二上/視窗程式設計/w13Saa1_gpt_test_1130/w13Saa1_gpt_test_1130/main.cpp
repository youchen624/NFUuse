#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CollidableMovableItem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. 创建场景 (QGraphicsScene)
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600); // 设置场景大小

    // 2. 创建第一个可拖动和碰撞的图形项 (Item 1)
    CollidableMovableItem *item1 = new CollidableMovableItem(QRectF(0, 0, 100, 100), Qt::blue);
    item1->setPos(100, 100); // 设置初始位置
    scene.addItem(item1);

    // 3. 创建第二个可拖动和碰撞的图形项 (Item 2)
    CollidableMovableItem *item2 = new CollidableMovableItem(QRectF(0, 0, 100, 100), Qt::green);
    item2->setPos(300, 300); // 设置初始位置
    scene.addItem(item2);

    // 4. 创建视图 (QGraphicsView)
    QGraphicsView view(&scene);
    view.setWindowTitle("Graphics View Framework: Movable and Collidable Items");
    view.resize(800, 600);
    view.show();

    return a.exec();
}
