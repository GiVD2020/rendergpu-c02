#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vNormal;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

struct MaterialComponents{
    vec4 ka;
    vec4 kd;
    vec4 ks;
    float shine;
};

uniform MaterialComponents materials; //It'll be uniform

struct LightComponents{
    vec3 ia;
    vec3 id;
    vec3 is;
    vec3 coeficients;
    vec4 position;
    vec3 direction;
    float angle;
    int typeLight;
};

uniform LightComponents lights[5];

uniform vec3 iAmbientGlobal;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    /*
    if (lights[0].typeLight != 2){
        color = vec4(lights[0].direction, 1.0);
    }else{
        color = vec4(1.0, 1.0, 0.0, 1.0); //This works
    }*/
    color = vNormal;
    //color = vec4(1.0, 0.0, 0.0, 1.0); //This works
}
