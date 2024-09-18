#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include "booking.h"
#include "customer.h"
#include "travel.h"
#include "qwidget.h"
#include <vector>
#include <QString>
#include <map>
#include <memory>
#include <QMap>
#include "airport.h"
using namespace std;

class TravelAgency
{
private:
    vector<shared_ptr<Booking>> allBookings;
    vector<shared_ptr<Customer>> allCustomer;
    vector<shared_ptr<Travel>> allTravels;
    int flightBookingsCount;
    int hotelBookingsCount;
    int rentalCarBookingsCount;
    int trainBookingsCount;
    double totalFlightValue;
    double totalHotelValue;
    double totalRentalCarValue;
    double totalTrainValue;
    map<QString, shared_ptr<Airport>> myMap;
public:
    TravelAgency();
    ~TravelAgency();
    void readFile(QString fileName, QString &message);
    void readISO();
    void readBinaryFile();
    const vector<shared_ptr<Booking>> &getBookings() const;
    QString showBookingStatsJ() const;
    void deleteVector();
    void resteData();
    QString printALL();
    shared_ptr<Booking> findBooking(QString id);
    shared_ptr<Travel> findTravel(long id) const;
    shared_ptr<Customer> findCustomer(long id);
    shared_ptr<Booking> find(int index);
    const vector<shared_ptr<Travel>> &getAllTravels() const;
    void changeData(QString id, QString attribute, QString newData);
    void setAllBookings(QDate from, QString id);
    void writeToFile(QString fileName, QString &message);
    shared_ptr<Travel> findBookint(QString id);
    QString findmyMAp(QString searchCode);


    vector<shared_ptr<Customer> > getAllCustomer() const;
};

#endif // TRAVELAGENCY_H
