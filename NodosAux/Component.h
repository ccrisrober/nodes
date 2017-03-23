#pragma once

#include <iostream>

typedef std::string ComponentUID;
#define IMPLEMENT_COMPONENT(__CLASS__) \
public: \
  static ComponentUID StaticGetUID( ) { \
  static std::string sUID = #__CLASS__; \
  return ( ComponentUID ) sUID; /* This will be unique in the executable! */ \
  } \
  virtual ComponentUID GetUID( ) const { return StaticGetUID( ); }

class Component
{
  friend class Node;
public:
  virtual ComponentUID GetUID( ) const = 0;
  virtual ~Component( );
  Node* node( );
  void update( const float &dt );
  virtual void start( void );
  virtual void onAttach( void );
  virtual void onDetach( void );
  bool activo = true;
private:
  void node( Node* n );
protected:
  Component( );
  Node* _node;
};