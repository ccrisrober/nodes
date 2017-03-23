#pragma once
#include "NodeVisitor.h"

class UpdateWorldState :
  public NodeVisitor
{
public:
  UpdateWorldState( );
  virtual ~UpdateWorldState( );
  virtual void visitNode( Node *node ) override;
  virtual void visitGroup( Group *node ) override;
};

