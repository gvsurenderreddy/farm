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
    if( xmlstream.attributes().hasAttribute("isbios") )
    {
        icol = new Bios(name);
    }
    else if( xmlstream.attributes().hasAttribute("ismechanical") )
    {
        icol = new Mechanical(name);
    }
    else
    {
        icol = new Game(name);
    }
    icol->setParent(parent);
    while(xmlstream.readNextStartElement())
    {
        QString secname = xmlstream.name().toString();
        if( secname == "rom" )
        { //code duplication, merge asap
            SItem rom = Rom(xmlstream.attributes().value("name").toString());
            rom.setCrc(xmlstream.attributes().value("crc").toString());
            rom.setSha1(xmlstream.attributes().value("sha1").toString());
            rom.setMerge(xmlstream.attributes().value("merge").toString());
            ((Rom)rom).setSize(xmlstream.attributes().value("size").toInt());
            icol->addItem(rom);
        }
        else if( secname == "sample" )
        {
            SItem sample = Sample(xmlstream.attributes().value("name").toString());
            sample.setCrc(xmlstream.attributes().value("crc").toString());
            sample.setSha1(xmlstream.attributes().value("sha1").toString());
            sample.setMerge(xmlstream.attributes().value("merge").toString());
            icol->addItem(sample);
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