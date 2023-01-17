#include "bsdf.h"
#include "integrator.h"
#include "scene.h"

class Direct : public Integrator {
public:
  Direct(const PropertyList &props) { /* No parameters this time */
  }

  Color3f Li(const Scene *scene, const Ray &ray) const {
    Hit hit = Hit();
    scene->intersect(ray, hit);
    if(hit.foundIntersection()){
      // normale
      Normal3f n = hit.normal;

      // point d'intersection
      Vector3f p = ray.at(hit.t);
      
      // matériau
      Color3f phong = hit.shape->bsdf()->eval(ray.direction, n, p); 

      // couleur
      Color3f color = Color3f(0,0,0);
      
    
      for(size_t i = 0; i < scene->lightList().size(); i++){
        
        // intensité de la lampe
        Color3f intensity = scene->lightList()[i]->intensity(p, hit.normal, hit.t);
        
        // direction de la lampe
        Vector3f lightDir = 
        
        color += std::max(intensity.dot(n), 0.f);
      }
      return color;

    }else{ 
      return scene->backgroundColor(ray.direction);
    }
  }

  std::string toString() const { return "Direct[]"; }
};

REGISTER_CLASS(Direct, "direct")
