#include "bsdf.h"
#include "integrator.h"
#include "scene.h"

class FlatIntegrator : public Integrator {
public:
  FlatIntegrator(const PropertyList &props) { /* No parameters this time */
  }

  Color3f Li(const Scene *scene, const Ray &ray) const {
     /** TODO : Find the surface that is visible in the requested direction
                   Return its ambiant color */
    // throw RTException("Flat::Li not implemented yet.");
    Hit hit = Hit();
    scene->intersect(ray, hit);
    if(hit.foundIntersection()){
      return hit.shape->bsdf()->albedo(); 
    }else{
      return scene->backgroundColor(ray.direction);
    }
  }

  std::string toString() const { return "FlatIntegrator[]"; }
};

REGISTER_CLASS(FlatIntegrator, "flat")
