#ifndef BOOKING_H
#define BOOKING_H
#include "qdatetime.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QString>
#include <QDate>
#include <memory>
using namespace std;

class Booking
{
protected:
    long travelid;
    QString id;
    double price;
    QDate fromDate;
    QDate toDate;
    QString predecessor1;
    QString predecessor2;
public:
    Booking(long travelid,QString id,double price,QDate fromDate,QDate toDate,QString predecessor1,QString predecessor2);
  virtual QString showDetails() const =0;

    QString &getId() ;
    double getPrice() const;
    QDate getFromDate() const;
    QDate getToDate() const;
   void setFromDate(const QDate &newFromDate);
   void setToDate(const QDate &newToDate);
   void setPrice(double newPrice);
   long getTravelid() const;
   QString getPredecessor1() const;
   QString getPredecessor2() const;
  // virtual string getType()=0;
};

#endif // BOOKING_H
