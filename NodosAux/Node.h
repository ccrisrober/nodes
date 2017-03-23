#pragma once

#include "Component.h"
#include <unordered_map>
#include <functional>
#include "NodeVisitor.h"

class Node
{
public:
  Node( const std::string& name );
  virtual ~Node( );
  std::string name( ) const;
  void name( const std::string& name )
  {
    _name = name;
  }

protected:
  Node* _parent;
  std::string _name;

public:
  void perform( NodeVisitor &visitor );
  void perform( const NodeVisitor &visitor );
  virtual void accept( NodeVisitor &visitor );

public:
  bool hasParent( void ) const;
  Node* parent( void );

  template<class NodeClass>
  NodeClass* parent( void )
  {
    return static_cast< NodeClass* >( _parent );
  }
  void parent( Node* p );

  void startComponents( );
  void addComponent( Component* comp );
  void updateComponents( const float& dt );
  void detachAllComponents( void );
  void forEachComponent( std::function< void( Component * ) > callback );

  template <class T>
  bool hasComponent( )
  {
    auto aux = _components.find( T::StaticGetUID( ) );
    if ( aux == _components.end( ) )
    {
      return false;
    }
    return true;
  }
  template <class T>
  T* getComponent( )
  {
    auto aux = _components.find( T::StaticGetUID( ) );
    if ( aux == _components.end( ) )
    {
      return nullptr;
    }
    return static_cast<T*>( aux->second );
  }
  /*template <class T>
  void removeComponent( )
  {
    onDetach( );
  }
  template <class T>
  void removeComponents( )
  {

  }
  template <class T>
  T* componentInparent( void )
  {
    return nullptr;
  }*/
  Component* getComponentByName( const std::string& name );
  /*std::vector<Componente*> getComponentsByName( const std::string& name )
  {
    std::vector<Componente*> cs;
    auto finds = _components.find( name );
    return cs;
  }*/
  protected:
    std::unordered_multimap<std::string, Component*> _components;
};

