#pragma once
#include "NodeVisitor.h"
#include "RenderQueue.h"
class FetchGeometry :
  public NodeVisitor
{
public:
  FetchGeometry( int camera );
  virtual ~FetchGeometry( );
  virtual void traverse( Node* n ) override;
  virtual void visitNode( Node* n ) override;
  virtual void visitGroup( Group* g ) override;
  RenderQueue rq;
protected:
  int camera;
};

