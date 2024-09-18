#ifndef CHECK_H
#define CHECK_H
#include "travelagency.h"
#include <memory>
using namespace std;


class Check
{
private:
    shared_ptr<TravelAgency> travelAgency;
public:
    Check(shared_ptr<TravelAgency> travelAgency);
    bool operator()(QString& message);
    bool Customerc(long id, QString &message);
    void checkNoMissingHotels(QString &message);

};

#endif // CHECK_H
