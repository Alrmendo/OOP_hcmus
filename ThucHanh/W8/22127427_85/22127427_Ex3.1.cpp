#include "Ticket.h"

int main() 
{
    vector<Ticket*> tickets;

    inputTickets(tickets);
    sortAndSaveTickets(tickets, "sorted_tickets.txt");
    double total = calculateTotalPrice(tickets);
    cout << "\nTotal Price of all tickets: " << total << endl;
    summarizeTickets(tickets);

    for (size_t i = 0; i < tickets.size(); i++) 
    {
        delete tickets[i];
    }

    return 0;
}
