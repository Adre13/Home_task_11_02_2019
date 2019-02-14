//
// Created by msi on 13.02.2019.
//

#ifndef HOME_TASK_11_02_2019_AUTOSHOW_H
#define HOME_TASK_11_02_2019_AUTOSHOW_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class AutoShow
{
private:
    int id = 0;
    map<int, string> brand;
    map<int, int> year;
    map<int, float> engineV;
    map<int, int> price;
    map<int, bool> visible;

public:

    AutoShow() = default;
    ~AutoShow() = default;
    void addAuto();
    void remove();
    void showData();
    void sortDataAndShow();
    void find();
    void defaultFill(vector<string> str, vector<int> year, vector<float> engineV, vector<int> price);
    template <typename K, typename V>
    multimap<V, K> invertMap(map<K, V> const &map);

//    "If you want to: \n\tadd Data - press 1"
//    "\n\tremove Data - press 2"
//    "\n\tshow data - press 3"
//    "\n\tsort data - press 4"
//    "\n\tfind Data - press 5"
//    "\n\tif you want to work with default Data - press 6"
//    "\n\tPress 0 if you want to exit" << endl;

};


#endif //HOME_TASK_11_02_2019_AUTOSHOW_H
