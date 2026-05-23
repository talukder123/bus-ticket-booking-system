#include <iostream>
#include <string>
using namespace std;

void viewBuses() {
    cout << "Viewing buses...\n";
    cout << "This feature will be added soon!\n";
}

void viewSeats() {
    cout << "Viewing seats...\n";
    cout << "This feature will be added soon!\n";
}

void bookTicket() {
    cout << "Booking ticket...\n";
    cout << "This feature will be added soon!\n";
}

void cancelTicket() {
    cout << "Cancelling ticket...\n";
    cout << "This feature will be added soon!\n";
}

void searchBooking() {
    cout << "Searching booking...\n";
    cout << "This feature will be added soon!\n";
}

void addBus() {
    cout << "Adding bus...\n";
    cout << "This feature will be added soon!\n";
}

void passenger_menu() {
    int choice;

    while (true) {
        cout << "\n---- PASSENGER PANEL ----\n";
        cout << "1. View Buses\n";
        cout << "2. View Seats\n";
        cout << "3. Book Ticket\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Search Booking\n";
        cout << "6. Logout\n";
        cout << "Choose: ";
        cin >> choice;

        switch(choice) {
            case 1: viewBuses(); 
            break;
            case 2: viewSeats(); 
            break;
            case 3: bookTicket(); 
            break;
            case 4: cancelTicket(); 
            break;
            case 5: searchBooking(); 
            break;
            case 6:
                cout << "Logging out...\n";
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void admin_menu() {
    int choice;

    while (true) {
        cout << "\n---- ADMIN PANEL ----\n";
        cout << "1. View Buses\n";
        cout << "2. View Seats\n";
        cout << "3. Book Ticket\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Search Booking\n";
        cout << "6. Add Bus\n";
        cout << "7. Logout\n";
        cout << "Choose: ";
        cin >> choice;

        switch(choice) {
            case 1:
                viewBuses();
                break;

            case 2:
                viewSeats();
                break;

            case 3:
                bookTicket();
                break;

            case 4:
                cancelTicket();
                break;

            case 5:
                searchBooking();
                break;

            case 6:
                addBus();
                break;

            case 7:
                cout << "Logging out...\n";
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}


bool log_in (string s1, string s2, int p, int s) {
    if (s1 == s2 && p == s) {
        return true;
    } else {
        return false;
    }
}

int main() {

    string admin_name = "admin";
    int admin_pin = 1234;

    string user_name = "user";
    int user_pin = 9999;

    int choice;

    while (true) {
        cout << "\n\n=================================\n";
        cout << "   SKYLINE BUS SERVICE\n";
        cout << "=================================\n\n";

        cout << "Which service do you need?\n";
        cout << "1. Admin\n";
        cout << "2. Passenger\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1: {
        string entered_name;
        int entered_pin;
        cout << "Enter username: ";
        cin >> entered_name;
        cout << "Enter PIN: ";
        cin >> entered_pin;


            bool allow = log_in(admin_name, entered_name, admin_pin, entered_pin );
            if (allow) {
                admin_menu();
            } else {
                cout << "wrong credentials\n";
            }
            break;
        }
        case 2: {
            string temp_user;
            int temp_pin;
            cout << "Enter username: ";
            cin >> temp_user;
            cout << "Enter PIN: ";
            cin >> temp_pin;

            bool allow = log_in(user_name, temp_user, user_pin, temp_pin );
            if (allow) {
                passenger_menu();
            } else {
                cout << "wrong credentials\n";
            }
            break;
        }
        case 3:
            cout << "\nSystem closed!\n";
            return 0;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    }

    return 0;
}