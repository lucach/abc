/**
DOUBLE WARNING! THIS IS NOT AN USER SOLUTION.
THIS TAKES INPUT AND GENERATES OUTPUT AS TO BE CONSUMED
BY CHECKER.

AGAIN: *******THIS IS NOT AN USER SOLUTION********
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
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


int risolvibile(int time)
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
        if (q.empty()) return -1; /** We have more bugs and no student
                                         can do them. */
        now += q.top().first; /** Add the cost of the cheapest student */
        if (now < 0) return -1;   /** If we run out of cash */
        for (int k = 0; k < time && i + k < nbugs; k++)
            res[bugs[i+k].second] = q.top().second;
        q.pop();
    }
    return now;
}


int main(int argc, char* argv[])
{
    ifstream in;
    (argc > 1) ? in.open(argv[1]) : in.open("input.txt");
    in >> nstudents >> nbugs >> maxpass;
    for(int i = 0; i < nbugs; i++)
    {
        in >> tmp;
        bugs.push_back(make_pair(tmp, i));
    }
    for(int i = 0; i < nstudents; i++)
    {
        in >> tmp;
        students.push_back(make_pair(i, make_pair(tmp, 0)));
    }
    for(int i = 0; i < nstudents; i++)
    {
        in >> tmp;
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
    int low = 0, high = nbugs, mid;
    while (low < high) /** Simple binary search */
    {
        mid = (low + high) / 2;
        if (risolvibile(mid) >= 0)
            high = mid;
        else
            low = mid + 1;
    }
    int tot = maxpass - risolvibile(low);
    cout << tot << " " << low << endl; /** Print best cost and days taken*/
}
