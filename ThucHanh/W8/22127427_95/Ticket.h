#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Ticket {
protected:
    string filmTitle;
    string startTime;
    string roomName;
    double foodAndDrinkPrice;
    double ticketFactor;
    double basePrice;

public:
    Ticket(string filmTitle, string startTime, string roomName, double foodAndDrinkPrice, double ticketFactor);

    virtual double calculatePrice();

    string getFilmTitle();

    string getStartTime();

    string getRoomName();

    double getFoodAndDrinkPrice();

    double getTicketFactor();
};

class RegularTicket : public Ticket {
public:
    RegularTicket(string filmTitle, string startTime, string roomName, double foodAndDrinkPrice, double ticketFactor = 1.0);
    double calculatePrice();
};

class ComboTicket : public Ticket {
public:
    ComboTicket(string filmTitle, string startTime, string roomName, double foodAndDrinkPrice, double ticketFactor = 1.5);

    double calculatePrice();
};

void inputTickets(vector<Ticket*>& tickets);

bool compareTickets(Ticket* ticket1, Ticket* ticket2);

double calculateTotalPrice(vector<Ticket*>& tickets);

void sortAndSaveTickets(vector<Ticket*>& tickets, string filename);

void summarizeTickets(vector<Ticket*>& tickets);

#endif
