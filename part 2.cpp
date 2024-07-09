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
unction to let a student choose their activities
 chooseActivities(Student& s) {
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