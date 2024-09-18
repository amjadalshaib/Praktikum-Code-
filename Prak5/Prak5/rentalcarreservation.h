#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"
#include <QDate>
class RentalCarReservation : virtual public Booking
{
private:
    QString pickupLocation;
    QString returnLocation;
    QString company;
    QString Fahrzeugtypen;
    double pickupLatitude;
    double pickupLongitude;
    double returnLatitude;
    double returnLongitude;
    QString Type="Car";

public:
    RentalCarReservation(long travelid,QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2,
                         QString pickupLocation,QString returnLocation,QString company, QString Fahrzeugtypen,
                         double pickupLatitude,double pickupLongitude,double returnLatitude,double returnLongitude);
    QString showDetails() const  override;

    const QString &getPickupLocation() const;
    const QString &getReturnLocation() const;
    const QString &getCompany() const;
    QString getFahrzeugtypen();

    void setPickupLocation(const QString &newPickupLocation);
    void setReturnLocation(const QString &newReturnLocation);
    void setCompany(const QString &newCompany);
    void setFahrzeugtypen(const QString &newFahrzeugtypen);
    double getPickupLatitude() const;
    double getPickupLongitude() const;
    double getReturnLatitude() const;
    double getReturnLongitude() const;
    QString getType() const;
};

#endif // RENTALCARRESERVATION_H
