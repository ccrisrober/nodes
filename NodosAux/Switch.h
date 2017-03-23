#pragma once
#include "Group.h"
class Switch :
  public Group
{
public:
  Switch( const std::string name );
  virtual ~Switch( );

  virtual void forEachNode( std::function<void( Node* )> cb );
  Node* currentNode( void );

  int currentNodeIndex( void ) const;
  void currentNodeIndex( int idx );

  void selectNextNode( void );
  void selectPrevNode( void );

private:
  int _currentIdx;
};

