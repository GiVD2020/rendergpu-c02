#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vNormal;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

/***       PAS 2      ***/
struct MaterialComponents {
    vec4 ka;
    vec4 kd;
    vec4 ks;
    float shine;
};

uniform MaterialComponents materials; //It'll be uniform

/***       PAS 3      ***/
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

/***       PAS 4      ***/
uniform vec4 obs;


void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    /* GOURAUND SHADING  */
    vec4 H, L, N, V;

    float epsilon = 0.01f;
    vec4 difuseAndSpecular, ambiental;

    // TODO Tienes que saber el num. de lights de antemano, por ahora hardcoded
    for (int i = 0; i < 1 ; i++) {

        /* DIFUSE */
        L = normalize(lights[i].position - vPosition);
        N = normalize(vNormal);
        float LN = max(dot(L,N), 0.0f);
        difuseAndSpecular = vec4(lights[i].id, 1.0) * materials.kd * LN;    //Solo difusa

        /* SPECULAR */
        V = normalize(obs - vPosition);
        H = normalize((L + V)/ (sqrt((L.x + V.x)*(L.x + V.x)) +
                                sqrt((L.y + V.y)*(L.y + V.y)) +
                                sqrt((L.z + V.z)*(L.z + V.z))));

        float NH = max(dot(H, N), 0.0f);
        difuseAndSpecular += vec4(lights[i].is, 1.0) * materials.ks * pow(NH, materials.shine); // Difusa y especular

        /* ATENUACIO */
        //float d = distance(vec3(vPosition), vec3(lights[i].position));
        //float atenuacion = (1.0f / (lights[i].coeficients.x * pow(d, 2.0) + lights[i].coeficients.y * d + lights[i].coeficients.z));
        //difuseAndSpecular *= atenuacion;

        //AMBIENTAL COLOR(local)
        ambiental = vec4(lights[i].ia, 1.0) * materials.ka;
        color = difuseAndSpecular + ambiental;

    }
    vec4 ambientGlobal = vec4(iAmbientGlobal,1.0);
    color +=  ambientGlobal * materials.ka;
    //color = difuseAndSpecular;
}
