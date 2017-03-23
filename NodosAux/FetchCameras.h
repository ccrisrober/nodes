#pragma once

#include "NodeVisitor.h"
#include <vector>
#include <functional>

class FetchCameras :
  public NodeVisitor
{
public:
  FetchCameras( );
  virtual ~FetchCameras( );
  virtual void reset( void ) override;
  virtual void visitCamera( Camera* c ) override;
  bool hasCameras( void ) const
  {
    return !_cameras.empty( );
  }
  void forEachCamera( std::function<void( Camera* )> cb );
protected:
  std::vector<Camera*> _cameras;
};

