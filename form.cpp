#include <QtGui>

#include "form.h"
#include "HandleItem.h"

#include <iostream>

Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  
  QGraphicsScene* scene = new QGraphicsScene( 0, 0, 200, 200 );
  QGraphicsRectItem *rectItem = new QGraphicsRectItem( QRect( 10, 10, 50, 100 ), 0, scene );
  
  // The center handle must know about all of the other handles so it can translate them with the object
  HandleItem *topHandle = new HandleItem( rectItem, scene, Qt::red, HandleItem::TopHandle );
  HandleItem *rightHandle = new HandleItem( rectItem, scene, Qt::red, HandleItem::RightHandle );
  HandleItem *leftHandle = new HandleItem( rectItem, scene, Qt::red, HandleItem::LeftHandle );
  HandleItem *bottomHandle = new HandleItem( rectItem, scene, Qt::red, HandleItem::BottomHandle );

  topHandle->SetDependentHandles(QList<HandleItem*>() << rightHandle << leftHandle);

  rightHandle->SetDependentHandles(QList<HandleItem*>() << topHandle << bottomHandle);

  leftHandle->SetDependentHandles(QList<HandleItem*>() << topHandle << bottomHandle);

  bottomHandle->SetDependentHandles(QList<HandleItem*>() << rightHandle << leftHandle);

  this->graphicsView->setScene( scene );

}
