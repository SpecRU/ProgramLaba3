#include <iostream>
#include <string>
#include "iterator.h"

using namespace std;

int main(){
    int a = 5;
    int& b = a;
    Map<int, int> map;
    for (int i=0; i < 5; i++){
        map.add(i, --b);
    }
    //map.deleteEl(1);
    for (int i=0; i < map.size(); i++){
        cout << "Key: " << i << " " << "Value: " << map[i] << " ";
    }
    cout << endl;
    Map<int, int> map1(map);
    if (map == map1) cout << "12345";
    cout << endl;
    std::list<int> l = map1.keys();
    for (auto it : l){
        cout << it << " ";
    }
    cout << endl;
    Iteratorclass<Map<int, int>> iter(map1);
    cout << iter.first() << " " << iter.second() << endl;
    ++iter;
    cout << iter.first() << " " << iter.second() << endl;

    cout << iter.second();
    cout << map1.toJSON() << endl;
    const Map<int, int> abc(map1);
    cout << abc.toJSON() << endl;
    Iteratorclass<Map<int, int>> iter2(abc);
}