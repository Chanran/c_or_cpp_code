#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream input;
    input.open("word.txt");
    string eachline;
    map<string, int> mapA; //第一个存单词,第二个存单词出现的次数;

    while (getline(input, eachline)) {
        string::size_type start = 0;
        string::size_type end = eachline.find_first_of(" ");
        while (end != string::npos) {
            string content = eachline.substr(start, end - start);
            map<string, int>::iterator it = mapA.find(content);
            if (it == mapA.end()) {
                mapA.insert(pair<string, int>(content, 1));//赋值的时候只接受pair类型；
            } else {
                ++it->second;

            }
            start = end + 1;
            end = eachline.find_first_of(" ", start);
        }

    }
    multimap<int, string, greater<int> > mapB;

    for (map<string, int>::iterator it1 = mapA.begin(); it1 != mapA.end();++it1) {
        mapB.insert(pair<int, string>(it1->second, it1->first));
    }

    for (map<int, string>::iterator it2 = mapB.begin(); it2 != mapB.end();++it2) {
        cout << it2->second << "单词出现的次数是" << it2->first << endl;
    }

}
        string::size_type start = 0;
        string::size_type end = eachline.find_first_of(" ");
        while (end != string::npos) {
            string content = eachline.substr(start, end - start);
            map<string, int>::iterator it = mapA.find(content);
            if (it == mapA.end()) {
                mapA.insert(pair<string, int>(content, 1));//赋值的时候只接受pair类型；
            } else {
                ++it->second;

            }
            start = end + 1;
            end = eachline.find_first_of(" ", start);
        }

    }
    multimap<int, string, greater<int> > mapB;

    for (map<string, int>::iterator it1 = mapA.begin(); it1 != mapA.end();++it1) {
        mapB.insert(pair<int, string>(it1->second, it1->first));
    }

    for (map<int, string>::iterator it2 = mapB.begin(); it2 != mapB.end();++it2) {
        cout << it2->second << "单词出现的次数是" << it2->first << endl;
    }

}