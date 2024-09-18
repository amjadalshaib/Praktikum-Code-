#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <QString>
#include "booking.h"
#include <QDate>


class FlightBooking : virtual public Booking
{
private:
    QString fromDestination;
    QString toDestination;
    QString airline;
    QString reservationTyp;
    double fromDestLatitude;
    double fromDestLongitude;
    double toDestLatitude;
    double toDestLongitude;
    QString Type ="Flight";

public:
    FlightBooking(long travelid,QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2, QString fromDestination,
                  QString toDestination, QString airline,QString reservationTyp,double fromDestLatitude,
                  double fromDestLongitude,double toDestLatitude,double toDestLongitude);
    QString showDetails() const override;

    const QString &getFromDestination() const;
    const QString &getToDestination() const;
    const QString &getAirline() const;
    QString getReservationTyp();
    void setAirline(const QString &newAirline);
    void setFromDestination(const QString &newFromDestination);
    void setToDestination(const QString &newToDestination);
    void setReservationTyp(const QString &newReservationTyp);
    QString getReservationTypCode(const QString &reservationTyp);
    double getFromDestLatitude() const;
    double getFromDestLongitude() const;
    double getToDestLatitude() const;
    double getToDestLongitude() const;
    QString getType() const;
};

#endif // FLIGHTBOOKING_H
