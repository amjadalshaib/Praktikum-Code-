#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "travel.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Customer
{
private:
    long id;
    QString lastName;
    QString firstName;
    vector<shared_ptr<Travel>> travelList;
public:
    Customer(long id,QString lastName,QString firstName);
    void addTravel(shared_ptr<Travel> travel);
    long getId() const;
    const vector<shared_ptr<Travel>> &getTravelList() const;
    const QString &getLastName() const;
    const QString &getFirstName() const;
    QString print();
    void setLastName(const QString &newLastName);
    void setFirstName(const QString &newFirstName);
    shared_ptr<Travel> findid(QString ID);
    void deletevector();
};

#endif // CUSTOMER_H
