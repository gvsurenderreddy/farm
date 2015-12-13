//
// Created by stengun on 19/10/15.
//

#include <iostream>
#include "Datparser.h"
#include <QtDebug>

Datparser::Datparser(QString path)
{
    this->datfile = new QFile(path);
    this->totalsets=0;
}

void Datparser::startRead()
{
    if(datfile->open(QFile::ReadOnly))
    {
        xmlstream.setDevice(datfile);
        xmlstream.readNextStartElement();
        if( xmlstream.name() == "mame" ) {
            qInfo("Reading mame");
            qInfo() << "build:" << xmlstream.attributes().value("build").toString();
            qInfo() << "config:" << xmlstream.attributes().value("mameconfig").toString();
        }
        else
        {
            xmlstream.device()->close();
            qFatal("This is not a valid mame datfile.");
        }
        while (!xmlstream.atEnd()) {
            xmlstream.readNextStartElement();
            totalsets++;
            xmlstream.skipCurrentElement();
        }
        datfile->seek(0);
        xmlstream.setDevice(datfile);
        xmlstream.readNextStartElement();
    }
    else
    {
        qCritical("xml file error: %s", datfile->error());
    }
}

ItemCollection* Datparser::readObject()
{
    std::lock_guard<std::mutex> Guard(this->Mutex);
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

int Datparser::getTotalSets() {
    return this->totalsets;
}
