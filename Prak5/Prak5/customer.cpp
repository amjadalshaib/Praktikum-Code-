#include "customer.h"

long Customer::getId() const
{
    return id;
}

const vector<shared_ptr<Travel> > &Customer::getTravelList() const
{
    return travelList;
}

const QString &Customer::getLastName() const
{
    return lastName;
}

const QString &Customer::getFirstName() const
{
    return firstName;
}


void Customer::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}

void Customer::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}

shared_ptr<Travel> Customer::findid(QString ID)
{
for(auto &t:travelList){
    if(t->getID()==ID){
    return t;
    }
}
}/*
void Customer::deletevector()
{
travelList.clear();
}

*/Customer::Customer(long id, QString lastName, QString firstName)
    :id(id),lastName(lastName),firstName(firstName)
{

}

void Customer::addTravel(shared_ptr<Travel> travel)
{

       travelList.push_back(travel);
}
