#pragma once
#include "ApplyVisitor.h"
class UpdateComponents :
  public ApplyVisitor
{
public:
  // TODO: USE CLOCK
  UpdateComponents( const float& dt );
  virtual ~UpdateComponents( );
};

