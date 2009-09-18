/* 
 * 
 * Copyright (C) 2009, Joacim Jacobsson ( j dot jacobsson at gmail dot com ) 
 * All rights reserved.
 * 
 * See LICENSE file for details
 * 
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>
#include <vector>

class Identifier;
class BehaviourTree;

class Variable
{
public:
    enum EVariableTypes
    {
        E_VART_UNDEFINED,
        E_VART_INTEGER,
        E_VART_FLOAT,
        E_VART_STRING,
        E_VART_BOOL
    };

    union UData {
        int         m_Integer;
    	float       m_Float;
        const char* m_String;
        bool		m_Bool;
    };

    bool        SafeToConvert( int to_type ) const;
    int         ValueAsInteger() const;
    float       ValueAsFloat() const;
    const char* ValueAsString() const;
    bool		ValueAsBool() const;

    int             m_Type;
    Identifier*     m_Id;
    UData           m_Data;
    Variable*       m_Next;
};

void DeleteVariableList( Variable* v );
Variable* FindLastVariable( Variable* v );

#endif /*VARIABLE_H_*/
