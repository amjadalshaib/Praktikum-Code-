// booking.cpp
#include "booking.h"

QString &Booking::getId() {
    return id;
}

double Booking::getPrice() const {
    return price;
}

 QDate Booking::getFromDate() const { // Corrected definition
    return fromDate;
}

 QDate Booking::getToDate() const {
    return toDate;
}

 void Booking::setFromDate(const QDate &newFromDate)
 {
     fromDate = newFromDate;
 }

 void Booking::setToDate(const QDate &newToDate)
 {
     toDate = newToDate;
 }

 void Booking::setPrice(double newPrice)
 {
     price = newPrice;
 }

 long Booking::getTravelid() const
 {
     return travelid;
 }

 QString Booking::getPredecessor1() const
 {
     return predecessor1;
 }

 QString Booking::getPredecessor2() const
 {
     return predecessor2;
 }

 Booking::Booking(long travelid, QString id, double price, QDate fromDate, QDate toDate, QString predecessor1, QString predecessor2)
     : travelid(travelid),id(id), price(price), fromDate(fromDate), toDate(toDate),predecessor1(predecessor1),predecessor2(predecessor2) {
}
