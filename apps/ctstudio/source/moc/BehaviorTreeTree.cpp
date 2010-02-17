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

#include "BehaviorTreeTree.h"
#include "../standard_resources.h"
#include <btree/btree.h>

BehaviorTreeTree::BehaviorTreeTree( BehaviorTree* tree )
  : BehaviorTreeSceneItem( ":/nodes/tree.svg" )
  , m_Tree( tree )
{
  setFlag( QGraphicsItem::ItemIsMovable, false );
}
