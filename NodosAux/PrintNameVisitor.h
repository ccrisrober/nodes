#pragma once
#include "ApplyVisitor.h"
class PrintNameVisitor :
  public ApplyVisitor
{
public:
  PrintNameVisitor( );
  virtual ~PrintNameVisitor( );
};

