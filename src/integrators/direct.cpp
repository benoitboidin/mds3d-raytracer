#include "bsdf.h"
#include "integrator.h"
#include "scene.h"

class Direct : public Integrator {
public:
  Direct(const PropertyList &props) { /* No parameters this time */
  }

  Color3f Li(const Scene *scene, const Ray &ray) const {
    Hit hit = Hit();
    Ray direction = Ray();
    scene->intersect(ray, hit);
    if(hit.foundIntersection()){
      // normale
      Normal3f n = hit.normal;

      // point d'intersection
      Vector3f p = ray.at(hit.t);

      // couleur
      Color3f color = Color3f(0,0,0);
      
      for(size_t i = 0; i < scene->lightList().size(); i++){
        
        Vector3f lightdir;
        float dist;
        Color3f intensity = scene->lightList()[i]->intensity(p, lightdir, dist);

        Color3f phong = hit.shape->bsdf()->eval(lightdir, ray.direction, n); 
        // intensité de la lampe
        
        color += std::max(lightdir.dot(n), 0.f) * intensity * phong;
      }
      return color;

    }else{ 
      return scene->backgroundColor(ray.direction);
    }
  }

  std::string toString() const { return "Direct[]"; }
};

REGISTER_CLASS(Direct, "direct")
