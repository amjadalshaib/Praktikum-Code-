#include "travelagencyui.h"
#include "travelagency.h"
#include <QApplication>
#include <memory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shared_ptr<TravelAgency> T = make_shared<TravelAgency>();
    TravelAgencyUI w(T);
    w.show();
    return a.exec();
}
