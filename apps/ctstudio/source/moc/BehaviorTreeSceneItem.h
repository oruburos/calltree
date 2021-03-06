/*******************************************************************************
 * Copyright (c) 2009-04-24 Joacim Jacobsson.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Joacim Jacobsson - first implementation
 *******************************************************************************/

#ifndef BEHAVOIRTREESCENEITEM_H_INCLUDED
#define BEHAVOIRTREESCENEITEM_H_INCLUDED

#include <QtGui/QGraphicsItem>
#include <QtCore/QList>
#include <QtCore/QPointF>

#include "../GraphicsItemTypes.h"
#include "../standard_resources.h"

#include <btree/btree_data.h>

// Qt forward declares
class QGraphicsSvgItem;

// Internal Forward declares
class NodeToNodeArrow;


class BehaviorTreeSceneItem: public QGraphicsObject
{

Q_OBJECT

public:

  enum
  {
    Type = BehaviorTreeSceneItemType
  };

  int type() const
  {
    return Type;
  }

  BehaviorTreeSceneItem( BehaviorTreeContext ctx, QGraphicsObject* parent = 0x0 );
  ~BehaviorTreeSceneItem();

  virtual bool isType( int type ) const
  {
    if( Type == type )
      return true;
    return false;
  }

  void dropArrows();
  void removeArrow( NodeToNodeArrow* arrow );
  void removeArrows();
  void addArrow( NodeToNodeArrow* arrow );
  NodeToNodeArrow* findArrowTo( BehaviorTreeSceneItem* other );
  void positionArrows();

  virtual bool toCloseForArrow( const BehaviorTreeSceneItem* other ) const;
  virtual QPointF arrowAnchor() const;

  virtual QPointF iconPosition() const;
  virtual QRectF layoutBoundingRect() const;
  virtual qreal layoutOffset() const;
  virtual BehaviorTreeSceneItem* getParent();
  virtual BehaviorTreeSceneItem* firstChild();
  virtual BehaviorTreeSceneItem* nextSibling();
  virtual bool validForDrop() const;

  virtual void dragMove();
  virtual void dragBegin();
  virtual void dragEnd();
  virtual void dragFail();
  virtual void symbolChanged( unsigned int hash_id );

  void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );

signals:

  void itemDragged();
  void itemSelected( QWidget* );
  void itemSymbolChanged( unsigned int hash_id );
  void modified( bool geometry_changed );
  void itemDeleted();

protected slots:

  void deleteThis();
  void positionIcons();

protected:

  QVariant itemChange( GraphicsItemChange change, const QVariant &value );

  void mousePressEvent( QGraphicsSceneMouseEvent* event );
  void mouseReleaseEvent( QGraphicsSceneMouseEvent* event );
  void mouseMoveEvent( QGraphicsSceneMouseEvent* event );

  void signalModified( bool geometry_changed );

private:

  enum MouseState
  {
    E_MS_NONE, E_MS_LB_DOWN, E_MS_DRAGGING
  };

  MouseState m_MouseState; // Current state of mouse handling.
  QPoint m_StartPos; // The event's screen position when the LMB was pressed;

protected:
  QList<NodeToNodeArrow*> m_Arrows;

  QWidget* m_PropertyWidget;

  QGraphicsSvgItem* m_Graphics;
  QGraphicsSvgItem* m_Icons[ ICON_COUNT ];

  BehaviorTreeContext m_Context;
};

#endif
