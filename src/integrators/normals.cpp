#include "bsdf.h"
#include "integrator.h"
#include "scene.h"

class Normals : public Integrator {
public:
  Normals(const PropertyList &props) { /* No parameters this time */
  }

  Color3f Li(const Scene *scene, const Ray &ray) const {
    Hit hit = Hit();
    scene->intersect(ray, hit);
    if(hit.foundIntersection()){
      return Color3f(hit.normal.cwiseAbs().x(), hit.normal.cwiseAbs().y(), hit.normal.cwiseAbs().z());
    }else{ 
      return scene->backgroundColor(ray.direction);
    }
  }

  std::string toString() const { return "Normals[]"; }
};

REGISTER_CLASS(Normals, "normals")
