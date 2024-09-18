#include "check.h"
#include <vector>
#include <QDate>
#include <algorithm>
#include "rentalcarreservation.h"
#include <typeinfo>
Check::Check(shared_ptr<TravelAgency> travelAgency)
    :travelAgency(travelAgency){}

bool Check::operator()(QString &message)
{
    for(auto &c : travelAgency->getAllCustomer()){
        vector<shared_ptr<Travel>> travellist =  c->getTravelList();
        for(auto tlist : travellist){

            shared_ptr<Travel> t = travelAgency->findTravel(tlist->getTravelID());
            QDate smallestDate = QDate::fromString("25020514", "yyyyMMdd");
            QDate largestDate = QDate::fromString("10100111", "yyyyMMdd");
            for(auto &t1 : t->getTravelBookings()){

                // Iterate through the vector to find the smallest and largest dates
                if ( t1->getFromDate() < smallestDate) {
                    smallestDate = t1->getFromDate() ;
                }

                if (t1->getToDate() > largestDate) {
                    largestDate = t1->getToDate();
                }

            }
            for(auto &tlist1 : travellist){

                shared_ptr<Travel> t2 = travelAgency->findTravel(tlist1->getTravelID());
                for(auto &t3 : t2->getTravelBookings()){
                    if(tlist->getTravelID()!=tlist1->getTravelID()){
                        if ((t3->getFromDate() < smallestDate && t3->getFromDate() > largestDate) ||
                            (t3->getToDate() < smallestDate && t3->getToDate() > largestDate) ||
                            (t3->getFromDate() > smallestDate && t3->getToDate() < largestDate)) {
                            message+= " There is an overlaping\n";
                            message+="Customer: "+ QString::number(tlist->getCustomerID()) + "Travel ID " + QString::number(tlist->getTravelID())+ "\n";
                            message+="Customer: "+ QString::number(tlist1->getCustomerID()) + "Travel ID " + QString::number(tlist1->getTravelID())+ "\n"; ;
                            message += "small " + smallestDate.toString("yyyy-MM-dd") + " large " + largestDate.toString("yyyy-MM-dd") + "\n";

                            message += "from " + t3->getFromDate().toString("yyyy-MM-dd") + " to " + t3->getToDate().toString("yyyy-MM-dd") + "\n";


                        }
                    }


                }
                // neueAbgabe >= vorhandeneAbholung UND neueAbgabe <= vorhandenAbgabe
                // neueAbholung >= vorhandeneAbholung UND neueAbholung <= vorhandenAbgabe
                // neueAbholung <= vorhandeneAbholung UND neueAbgabe >= vorhandenAbgabe


            }

        }


    }
    if(!message.isEmpty()){
        return false;
    }else{
    return true;
    }
    }

bool Check::Customerc(long id, QString &message)
{
      shared_ptr<Customer> c = travelAgency->findCustomer(id);
        vector<shared_ptr<Travel>> travellist =  c->getTravelList();
        for(auto tlist : travellist){

            shared_ptr<Travel> t = travelAgency->findTravel(tlist->getTravelID());
            QDate smallestDate = QDate::fromString("25020514", "yyyyMMdd");
            QDate largestDate = QDate::fromString("10100111", "yyyyMMdd");
            for(auto &t1 : t->getTravelBookings()){

                // Iterate through the vector to find the smallest and largest dates
                if ( t1->getFromDate() < smallestDate) {
                    smallestDate = t1->getFromDate() ;
                }

                if (t1->getToDate() > largestDate) {
                    largestDate = t1->getToDate();
                }

            }
            for(auto &tlist1 : travellist){

                shared_ptr<Travel> t2 = travelAgency->findTravel(tlist1->getTravelID());
                for(auto &t3 : t2->getTravelBookings()){
                    if(tlist->getTravelID()!=tlist1->getTravelID()){
                        if ((t3->getFromDate() >= smallestDate && t3->getFromDate() <= largestDate) ||
                            (t3->getToDate() >= smallestDate && t3->getToDate() <= largestDate) ||
                            (t3->getFromDate() <= smallestDate && t3->getToDate() >= largestDate)) {
                            message+= " There is an overlaping\n";
                            message+="Customer: "+ QString::number(tlist->getCustomerID()) + "Travel ID " + QString::number(tlist->getTravelID())+ "\n";
                            message+="Customer: "+ QString::number(tlist1->getCustomerID()) + "Travel ID " + QString::number(tlist1->getTravelID())+ "\n"; ;
                            message += "small " + smallestDate.toString("yyyy-MM-dd") + " large " + largestDate.toString("yyyy-MM-dd") + "\n";

                            message += "from " + t3->getFromDate().toString("yyyy-MM-dd") + " to " + t3->getToDate().toString("yyyy-MM-dd") + "\n";

                            return false;
                        }
                    }


                }
                // neueAbgabe >= vorhandeneAbholung UND neueAbgabe <= vorhandenAbgabe
                // neueAbholung >= vorhandeneAbholung UND neueAbholung <= vorhandenAbgabe
                // neueAbholung <= vorhandeneAbholung UND neueAbgabe >= vorhandenAbgabe


            }

        }


        return true;
}
void Check::checkNoMissingHotels(QString &message) {
    for(auto &c : travelAgency->getAllCustomer()){
        vector<shared_ptr<Travel>> travellist =  c->getTravelList();
        for(auto &tlist : travellist){

    shared_ptr<Travel> checkTravel = this->travelAgency->findTravel(tlist->getTravelID());
    checkTravel->createGraph();
    checkTravel->checkHotelMidding(message);
        }
    }
    qDebug()<<"Hotel finished";
}

