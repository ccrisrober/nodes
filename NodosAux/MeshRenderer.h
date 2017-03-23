#pragma once
#include "Component.h"
class MeshRenderer :
  public Component
{
  IMPLEMENT_COMPONENT( MeshRenderer )
public:
  MeshRenderer( int vao );
  virtual ~MeshRenderer( );
public:
  int vao;
};

