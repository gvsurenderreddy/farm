#include <iostream>
#include <src/utils/Datparser.h>
#include "farm.h"

int main(int argc, char** argv)
{
    std::cout << *argv <<std::endl;
    Datparser dpars("/home/stengun/mame166.dat");
    QFile *datfile = new QFile("/home/stengun/mame166.dat");
    dpars.startRead(datfile);
    int count = 0;
    ItemCollection *col = dpars.readObject();
    while(col != nullptr) {
        std::cout << "Machine " << col->getName().toStdString() << std::endl;
        std::cout << "Description " << col->getDescription().toStdString() << std::endl;
        std::cout << "Manufacturer " << col->getManufacturer().toStdString() << std::endl;
        std::cout << "Year " << col->getYear() << std::endl;
        std::cout << "Items " << col->getItemQuantity() << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        col = dpars.readObject();
        count++;
    }
    std::cout << "PARSED ROMS " << count << std::endl;

//    Farm farm(argc, argv);
//    return farm.exec();
}
