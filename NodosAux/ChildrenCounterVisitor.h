#pragma once
#include "NodeVisitor.h"
class ChildrenCounterVisitor :
  public NodeVisitor
{
public:
  ChildrenCounterVisitor( );
  virtual ~ChildrenCounterVisitor( );
  virtual void reset( ) override;
  virtual void traverse( Node* n ) override;
  virtual void visitNode( Node* n ) override;
  virtual void visitGroup( Group* g ) override;

//protected:
  unsigned int _childrens;
};

