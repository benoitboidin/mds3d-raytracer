#include "sphere.h"

Sphere::Sphere(float radius) : m_radius(radius) {}

Sphere::Sphere(const PropertyList &propList) {
  m_radius = propList.getFloat("radius", 1.f);
  m_center = propList.getPoint("center",Point3f(0,0,0));
}

void Sphere::intersect(const Ray &ray, Hit &hit) const {
  /// TODO: compute ray-sphere intersection
  // throw RTException("Sphere::intersect not implemented yet.");
  float delta = 2 * (ray.origin - m_center).dot(d) - 
          4 * d.norm() * 
          ((ray.origin - m_center).norm() - m_radius * m_radius); 
  
  printf("%f", delta);

  // if (delta < 0){
  //   return false;
  // }else if (delta = 0){
  //   return 
  // }
}

REGISTER_CLASS(Sphere, "sphere")
