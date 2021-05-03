#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;

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
};

uniform LightComponents lights[5];

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    color = vec4(lights[0].is, 1.0);
    //color = vec4(1.0, 0.0, 0.0, 1.0); //This works
}
