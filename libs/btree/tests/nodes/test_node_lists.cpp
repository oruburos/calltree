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

#include <UnitTest++.h>
#include <btree/btree_data.h>
#include <btree/btree_func.h>

TEST( TestUnlinkParentAndSiblingsDoesNotBreakList )
{
	Node n1,n2,n3;

	InitNode( &n1 );
	InitNode( &n2 );
	InitNode( &n3 );

	AppendToEndOfList( &n1, &n2 );
	AppendToEndOfList( &n1, &n3 );

	CHECK( n1.m_Next == &n2 );
	CHECK( n1.m_Prev == 0x0 );
	CHECK( n2.m_Next == &n3 );
	CHECK( n2.m_Prev == &n1 );
	CHECK( n3.m_Next == 0x0 );
	CHECK( n3.m_Prev == &n2 );

	UnlinkNodeFromParentAndSiblings( &n2 );

	CHECK( n1.m_Next == &n3 );
	CHECK( n1.m_Prev == 0x0 );
	CHECK( n2.m_Next == 0x0 );
	CHECK( n2.m_Prev == 0x0 );
	CHECK( n3.m_Next == 0x0 );
	CHECK( n3.m_Prev == &n1 );
}

TEST( GetFirstChildReturnsNullOnNull )
{
	CHECK( GetFirstChild( 0x0 ) == 0x0 );
}
