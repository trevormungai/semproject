#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm> 

using namespace std;

// Structure to hold student information
struct Student {
    int admissionnumber;
    string firstname;
    string surname;
    string gender;
    int age;
    int group;
    vector<string> activities;  // List of activities the student is involved in
};

// Structure to hold activity information
struct Activity {
    string name;
    int max_capacity;
    int current_capacity;
    map<string, int> gender_count;  // Count of students by gender
};

// Vectors and maps to hold students and activities
vector<Student> students;
unordered_map<string, Activity> sports;
unordered_map<string, Activity> clubs;

// Function prototypes
void initialize_activities();
void chooseActivities(Student& s);
bool add_student();
void view_students();
void view_clubs();
void view_sports();
void save_to_file(const string& filename);
void menu();

// Function to initialize activities with predefined values and capacities
void initialize_activities() {
    sports["Rugby"] = {"Rugby", 20, 0, {{"Male", 0}, {"Female", 0}}};
    sports["Athletics"] = {"Athletics", 20, 0, {{"Male", 0}, {"Female", 0}}};
    sports["Swimming"] = {"Swimming", 20, 0, {{"Male", 0}, {"Female", 0}}};
    sports["Soccer"] = {"Soccer", 20, 0, {{"Male", 0}, {"Female", 0}}};

    clubs["Journalism Club"] = {"Journalism Club", 60, 0, {{"Male", 0}, {"Female", 0}}};
    clubs["Red Cross Society"] = {"Red Cross Society", 60, 0, {{"Male", 0}, {"Female", 0}}};
    clubs["AISEC"] = {"AISEC", 60, 0, {{"Male", 0}, {"Female", 0}}};
    clubs["Business Club"] = {"Business Club", 60, 0, {{"Male", 0}, {"Female", 0}}};
    clubs["Computer Science Club"] = {"Computer Science Club", 60, 0, {{"Male", 0}, {"Female", 0}}};

    vector<Student> predefined_students = {
        {1001, "John", "Doe", "Male", 18, 1, {"Rugby", "AISEC", "Business Club"}},
        {1002, "Jane", "Smith", "Female", 19, 1, {"Swimming", "Business Club", "Red Cross Society"}},
        {1003, "Alice", "Johnson", "Female", 18, 2, {"Soccer", "Red Cross Society", "AISEC"}},
        {1004, "Bob", "Brown", "Male", 20, 2, {"Athletics", "Journalism Club", "Business Club"}},
        {1005, "Charlie", "Davis", "Male", 19, 3, {"AISEC", "Business Club", "Computer Science Club"}},
        {1006, "Diana", "Miller", "Female", 18, 3, {"Journalism Club", "Red Cross Society", "AISEC"}}
    };

    for (auto& s : predefined_students) {
        for (const auto& activity : s.activities) {
            if (sports.find(activity) != sports.end()) {
                sports[activity].current_capacity++;
                sports[activity].gender_count[s.gender]++;
            } else if (clubs.find(activity) != clubs.end()) {
                clubs[activity].current_capacity++;
                clubs[activity].gender_count[s.gender]++;
            }
        }
        students.push_back(s);
    }
}

// Function to let a student choose their activities
void chooseActivities(Student& s) {
    cout << "Choose activities (one sporting activity and up to two clubs):\n";
    string activity;
    int sport_count = 0;
    int club_count = 0;
    vector<string> chosenActivities;

    while (true) {
        cout << "Enter an activity (type 'done' when finished): ";
        cin >> activity;
        if (activity == "done") break;

        // Check if valid activity (sport or club)
        if (sports.find(activity) != sports.end() || clubs.find(activity) != clubs.end()) {
            if (find(chosenActivities.begin(), chosenActivities.end(), activity) != chosenActivities.end()) {
                cout << "You have already chosen this activity." << endl;
                continue;
            }

            chosenActivities.push_back(activity);
            cout << "Chosen activity: " << activity << endl;

            if (sports.find(activity) != sports.end()) {
                // Handle sport selection
                if (sport_count >= 1) {
                    cout << "You can only choose one sporting activity." << endl;
                    chosenActivities.pop_back(); // Remove duplicate sport
                    continue;
                }

                if (sports[activity].current_capacity >= sports[activity].max_capacity) {
                    cout << "This sport is full." << endl;
                    chosenActivities.pop_back(); // Remove full sport
                    continue;
                }

                sports[activity].current_capacity++;
                sports[activity].gender_count[s.gender]++;
                sport_count++;
            } else {
                // Handle club selection
                if (club_count >= 2) {
                    cout << "You can only choose up to two clubs/societies." << endl;
                    chosenActivities.pop_back(); // Remove extra club
                    continue;
                }

                if (clubs[activity].current_capacity >= clubs[activity].max_capacity) {
                    cout << "This club is full." << endl;
                    chosenActivities.pop_back(); // Remove full club
                    continue;
                }

                clubs[activity].current_capacity++;
                clubs[activity].gender_count[s.gender]++;
                club_count++;
            }
        } else {
            cout << "Invalid activity. Please choose a sport or a club from the list." << endl;
        }
    }

    // Ensure at least one sport is chosen
    if (sport_count == 0) {
        cout << "You must choose one sporting activity." << endl;
        return;
    }

    // Ensure the total number of activities is valid
    if (sport_count + club_count < 1 || sport_count + club_count > 3) {
        cout << "You must choose exactly one sport and up to two clubs." << endl;
        return;
    }

    // Update student activities list
    s.activities = chosenActivities;
}

// Function to add a student
bool add_student() {
    Student s;
    cout << "Enter admission number: ";
    cin >> s.admissionnumber;
    cout << "Enter first name: ";
    cin >> s.firstname;
    cout << "Enter surname: ";
    cin >> s.surname;
    cout << "Enter gender: ";
    cin >> s.gender;
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter group: ";
    cin >> s.group;

    chooseActivities(s);

    students.push_back(s);

    // Update activity capacities and gender counts
    for (const auto& activity : s.activities) {
        if (sports.find(activity) != sports.end()) {
            sports[activity].current_capacity++;
            sports[activity].gender_count[s.gender]++;
        } else if (clubs.find(activity) != clubs.end()) {
            clubs[activity].current_capacity++;
            clubs[activity].gender_count[s.gender]++;
        }
    }

    return true;
}

// Function to view all students and their activities
void view_students() {
    for (const auto& s : students) {
        cout << "Admission Number: " << s.admissionnumber << ", Name: " << s.firstname << " " << s.surname << ", Gender: " << s.gender
             << ", Age: " << s.age << ", Group: " << s.group << ", Activities: ";
        if (s.activities.empty()) {
            cout << "None";
        } else {
            for (size_t i = 0; i < s.activities.size(); ++i) {
                cout << s.activities[i];
                if (i < s.activities.size() - 1) {
                    cout << ", ";  // Separate multiple activities with a comma and space
                }
            }
        }
        cout << endl;
    }
}

// Function to view all clubs and their capacities
void view_clubs() {
    for (const auto& [name, club] : clubs) {
        cout << "Club: " << name << ", Capacity: " << club.current_capacity << "/" << club.max_capacity << ", Gender Count: ";
        for (const auto& [gender, count] : club.gender_count) {
            cout << gender << ": " << count << " ";
        }
        cout << endl;
    }
}

// Function to view all sports and their capacities
void view_sports() {
    for (const auto& [name, sport] : sports) {
        cout << "Sport: " << name << ", Capacity: " << sport.current_capacity << "/" << sport.max_capacity << ", Gender Count: ";
        for (const auto& [gender, count] : sport.gender_count) {
            cout << gender << ": " << count << " ";
        }
        cout << endl;
    }
}

// Function to save student data to a CSV file
void save_to_file(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Admission Number,First Name,Surname,Gender,Age,Group,Activities\n";
        for (const auto& s : students) {
            file << s.admissionnumber << "," << s.firstname << "," << s.surname << "," << s.gender << "," << s.age << "," << s.group << ",";
            for (size_t i = 0; i < s.activities.size(); ++i) {
                file << s.activities[i];
                if (i < s.activities.size() - 1) {
                    file << ";";  // Separate multiple activities with a semicolon
                }
            }
            file << "\n";
        }
        file.close();
        cout << "Data saved to " << filename << " successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Main menu function
void menu() {
    int choice;
    initialize_activities();
    do {
        cout << "Menu:\n1. Add Student\n2. View Students\n3. View Clubs\n4. View Sports\n5. Save to CSV\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                add_student();
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
            case 5:
                save_to_file("students.csv");
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
