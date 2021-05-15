#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vNormal;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

/***       PAS 2      ***/
struct MaterialComponents{
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
    vec4 H, L, N = vNormal;
    vec4 V;
    float epsilon = 0.01f, LN;
    vec4 iluminacioLocal, difuseAndSpecular;

    for (int i = 0; i < 1 ; i++) {
        iluminacioLocal = vec4(lights[i].ia, 1.0) * materials.ka;

        /* DIFSUSE */
        L = lights[0].position - gl_Position;
        L = normalize(L);
        float LN = max(dot(L,N), 0.0f);
        difuseAndSpecular = vec4(lights[0].id, 1.0) * materials.kd * LN;

        /* SPECULAR */
        V = obs - gl_Position;
        V = normalize(V);

        H = (L + V) / (sqrt((L.x + V.x)*(L.x + V.x)) +
                                 sqrt((L.y + V.y)*(L.y + V.y)) +
                                 sqrt((L.z + V.z)*(L.z + V.z)));
        H = normalize(H);
        float NH = max(dot(N, H), 0.0f);
        difuseAndSpecular += vec4(lights[0].is, 1.0) * materials.ks * pow(NH, materials.shine);

    }
    color = difuseAndSpecular;

}
