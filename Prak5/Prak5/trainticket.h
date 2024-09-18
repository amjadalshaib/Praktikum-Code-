#ifndef TRAINTICKET_H
#define TRAINTICKET_H
#include "booking.h"
#include <vector>
#include <QDate>
struct Connections{
    double latitude;
    double longitudel;
    QString stationName;

public:
    Connections(double latitude,double longitudel,QString stationName)
        :latitude(latitude),longitudel(longitudel),stationName(stationName){}

    double getLatitude() const;
    double getLongitudel() const;
    QString getStationName() const;
};

    class TrainTicket : virtual public Booking
    {
    private:
        QString fromDestination;
        QString toDestination;
        QString departureTime;
        QString arrivalTime;
        QString sittingKlasse;
        vector<Connections*> connectingStation;
        double fromStationLatitude;
        double fromStationLongitude;
        double toStationLatitude;
        double toStationLongitude;
        QString Type ="Train";
    public:
        TrainTicket(long travelid,QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2,
                    QString fromDestination,QString toDestination,QString departureTime,QString arrivalTime
                    ,vector<Connections*> connectingStation, QString sittingKlasse,double fromStationLatitude,
                    double fromStationLongitude,double toStationLatitude,double toStationLongitude);
        QString showDetails() const override;


        const QString &getDepartureTime() const;
        const QString &getToDestination() const;
        const QString &getFromDestination() const;
        const QString &getArrivalTime() const;
        QString getSittingKlasse();
        void setFromDestination(const QString &newFromDestination);
        void setToDestination(const QString &newToDestination);
        void setDepartureTime(const QString &newDepartureTime);
        void setArrivalTime(const QString &newArrivalTime);
        void setSittingKlasse(const QString &newSittingKlasse);
        QTime getQTimeDeparture() const;
        QTime getQTimeArrival() const;
        void setQTimeDeparture(const QTime &newDepartureTime);
        void setQTimeArrival(const QTime &newArrivalTime);

        QString getSittingKlasseCode(const QString &typ);
        const vector<Connections *> &getConnectingStation() const;
        void setConnectingStation(const vector<Connections *> &newConnectingStation);
        double getFromStationLatitude() const;
        double getFromStationLongitude() const;
        double getToStationLatitude() const;
        double getToStationLongitude() const;
        QString getType() const;
    };

#endif // TRAINTICKET_H
