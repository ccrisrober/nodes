#pragma once

class Node;
class Group;
class Camera;

class NodeVisitor
{
protected:
  NodeVisitor( );
public:
  virtual ~NodeVisitor( );
  virtual void reset( void );
  virtual void traverse( Node* node );
  virtual void visitNode( Node *node );
  virtual void visitGroup( Group *group );
  virtual void visitCamera( Camera *camera );
private:
  NodeVisitor( const NodeVisitor& );
  NodeVisitor &operator= ( const NodeVisitor& );
};

