#pragma once
#include "Node.h"
class Group :
  public Node
{
public:
  Group( const std::string name );
  virtual ~Group( );

  bool hasNodes( void ) const;
  unsigned int numChildren( void ) const;

  void addChild( Node* node );
  void removeChild( Node* node );
  void removeChildren( void );
  Node* nodeAt( unsigned int idx );

  template<typename T>
  T* nodeAt( unsigned int idx )
  {
    return static_cast< T* >( nodeAt( idx ); )
  }

  // TODO: getNode (string)
  // TODO: T* getNode<T>(string)
  virtual void forEachNode( std::function< void( Node * ) > callback );
protected:
  std::vector<Node*> _children;

public:
  virtual void accept( NodeVisitor& v );
};

