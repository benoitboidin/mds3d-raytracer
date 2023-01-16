#include "plane.h"

Plane::Plane(const PropertyList &propList) {
  m_position = propList.getPoint("position", Point3f(0, 0, 0));
  m_normal = propList.getVector("normal", Point3f(0, 0, 1));
  m_normal.normalize();
}

void Plane::intersect(const Ray &ray, Hit &hit) const {
  /// TODO: compute ray-plane intersection
  // throw RTException("Plane::intersect not implemented yet.");

  Point3f a = m_position;
  Vector3f d = ray.direction;
  Vector3f n = m_normal;
  Point3f o = ray.origin;

  // float equation = (o.dot(n) + a.dot(n)) + hit.t*(d.dot(n));

  if (d.dot(n) == 0) 
    return;

  float t = (a.dot(n) - o.dot(n)) / (d.dot(n));
  if (t > 0) {
    hit.t = t;
    hit.shape = this;
    hit.normal = m_normal;
    }
  return;
}

REGISTER_CLASS(Plane, "plane")
