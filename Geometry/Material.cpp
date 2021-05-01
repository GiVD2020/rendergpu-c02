#include "Geometry/Material.h"


Material::Material() {
    this->ambiental = vec3(1.0, 0.0, 0.0);
    this->diffuse = vec3(0.6, 0.6, 0.6);
    this->specular = vec3(1.0, 1.0, 1.0);
    this->shiness = 1.0;
}

/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(shared_ptr<QGLShaderProgram> program){


}

