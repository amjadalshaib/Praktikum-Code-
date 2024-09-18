#include "trainticket.h"

const QString &TrainTicket::getDepartureTime() const
{
    return departureTime;
}

const QString &TrainTicket::getToDestination() const
{
    return toDestination;
}

const QString &TrainTicket::getFromDestination() const
{
    return fromDestination;
}

const QString &TrainTicket::getArrivalTime() const
{
    return arrivalTime;
}

QString TrainTicket::getSittingKlasse()
{
    QString typ;
    if(sittingKlasse == "SSP1"){
       return "Supersparpreis 1. Klasse";
    }else if(sittingKlasse== "SSP2"){
        return "Supersparpreis 2. Klasse";
    }else if(sittingKlasse == "SP1"){
        return  "Sparpreis 1. Klasse";
    }else if(sittingKlasse == "SP2"){
        return  "Sparpreis 2. Klasse";
    }else if(sittingKlasse == "FP1"){
        return "Flexpreis 1. Klasse";
    }else{
        return "Flexpreis 2. Klasse";
    }

}
QString TrainTicket::getSittingKlasseCode(const QString &typ)
{
    if (typ == "Supersparpreis 1. Klasse") {
        return "SSP1";
    } else if (typ == "Supersparpreis 2. Klasse") {
        return "SSP2";
    } else if (typ == "Sparpreis 1. Klasse") {
        return "SP1";
    } else if (typ == "Sparpreis 2. Klasse") {
        return "SP2";
    } else if (typ == "Flexpreis 1. Klasse") {
        return "FP1";
    } else if (typ == "Flexpreis 2. Klasse") {
        return "FP2";
    } else {
        // Handle unknown type, you may throw an exception or return a default value
        return ""; // or throw std::invalid_argument("Unknown sitting class");
    }
}

void TrainTicket::setFromDestination(const QString &newFromDestination)
{
    fromDestination = newFromDestination;
}

void TrainTicket::setToDestination(const QString &newToDestination)
{
    toDestination = newToDestination;
}

void TrainTicket::setDepartureTime(const QString &newDepartureTime)
{
    departureTime = newDepartureTime;
}

void TrainTicket::setArrivalTime(const QString &newArrivalTime)
{
    arrivalTime = newArrivalTime;
}

void TrainTicket::setSittingKlasse(const QString &newSittingKlasse)
{
    sittingKlasse = newSittingKlasse;
}



const vector<Connections *> &TrainTicket::getConnectingStation() const
{
    return connectingStation;
}

void TrainTicket::setConnectingStation(const vector<Connections *> &newConnectingStation)
{
    connectingStation = newConnectingStation;
}

double TrainTicket::getFromStationLatitude() const
{
    return fromStationLatitude;
}

double TrainTicket::getFromStationLongitude() const
{
    return fromStationLongitude;
}

double TrainTicket::getToStationLatitude() const
{
    return toStationLatitude;
}

double TrainTicket::getToStationLongitude() const
{
    return toStationLongitude;
}

QString TrainTicket::getType() const
{
    return Type;
}

TrainTicket::TrainTicket(long travelid, QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2,
                             QString fromDestination, QString toDestination, QString departureTime, QString arrivalTime,
      vector<Connections*> connectingStation, QString sittingKlasse, double fromStationLatitude, double fromStationLongitude, double toStationLatitude, double toStationLongitude)
        :Booking(travelid,id,price,fromDate,toDate,predecessor1,predecessor2),fromDestination(fromDestination),toDestination(toDestination),
          departureTime(departureTime),arrivalTime(arrivalTime),sittingKlasse(sittingKlasse), connectingStation(connectingStation)
        ,fromStationLatitude(fromStationLatitude),fromStationLongitude(fromStationLongitude),toStationLatitude(toStationLatitude),toStationLongitude(toStationLongitude)
    {

    }

    QString TrainTicket::showDetails() const
    {
        QString s;
        QString fromDate1 = fromDate.toString("yyyy-MM-dd");
     //   QString toDate1 = toDate.toString("yyyy-MM-dd");
        s="Zugticket "+ id + " : Zugticket von "+ fromDestination+" nach "+toDestination+" am ";
        s+=fromDate1+"von "+departureTime+" bis "+arrivalTime +" uber ";
        for(auto &auto1 : connectingStation){
            s+=auto1->stationName+", ";
        }
        s+=". Preis: "+QString::number(price)+" Euro.";
        return s;
    }
    QTime TrainTicket::getQTimeDeparture() const {
        return QTime::fromString(departureTime, "hh:mm");
    }

    QTime TrainTicket::getQTimeArrival() const {
        return QTime::fromString(arrivalTime, "hh:mm");
    }
    void TrainTicket::setQTimeDeparture(const QTime &newDepartureTime) {
        departureTime = newDepartureTime.toString("hh:mm");
    }

    void TrainTicket::setQTimeArrival(const QTime &newArrivalTime) {
        arrivalTime = newArrivalTime.toString("hh:mm");
    }

    double Connections::getLongitudel() const
    {
        return longitudel;
    }

    QString Connections::getStationName() const
    {
        return stationName;
    }

    double Connections::getLatitude() const
    {
        return latitude;
    }
