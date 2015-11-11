//
// Created by stengun on 19/10/15.
//

#include <iostream>
#include "Datparser.h"

Datparser::Datparser(QString path)
{
    this->path = path;
}

void Datparser::startRead(QFile *datfile)
{
    if(datfile->open(QFile::ReadOnly))
    {
        xmlstream.setDevice(datfile);
        xmlstream.readNextStartElement();
        if( xmlstream.name() == "mame" ) {
            std::cout << "Reading mame" << std::endl
                << "build " << xmlstream.attributes().value("build").toString().toStdString() << std::endl
                << "config " << xmlstream.attributes().value("mameconfig").toString().toStdString() << std::endl;
        }
        else
        {
            std::cerr << "This is not a valid mame datfile." << std::endl;
            xmlstream.device()->close();
            throw QFile::FatalError;
        }

    }
    else
    {
        std::cerr << datfile->error() << std::endl;
        throw QFile::OpenError;
    }
}

ItemCollection* Datparser::readObject()
{
    if(!xmlstream.readNextStartElement()) return nullptr;
    Q_ASSERT(xmlstream.isStartElement() && xmlstream.name() == "machine");
    ItemCollection* icol;
    QString name = xmlstream.attributes().value("name").toString();
    QString parent = xmlstream.attributes().hasAttribute("parent") ? xmlstream.attributes().value("parent").toString() : "" ;
    if( xmlstream.attributes().value("isbios") == "yes" )
    {
        icol = new Bios(name);
    }
    else if( xmlstream.attributes().value("ismechanical") == "yes" )
    {
        icol = new Mechanical(name);
    }
    else if( xmlstream.attributes().value("isdevice") == "yes")
    {
        icol = new Device(name);
    }
    else
    {
        icol = new Game(name);
    }
    icol->setParent(parent);
    while(xmlstream.readNextStartElement())
    {
        QString secname = xmlstream.name().toString();
        SItem* itm;
        if( secname == "rom" || secname == "sample") {
            if( secname == "rom" ) {
                itm = new Rom(xmlstream.attributes().value("name").toString());
                reinterpret_cast<Rom*>(itm)->setSize(xmlstream.attributes().value("size").toString().toInt());
            } else {
                itm = new Sample(xmlstream.attributes().value("name").toString());
            }
            itm->setCrc(xmlstream.attributes().value("crc").toString());
            itm->setSha1(xmlstream.attributes().value("sha1").toString());
            itm->setMerge(xmlstream.attributes().value("merge").toString());
            icol->addItem(itm);
        }
        else if( secname == "manufacturer" )
        {
            icol->setManufacturer(xmlstream.readElementText());
            continue;
        }
        else if( secname == "year" )
        {
            icol->setYear(xmlstream.readElementText().toInt());
            continue;
        }
        else if( secname == "description" )
        {
            icol->setDescription(xmlstream.readElementText());
            continue;
        }
        xmlstream.skipCurrentElement();
    }
    return icol;
};

Datparser::~Datparser()
{
    this->xmlstream.clear();
};