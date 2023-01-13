#include "sphere.h"

Sphere::Sphere(float radius) : m_radius(radius) {}

Sphere::Sphere(const PropertyList &propList) {
  m_radius = propList.getFloat("radius", 1.f);
  m_center = propList.getPoint("center",Point3f(0,0,0));
}

void Sphere::intersect(const Ray &ray, Hit &hit) const {
  /// TODO: compute ray-sphere intersection
  // throw RTException("Sphere::intersect not implemented yet.");

  printf("Center : %f %f %f \n", m_center.x(), m_center.y(), m_center.z());
  printf("Ray origin : %f %f %f \n", ray.origin.x(), ray.origin.y(), ray.origin.z());
  printf("Ray direction : %f %f %f \n", ray.direction.x(), ray.direction.y(), ray.direction.z());

  float delta = 2 * (ray.origin - m_center).dot(ray.direction) - 
          4 * ray.direction.norm() * 
          ((ray.origin - m_center).norm() - m_radius * m_radius); 

  if (delta >= 0){
    hit.t = (-2 * (ray.origin - m_center).dot(ray.direction) - sqrt(delta)) / (2 * ray.direction.norm());
    hit.shape = this;
  }
}

REGISTER_CLASS(Sphere, "sphere")
