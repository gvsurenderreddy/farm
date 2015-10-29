#include <iostream>
#include <src/utils/Datparser.h>
#include "farm.h"

int main(int argc, char** argv)
{
    std::cout << *argv <<std::endl;
    Datparser dpars("/home/stengun/mame166.dat");
    QFile *datfile = new QFile("/home/stengun/mame166.dat");
    dpars.startRead(datfile);
    int bios=0,mech=0,oth=0;
    while(true) {
        ItemCollection *col = dpars.readObject();
        if(col == nullptr) break;
/*
        std::cout << "Machine " << col->getName().toStdString() << std::endl;
        std::cout << "Description " << col->getDescription().toStdString() << std::endl;
        std::cout << "Manufacturer " << col->getManufacturer().toStdString() << std::endl;
        std::cout << "Year " << col->getYear() << std::endl;
        std::cout << "TYPE " << col->getType() << std::endl;
        std::cout << "Items " << col->getItemQuantity() << std::endl;

        QHash<QString, SItem>::iterator it = col->getItemIteratorBegin();
        for(it; it != col->getItemIteratorEnd(); ++it){
            std::cout << "rom " << it->getName().toStdString() << " "
                    << it->getSha1().toStdString() << " "
                    << it->getCrc().toStdString() << " " << it->getType() << std::endl;
        }

        std::cout << "-------------------------------------" << std::endl;*/
        switch(col->getType()) {
            case TYPE_BIOS:
                bios++;
                break;
            case TYPE_GAME:
            case TYPE_MECHANICAL:
                mech++;
                break;
            case TYPE_DEVICE:
                oth++;
            default:
                break;
        }
    }
    std::cout << "PARSED sets " << mech << std::endl;
    std::cout << "PARSED BIOS " << bios << std::endl;
    std::cout << "PARSED OTHER " << oth << std::endl;

//    Farm farm(argc, argv);
//    return farm.exec();
}
