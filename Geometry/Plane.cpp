#include "Geometry/Plane.h"
#include "library/Common.h"
Plane::Plane(vector<vec3> planeLimits):Object(100){
    //plane = make_shared<Object>(100);
    vec3 normal = cross(planeLimits.at(0)-planeLimits.at(1),planeLimits.at(0)-planeLimits.at(2));
    for(vec3 point: planeLimits){
        vertexs.push_back(point4(point.x,point.y,point.z,1.0f));
        normalsVertexs.push_back(point4(normal.x,normal.y,normal.z,1.0f));
    }
    //Muy harcoded pero se puede mejorar luego
    Cara *a = new Cara();
    Cara *b = new Cara();
    a->idxVertices.push_back(0);
    a->idxVertices.push_back(1);
    a->idxVertices.push_back(2);
    b->idxVertices.push_back(3);
    b->idxVertices.push_back(1);
    b->idxVertices.push_back(2);
    a->idxNormals.push_back(0);
    a->idxNormals.push_back(1);
    a->idxNormals.push_back(2);
    b->idxNormals.push_back(3);
    b->idxNormals.push_back(1);
    b->idxNormals.push_back(2);
    cares.push_back(*a);
    cares.push_back(*b);
}
Plane::~Plane(){
    delete points;
    delete normals;
    delete colors;
}