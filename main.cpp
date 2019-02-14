#include <iostream>

#include "AutoShow.h"
#include "DataBase.h"

using namespace std;

int main()
{

    AutoShow autoShow;
    int choice = -1;
    while(choice != 0)
    {
        cout << "If you want to: \n\tadd Data - press 1"
                "\n\tremove Data - press 2"
                "\n\tshow data - press 3"
                "\n\tsort data - press 4"
                "\n\tfind Data - press 5"
                "\n\tif you want to work with default Data - press 6"
                "\n\tPress 0 if you want to exit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 0:
                cout << "Bye=)" << endl;
                break;
            case 1:
                //интерфейс ввода
                autoShow.addAuto();
                break;
            case 2:
                // удалить по ID
                autoShow.remove();
                break;
            case 3:
                //отобразить
                autoShow.showData();
                break;
            case 4:
                //выбрать критерий сортировки
                autoShow.sortDataAndShow();
                break;
            case 5:
                //спросить что мы знаем о искомом, вывести возможные варианты
                autoShow.find();
                break;
            case 6:
                //загрузить в контейнеры данные по умолчанию
                autoShow.defaultFill(BRAND, YEAR, ENGINEV, PRICE);
                break;
            default:
                cout << "Sorry but I don't know what you want" << endl;
        }
    }


    return 0;
}
