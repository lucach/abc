#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int> > students;
    vector<int> bugs;
    int nstudents, nbugs, maxpass, tmp;
    cin >> nstudents >> nbugs >> maxpass;
    for(int i = 0; i < nbugs; i++)
    {
        cin >> tmp;
        bugs.push_back(tmp);
    }
    for(int i = 0; i < nstudents; i++)
    {
        cin >> tmp;
        students.push_back(make_pair(tmp, 0));
    }
    for(int i = 0; i < nstudents; i++)
    {
        cin >> tmp;
        students[i] = make_pair(students[i].first, tmp);
    }
    /** Ordinamento evitabile se volessimo trovare solo SI/NO */
    sort(students.begin(), students.end());
    sort(bugs.begin(), bugs.end());
    reverse(students.begin(), students.end());
    reverse(bugs.begin(), bugs.end());
    bool trovato = false;
    for (int i = 0; i < nstudents; i++)
        if (students[i].first >= bugs[0] && students[i].second <= maxpass)
            trovato = true;
    if(trovato)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}
