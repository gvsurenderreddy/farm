//
// Created by stengun on 15/12/15.
//

#include <QtCore/qcryptographichash.h>
#include <iomanip>
#include "FolderParser.h"

ItemCollection* SetReader::itemFromZip(QString path) {
    QuaZip setfile(path);
    if(setfile.open(QuaZip::mdUnzip)) {
        QCryptographicHash hasher(QCryptographicHash::Sha1);
        QuaZipFile zipfile(&setfile);
        ItemCollection* retval = new Game(setfile.getCurrentFileName());
        retval->setName(setfile.getZipName());
        qInfo() << setfile.getZipName();
        for( QuaZipFileInfo file : setfile.getFileInfoList()) {
            //zipfile.setFileName(file.name);
            Rom* tmprom = new Rom();
            setfile.setCurrentFile(file.name);
            zipfile.open(QIODevice::ReadOnly);
            hasher.addData(&zipfile);
            tmprom->setName(file.name);
            tmprom->setSha1(QString(hasher.result().toHex()));
            tmprom->setCrc(QString("%1").arg(file.crc, 8, 16, QLatin1Char( '0' )));
            tmprom->setSize(file.uncompressedSize);
            qInfo() << "file name" << tmprom->getName() << "sha1" << tmprom->getSha1() << "crc" << tmprom->getCrc()  << "size" << tmprom->getSize();
            zipfile.close();
            hasher.reset();
        }
        return retval;
    } else
        return nullptr;
};