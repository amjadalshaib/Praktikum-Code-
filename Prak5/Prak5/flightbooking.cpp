#include "flightbooking.h"
const QString &FlightBooking::getFromDestination() const
{
    return fromDestination;
}

const QString &FlightBooking::getToDestination() const
{
    return toDestination;
}

const QString &FlightBooking::getAirline() const
{
    return airline;
}

QString FlightBooking::getReservationTyp()
{

        if(reservationTyp == "Y"){
            return "Economy";
        } else if(reservationTyp == "W"){
            return "Premium Economy";
        } else if(reservationTyp == "J"){
            return "Business";
        } else if(reservationTyp == "F"){
             return "First";
        }
 return "Unknown";
}
QString FlightBooking::getReservationTypCode(const QString &reservationTyp)
{
    if (reservationTyp == "Economy") {
        return "Y";
    } else if (reservationTyp == "Premium Economy") {
        return "W";
    } else if (reservationTyp == "Business") {
        return "J";
    } else if (reservationTyp == "First") {
        return "F";
    } else {
        // Handle unknown type, you may throw an exception or return a default value
        return ""; // or throw std::invalid_argument("Unknown reservation type");
    }
}

void FlightBooking::setAirline(const QString &newAirline)
{
    airline = newAirline;
}

void FlightBooking::setFromDestination(const QString &newFromDestination)
{
    fromDestination = newFromDestination;
}

void FlightBooking::setToDestination(const QString &newToDestination)
{
    toDestination = newToDestination;
}

void FlightBooking::setReservationTyp(const QString &newReservationTyp)
{
    reservationTyp = newReservationTyp;
}

double FlightBooking::getFromDestLatitude() const
{
    return fromDestLatitude;
}

double FlightBooking::getFromDestLongitude() const
{
    return fromDestLongitude;
}

double FlightBooking::getToDestLatitude() const
{
    return toDestLatitude;
}

double FlightBooking::getToDestLongitude() const
{
    return toDestLongitude;
}

QString FlightBooking::getType() const
{
    return Type;
}

FlightBooking::FlightBooking(long travelid, QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2, QString fromDestination, QString toDestination, QString airline, QString reservationTyp
                             , double fromDestLatitude,
                                 double fromDestLongitude, double toDestLatitude, double toDestLongitude)
    :Booking(travelid,id,price,fromDate,toDate,predecessor1,predecessor2),fromDestination(fromDestination),toDestination(toDestination)
    ,airline(airline),reservationTyp(reservationTyp),fromDestLatitude(fromDestLatitude),fromDestLongitude(fromDestLongitude)
    ,toDestLatitude(toDestLatitude),toDestLongitude(toDestLongitude)

{

}



QString FlightBooking::showDetails() const
{
    QString s;
    QString fromDate1 = fromDate.toString("yyyy-MM-dd");
      s = "Flugbuchung " + id + " : Flugbuchung von " + fromDestination + " nach ";
      s += toDestination + " mit " + airline + " am " + fromDate1 + ". Preis: ";
      s += QString::number(price) + " Euro.";
      return s;
}
