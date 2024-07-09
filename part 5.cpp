    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    file << "AdmissionNumber,FirstName,Surname,Gender,Age,Group,Activities\n";
    for (const auto& s : students) {
        file << s.admissionnumber << "," << s.firstname << "," << s.surname << "," << s.gender << "," << s.age << "," << s.gro
        for (size_t i = 0; i < s.activities.size(); ++i) {
            file << s.activities[i];
            if (i < s.activities.size() - 1) {
                file << ";";  // Use semicolon to separate multiple activities
            }
        }
        file << "\n";
    }

    file.close();
    cout << "Data saved to " << filename << endl;
}

// Function to display the menu and handle user choices
void menu() {
    while (true) {
        cout << "\nActivity Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. View Clubs\n";
        cout << "4. View Sports\n";
        cout << "5. Save to CSV\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if (!add_student()) {
                    cout << "Failed to add student. Please try again." << endl;
                }
                break;
            case 2:
                view_students();
                break;
            case 3:
                view_clubs();
                break;
            case 4:
                view_sports();
                break;
            case 5: {
                string filename;
                cout << "Enter filename to save to: ";
                cin >> filename;
                save_to_file(filename);
                break;
            }
            case 6:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Main function
int main() {
    initialize_activities();
    menu();
    return 0;
}
