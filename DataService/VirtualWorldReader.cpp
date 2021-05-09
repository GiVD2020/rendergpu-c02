#include "VirtualWorldReader.h"


VirtualWorldReader::VirtualWorldReader(shared_ptr<Scene> s)
{
    scene = s;
}

void VirtualWorldReader::readFile(QString fileName, shared_ptr<Mapping> map) {

    mapping = map;
    std::cout << fileName.toStdString()<<std::endl;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error opening the file" << std::endl;
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        fileLineRead(line);
    }

    file.close();
}

// TODO: Fase 1: Cal afegir més tipus d'objectes
void VirtualWorldReader::fileLineRead (QString lineReaded) {

    QStringList fields = lineReaded.split(",");

    if(QString::compare("object", fields[0], Qt::CaseInsensitive) == 0)
        brObjectFound(fields);

    else
        std::cerr << "Element unknown" << std::endl;
}

void VirtualWorldReader::brObjectFound(QStringList fields) {

    // TODO Fase 1: Per incloure BrObjecte
    //  Es suposa que serà una linia del fitxer de l'estil
    //  brobject, nomDelFitxer, propietats del material, textura

    if (fields.size() != 5 && fields.size() != 16) {
        std::cerr << "Wrong brObject format" << std::endl;
        return;
    }

    shared_ptr<Object> o;

    vector<vec3> points;
    vector<double> properties;

    o = ObjectFactory::getInstance().createObject(points, properties, -1.0f, fields[1]);
    /*
    if(fields.length() == 5){
        auto mat = make_shared<Lambertian>(vec3(fields[2].toDouble(),fields[3].toDouble(),fields[4].toDouble()));
    }else{
        auto mat = make_shared<Lambertian>(vec3(fields[2].toDouble(),fields[3].toDouble(),fields[4].toDouble()),
                vec3(fields[5].toDouble(),fields[6].toDouble(),fields[7].toDouble()), vec3(fields[8].toDouble(),
                fields[9].toDouble(),fields[10].toDouble()),vec3(fields[11].toDouble(),fields[12].toDouble(),fields[13].toDouble()),
                fields[14].toDouble());

        o->setMaterial(mat);
    }*/

    scene->objects.push_back(o);


}


