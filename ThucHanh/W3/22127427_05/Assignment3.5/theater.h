#ifndef TICKET_SYSTEM_H
#define TICKET_SYSTEM_H

#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 15;
const int SEATS_PER_ROW = 30;

class Ticket 
{
    char seats[NUM_ROWS][SEATS_PER_ROW];
    double prices[NUM_ROWS];
    double totalSales;

public:
    Ticket();
    void initializeSeats();
    void setPrices();
    void displaySeatingChart() const;
    double calculateTotalPrice(const int rowNums[], int numTickets) const;
    bool isSeatAvailable(int rowNum, int seatNum) const;
    void sellTickets();
    void viewTotalSales() const;
    void viewSeatAvailability() const;
};

#endif
