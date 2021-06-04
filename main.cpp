#include "test_for_my_set.hpp"
#include "keyboard_set.hpp"
#include "set_stl_test.hpp"
#include "time_test_for_my_set.hpp"
int main() {
    int choice = 0;
    int type_cont = 0;
    int for_set = 0;
    int type_data = 0;
    int for_data = 0;
    int ded = 0;
    int babka = 0;
    int batya = 0;

    while(choice != 3) {
        cout << endl << "Choose an action:" << endl;
        cout << "1. Start operation tests" << endl << "2. Start time test" << endl << "3. Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: {
                for_set=0;
                while (for_set != 4) {
                    cout << endl << "Choose a type: " << endl;
                    cout << "1. Ready Set Test" << endl << "2. Keyboard Set Test" << endl << "3. Stl Set Test"<<endl<<"4. Back"
                         << endl;
                    cin >> for_set;
                    cout << endl;
                    switch(for_set){
                        case 1:{
                            type_cont = 0;
                            while (type_cont != 3) {
                                cout << endl << "Choose a type: " << endl;
                                cout << "1. Int Set Test" << endl << "2. Double Set Test" << endl << "3. Back"
                                     << endl;
                                cin >> type_cont;
                                cout << endl;
                                switch(type_cont){
                                    case 1:{
                                        type_data = 0;
                                        while (type_data != 7) {
                                            cout << endl << "Choose a type: " << endl;
                                            cout << "1. Lkp" << endl << "2. Lpk" << endl << "3. Plk"
                                                 << endl<<"4. Pkl"<<endl<<"5. Klp"<<endl<<"6. Kpl"<<endl<<"7. Back";
                                            cin >> type_data;
                                            cout << endl;
                                            switch(type_data){
                                                case 1: {
                                                    test_for_int_set_lkp();
                                                    break;
                                                }
                                                case 2:{
                                                    test_for_int_set_lpk();
                                                    break;
                                                }
                                                case 3:{
                                                    test_for_int_set_plk();
                                                    break;
                                                }
                                                case 4:{
                                                    test_for_int_set_pkl();
                                                    break;
                                                }
                                                case 5:{
                                                    test_for_int_set_klp();
                                                    break;
                                                }
                                                case 6:{
                                                    test_for_int_set_kpl();
                                                }
                                                case 7:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 2:{
                                        for_data = 0;
                                        while(for_data != 7){
                                            cout << endl << "Choose a type: " << endl;
                                            cout << "1. Lkp" << endl << "2. Lpk" << endl << "3. Plk"
                                                 << endl<<"4. Pkl"<<endl<<"5. Klp"<<endl<<"6. Kpl"<<endl<<"7. Back";
                                            cin >> for_data;
                                            cout << endl;
                                            switch(for_data){
                                                case 1:{
                                                    test_for_double_set_lkp();
                                                    break;
                                                }
                                                case 2:{
                                                    test_for_double_set_lpk();
                                                    break;
                                                }
                                                case 3:{
                                                    test_for_double_set_plk();
                                                    break;
                                                }
                                                case 4:{
                                                    test_for_double_set_pkl();
                                                    break;
                                                }
                                                case 5:{
                                                    test_for_double_set_klp();
                                                    break;
                                                }
                                                case 6:{
                                                    test_for_double_set_kpl();
                                                    break;
                                                }
                                                case 7:{
                                                    break;
                                                }
                                                default:{
                                                    cout<<"Enter a number from the list";
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    case 3:{
                                        break;
                                    }
                                    default:{
                                        cout<<"Enter a number from the list";
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{
                            ded = 0;
                            while(ded != 3){
                                cout << endl << "Choose a type: " << endl;
                                cout << "1. Int keyboard Set Test" << endl << "2. Double keyboard Set Test" << endl << "3. Back"
                                     << endl;
                                cin >> ded;
                                cout << endl;
                                switch(ded){
                                    case 1:{
                                        keyboard_set_test<int>();
                                        break;
                                    }
                                    case 2: {
                                        keyboard_set_test<double>();
                                        break;
                                    }
                                    case 3:{
                                        break;
                                    }
                                    default:{
                                        cout<<"Enter a number from the list";
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3:{
                            babka = 0;
                            while(babka != 3){
                                cout << endl << "Choose a type: " << endl;
                                cout << "1. Int Stl Set Test" << endl << "2. Double Stl Set Test" << endl << "3. Back"
                                     << endl;
                                cin >> babka;
                                cout << endl;
                                switch(babka){
                                    case 1:{
                                        int_stl_set_test(10);
                                        break;
                                    }
                                    case 2:{
                                        double_stl_set_test(10);
                                        break;
                                    }
                                    case 3: {
                                        break;
                                    }
                                    default:{
                                        cout<<"Enter a number from the list"<<"\n";
                                        break;
                                    }
                                }
                                break;
                            }
                            break;
                        }
                        case 4:{
                            break;
                        }
                        default:{
                            cout<<"Enter a number from the list"<<"\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                while(batya != 3){
                    cout << endl << "Choose a type: " << endl;
                    cout << "1. Int Time Test" << endl << "2. Double Time Test" << endl << "3. Back"
                         << endl;
                    cin >> batya;
                    cout << endl;
                    switch(batya){
                        case 1:{
                            time_test_int(10000);
                            break;
                        }
                        case 2:{
                            time_test_double(10000);
                            break;
                        }
                        case 3:{
                            break;
                        }
                        default:{
                            cout<<"Enter a number from the list"<<"\n";
                            break;
                        }
                    }

                }
                break;
            }
            case 3:{
                break;
            }
            default:{
                cout<<"Enter a number from the list"<<"\n";
                break;
            }
        }
    }
}