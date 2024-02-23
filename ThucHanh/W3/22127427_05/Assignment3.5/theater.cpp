#include "theater.h"

Ticket::Ticket() : totalSales(0.0)
{
    initializeSeats();
    setPrices();
}

void Ticket::initializeSeats() 
{
    for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) {
        for (int seatNum = 0; seatNum < SEATS_PER_ROW; seatNum++) {
            seats[rowNum][seatNum] = '#';
        }
    }
}

void Ticket::setPrices() 
{
    for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) {
        cout << "Enter the price for row " << rowNum + 1 << ": ";
        cin >> prices[rowNum];
    }
}

void Ticket::displaySeatingChart() const
{
    cout << "Seating Chart:\n";
    cout << setw(6) << " ";
    for (int seatNum = 0; seatNum < SEATS_PER_ROW; seatNum++) 
    {
        cout << setw(3) << seatNum + 1;
    }
    cout << endl;

    for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) 
    {
        cout << "ROW" << setw(3) << rowNum + 1 << " ";
        for (int seatNum = 0; seatNum < SEATS_PER_ROW; seatNum++) 
        {
            cout << setw(2) << seats[rowNum][seatNum] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double Ticket::calculateTotalPrice(const int rowNums[], int numTickets) const
{
    double total = 0.0;
    for (int i = 0; i < numTickets; i++) 
    {
        int rowNum = rowNums[i];
        total += prices[rowNum];
    }
    return total;
}

bool Ticket::isSeatAvailable(const int rowNum, const int seatNum) const
{
    return seats[rowNum][seatNum] == '*'; // Change '*'
}

void Ticket::sellTickets()
{
    int numTickets;
    cout << "Enter the number of tickets to sell: ";
    cin >> numTickets;

    int rowNums[numTickets];
    int seatNums[numTickets];

    for (int i = 0; i < numTickets; i++) 
    {
        cout << "Enter the row and seat number for ticket " << i + 1 << ": ";
        cin >> rowNums[i] >> seatNums[i];
        rowNums[i]--;
        seatNums[i]--;

        if (rowNums[i] >= 0 && rowNums[i] < NUM_ROWS && seatNums[i] >= 0 && seatNums[i] < SEATS_PER_ROW) {
            if (!isSeatAvailable(rowNums[i], seatNums[i])) 
            {
                cout << "Seat " << rowNums[i] + 1 << "-" << seatNums[i] + 1 << " is already taken.\n";
            }
            else 
            {
                seats[rowNums[i]][seatNums[i]] = '*';
                totalSales += prices[rowNums[i]];
                cout << "Ticket sold for $" << prices[rowNums[i]] << endl;
            }
        } 
        else 
        {
            cout << "Invalid seat number!\n";
        }
    }

    cout << "Total ticket price: $" << totalSales << endl; // Use totalSales directly
}

void Ticket::viewTotalSales() const
{
    cout << "Total ticket sales: $" << totalSales << endl;
}

void Ticket::viewSeatAvailability() const
{
    int totalAvailable = 0;
    int availableInRow[NUM_ROWS] = {0};

    for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) 
    {
        for (int seatNum = 0; seatNum < SEATS_PER_ROW; seatNum++) 
        {
            if (isSeatAvailable(rowNum, seatNum))
            {
                totalAvailable++;
                availableInRow[rowNum]++;
            }
        }
    }

    cout << "Seats available in each row:\n";
    for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) 
    {
        cout << "Row " << rowNum + 1 << ": " << availableInRow[rowNum] << " seats\n";
    }

    cout << "Total seats available: " << totalAvailable << endl;
}