#pragma once

#include "Node.h"

class Camera;

class ImageEffect
{
public:
  // TODO Renderer?
  virtual void apply( Camera* camera ) = 0;
  // TODO Renderer?
  virtual void compute( Camera* camera ) = 0;

  bool enabled = true;
protected:
  
};


class SepiaToneEffect :
  public ImageEffect
{
public:
  virtual void compute( Camera* camera ) override;
  virtual void apply( Camera* camera ) override;
protected:
  int shader;
};

class RenderPass
{
public:
  std::vector< ImageEffect *> _imageEffects;
};

class Camera:
  public Node
{
public:
  static Camera *mainCamera( void )
  {
    return _mainCamera;
  }
  static void mainCamera( Camera *camera )
  {
    _mainCamera = camera;
  }
private:
  static Camera *_mainCamera;
public:
  Camera( );
  ~Camera( );
public:
  virtual void accept( NodeVisitor& v ) override;
public:
  void renderPass( RenderPass* rp )
  {
    _renderPass = rp;
  }
  RenderPass* renderPass( )
  {
    return _renderPass;
  }

  bool isMainCamera( void ) const
  {
    return _isMainCamera;
  }
  void setIsMainCamera( bool v )
  {
    _isMainCamera = v;
  }

private:
  bool _isMainCamera = false;
protected:
  RenderPass* _renderPass;
};

