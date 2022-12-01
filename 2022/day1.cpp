#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("day1input.txt");
vector<int> result;

int string_to_int(string str)
{
    int result = 0;
    for (int i = 0; i < str.size(); i++) {
        result = result * 10 + str[i] - '0';
    }

    return result;
}

int part1()
{
    int top = 0;
    for (auto i : result) {
        if (i > top)
            top = i;
    }

    return top;
}

int part2()
{
    int top1 = 0, top2 = 0, top3 = 0;
    for (auto i : result) {
        if (i > top1) {
            top3 = top2;
            top2 = top1;
            top1 = i;
        } else if (i > top2) {
            top3 = top2;
            top2 = i;
        } else if (i > top3) {
            top3 = i;
        }
    }

    return top1+top2+top3;
}

int main()
{
    string temp;
    int sum = 0;

    while (getline(fin, temp)) {
        if (temp == "") {
            result.push_back(sum);
            sum = 0;
        } else {
            int numtemp = string_to_int(temp);
            sum += numtemp;
        }
    }

    cout << part1() << endl << part2(); 
}