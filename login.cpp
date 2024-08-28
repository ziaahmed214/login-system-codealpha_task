#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file(username + ".txt");
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Unable to register!" << endl;
    }
}

void loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (file.is_open()) {
        string uname, pass;
        file >> uname;
        file >> pass;
        file.close();

        if (uname == username && pass == password) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password!" << endl;
        }
    } else {
        cout << "User not found!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}