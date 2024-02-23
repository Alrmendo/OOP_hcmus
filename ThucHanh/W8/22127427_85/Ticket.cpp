#include "Ticket.h"

Ticket::Ticket(string filmTitle, string startTime, string roomName, double foodAndDrinkPrice, double ticketFactor)
    : filmTitle(filmTitle), startTime(startTime), roomName(roomName), foodAndDrinkPrice(foodAndDrinkPrice), ticketFactor(ticketFactor), basePrice(80000) {}

double Ticket::calculatePrice() 
{
    return ticketFactor * basePrice + foodAndDrinkPrice;
}

string Ticket::getFilmTitle() 
{
    return filmTitle;
}

string Ticket::getStartTime() 
{
    return startTime;
}

string Ticket::getRoomName() 
{
    return roomName;
}

double Ticket::getFoodAndDrinkPrice() 
{
    return foodAndDrinkPrice;
}

double Ticket::getTicketFactor() 
{
    return ticketFactor;
}

RegularTicket::RegularTicket(string filmTitle, string startTime, string roomName, double foodAndDrinkPrice, double ticketFactor)
    : Ticket(filmTitle, startTime, roomName, foodAndDrinkPrice, ticketFactor) {}

ComboTicket::ComboTicket(string filmTitle, string startTime, string roomName, double foodAndDrinkPrice, double ticketFactor)
    : Ticket(filmTitle, startTime, roomName, foodAndDrinkPrice, ticketFactor) {}

double RegularTicket::calculatePrice()
{
    return ticketFactor * basePrice + (foodAndDrinkPrice * 0.8);
}

double ComboTicket::calculatePrice() 
{
    return ticketFactor * basePrice + (foodAndDrinkPrice * 0.8);
}

void inputTickets(vector<Ticket*>& tickets) 
{
    int numTickets;
    cout << "Enter the number of tickets: ";
    cin >> numTickets;
    cin.ignore();

    for (int i = 0; i < numTickets; i++) 
    {
        string filmTitle, startTime, roomName;
        double foodAndDrinkPrice, ticketFactor;
        int ticketType;

        cout << "Ticket " << (i + 1) << ":" << endl;
        
        cout << "Enter film title: ";
        getline(cin, filmTitle);

        cout << "Enter start time (hh:mm): ";
        getline(cin, startTime);

        cout << "Enter room name: ";
        getline(cin, roomName);

        cout << "Enter price of food and drink: ";
        cin >> foodAndDrinkPrice;

        cout << "Enter ticket type (1 - Regular, 2 - Combo): ";
        cin >> ticketType;

        cin.ignore();

        if (ticketType == 1) 
        {
            tickets.push_back(new RegularTicket(filmTitle, startTime, roomName, foodAndDrinkPrice, ticketFactor));
        } 
        else if (ticketType == 2) 
        {
            tickets.push_back(new ComboTicket(filmTitle, startTime, roomName, foodAndDrinkPrice, ticketFactor));
        }
    }
}

bool compareTickets(Ticket* ticket1, Ticket* ticket2) 
{
    if (typeid(*ticket1) != typeid(*ticket2)) 
    {
        return typeid(*ticket1).before(typeid(*ticket2));
    } 
    else 
    {
        return ticket1->calculatePrice() > ticket2->calculatePrice();
    }
}

double calculateTotalPrice(vector<Ticket*>& tickets) 
{
    double totalPrice = 0.0;

    for (size_t i = 0; i < tickets.size(); i++) 
    {
        totalPrice += tickets[i]->calculatePrice();
    }

    return totalPrice;
}

void sortAndSaveTickets(vector<Ticket*>& tickets, string filename) 
{
   sort(tickets.begin(), tickets.end(), compareTickets);

    ofstream outputFile(filename);
    if (outputFile.is_open()) 
    {
        for (size_t i = 0; i < tickets.size(); i++) 
        {
            Ticket* ticket = tickets[i];
            outputFile << ticket->getFilmTitle() << " | "
                       << ticket->getStartTime() << " | "
                       << ticket->getRoomName() << " | "
                       << ticket->calculatePrice() << endl;
        }
        outputFile.close();
        cout << "\nSorted tickets saved to " << filename << endl;
    } 
    else 
    {
        cout << "Unable to open file " << filename << endl;
    }
}

void summarizeTickets(vector<Ticket*>& tickets) 
{
    int timeRanges[24] = {0};
    int regularCount[24] = {0};
    int comboCount[24] = {0};

    for (size_t i = 0; i < tickets.size(); i++) 
    {
        Ticket* ticket = tickets[i];
        int hour = stoi(ticket->getStartTime().substr(0, 2));
        timeRanges[hour]++;

        if (typeid(*ticket) == typeid(RegularTicket)) 
        {
            regularCount[hour]++;
        } 
        else if (typeid(*ticket) == typeid(ComboTicket)) 
        {
            comboCount[hour]++;
        }
    }

    cout << "\nSummary of tickets in 24 time ranges of a day:" << endl;
    cout << "Range\t\t#Regular\t#Combo" << endl;
    
    for (int i = 0; i < 24; i++) 
    {
        cout << i << ":00 - " << (i + 1) << ":00\t" << regularCount[i] << "\t\t" << comboCount[i] << endl;
    }
}