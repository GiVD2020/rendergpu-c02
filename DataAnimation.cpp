#include "DataAnimation.h"


DataAnimation::DataAnimation()
{

}

void DataAnimation::OneSphere(shared_ptr<Scene> s){
    QString s1("://resources/models/sphere1.obj");
    shared_ptr<Object> obj1 = make_shared<Object>(100000, s1);
    // ... Troç de codi just per a afegir animació a l'objecte
    shared_ptr<Animation> anim = make_shared<Animation>();
    anim->transf = make_shared<TranslateTG>(vec3(0.2));
    obj1->addAnimation(anim);
    s->objects.push_back(obj1);
}
