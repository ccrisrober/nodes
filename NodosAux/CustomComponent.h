#pragma once

#include "Component.h"

class CustomComponent : public Component
{
  IMPLEMENT_COMPONENT( CustomComponent )
public:
  CustomComponent( );
  ~CustomComponent( );
  int v;
};

