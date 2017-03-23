#pragma once

#include <vector>
#include "MeshRenderer.h"

class RenderQueue
{
public:
  enum class RenderableType
  {
    OPAQUE,
    TRANSPARENT
  };
  RenderQueue( );
  virtual ~RenderQueue( );
  /*void sortGeometry( std::function<bool( int, int )> cb )
  {
    std::sort( _queue.begin( ), _queue.end( ), cb );
  }*/
  void pushGeometry( MeshRenderer* mr )
  {
    _queue.push_back( mr );
  }
  unsigned int size( ) const
  {
    return _queue.size( );
  }
  void reset( )
  {
    _queue.clear( );
  }
  void camera( Camera* c )
  {
    _camera = c;
  }
  Camera* camera( )
  {
    return _camera;
  }
protected:
  std::vector< MeshRenderer* > _queue;
  Camera* _camera;
};

