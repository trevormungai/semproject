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
    clubs["Red Cross Society"] = {"Red Cross Society", 60, 0, {{"Male", 0}, {"Female", 0}}
    clubs["AISEC"] = {"AISEC", 60, 0, {{"Male", 0}, {"Female", 0}}};
    clubs["Business Club"] = {"Business Club", 60, 0, {{"Male", 0}, {"Female", 0}}};
    clubs["Computer Science Club"] = {"Computer Science Club", 60, 0, {{"Male", 0}, {"Fema

    vector<Student> predefined_students = {