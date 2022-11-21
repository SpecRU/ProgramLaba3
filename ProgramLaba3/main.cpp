#include <iostream>
#include <string>
#include "iterator.h"

using namespace std;

int main(){
    int a = 5;
    int& b = a;
    Map<int, int> map;
    for (int i=0; i < 5; i++){
        map.push(i, --b);
    }

    for (int i = 0; i < map.size(); i++){
        cout << "Key: " << i << " " << "Value: " << map[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        map.delElem(i);
    }

    std::list<int> ml = map.keys();
    for (auto it : ml){
        cout << "Key: " << it << " " << "Value: " << map[it] << endl;
    }
    cout << endl;

    Map<int, int> map1(map);
    if (map == map1) cout << "map == map1" << endl << endl;

    std::list<int> l = map1.keys();
    for (auto it : l){
        cout << it << " ";
    }
    cout << endl << endl;

    Iteratorclass<Map<int, int>> iter(map1); //вылет при пустом итераторе
    cout << iter.first() << " " << iter.second() << endl;
    ++iter;
    cout << iter.first() << " " << iter.second() << endl << endl;

    cout << map1.toJSON() << endl;
    const Map<int, int> map2(map1);
    cout << map2.toJSON() << endl;
    Iteratorclass<Map<int, int>> iter2(map2);
}