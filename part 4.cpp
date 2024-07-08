// Function to view all students and their activities
void view_students() {
    ifstream file("students.csv");  // Open the CSV file
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    getline(file, line);  // Read and ignore the header line

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        // Read each field from the CSV line
        vector<string> fields;
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }

        // Ensure the line has the expected number of fields
        if (fields.size() != 7) {
            cerr << "Error: Invalid data format in CSV file." << endl;
            continue;
        }

        // Extract fields
        int admissionnumber = stoi(fields[0]);
        string firstname = fields[1];
        string surname = fields[2];
        string gender = fields[3];
        int age = stoi(fields[4]);
        int group = stoi(fields[5]);
        string activities = fields[6];

        // Output student information
        cout << "Admission Number: " << admissionnumber << ", Name: " << firstname << " " << surnam
             << ", Gender: " << gender << ", Age: " << age << ", Group: " << group
             << ", Activities: " << activities << endl;
    }

    file.close();  // Close the file
}

// Function to view all clubs and their capacities
void view_clubs() {
    cout << "List of Clubs:\n";
    for (const auto& [name, club] : clubs) {
        cout << "Club: " << name << ", Capacity: " << club.current_capacity << "/" << club.max_capa
        for (const auto& [gender, count] : club.gender_count) {
            cout << gender << ": " << count << " ";
        }
        cout << endl;
    }
}
// Function to view all sports and their capacities
void view_sports() {
    cout << "List of Sports:\n";
    for (const auto& [name, sport] : sports) {
        cout << "Sport: " << name << ", Capacity: " << sport.current_capacity << "/" << sport.max_c
        for (const auto& [gender, count] : sport.gender_count) {
            cout << gender << ": " << count << " ";
        }
        cout << endl;
    }
}

// Function to save student data to a CSV file
void save_to_file(const string& filename) {
    ofstream file(filename);