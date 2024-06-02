#include <iostream>
#include <string>
using namespace std;

class House {
public:
    virtual void displayDetails() = 0;
};

class Flat : public House {
private:
    string colorOfWall;
    string materialForDoor;
    string materialForWindows;

public:
    Flat(string color, string doorMaterial, string windowsMaterial) : colorOfWall(color), materialForDoor(doorMaterial), materialForWindows(windowsMaterial) {}

    void displayDetails() override {
        cout << "Flat Details:" << endl;
        cout << "Color of Wall: " << colorOfWall << endl;
        cout << "Material for Door: " << materialForDoor << endl;
        cout << "Material for Windows: " << materialForWindows << endl;
    }
};

class Buyer {
private:
    string name;
    string surname;
    string phoneNumber;
    int desiredRooms;

public:
    static int numberOfSoldFlats;

    Buyer(string n, string s, string phone, int rooms) : name(n), surname(s), phoneNumber(phone), desiredRooms(rooms) {
        numberOfSoldFlats++;
    }

    void displayDetails() {
        cout << "Buyer Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Desired Number of Rooms: " << desiredRooms << endl;
    }
};

int Buyer::numberOfSoldFlats = 0;

class Admin {
private:
    string password;

public:
    Admin() : password("1412") {}

    bool isAdmin() {
        int choice;
        cout << "Enter 1 for Admin, 2 for Buyer, any other symbol to quit: ";
        cin >> choice;
        if (choice == 1) {
            string enteredPassword;
            cout << "Enter password: ";
            cin >> enteredPassword;
            if (enteredPassword == password)
                return true;
            else
                return false;
        }
        else if (choice == 2) {
            return false;
        }
        else {
            exit(0);
        }
    }

    void adminActions() {
        while (true) {
            int choice;
            cout << "Enter 1 to view admin details, 2 to change password, 3 to view number of sold flats: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Admin details: Name - Alisher, Surname - Rustamov" << endl;
            }
            else if (choice == 2) {
                int newPassword;
                cout << "Enter new password: ";
                cin >> newPassword;
                password = to_string(newPassword);
                cout << "Password changed successfully!" << endl;
            }
            else if (choice == 3) {
                cout << "Number of sold flats: " << Buyer::numberOfSoldFlats << endl;
            }
            else {
                break;
            }
        }
    }
};

int main() {
    Admin admin;
    Buyer* buyer = nullptr;

    while (true) {
        if (admin.isAdmin()) {
            admin.adminActions();
        }
        else {
            string name, surname, phoneNumber;
            int desiredRooms;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your surname: ";
            cin >> surname;
            cout << "Enter your phone number: ";
            cin >> phoneNumber;
            cout << "Enter desired number of rooms: ";
            cin >> desiredRooms;
            buyer = new Buyer(name, surname, phoneNumber, desiredRooms);

            string wallColor, doorMaterial, windowsMaterial;
            cout << "Enter color of wall: ";
            cin >> wallColor;
            cout << "Enter material for door: ";
            cin >> doorMaterial;
            cout << "Enter material for windows: ";
            cin >> windowsMaterial;
            Flat flat(wallColor, doorMaterial, windowsMaterial);
            flat.displayDetails();

            buyer->displayDetails();
            cout << "Buyer was added to database." << endl;

            delete buyer;
        }
    }

    return 0;
}