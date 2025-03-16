#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int a;
    int b;
};

bool compareGroup1(const Job &j1, const Job &j2) {
    return j1.a < j2.a;
}

bool compareGroup2(const Job &j1, const Job &j2) {
    return j1.b > j2.b;
}

vector<Job> johnsonSchedule(const vector<Job>& jobs) {
    vector<Job> group1, group2;

    for (vector<Job>::const_iterator it = jobs.begin(); it != jobs.end(); ++it) {
        if (it->a <= it->b)
            group1.push_back(*it);
        else
            group2.push_back(*it);
    }

    sort(group1.begin(), group1.end(), compareGroup1);

    sort(group2.begin(), group2.end(), compareGroup2);

    vector<Job> schedule;
    schedule.insert(schedule.end(), group1.begin(), group1.end());
    schedule.insert(schedule.end(), group2.begin(), group2.end());

    return schedule;
}

int main() {
    vector<Job> jobs;
    jobs.push_back(Job{1, 3, 5});
    jobs.push_back(Job{2, 2, 4});
    jobs.push_back(Job{3, 6, 2});
    jobs.push_back(Job{4, 5, 3});
    jobs.push_back(Job{5, 4, 6});

    vector<Job> schedule = johnsonSchedule(jobs);

    cout << "Thu tu gia cong toi uu: ";
    for (vector<Job>::const_iterator it = schedule.begin(); it != schedule.end(); ++it) {
        cout << "D" << it->id << " ";
    }
    cout << endl;

    return 0;
}