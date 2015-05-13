#include <iostream>
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


long long risolvibile(int time)
{
    int now = maxpass, current_stud = 0;
    while (!q.empty()) /** Empty the queue */
        q.pop();
    for (int i = 0; i < nbugs; i += time)
    {
        while (current_stud < nstudents &&
            students[current_stud].second.first >= bugs[i].first)
        {
            /** For convenience, we push negative values to not have
                a custom comparasion operator(). */
            q.push(make_pair(-students[current_stud].second.second,
                students[current_stud].first));
            current_stud++;
        }
        if (q.empty()) return false; /** We have more bugs and no student
                                         can do them. */
        now += q.top().first; /** Subtract (add negative) the cost of the cheapest student */
        if (now < 0) return false;   /** If we run out of cash */
        for (int k = 0; k < time && i + k < nbugs; k++)
            res[bugs[i+k].second] = q.top().second;
        q.pop();
    }
    return now;
}

int main()
{
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
    int low = 0, high = nbugs, mid;
    while (low < high) /** Simple binary search */
    {
        mid = (low + high) / 2;
        if (risolvibile(mid))
            high = mid;
        else
            low = mid + 1;
    }
    long long tot = maxpass - risolvibile(low);
    for (int i = 0; i < nbugs; i++)
        cout << res[i] + 1 << " ";
    for (int i = 0; i < nbugs; i++)
        cout << res[i] + 1 << " ";
    cout << endl;
}
