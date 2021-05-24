# RenderGPU
Segona pràctica de GiVD 2020-21

    Ángel Morales Carrasco NIUB 20150546
    Eric Duque Martín NIUB 20150443
    Oriol Saguillo González NIUB 20150502
    María Isabel González Sánchez NIUB 20221913
    
## **Abstract**

Per aquesta pràctica, hem pogut adaptar la Pràctica 1 i desenvolupar tota la part obligatòria de la Pràctica 2 (Fase 1). A més, hem implementat alguns opcionals de la Fase 1 i de la Fase 2. Ens hem repartit la feina de manera equitativa i proporcional a les aptituds de cada membre del grup: les parts més teòriques han sigut per l'Oriol, les parts més pràctiques per l'Àngel i l'Eric i la part més "artística" ha sigut per la Maribel.

Encara que cadascun ha treballat de forma més individual, tots hem avançat al nostre ritme fins a la setmana anterior a l'entrega. Arribat aquest punt, ens hem posat tot d'acord per repartir-nos la feina que encara quedava i decidir quins opcionals eren més interessants i útils per l'escena. Tot i això, estem molt contents del resultat de la pràctica en general, dels posts que hem fet als issues del projecte per explicar certes fases de la pràctica i dels testeos que hem fet per triar una escena pel padlet.

## **Features**

- Fase 1
    - Adaptació a la lectura de fitxers de dades
        - [x] Objectes: Eric, Angel
        - [x] Escenes virtuals: Eric, Angel
        - [x] Escenes de dades Reals: Eric, Angel
    - Material: Oriol
    - Light
        - [x] Puntual: Oriol
        - [x] Direccional: Oriol
        - [x] Spotlight: Oriol, María Isabel
        - [x] Ambient Global: Oriol
    - Shading
        - [X] Phong: María Isabel
        - [X] Gouraud: Maria Isabel
    - Textures
        - [x] Textura com material en un objecte: Eric, Angel
        - [x] Textura al pla base: Eric, Angel
        

- Fase 2 (OPT)
    - [x] Toon-shading i èmfasi de siluetes: María Isabel
    - [ ] Mapping indirecte de textures
    - [x] Animacions amb dades temporals: Oriol 
    - [x] Normal mapping: Angel
    - [ ] Entorn amb textures
    - [ ] Reflexions
    - [ ] Transparencias via objectes.
    - [ ] Transparencias via environmental mapping.


## **Extensions**

*(NOTA: Les extensions de la pràctica que heu fet i que no surten a la llista anterior)*

## **Memòria**

*(NOTA: Explicació només dels diferents punts que heu desenvolupat i funcionen, detallant les estratègies que heu fet servir)*
### **_FASE 1_**


#### *PAS 1*

#### *PASOS 2 I 3*
En el desenvolupament dels passos 2 i 3, l'estratègia va ser molt semblant entre ells. Primer de tot, llegim el pas a pas del guió. En ambdós casos, vam tenir problemes amb l'enviament de les dades als shaders i, per tant, vam haver de tornar a fer els passos de mica en mica.

Un dels problemes més grans va ser que, per defecte, el codi venia amb un "include vec.h" a la classe de la llum que feia que no funcionés res, ja que se superposaven els imports vec.h de la classe i el vec.h de la llibreria importada. Vam arreglar aquest error amb el Ricardo a Laboratori.

A l'hora de testejar que l'enviament era correcte, vam posar el color de sortida com el vector que estàvem enviant. Per exemple, si el vector era vec4(1.0, 0.0, 0.0, 1.0), en carregar l'esfera s'hauria de veure vermella. Aquesta forma de testejar va ser tant pel pas 2 com 3.

#### *PAS 4*
#### *PAS 5*
Per realitzar el pas de les textures primerament, amb molt de compte hem anat modificant els mètodes de object per poder enviar les textures a gpu (drawtexture(),toGPUTexture()). Una vegada creiem que hem realitzat bé aquesta part hem programat uns shaders molt simples, que simplement posaven a cada punt la textura sense Phong ni cap il·luminació (vshaderText i fshaderText). Una vegada hem aconseguit veure la textura plana, amb molt de compte hem copiat els shaders de Phong i canviat la component difusa del material per la de la textura. D'aquesta manera ja podíem visualitzar les textures amb Phong.

### **_FASE 2_**

#### *TOON SHADING I ENFASIS DE SILUETES*

#### *ANIMACIONS*
En el desenvolupament de les animacions se'ns donava bastant codi ja implementat. En aquest cas, a l'hora de fer el desenvolupament, primer hem creat la classe DataAnimation per crear les escenes d'animació amb les transformacions geomètriques corresponents. Seguidament, vam crear un botó extra en el menú per poder carregar aquesta escena i evitar conflictes de codi amb els altres botons, com per exemple "Save and Start Animation". El mètode associat a aquest botó el trobarem a la classe Builder amb el nom saveAnimationScene. Aquí apliquem l'escena que vulguem dins de DataAnimation per carregar l'escena. Per últim en el mètode setFrame haurem de posar el mètode toGpu per tal que s'actualitzi l'escena a la GPU.

#### *NORMAL MAPPING*
Per programar el normal mapping, primerament hem canviat els shaders que teníem abans que aplicaven una textura canviant la component difosa, per uns que deixaven la component difosa sempre en blanc i multiplicaven les components de les normals pels valors de les textures. Fent això, una vegada executem, veiem com tenim carregat un objecte, en el nostre cas hem utilitzat un model de Júpiter i observem que el color de l'objecte és blanc, però veiem un "relleu" quan s'il·lumina la figura que ens indica que estem fent normal mapping correctament. Ara toca modificar els mètodes addTexture() de GLwidget, perquè quan afegim un fitxer de textura puguem afegir un fitxer de textura associat que conté les normals. Ara modifiquem el mètode toGPU(), per poder passar dues textures al shaderPhongTextNormal. Per últim modifiquem els shaders creats anteriorment per poder modificar la component difusa amb la primera textura i la normal amb la segona.

## **Screenshots**

*(NOTA: Per a cada pas de l'enunciat (del 1 al 6), incloure captures de pantalla de les proves que heu fet per a demostrar la funcionalitat de la vostra pràctica amb explicacions de la seva configuració i com les heu aconseguides)*

*(NOTA2: Breu explicació, si cal, de com replicar els vostres resultats)*

## **Additional Information**

Para información más detallada, hay varios issues abiertos sobre el desarrollo de las partes del proyecto:
- Parte 4: Shaders y opcional Toon
- Parte 5: texturas y pruebas con Blender
