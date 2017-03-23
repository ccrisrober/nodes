#pragma once
#include <functional>
#include "NodeVisitor.h"
class ApplyVisitor :
  public NodeVisitor
{
private:
  typedef std::function<void( Node* )> CallbackType;
public:
  ApplyVisitor( CallbackType cb );
  virtual ~ApplyVisitor( );
  virtual void visitNode( Node* n ) override;
  virtual void visitGroup( Group* g ) override;
private:
  CallbackType _callback;
};

