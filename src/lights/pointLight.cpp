#include "light.h"

class PointLight : public Light {
public:
  PointLight(const PropertyList &propList) {
    m_intensity = propList.getColor("radiance", Color3f(1.f));
    m_position = propList.getPoint("position", Point3f::UnitX());
  }

  Color3f intensity(const Point3f &x, Vector3f &wi, float &dist) const {
    /// TODO: compute the light intensity received at point x,
    /// the normalized direction wi and distance between x and the ligth center
    // throw RTException("PointLight::intensity not implemented yet.");
    
    wi = (m_position - x).normalized();
    dist = (m_position - x).norm();

    return m_intensity / (dist * dist);
    // return Color3f(0.f);
  }

  std::string toString() const {
    return tfm::format("PointLight[\n"
                       "  intensity = %s\n"
                       "  position = %s\n"
                       "]",
                       m_intensity.toString(), ::toString(m_position));
  }

protected:
  Color3f m_intensity;
  Point3f m_position;
};

REGISTER_CLASS(PointLight, "pointLight")
