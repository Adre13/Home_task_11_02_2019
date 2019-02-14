//
// Created by msi on 13.02.2019.
//

#include <iostream>
#include <iomanip>
#include "AutoShow.h"

void AutoShow::addAuto()
{
    string brand;
    int year = 0, price = 0;
    float engineV = 0.0;
    cout << "Input brand (use 1 word):" << endl;
    cin >> brand;
    this->brand[id] = brand;
    cout << "Input year:" << endl;
    cin >> year;
    this->year[id] = year;
    cout << "Input the engine volume:" << endl;
    cin >> engineV;
    this->engineV[id] = engineV;
    cout << "Input price:" << endl;
    cin >> price;
    this->price[id] = price;
    this->visible[id] = true;
    id++;

}

void AutoShow::remove()
{
    int choice = -2;
    while(choice != -1)
    {
        cout << "You should input the Id position, that you want to delete.\n"
                "or input '-1' if you don't know it" << endl;

        cin >> choice;
        if(choice >= 0 && choice <= id)
        {
            cout << "I deleted it=)" << endl;
            this->visible[choice] = false;
        }
    }
}

void AutoShow::showData()
{

    cout << setw(3) << left << "Id" << setw(20) << left << "Brand" << setw(8) << left << "Year" << setw(15) << left << "Engine V" << setw(12) << "Price" << endl;
    for(auto i = 0; i < id; i++)
    {
        if(visible[i])
        {
            cout << setw(3) << left << i << setw(20) << left << brand[i] << setw(8) << left << year[i] << setw(15) << left << engineV[i] << setw(12) << price[i] << endl;
        }
    }
}

void AutoShow::sortDataAndShow()
{
    int choice = -1;
    while (choice)
    {
        cout << "If you wont to sort DB and show it:"
                "\tby Brand - input 1\n"
                "\tto sort by Year - input 2\n"
                "\tto sort by Engine V - input 3\n"
                "\tto sort by Price - input 4\n"
                "input 0 if you want to exit" << endl;
        cin >> choice;
        cout << setw(3) << left << "Id" << setw(20) << left << "Brand" << setw(8) << left << "Year" << setw(15)
             << left << "Engine V" << setw(12) << "Price" << endl;
        switch (choice)
        {
            case 0:
            {
                cout << "Bye=)" << endl;
            }
                break;
            case 1:
            {
                multimap<string, int> temp = invertMap<int, string>(brand);
                for (auto const &pair : temp)
                {
                    if (visible[pair.second])
                    {
                        cout << setw(3) << left << pair.second << setw(20) << left << pair.first << setw(8) << left
                             << year[pair.second] << setw(15) << left << engineV[pair.second] << setw(12)
                             << price[pair.second] << endl;
                    }
                }
            }
                break;
            case 2:
            {
                multimap<int, int> temp = invertMap<int, int>(year);
                for (auto const &pair : temp)
                {
                    if (visible[pair.second])
                    {
                        cout << setw(3) << left << pair.second << setw(20) << left << brand[pair.second] << setw(8)
                             << left
                             << pair.first << setw(15) << left << engineV[pair.second] << setw(12)
                             << price[pair.second] << endl;
                    }
                }
            }
                break;
            case 3:
            {
                multimap<float, int> temp = invertMap<int, float>(engineV);
                for (auto const &pair : temp)
                {
                    if (visible[pair.second])
                    {
                        cout << setw(3) << left << pair.second << setw(20) << left << brand[pair.second] << setw(8)
                             << left
                             << year[pair.second] << setw(15) << left << pair.first << setw(12)
                             << price[pair.second] << endl;
                    }
                }
            }
                break;
            case 4:
            {
                multimap<int, int> temp = invertMap<int, int>(price);
                for (auto const &pair : temp)
                {
                    if (visible[pair.second])
                    {
                        cout << setw(3) << left << pair.second << setw(20) << left << brand[pair.second] << setw(8)
                             << left
                             << year[pair.second] << setw(15) << left << engineV[pair.second] << setw(12)
                             << pair.first << endl;
                    }
                }
            }
                break;
            default:
                cout << "I don't know what you mean=)" << endl;
        }
    }
}

void AutoShow::find()
{
    int choice = -1;
    while (choice)
    {
        cout << "If you know the Id - input 1\n"
                "If you want to find by brand - input 2\n"
                "If you want to find by year - input 3\n"
                "If you want to find by engine V - input 4\n"
                "If you want to find by price - input 5\n"
                "If you want to exit - input 0" << endl;
        cin >> choice;
        cout << setw(3) << left << "Id" << setw(20) << left << "Brand" << setw(8) << left << "Year"
             << setw(15) << left << "Engine V" << setw(12) << "Price" << endl;
        switch (choice)
        {
            case 0:
                cout << "Bye=)" << endl;
                break;
            case 1:
            {
                int tempId;
                cout << "Input Id:" << endl;
                cin >> tempId;
                if (tempId >= 0 && tempId <= id && visible[tempId])
                {
                    cout << setw(3) << left << tempId << setw(20) << left << brand[tempId] << setw(8) << left
                         << year[tempId] << setw(15)
                         << left << engineV[tempId] << setw(12) << price[tempId] << endl;
                } else
                {
                    cout << "Invalid input or this position is deleted" << endl;
                }
            }
                break;
            case 2:
            {
                string searchBrand;
                cout << "Input the brand's name" << endl;
                cin >> searchBrand;
                for (auto const &pair : brand)
                {
                    if (visible[pair.first] && pair.second == searchBrand)
                    {
                        cout << setw(3) << left << pair.first << setw(20) << left << pair.second << setw(8) << left
                             << year[pair.first] << setw(15) << left << engineV[pair.first] << setw(12)
                             << price[pair.first] << endl;
                    }
                }
            }
                break;
            case 3:
            {
                int searchYear = 0;
                cout << "Input year:" << endl;
                cin >> searchYear;
                for (auto const &pair : year)
                {
                    if (visible[pair.first] && pair.second == searchYear)
                    {
                        cout << setw(3) << left << pair.first << setw(20) << left << brand[pair.first] << setw(8)
                             << left
                             << pair.second << setw(15) << left << engineV[pair.first] << setw(12) << price[pair.first]
                             << endl;
                    }
                }
            }
                break;
            case 4:
            {
                float searchEngV = 0.0;
                cout << "input engine V" << endl;
                cin >> searchEngV;
                for (auto const &pair : engineV)
                {
                    if (visible[pair.first] && pair.second == searchEngV)
                    {
                        cout << setw(3) << left << pair.first << setw(20) << left << brand[pair.first] << setw(8)
                             << left
                             << year[pair.first] << setw(15) << left << pair.second << setw(12) << price[pair.first]
                             << endl;
                    }
                }
            }
                break;
            case 5:
            {
                int searchPrice = 0;
                cout << "Input price" << endl;
                cin >> searchPrice;
                for (auto const &pair : price)
                {
                    if (visible[pair.first] && pair.second == searchPrice)
                    {
                        cout << setw(3) << left << pair.first << setw(20) << left << brand[pair.first] << setw(8)
                             << left
                             << year[pair.first] << setw(15) << left << engineV[pair.first] << setw(12) << pair.second
                             << endl;
                    }
                }
            }
                break;
            default:
                cout << "I don't know what you mean." << endl;
        }
    }

}

void AutoShow::defaultFill(vector<string> str, vector<int> year, vector<float> engineV, vector<int> price)
{
    for(auto i = 0; i < str.size(); i++)
    {
        this->brand[i] = str[i];
        this->year[i] = year[i];
        this->engineV[i] = engineV[i];
        this->price[i] = price[i];
        this->visible[i] = true;
        id++;
    }
}

template<typename K, typename V>
multimap<V, K> AutoShow::invertMap(const map<K, V> &map)
{
    multimap<V, K> temp;
    for(auto const& pair : map)
    {
        temp.insert(make_pair(pair.second, pair.first));
    }
    return temp;
}
