#include "rentalcarreservation.h"
const QString &RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

const QString &RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

const QString &RentalCarReservation::getCompany() const
{
    return company;
}

QString RentalCarReservation::getFahrzeugtypen()
{
    return Fahrzeugtypen;
}


void RentalCarReservation::setPickupLocation(const QString &newPickupLocation)
{
    pickupLocation = newPickupLocation;
}

void RentalCarReservation::setReturnLocation(const QString &newReturnLocation)
{
    returnLocation = newReturnLocation;
}

void RentalCarReservation::setCompany(const QString &newCompany)
{
    company = newCompany;
}

void RentalCarReservation::setFahrzeugtypen(const QString &newFahrzeugtypen)
{
    Fahrzeugtypen = newFahrzeugtypen;
}

double RentalCarReservation::getPickupLatitude() const
{
    return pickupLatitude;
}

double RentalCarReservation::getPickupLongitude() const
{
    return pickupLongitude;
}

double RentalCarReservation::getReturnLatitude() const
{
    return returnLatitude;
}

double RentalCarReservation::getReturnLongitude() const
{
    return returnLongitude;
}

QString RentalCarReservation::getType() const
{
    return Type;
}

RentalCarReservation::RentalCarReservation(long travelid, QString id, double price, QDate fromDate,
                                           QDate toDate, QString predecessor1, QString predecessor2, QString pickupLocation, QString returnLocation, QString company
           , QString Fahrzeugtypen, double pickupLatitude, double pickupLongitude, double returnLatitude, double returnLongitude)
    :Booking(travelid,id,price,fromDate,toDate,predecessor1,predecessor2),pickupLocation(pickupLocation),returnLocation(returnLocation)
    ,company(company),Fahrzeugtypen(Fahrzeugtypen),pickupLatitude(pickupLatitude),pickupLongitude(pickupLongitude),returnLatitude(returnLatitude),returnLongitude(returnLongitude)
{

}

QString RentalCarReservation::showDetails() const
{
QString s;
QString fromDate1 = fromDate.toString("yyyy-MM-dd");
  QString toDate1 = toDate.toString("yyyy-MM-dd");
   s="Mietwagenreservierung "+ id+" : Mietwagenreservierung mit "+company +". Abholung am ";
   s+=fromDate1+" in "+ pickupLocation+". Rückgabe am ";
    s+=toDate1+" in "+returnLocation+". Preis: "+QString::number(price)+" Euro.";
    return s;
}
