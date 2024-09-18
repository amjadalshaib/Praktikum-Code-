#include "airport.h"
const QString &Airport::getName() const
{
    return name;
}

Airport::Airport(QString name,QString iso_country,QString municipality,QString iata_code)
    :name(name),iso_country(iso_country),municipality(municipality),iata_code(iata_code){}
