#include "theater.h"

int main() 
{
    Ticket ticketSystem;

    while (true) 
    {
        cout << "1. Display seating chart\n";
        cout << "2. Sell tickets\n";
        cout << "3. View total ticket sales\n";
        cout << "4. View seat availability\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                ticketSystem.displaySeatingChart();
                break;
            case 2:
                ticketSystem.sellTickets();
                break;
            case 3:
                ticketSystem.viewTotalSales();
                break;
            case 4:
                ticketSystem.viewSeatAvailability();
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
