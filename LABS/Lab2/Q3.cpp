#include <iostream>
using namespace std;

bool checkfriend(bool friends[5][5], int person1, int person2)
{
    for (int i = 0; i < 5; i++)
    {
        if (friends[i][person1] && friends[i][person2])
        {
            cout << "person" << person1 << " and person" << person2 << " are common friends with person" << i << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    bool friends[5][5] = {
        {false, true, false, true, true},
        {true, false, true, false, true},
        {false, true, false, false, false},
        {true, false, false, false, true},
        {true, true, false, true, false}};

    int person1, person2;
    cout << "enter the first person you want to check: " << endl;
    cin >> person1;
    cin.ignore();
    cout << "enter the second person you want to check: " << endl;
    cin >> person2;

    if (!checkfriend(friends, person1, person2))
    {
        cout << "person" << person1 << " and person" << person2 << " have no common friends" << endl;
    }
    else
    {
        checkfriend(friends, person1, person2);
    }
}
