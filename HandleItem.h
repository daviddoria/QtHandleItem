#ifndef HANDLEITEM_H
#define HANDLEITEM_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class HandleItem;

class HandleItem : public QObject, public QGraphicsItem // QGraphicsItem does not inherit from QObject, so without this multiple inheritance we cannot use signals
{
Q_OBJECT
public:

  enum HandleRole
  {
    CenterHandle,
    RightHandle,
    TopHandle,
    LeftHandle,
    BottomHandle
  };

  HandleItem( QGraphicsRectItem *item, QGraphicsScene *scene, QColor color, HandleRole role = CenterHandle);
  
  void paint( QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget );
  QRectF boundingRect() const;

  void SetDependentHandles(QList<HandleItem*> handles);

signals:
  void Changed();
  
protected:
  void mousePressEvent( QGraphicsSceneMouseEvent *event );
  void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
  
  QVariant itemChange( GraphicsItemChange change, const QVariant &data );

public slots:
  void Update();
  
private:
  QGraphicsRectItem *m_item;
  
  HandleRole m_role;
  QColor m_color;
  
  QList<HandleItem*> m_handles;

  bool m_pressed;

  unsigned int HandleRadius;
  unsigned int MinSize;
};

#endif // HANDLEITEM_H
