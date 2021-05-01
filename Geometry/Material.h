#pragma once

#include <QObject>
#include <vector>
#include <memory>

#include <library/Common.h>
using namespace Common;

#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QString>
#include <QStringList>

#include <Geometry/TG.h>
#include <Geometry/Animation.h>
#include <Geometry/Cara.h>

typedef vec3  point3;

using namespace std;
// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    Material();

    void toGPU(shared_ptr<QGLShaderProgram> program);
private:
    vec3 ambiental;
    vec3 diffuse;
    vec3 specular;
    float shiness;

    GLuint kd;
    GLuint ka;
    GLuint ks;
    GLuint beta;
};

