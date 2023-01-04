#include "plane.h"

Plane::Plane(const PropertyList &propList) {
  m_position = propList.getPoint("position", Point3f(0, 0, 0));
  m_normal = propList.getVector("normal", Point3f(0, 0, 1));
  m_normal.normalize();
}

void Plane::intersect(const Ray &ray, Hit &hit) const {
  /// TODO: compute ray-plane intersection
  throw RTException("Plane::intersect not implemented yet.");
}

REGISTER_CLASS(Plane, "plane")
