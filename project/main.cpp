#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Table {
public:
    int id;
    int emptySeats;

    Table(int id, int emptySeats) : id(id), emptySeats(emptySeats) {}

    void display() const {
        cout << "Table ID: " << id << " | Empty Seats: " << emptySeats << endl;
    }
};

bool loadTables(const string &filename, vector<Table> &tables) { //loads tables from filename, filename is in format: "id empty_seats"
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    int id, emptySeats;
    tables.clear();
    while (file >> id >> emptySeats) {
        tables.push_back(Table(id, emptySeats));
    }

    file.close();
    return true;
}

int getNextReservationId(const string &reservationFile) { //auto-increment for the reservations. 
    ifstream file(reservationFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << reservationFile << endl;
        return 1;
    }

    int latestId = 0;
    string line;
    while (getline(file, line)) {
        size_t pos = line.find("Reservation ID: ");
        if (pos != string::npos) {
            int id = stoi(line.substr(pos + 15));
            if (id > latestId) {
                latestId = id;
            }
        }
    }

    file.close();
    return latestId + 1;
}

void logReservation(const string &reservationFile, int reservationId, int tableId, 
                    int seats, const string &date, const string &time, const string &name) { //enters a new reservation into reservationFile (reservations.txt)
                                                                                             //format of reservation: Reservation ID | Table ID | Seats Reserved | Date | Time | Name
    ofstream file(reservationFile, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << reservationFile << endl;
        return;
    }

    file << "Reservation ID: " << reservationId << " | Table ID: " << tableId
         << " | Seats Reserved: " << seats << " | Date: " << date
         << " | Time: " << time << " | Name: " << name << endl;
    file.close();
}

bool isTableReserved(const string &reservationFile, int tableId,
                     const string &date) { //checks if a table with tableId has a reservation in reservationFile for that date, outputs true if it finds one (thus being occupied)
    ifstream file(reservationFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << reservationFile << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("Table ID: " + to_string(tableId)) != string::npos &&
            line.find("Date: " + date) != string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void displayTables(const vector<Table> &tables, const string &date,
                   const string &reservationFile, int requestedSeats) { //goes through all tables and displays the ones that have enough empty seats using the display function
    bool availableTableFound = false;

    for (const auto &table : tables) {
        if (!isTableReserved(reservationFile, table.id, date) &&
            table.emptySeats >= requestedSeats) {
            table.display();
            availableTableFound = true;
        }
    }

    if (!availableTableFound) {
        cout << "Sorry, no table is available for the number of seats you "
                "requested.\n";
    }
}

Table *findTableById(vector<Table> &tables, int id) { // a simple function to find the vector of a table using its id
    for (auto &table : tables) {
        if (table.id == id) {
            return &table;
        }
    }
    return nullptr;
}

bool checkReservation(const string &reservationFile, int reservationId,
                      const string &inputName, string &reservationLine) { // outputs true if a reservation matches the input of someone trying to edit it and saves it into reservationLine
    ifstream file(reservationFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << reservationFile << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t idPos = line.find("Reservation ID: " + to_string(reservationId));
        size_t namePos = line.find("Name: ");

        if (idPos != string::npos && namePos != string::npos) {
            string storedName = line.substr(namePos + 6);

            // Transform the stored name to lowercase for case-insensitive comparison
            transform(storedName.begin(), storedName.end(), storedName.begin(), ::tolower);

            // Split the stored name into words
            stringstream ss(storedName);
            vector<string> storedWords;
            string word;
            while (ss >> word) {
                storedWords.push_back(word);
            }

            string lowerInputName = inputName;
            transform(lowerInputName.begin(), lowerInputName.end(), lowerInputName.begin(), ::tolower);

            stringstream inputStream(lowerInputName);
            vector<string> inputWords;
            while (inputStream >> word) {
                inputWords.push_back(word);
            }

            for (const string &inputWord : inputWords) {
                bool matchFound = false;
                for (const string &storedWord : storedWords) {
                    if (storedWord == inputWord) {
                        matchFound = true;
                        break;
                    }
                }
                if (!matchFound) {
                    return false;
                }
            }
            reservationLine = line;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void deleteReservation(const string &reservationFile, const string &reservationLine) { //takes reservationLine and removes it from reservationFile
    ifstream file(reservationFile);
    ofstream tempFile("temp.txt");

    if (!file.is_open() || !tempFile.is_open()) {
        cerr << "Error opening files for deletion." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line != reservationLine) {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();
    remove(reservationFile.c_str());
    rename("temp.txt", reservationFile.c_str());
}

void modifyReservation(const string &reservationFile,
                       const string &reservationLine, int reservationId) { //takes reservationLine and modifies it accordingly
    deleteReservation(reservationFile, reservationLine);

    string date, name, arrivalTime;
    int requestedSeats, tableId;

    cout << "Enter the new date for the reservation (DD-MM-YYYY): ";
    cin >> date;
    cout << "Enter the number of seats you need: ";
    cin >> requestedSeats;

    string filename = "tables-" + date + ".txt";
    vector<Table> tables;
    if (!loadTables(filename, tables)) {
        cout << "Could not load the tables for this date.\n";
        return;
    }

    cout << "Tables available for " << date << ":\n";
    displayTables(tables, date, reservationFile, requestedSeats);

    // Automatically choose the table with the least available seats
    Table *chosenTable = nullptr;
    for (auto &table : tables) {
        if (!isTableReserved(reservationFile, table.id, date) &&
            table.emptySeats >= requestedSeats) {
            if (!chosenTable || table.emptySeats < chosenTable->emptySeats) {
                chosenTable = &table;
            }
        }
    }

    if (chosenTable) {
        cout << "Table ID " << chosenTable->id << " selected for the reservation.\n";
        cout << "Enter your arrival time (HH:MM): ";
        cin >> arrivalTime;
        cout << "Enter your name for the reservation: ";
        cin.ignore();
        getline(cin, name);

        int reservationId = getNextReservationId(reservationFile);
        logReservation(reservationFile, reservationId, chosenTable->id, requestedSeats,
                       date, arrivalTime, name);
        cout << "Reservation successfully created with ID: " << reservationId
             << " for Table ID: " << chosenTable->id << endl;  // Now includes table ID
    } else {
        cout << "Error: Not enough empty seats or invalid table ID.\n";
    }
}

int main() {
    vector<Table> tables;

    int choice;
    do {
        cout << "\n--- Reservation System ---\n";
        cout << "1. Create a Reservation\n";
        cout << "2. Edit an Existing Reservation\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        string reservationFile = "reservations.txt";

        switch (choice) {
        case 1: {
            string date, name;
            cout << "Enter the date for the reservation (DD-MM-YYYY): ";
            cin >> date;

            string filename = "tables-" + date + ".txt";

            if (!loadTables(filename, tables)) {
                cout << "Could not load the tables for this date.\n";
                break;
            }

            int requestedSeats;
            cout << "Enter the number of seats you need: ";
            cin >> requestedSeats;

            cout << "Tables available for " << date << ":\n";
            displayTables(tables, date, reservationFile, requestedSeats);

            bool tableAvailable = false;
            for (const auto &table : tables) {
                if (!isTableReserved(reservationFile, table.id, date) &&
                    table.emptySeats >= requestedSeats) {
                    tableAvailable = true;
                    break;
                }
            }

            if (tableAvailable) {
                Table *chosenTable = nullptr;
                for (auto &table : tables) {
                    if (!isTableReserved(reservationFile, table.id, date) &&
                        table.emptySeats >= requestedSeats) {
                        if (!chosenTable || table.emptySeats < chosenTable->emptySeats) {
                            chosenTable = &table;
                        }
                    }
                }

                if (chosenTable) {
                    cout << "Table ID " << chosenTable->id
                         << " selected for the reservation.\n";
                    string arrivalTime;
                    cout << "Enter your arrival time (HH:MM): ";
                    cin >> arrivalTime;
                    cout << "Enter your name for the reservation: ";
                    cin.ignore();
                    getline(cin, name);

                    int reservationId = getNextReservationId(reservationFile);
                    logReservation(reservationFile, reservationId, chosenTable->id,
                                   requestedSeats, date, arrivalTime, name);
                    cout << "Reservation successfully created with ID: " << reservationId
                         << " for Table ID: " << chosenTable->id << endl;
                } else {
                    cout << "No available tables for your request.\n";
                }
            } else {
                cout << "Sorry, no tables available for the requested seats.\n";
            }

            break;
        }
        case 2: {
            int reservationId;
            string inputName, reservationLine;

            cout << "Enter the reservation ID you want to modify: ";
            cin >> reservationId;

            cout << "Enter the name associated with the reservation: ";
            cin.ignore();
            getline(cin, inputName);

            if (checkReservation(reservationFile, reservationId, inputName, reservationLine)) {
                modifyReservation(reservationFile, reservationLine, reservationId);
            } else {
                cout << "Reservation not found.\n";
            }

            break;
        }
        case 3:
            cout << "Exiting the reservation system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
