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
    cout << "Enter gender (Male/Female): ";
    cin >> s.gender;
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter group (1/2/3): ";
    cin >> s.group;

    // Verify group number
    if (s.group < 1 || s.group > 3) {
        cout << "Invalid group number." << endl;
        return false;
    }

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