# RenderGPU
Segona pràctica de GiVD 2020-21

    Ángel Morales Carrasco NIUB 20150546
    Eric Duque Martín NIUB 20150443
    Oriol Saguillo González NIUB 20150502
    María Isabel González Sánchez NIUB 20221913
    
**Abstract**

*(NOTA: Petit resum del què heu fet, no més de 200 paraules)*

**Features**

- Fase 1
    - Adaptació a la lectura de fitxers de dades
        - [x] Objectes Eric, Angel
        - [x] Escenes virtuals Eric, Angel
        - [x] Escenes de dades Reals Eric,Angel
    - Material Oriol
    - Light
        - [x] Puntual Oriol
        - [x] Direccional Oriol
        - [x] Spotlight Oriol, María Isabel
        - [x] Ambient Global Oriol
    - Shading
        - [X] Phong María Isabel
        - [X] Gouraud Maria Isabel
    - Textures
        - [x] Textura com material en un objecte Eric,Angel
        - [x] Textura al pla base Eric,Angel
        

- Fase 2 (OPT)
    - [x] Toon-shading i èmfasi de siluetes María Isabel
    - [ ] Mapping indirecte de textures
    - [x] Animacions amb dades temporals Oriol Saguillo
    - [x] Normal mapping Angel
    - [ ] Entorn amb textures
    - [ ] Reflexions
    - [ ] Transparencias via objectes.
    - [ ] Transparencias via environmental mapping.


**Extensions**

*(NOTA: Les extensions de la pràctica que heu fet i que no surten a la llista anterior)*

**Memòria**

*(NOTA: Explicació només dels diferents punts que heu desenvolupat i funcionen, detallant les estratègies que heu fet servir)*

Oriol Saguillo: En el desenvolupament dels passos 2 i 3, l'estratègia va ser molt semblant. Primer de tot llegia el pas a pas del guió. En ambdós casos vaig tenir problemes amb l'enviament de les dades als shaders i per tant vaig haver de tornar a fer els passos de mica en mica. Un dels problemes més grans va ser que per defecte el codi venia amb un include vec.h a la classe de la llum si no recordo malament que feia que no funcionés res, vam arreglar aquest error amb el Ricardo a Laboratori. A l'hora de testejar que l'enviament era correcte posava que el color de sortida fos el vector que estava enviant, per exemple si era (1.0, 0.0, 0.0) en carregar l'esfera es haguera de veure vermella. Aquesta forma de testejar va ser tant al pas 2 com 3. En el desenvolupament de les animacions se'ns donava bastant codi ja implementat. En aquest cas a l'hora de fer el desenvolupament va ser primer crear la classe DataAnimation per crear les escenes d'animació amb les transformacions geomètriques corresponents. Seguidament vaig crear un botó extra en el menú per tal de poder carregar aquesta escena per evitar conflictes de codi amb els altres botons. El mètode associat a aquest botó el trobem a la classe Builder amb el nom saveAnimationScene, i aquí apliquem l'escena que vulguem dins de DataAnimation per carregar l'escena. Per últim en el mètode setFrame haurem de posar el mètode toGpu per tal que s'actualitzi l'escena a la GPU.

**Screenshots**

*(NOTA: Per a cada pas de l'enunciat (del 1 al 6), incloure captures de pantalla de les proves que heu fet per a demostrar la funcionalitat de la vostra pràctica amb explicacions de la seva configuració i com les heu aconseguides)*

*(NOTA2: Breu explicació, si cal, de com replicar els vostres resultats)*

**Additional Information**

Para información más detallada, hay varios issues abiertos sobre el desarrollo de las partes del proyecto:
- Parte 4: Shaders y opcional Toon
- Parte 5: texturas y pruebas con Blender
