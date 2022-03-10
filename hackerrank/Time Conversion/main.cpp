#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    string ret;
    char format = s.at(8);
    int hours = stoi(string(s.begin(), s.begin() + 2));
    switch (format)
    {
        case 'A':
        {
            if (hours == 12)
            {
                ret.append("00");
                ret.append(s.begin() + 2, s.begin() + 8);
            }
            else
            {
                ret.append(s.begin(), s.begin() + 8);
            }
            break;
        }
        case 'P':
        {
            if (hours == 12)
            {
                ret.append(s.begin(), s.begin() + 8);
            }
            else
            {
                string new_hours = to_string(hours + 12);
                if (new_hours.size() == 1)
                    ret.append("0");
                ret.append(new_hours);
                ret.append(s.begin() + 2, s.begin() + 8);
            }
            break;
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
