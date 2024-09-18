#ifndef TRAVEL_H
#define TRAVEL_H
#include "booking.h"
#include <string>
#include <vector>
#include <memory>
#include "graph.h"
#include "algorithmen.cpp"
using namespace std;

struct VertexData
{
    int vertexNumber;
    shared_ptr<Booking> booking;
};

class Travel
{
private:
    long travelID;
    long customerID;
    QString ID;
    vector<shared_ptr<Booking>> travelBookings;
    Graph<shared_ptr<Booking>, 20> graph;
     vector<VertexData> data;
public:
    Travel(long travelID, long customerID,QString ID);
    void addBooking(shared_ptr<Booking> booking);
     void addallBooking(shared_ptr<Booking> booking);
    long getCustomerID() const;
    const vector<shared_ptr<Booking>> &getTravelBookings() const;
    QString print();
    long getTravelID() const;
    QDate getstartDatum();
    QDate getendDatum();
    double getPrice();
    QString getID1();
    QString getallID();
    void clearevectore();
    void createGraph();
    const QString &getID() const;
    shared_ptr<Booking> findBooking(const QString& bookingID);
    int findBookingIndex(const QString& bookingId) const;
    void sortGraph();
    Graph<shared_ptr<Booking>, 20> getGraph() const;
    void checkHotelMidding(QString& s);
};

#endif // TRAVEL_H
