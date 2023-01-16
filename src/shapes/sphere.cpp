#include "sphere.h"
#include "math.h"

Sphere::Sphere(float radius) : m_radius(radius) {}

Sphere::Sphere(const PropertyList &propList) {
  m_radius = propList.getFloat("radius", 1.f);
  m_center = propList.getPoint("center",Point3f(0,0,0));
}

void Sphere::intersect(const Ray &ray, Hit &hit) const {
  /// TODO: compute ray-sphere intersection
  // throw RTException("Sphere::intersect not implemented yet.");

  // First try : 
  // float delta = 2 * (ray.origin - m_center).dot(ray.direction) - 
  //         4 * ray.direction.norm() * ((ray.origin - m_center).norm() - m_radius * m_radius); 

  // float a = (ray.direction.norm() * ray.direction.norm());
  // float b = (2 * (ray.origin - m_center).dot(ray.direction));
  // float c = (pow((ray.origin - m_center).norm(), 2) - m_radius * m_radius);

  // float delta =  pow(b, 2) - 4 * a * c;

  Vector3f xp = ray.origin - m_center;
  float dn = ray.direction.norm();
  float dot = xp.dot(ray.direction);
  float xpn = xp.norm();

  float a = dn * dn;
  float b = 2 * dot;
  float c = xpn * xpn - m_radius * m_radius;


  float delta = b*b - 4 * a * c;
  // cout << "Delta: " << delta << endl;
  if (delta == 0) {
    hit.t = - b / (2 * a);
    hit.shape = this;
  } else if (delta > 0) {
    hit.t = std::min((-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
    hit.shape = this;
    hit.normal = (ray.at(hit.t) - m_center).normalized();
  }
  else {
    hit = Hit();
  }

  if(delta < 0){
    return;
  }else if (delta == 0){
    float t = (-b) / (2 * a);
    hit.t = t;
    hit.shape = this;
    hit.normal = (ray.at(t) - m_center).normalized();
  }else{
    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);
    hit.t = std::min(t1, t2);
    hit.shape = this;
    hit.normal = (ray.at(hit.t) - m_center).normalized();
  }
}

REGISTER_CLASS(Sphere, "sphere")
