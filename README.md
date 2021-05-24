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
        - [x] Escenes virtuals: Eric
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
Per fer el pas 1 hem hagut d'importar classes de la pràctica anterior ja que ja estava implementat el mapping de les dades reals. Hem netejat codi innecesari com el suport de diferents objectes ja que en aquesta práctica nomes hi existeix un tipus. Hem hagut d'implementar Translació i Escalament dels objectes (no els teniem dels brobjects) així com la implementació del terra i el posicionament dels objectes sobre aquest terra utilitzant la capsa contenidora.

Per carregar les escenes hem reutilitzat la idea de l'anterior práctica, mitjançant un fitxer amb la configuració de l'escena (configMapping) i un fitxer on cada linia representa el path del objecte i/o la seva textura afegim aquests objectes a l'escena. 

Com a guia:
- Per poder carregar una escena virtual: File -> Obre escena -> configMapping.txt -> virtualScene1.txt
- Per poder carregar dades: File -> Obre dades -> configMappingData.txt -> data10.txt

#### *PASOS 2 I 3*
En el desenvolupament dels passos 2 i 3, l'estratègia va ser molt semblant entre ells. Primer de tot, llegim el pas a pas del guió. En ambdós casos, vam tenir problemes amb l'enviament de les dades als shaders i, per tant, vam haver de tornar a fer els passos de mica en mica.

Un dels problemes més grans va ser que, per defecte, el codi venia amb un "include vec.h" a la classe de la llum que feia que no funcionés res, ja que se superposaven els imports vec.h de la classe i el vec.h de la llibreria importada. Vam arreglar aquest error amb el Ricardo a Laboratori.

A l'hora de testejar que l'enviament era correcte, vam posar el color de sortida com el vector que estàvem enviant. Per exemple, si el vector era vec4(1.0, 0.0, 0.0, 1.0), en carregar l'esfera s'hauria de veure vermella. Aquesta forma de testejar va ser tant pel pas 2 com 3.

#### *PAS 4*
#### *PAS 5*

### **_FASE 2_**

#### *TOON SHADING I ENFASIS DE SILUETES*

#### *ANIMACIONS*
En el desenvolupament de les animacions se'ns donava bastant codi ja implementat. En aquest cas, a l'hora de fer el desenvolupament, primer hem creat la classe DataAnimation per crear les escenes d'animació amb les transformacions geomètriques corresponents. Seguidament, vam crear un botó extra en el menú per poder carregar aquesta escena i evitar conflictes de codi amb els altres botons, com per exemple "Save and Start Animation". El mètode associat a aquest botó el trobarem a la classe Builder amb el nom saveAnimationScene. Aquí apliquem l'escena que vulguem dins de DataAnimation per carregar l'escena. Per últim en el mètode setFrame haurem de posar el mètode toGpu per tal que s'actualitzi l'escena a la GPU.

#### *NORMAL MAPPING*

## **Screenshots**

*(NOTA: Per a cada pas de l'enunciat (del 1 al 6), incloure captures de pantalla de les proves que heu fet per a demostrar la funcionalitat de la vostra pràctica amb explicacions de la seva configuració i com les heu aconseguides)*

*(NOTA2: Breu explicació, si cal, de com replicar els vostres resultats)*

## **Additional Information**

Para información más detallada, hay varios issues abiertos sobre el desarrollo de las partes del proyecto:
- Parte 4: Shaders y opcional Toon
- Parte 5: texturas y pruebas con Blender
