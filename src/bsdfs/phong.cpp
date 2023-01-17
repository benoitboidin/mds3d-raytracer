/*
    This file is part of Nori, a simple educational ray tracer

    Copyright (c) 2015 by Wenzel Jakob
*/

#include "bsdf.h"

/**
 * \brief Phong BRDF model (energy conservative)
 */
class Phong : public BSDF {
public:
  Phong(const PropertyList &propList) {
    /* Albedo of the diffuse base material (a.k.a "kd") */
    m_kd = propList.getColor("kd", Color3f(0.5f));
    /* Albedo of the specular base material (a.k.a "ks") */
    m_ks = propList.getColor("ks", Color3f(0.5f));
    /* Roughness of the material (a.k.a "exponent") */
    m_exponent = propList.getFloat("exponent", 0.1f);

    m_type = MaterialType::DiffuseAndGlossy;
  }

  Color3f albedo() const { return m_kd; }

  /// Evaluate the BRDF model
  Color3f eval(const Vector3f &wi, const Vector3f &wo,
               const Normal3f &n) const {
    /// TODO: implement Phong BRDF
    // throw RTException("Phong::eval not implemented yet.");

    // Not sure about this...
    Vector3f h = (wi + wo).normalized();
    float cosTheta = std::max(0.f, h.dot(n));
    return m_kd * INV_PI + m_ks * m_exponent * INV_TWOPI * std::pow(cosTheta, m_exponent);
    
    // return Color3f(0.f);
  }

  /// Return a human-readable summary
  std::string toString() const {
    return tfm::format("Phong[\n"
                       "  kd = %s\n"
                       "  ks = %s\n"
                       "  exponent = %f\n"
                       "]",
                       m_kd.toString(), m_ks.toString(), m_exponent);
  }

  EClassType getClassType() const { return EBSDF; }

private:
  Color3f m_kd, m_ks;
  float m_exponent;
};

REGISTER_CLASS(Phong, "phong");
