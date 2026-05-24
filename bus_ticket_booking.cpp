#include <iostream>
#include <string>
#include <limits> 
using namespace std;


//total bus :
int busCount = 5;

//bus route and fare: 
string busRoute[100];
int busFare[100];

int seats[100][40];   // 100 karon jodi aro bus add kori
string passenger[100][40]; // passenger name;

// set the bus information
void initBuses() {
    busRoute[0] = "Dhaka-Sylhet";
    busFare[0] = 500;

    busRoute[1] = "Dhaka-CoxBazar";
    busFare[1] = 1200;

    busRoute[2] = "Dhaka-Chittagong";
    busFare[2] = 700;

    busRoute[3] = "Dhaka-Rajshahi";
    busFare[3] = 600;

    busRoute[4] = "Dhaka-Khulna";
    busFare[4] = 800;
}

// set the seat information
void initSeats() {
    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < 40; j++) {
            seats[i][j] = 0;
            passenger[i][j] = "";
        }
    }
}

void viewBuses() {
    cout << "\n--- Available Buses ---\n";
    for (int i =0; i<busCount; i++) {
        cout << "Bus ID: " << i << endl;
        cout << "Route : " << busRoute[i] << endl;
        cout << "Fare  : " << busFare[i] << " BDT" << endl;
        cout << endl;
    }
    cout << "\nPress Enter to go back  ";

    cin.ignore();
    cin.get(); 
}

void viewSeats() {
    int bus_id;

      cout << "\n---Bus list---\n";
    for (int i =0; i<busCount; i++) {
        cout << "Bus ID: " << i << endl;
        cout << "Route : " << busRoute[i] << endl;
        cout << "Fare  : " << busFare[i] << " BDT" << endl;
        cout << endl;
    }
    cout << "Enter Bus ID to choose seat: ";
    cin >> bus_id;

    if (bus_id < 0 || bus_id >= busCount) {
        cout << "Invalid Bus ID!\n";
        return;
    }

    cout << "\nBus: " << busRoute[bus_id] << endl;
    
     for (int i = 0; i < 40; i++) {

        if (seats[bus_id][i] == 0)
            cout << "[ " << i + 1 << " ]\t";
        else
            cout << "[ X ] ";

        if ((i + 1) % 4 == 0)
            cout << endl;
    }

    cout << "\n\n";
    cout << "X = Booked Seat\n";

    cout << "\nPress Enter to go back...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

}

void bookTicket() {
    int bus_id;
    int seat_no;
    string name;

    cout << "\nEnter Bus ID: ";
    cin >> bus_id;

    if (bus_id < 0 || bus_id >= busCount) {
        cout << "Invalid Bus ID!\n";
        return;
    }

     cout << "\nSeats for Bus " << busRoute[bus_id] << ":\n";

    for (int i = 0; i < 40; i++) {

        if (seats[bus_id][i] == 0)
            cout << "[ " << i + 1 << " ] ";
        else
            cout << "[ X ] ";

        if ((i + 1) % 4 == 0)
            cout << endl;
    }

    // now seat input
    cout << "\nEnter Seat Number (1-40): ";
    cin >> seat_no;

    if (seat_no < 1 || seat_no > 40) {
        cout << "Invalid Seat Number!\n";
        return;
    }

    // check if the seat is booked or not
    if (seats[bus_id][seat_no - 1] == 1) {
        cout << "Seat already booked!\n";
        return;
    }

    // booking
    cout << "Enter Passenger Name(only surname): ";
    cin >> name;

    seats[bus_id][seat_no - 1] = 1;
    passenger[bus_id][seat_no - 1] = name;

    cout << "\nBooking Successful!\n";
    cout << "Seat No: " << seat_no << endl;
    cout << "Passenger: " << name << endl;

    cout << "\nPress Enter to continue...";

    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void cancelTicket() {
    int B_id; // Bus ID
    int S_no; // Seat number

    cout << "Enter Bus ID: ";
    cin >> B_id;
    

    if (B_id < 0 || B_id >= busCount) {
        cout << "Invalid Bus ID!\n";
        return;
    }

    cout << "Enter Seat Number (1-40): ";
    cin >> S_no;

    if (S_no < 1 || S_no > 40) {
        cout << "Invalid Seat Number!\n";
        return;
    }

    if (seats[B_id][S_no - 1] == 0) {
        cout << "Seat is already empty!\n";
        return;
    }

    seats[B_id][S_no - 1] = 0;
    passenger[B_id][S_no - 1] = "";

    cout << "\nTicket Cancelled Successfully!\n";
    cout << "Bus: " << busRoute[B_id] << endl;
    cout << "Seat No: " << S_no << endl;
}

void searchBooking() {
    string name;
    bool found = false;

    cout << "\nEnter Passenger Name: ";
    cin >> name;

    for (int i = 0; i < busCount; i++) {
        for (int j = 0; j < 40; j++) {

            if (passenger[i][j] == name) {

                cout << "\nBooking Found!\n";
                cout << "Bus: " << busRoute[i] << endl;
                cout << "Bus ID: " << i << endl;
                cout << "Seat No: " << j + 1 << endl;

                found = true;
            }
        }
    }

    if (!found) {
        cout << "No booking found for this name!\n";
    }
}

void addBus() {
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
    
    initBuses(); // load out all buses
    initSeats(); // loaded all seats

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