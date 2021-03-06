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
#ifndef ENDIAN_H_
#define ENDIAN_H_

inline void Swap( unsigned char* p_byte1, unsigned char* p_byte2 )
{
  unsigned char swap_byte;
  swap_byte = *p_byte1;
  *p_byte1 = *p_byte2;
  *p_byte2 = swap_byte;
}

inline void EndianSwap_2bytes( unsigned char* data )
{
  Swap( data, data + 1 );
}
inline void EndianSwap_4bytes( unsigned char* data )
{
  unsigned int *ival = (unsigned int *)data;
  unsigned int val = *ival;
  *ival = ((val >> 24) & 0x000000ff) | ((val >> 8) & 0x0000ff00) | ((val << 8)
      & 0x00ff0000) | ((val << 24) & 0xff000000);
}

inline void EndianSwap( short& data )
{
  EndianSwap_2bytes( (unsigned char*)&data );
}
inline void EndianSwap( unsigned short& data )
{
  EndianSwap_2bytes( (unsigned char*)&data );
}
inline void EndianSwap( int& data )
{
  EndianSwap_4bytes( (unsigned char*)&data );
}
inline void EndianSwap( unsigned int& data )
{
  EndianSwap_4bytes( (unsigned char*)&data );
}

#endif /*ENDIAN_H_*/
