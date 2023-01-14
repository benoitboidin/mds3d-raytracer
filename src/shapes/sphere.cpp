#include "sphere.h"

Sphere::Sphere(float radius) : m_radius(radius) {}

Sphere::Sphere(const PropertyList &propList) {
  m_radius = propList.getFloat("radius", 1.f);
  m_center = propList.getPoint("center",Point3f(0,0,0));
}

void Sphere::intersect(const Ray &ray, Hit &hit) const {
  /// TODO: compute ray-sphere intersection
  // throw RTException("Sphere::intersect not implemented yet.");
  
  float delta = 2 * (ray.origin - m_center).dot(ray.direction) - 
          4 * ray.direction.norm() * 
          ((ray.origin - m_center).norm() - m_radius * m_radius); 

  if (delta >= 0){
    hit.t = (-2 * (ray.origin - m_center).dot(ray.direction) - sqrt(delta)) / (2 * ray.direction.norm());
    hit.normal = (ray.at(hit.t) - m_center).normalized();
    hit.shape = this; // Not sure about this...
    printf("Hit t : %f \n", hit.t);
  }
}

REGISTER_CLASS(Sphere, "sphere")
