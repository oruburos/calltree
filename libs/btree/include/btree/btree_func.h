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

#ifndef BTREE_FUNCTIONS_H_INCLUDED
#define BTREE_FUNCTIONS_H_INCLUDED

#include "btree_data.h"

/*
 * Function that can be used to check if a word or string as one of the keywords
 * used in the btree lexer.
 */

bool is_btree_keyword( const char* str );

/*
 * Locator functions
 */

void init( Locator* l );

/*
 * Identifier Functions
 */

void init( Identifier* id );

/*
 * Variable Functions
 */

void init( Parameter* v );

Parameter* find_last( Parameter* v );

void append_to_end( Parameter* start, Parameter* v );

int count_elements( Parameter* start );

Parameter* find_by_hash( Parameter* start, hash_t hash );

Parameter* find_child_by_hash( Parameter* start, hash_t hash );

int count_occourances_of_hash_in_list( Parameter* start, hash_t hash );

bool id_hashes_are_unique_in_list( Parameter* start );

bool safe_to_convert( const Parameter*, int to_type );

int as_integer( const Parameter& );

float as_float( const Parameter& );

const StringData* as_string( const Parameter& );

hash_t as_hash( const Parameter& );

bool as_bool( const Parameter& );

const char* list_as_string( BehaviorTreeContext tree, Parameter* start );

void free_list( BehaviorTreeContext ctx, Parameter* start );

const char* get_type_name( Parameter* p );

/*
 * BehaviorTree Functions
 */

void init( BehaviorTree* );

void set_parent_on_children( BehaviorTree* t );

void unlink_from_children( BehaviorTree* t );

/*
 * Action Functions
 */

void init( Action* );

/*
 * Decorator Functions
 */

void init( Decorator* );

/*
 * Node Functions
 */

void init( Node* );

void free_node( BehaviorTreeContext, Node* );

void append_to_end( Node* s, Node* n );

void set_parent_on_children( Node* s );

Node* get_first_child( Node* n );

Node* get_first_child( const NodeParent& p );

void set_first_child( Node* p, Node* c );

void set_first_child( const NodeParent& p, Node* c );

void unlink_from_siblings( Node *n );

void unlink_from_parent_and_siblings( Node* n );

int count_children( Node* n );

bool accepts_more_children( Node* n );

//Returns the parameter list for this node, if it has one.
Parameter* get_parameters( Node* n );

//Set's the parameter list on this node. Old parameters leaked if they exist. p leaked is this node does not accept parameters.
void set_parameters( Node* n, Parameter* p );

//Returns the declaration list for the action/decorator/tree that this node uses, if it exists
Parameter* get_declarations( Node* n );

//Returns the options list for the action/decorator/tree that this node uses, if it exists
Parameter* get_options( Node* n );

// Searches up from parent p to find the first BehaviorTree
BehaviorTree* find_parent_tree( const NodeParent& p );

// Searches down from n to see if a reference to tree can be found.
bool contains_reference_to_tree( Node* n, BehaviorTree* tree );

/**
 * @brief Removes all declaration parameters in tree by hash id. Free's resources back to ctx.
 * @param ctx The context that "owns" tree
 * @param tree The tree structure to remove the declaration parameter from
 * @param id The id of the parameter to be removed
 */

void remove_declaration( BehaviorTreeContext ctx, BehaviorTree* tree, hash_t id );

/*
 * Node Grist Functions
 */

void init( NodeGrist* );

/*
 * BehaviorTreeContext Functions
 */

BehaviorTreeContext create_bt_context( Allocator& );

void destroy( BehaviorTreeContext );

const char* register_string( BehaviorTreeContext, const char* );

const char* register_string( BehaviorTreeContext, const char*, hash_t );

void* allocate_object( BehaviorTreeContext );

void free_object( BehaviorTreeContext, void* );

void register_symbol( BehaviorTreeContext, const NamedSymbol& );

void remove_symbol( BehaviorTreeContext, hash_t );

NamedSymbol* find_symbol( BehaviorTreeContext, hash_t );

NamedSymbol* access_symbols( BehaviorTreeContext, int* );

void add_include( BehaviorTreeContext, const Include& );

Include* create_include( BehaviorTreeContext, const char* );

Include* get_first_include( BehaviorTreeContext );

void release_include( BehaviorTreeContext, Include* );

BehaviorTree* look_up_behavior_tree( BehaviorTreeContext, Identifier* );

Decorator* look_up_decorator( BehaviorTreeContext, Identifier* );

Action* look_up_action( BehaviorTreeContext, Identifier* );

Parameter* look_up_type( BehaviorTreeContext, Identifier* );

Parameter* get_options( BehaviorTreeContext );

Parameter* get_options( NamedSymbol* ns  );

Locator* get_locator( NamedSymbol* ns  );

NodeGristType get_grist_type( NamedSymbol* ns );

/*
 * String Buffer Functions
 */

void init( Allocator&, StringBuffer*, int initial_size = 1024 );
void destroy( StringBuffer* );

void append( StringBuffer*, char );
void append( StringBuffer*, const char * );
void append( StringBuffer*, const char *, int );

void clear( StringBuffer* );

void grow( StringBuffer* sb, int min );

/*
 * Parser Functions
 */

ParserContext create_parser_context( BehaviorTreeContext );

void destroy( ParserContext );

void* get_extra( ParserContext );
void set_extra( ParserContext, void* );

void set_current( ParserContext, const char* );
const char* get_current( ParserContext );

int get_line_no( ParserContext );

BehaviorTreeContext get_bt_context( ParserContext );

int parse( ParserContext, ParserContextFunctions* );

/*
 * Saver Functions
 */

SaverContext create_saver_context( BehaviorTreeContext );

void destroy( SaverContext );

void* get_extra( SaverContext );
void set_extra( SaverContext, void* );

BehaviorTreeContext get_bt_context( SaverContext );

void save( SaverContext, SaverContextFunctions* );

/*
 * Cloning
 */

BehaviorTreeContext clone( BehaviorTreeContext );
void clone( BehaviorTreeContext, Identifier*, Identifier* );
void clone( BehaviorTreeContext, Locator*, Locator* );
void clone( BehaviorTreeContext, Include* );
void clone( BehaviorTreeContext, BehaviorTree* );
void clone( BehaviorTreeContext, Action* );
void clone( BehaviorTreeContext, Decorator* );

Parameter* clone( BehaviorTreeContext, Parameter* );
Node*      clone( BehaviorTreeContext, Node* );

void       clone_symbols( BehaviorTreeContext, NamedSymbol*, int );
Parameter* clone_list( BehaviorTreeContext, Parameter* );
Node*      clone_tree( BehaviorTreeContext, Node* );

#endif /* BTREE_FUNCTIONS_H_INCLUDED */

