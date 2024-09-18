#include "hotelbooking.h"
const QString &HotelBooking::getHotel() const
{
    return hotel;
}

const QString &HotelBooking::getTown() const
{
    return town;
}

 QString HotelBooking::getZimmerTyp()
{

        if(zimmerTyp == "EZ"){
            return "Einzelzimmer";
        } else if(zimmerTyp == "DZ"){
            return "Doppelzimmer";
        } else if(zimmerTyp == "SU"){
            return "Suite";
        } else {
            // Default case or if(zimmerTyp == "AP")
            return "Appartment";
        }
        return "Unknown";

}
 QString HotelBooking::getZimmerTypCode(const QString &zimmerTyp)
 {
     if (zimmerTyp == "Einzelzimmer") {
         return "EZ";
     } else if (zimmerTyp == "Doppelzimmer") {
         return "DZ";
     } else if (zimmerTyp == "Suite") {
         return "SU";
     } else if (zimmerTyp == "Appartment") {
         return "AP";
     } else {
         // Handle unknown type, you may throw an exception or return a default value
         return ""; // or throw std::invalid_argument("Unknown room type");
     }
 }

 void HotelBooking::setHotel(const QString &newHotel)
 {
     hotel = newHotel;
 }

 void HotelBooking::setTown(const QString &newTown)
 {
     town = newTown;
 }

 void HotelBooking::setZimmerTyp(const QString &newZimmerTyp)
 {
     zimmerTyp = newZimmerTyp;
 }

 double HotelBooking::getHotelLatitude() const
 {
     return hotelLatitude;
 }

 double HotelBooking::getHotelLongitude() const
 {
     return hotelLongitude;
 }

 QString HotelBooking::getType() const
 {
     return Type;
 }

 HotelBooking::HotelBooking(long travelid, QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2, QString hotel, QString town, QString zimmerTyp, double hotelLatitude, double hotelLongitude)
    :Booking(travelid,id,price,fromDate,toDate,predecessor1,predecessor2),hotel(hotel),town(town),zimmerTyp(zimmerTyp),hotelLatitude(hotelLatitude),hotelLongitude(hotelLongitude)
{

}

QString HotelBooking::showDetails() const
{
  QString s;
   QString fromDate1 = fromDate.toString("yyyy-MM-dd");
     QString toDate1 = toDate.toString("yyyy-MM-dd");
    s= "Hotelreservierung "+ id +" : Hotelreservierung im " + hotel + " in " + town;
    s+=" vom " + fromDate1 + " bis zum " + toDate1 + ". Preis: " + QString::number(price) + " Euro.";
    return s;
}
