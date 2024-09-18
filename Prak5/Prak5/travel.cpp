#include "travel.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "trainticket.h"
#include <memory>
long Travel::getCustomerID() const
{
    return customerID;
}

const vector<shared_ptr<Booking>> &Travel::getTravelBookings() const
{
    return travelBookings;
}



long Travel::getTravelID() const
{
    return travelID;
}

QDate Travel::getstartDatum()
{
for(auto b : travelBookings){

    return  b->getFromDate();
}
}

QDate Travel::getendDatum()
{
    for(auto booking : travelBookings){

        return  booking->getToDate();
    }
}

double Travel::getPrice()
{
    for(auto booking : travelBookings){

        return  booking->getPrice();
    }
}
QString Travel::getID1()
{
    for(auto booking : travelBookings){

        return  booking->getId();
    }
}

void Travel::createGraph()
{

    for (int i = 0; i < travelBookings.size(); i++)
    {
        graph.insertVertex(i, travelBookings[i]);
    }
    for(int i=0;i<travelBookings.size();i++)
    {
        graph.insertVertex(i, travelBookings[i]);
    }
    // Connect bookings based on predecessors
    for (int i = 0; i < travelBookings.size(); i++)
    {
        auto booking1 = travelBookings[i];
        for (int j = 0; j < travelBookings.size(); j++)
        {
            auto booking2 = travelBookings[j];
            if (booking1->getId()!=booking2->getId() && (booking1->getId() == booking2->getPredecessor1() || booking1->getId() == booking2->getPredecessor2()))
            {
                this->graph.insertEdge(i, j);
            }
        }
    }
    sortGraph();
   // graph.printVertices();
}

void Travel::sortGraph()
{
    depthFirstSearch(graph);
    if(data.size() == 0)
    {
        for (int i = 0; i < travelBookings.size(); i++)
        {
            VertexData vertexData;
            vertexData.booking = graph.getVertexValue(i);
            vertexData.vertexNumber = graph.getEnd(i);
            this->data.push_back(vertexData);
        }

        for (unsigned int step = 0; step < this->data.size(); step++)
        {
            int max = step;
            for (unsigned int i = step + 1; i < data.size(); i++)
            {
                if(this->data[i].vertexNumber > this->data[max].vertexNumber)
                    max = i;
            }
            VertexData temp = this->data[max];
            this->data[max] = this->data[step];
            this->data[step] = temp;
        }
    }
}

//ADD check data
void Travel::checkHotelMidding(QString &s)
{

    for(int i =0; i< data.size();i++){

        if (std::dynamic_pointer_cast<TrainTicket>(data[i].booking) || std::dynamic_pointer_cast<FlightBooking>(data[i].booking))
        {

            QDate smallestDate = data[i].booking->getFromDate();
            QDate largestDate =  data[i].booking->getToDate();

            for(int j = i +1;j< data.size();j++){
                if(std::dynamic_pointer_cast<HotelBooking>(data[j].booking)){
                    QDate from = data[j].booking->getFromDate();
                    QDate to =  data[j].booking->getToDate();

                    if (from == largestDate) {

                        break;
                    }else if((data[j].booking->getPredecessor1()==data[i].booking->getId()) || (data[j].booking->getPredecessor2()==data[i].booking->getId())){
                        s+="From: "+ data[j].booking->getId()+" laregest: " +  data[i].booking->getId();
                       s += " (From: " + from.toString() + ", To: " + largestDate.toString() + ")"+"\n";

                        break;
                    }
                }
            }
        }
    }



}
const QString &Travel::getID() const
{
    return ID;
}

shared_ptr<Booking> Travel::findBooking(const QString &bookingID)
{
    for (auto b : travelBookings) {
        if (b->getId() == bookingID) {
            return b;
        }
    }
    return nullptr;
}


Graph<shared_ptr<Booking>, 20> Travel::getGraph() const
{
    return graph;
}


Travel::Travel(long travelID, long customerID, QString ID)
    :travelID(travelID),customerID(customerID),ID(ID)
{

}

void Travel::addBooking(shared_ptr<Booking> booking)
{
    travelBookings.push_back(booking);
}
