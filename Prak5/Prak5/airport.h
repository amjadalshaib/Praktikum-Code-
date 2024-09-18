#ifndef AIRPORT_H
#define AIRPORT_H
#include <QString>
#include <map>
#include <memory>
#include <QMap>


class Airport
{    QString name;
     QString iso_country;
     QString municipality;
     QString iata_code;

 public:

      Airport(QString name,QString iso_country,QString municipality,QString iata_code);
       const QString &getName() const;
};

#endif // AIRPORT_H
