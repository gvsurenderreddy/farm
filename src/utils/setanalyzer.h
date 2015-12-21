//
// Created by stengun on 15/12/15.
//

#ifndef FARM_SETANALYZER_H
#define FARM_SETANALYZER_H


class Analizer {
public:
    Analizer(QString setname);
    Analizer(ItemCollection itm);
    void analyze();
    void getFixable();
};

class AnalisysResult {
private:
    QMap fixable;
};
#endif //FARM_SETANALYZER_H
