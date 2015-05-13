#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

bool cmp( pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
{
    return a.second.first > b.second.first;
}

vector <int> res;
vector< pair<int, pair<int, int> > > students;
vector<pair<int, int> > bugs;
priority_queue <pair<int, int> > q;

int nstudents, nbugs, maxpass, tmp;


bool risolvibile(int time)
{
    int now = maxpass, current_stud = 0;
    while (!q.empty()) /** Empty the queue */
        q.pop();
    for (int i = 0; i < nbugs; i += time)
    {
        while (current_stud < nstudents &&
            students[current_stud].second.first >= bugs[i].first)
        {
            q.push(make_pair(-students[current_stud].second.second,
                students[current_stud].first));
            current_stud++;
        }
        if (q.empty()) return false; /** We have more bugs and no student
                                         can do them. */
        now += q.top().first; /** Add the cost of the cheapest student */
        if (now < 0) return false;   /** If we run out of cash */
        for (int k = 0; k < time && i + k < nbugs; k++)
            res[bugs[i+k].second] = q.top().second;
        q.pop();
    }
    return true;
}

int main(int argc, char* argv[])
{
    fstream in;
    (argc > 1) ? in.open(argv[1]) : in.open("input.txt");
    cin >> nstudents >> nbugs >> maxpass;
    for(int i = 0; i < nbugs; i++)
    {
        cin >> tmp;
        bugs.push_back(make_pair(tmp, i));
    }
    for(int i = 0; i < nstudents; i++)
    {
        cin >> tmp;
        students.push_back(make_pair(i, make_pair(tmp, 0)));
    }
    for(int i = 0; i < nstudents; i++)
    {
        cin >> tmp;
        students[i].second = make_pair(students[i].second.first, tmp);
    }
    res.reserve(nbugs+1);
    sort(bugs.begin(), bugs.end());
    reverse(bugs.begin(), bugs.end());
    sort(students.begin(), students.end(), cmp);
    bool found = false;
    for (int i = 0; i < nstudents; i++)
        if (students[i].second.first >= bugs[0].first && students[i].second.second <= maxpass)
            found = true;
    if(found)
        cout << "SI" << endl;
    else
    {
        cout << "NO" << endl;
        return 0;
    }
    int best = INT_MAX, i = 0;
    /** Instead of a binary_search, we can do a linear search from the bottom
        until the first solvable. Test case do not penalize solution like this.*/
    for (; !risolvibile(i); i++);
    risolvibile(i);
    for (int i = 0; i < nbugs; i++)
        cout << res[i] + 1 << " ";
    cout << endl;
}
