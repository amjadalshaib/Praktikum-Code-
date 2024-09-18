#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"
#include <QDate>
class HotelBooking : virtual public Booking
{
private:
    QString hotel;
    QString town;
    QString zimmerTyp;
    double hotelLatitude;
    double hotelLongitude;
    QString Type = "Hotel";
public:
    HotelBooking(long travelid,QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2, QString hotel,
                 QString town,QString zimmerTyp,double hotelLatitude,
    double hotelLongitude);
    QString showDetails() const override;

    const QString &getHotel() const;
    const QString &getTown() const;
    QString getZimmerTyp();
    void setHotel(const QString &newHotel);
    void setTown(const QString &newTown);
    void setZimmerTyp(const QString &newZimmerTyp);
    QString getZimmerTypCode(const QString &zimmerTyp);
    double getHotelLatitude() const;
    double getHotelLongitude() const;
    QString getType() const;
};

#endif // HOTELBOOKING_H
