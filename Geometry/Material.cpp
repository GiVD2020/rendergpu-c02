#include "Geometry/Material.h"


Material::Material() {
    // This values are done in order to test that material goes to GPU
    this->ambiental = vec4(1.0, 0.0, 0.0, 1.0);
    this->diffuse = vec4(0.0, 1.0, 0.0, 1.0);
    this->specular = vec4(0.0, 0.0, 1.0, 1.0);
    this->shiness = 1.0;
}

/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(shared_ptr<QGLShaderProgram> program){
    MaterialGPU.ka = program->uniformLocation("materials.ka");
    MaterialGPU.kd = program->uniformLocation("materials.kd");
    MaterialGPU.ks = program->uniformLocation("materials.ks");
    MaterialGPU.shine = program->uniformLocation("materials.shine");

    glUniform4fv(MaterialGPU.ka, 1, ambiental);
    glUniform4fv(MaterialGPU.kd, 1, diffuse);
    glUniform4fv(MaterialGPU.ks, 1, specular);
    glUniform1f(MaterialGPU.shine, shiness);

    qDebug() << "Material Sended to GPU" ;
}

