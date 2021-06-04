#pragma once
#include"set.hpp"

template<typename T>
void func_for_my_set1(tree_elem<T>* t){
    t->m_value = 3 * t->m_value;
}
template<typename T>
bool isMoreTwo1(tree_elem<T>* t){
    if(t->m_value > 2){
        return true;
    }
    else{
        return false;
    }
}
template<typename T>
void template_lkp(Set<T>* x, Set<T>* y){
    cout<<"First Set: ";
    x->print_lkp();
    cout<<"\n";
    cout<<"Second Set: ";
    y->print_lkp();
    cout<<"\n";
    cout<<"Union for first and second set: ";
    Set<T> Set3 = *x + *y;
    Set3.print_lkp();
    cout<<"\n";
    cout<<"Cross for first and second set: ";
    Set<T> Set4 = (*x)*(*y);
    Set4.print_lkp();
    cout<<"\n";
    cout<<"Substraction for first and second set: ";
    Set<T> Set5 = *x - *y;
    Set5.print_lkp();
    cout<<"\n";
    cout<<"Map test for first set: ";
    x->Map_lkp(func_for_my_set);
    x->print_lkp();
    cout<<"\n";
    cout<<"Where test for second set: ";
    y->Where_lkp(isMoreTwo);
    y->print_lkp();
}

template<typename T>
void template_lpk(Set<T>* x, Set<T>* y){
    cout<<"First Set: ";
    x->print_lpk();
    cout<<"\n";
    cout<<"Second Set: ";
    y->print_lpk();
    cout<<"\n";
    cout<<"Union for first and second sets: ";
    Set<T> SetU = x->Sum_lpk(*y);
    SetU.print_lpk();
    cout<<"\n";
    cout<<"Cross for first and second sets: ";
    Set<T> SetC = x->Cross_lpk(*y);
    SetC.print_lpk();
    cout<<"\n";
    cout<<"Substraction for first and second sets: ";
    Set<T> SetS = x->Substraction_lpk(*y);
    SetS.print_lpk();
    cout<<"\n";
    cout<<"Map for first Set: ";
    x->Map_lpk(func_for_my_set);
    x->print_lpk();
    cout<<"\n";
    cout<<"Where for second Set(isMoreTwo): ";
    y->Where_lpk(isMoreTwo);
    y->print_lpk();
    cout<<"\n";
}

template<typename T>
void template_plk(Set<T>* x, Set<T>* y){
    cout<<"First Set: ";
    x->print_plk();
    cout<<"\n";
    cout<<"Second Set: ";
    y->print_plk();
    cout<<"\n";
    cout<<"Union for first and second sets: ";
    Set<T> SetU = x->Sum_plk(*y);
    SetU.print_plk();
    cout<<"\n";
    cout<<"Cross for first and second sets: ";
    Set<T> SetC = x->Cross_plk(*y);
    SetC.print_plk();
    cout<<"\n";
    cout<<"Substraction for first and second sets: ";
    Set<T> SetS = x->Substraction_plk(*y);
    SetS.print_plk();
    cout<<"\n";
    cout<<"Map for first Set: ";
    x->Map_plk(func_for_my_set);
    x->print_plk();
    cout<<"\n";
    cout<<"Where for second Set(isMoreTwo): ";
    y->Where_plk(isMoreTwo);
    y->print_plk();
    cout<<"\n";
}

template<typename T>
void template_pkl(Set<T>* x, Set<T>* y){
    cout<<"First Set: ";
    x->print_pkl();
    cout<<"\n";
    cout<<"Second Set: ";
    y->print_pkl();
    cout<<"\n";
    cout<<"Union for first and second sets: ";
    Set<T> SetU = x->Sum_pkl(*y);
    SetU.print_pkl();
    cout<<"\n";
    cout<<"Cross for first and second sets: ";
    Set<T> SetC = x->Cross_pkl(*y);
    SetC.print_pkl();
    cout<<"\n";
    cout<<"Substraction for first and second sets: ";
    Set<T> SetS = x->Substraction_pkl(*y);
    SetS.print_pkl();
    cout<<"\n";
    cout<<"Map for first Set: ";
    x->Map_pkl(func_for_my_set);
    x->print_pkl();
    cout<<"\n";
    cout<<"Where for second Set(isMoreTwo): ";
    y->Where_pkl(isMoreTwo);
    y->print_pkl();
    cout<<"\n";
}

template<typename T>
void template_klp(Set<T>* x, Set<T>* y){
    cout<<"First Set: ";
    x->print_klp();
    cout<<"\n";
    cout<<"Second Set: ";
    y->print_klp();
    cout<<"\n";
    cout<<"Union for first and second sets: ";
    Set<T> SetU = x->Sum_klp(*y);
    SetU.print_klp();
    cout<<"\n";
    cout<<"Cross for first and second sets: ";
    Set<T> SetC = x->Cross_klp(*y);
    SetC.print_klp();
    cout<<"\n";
    cout<<"Substraction for first and second sets: ";
    Set<T> SetS = x->Substraction_klp(*y);
    SetS.print_klp();
    cout<<"\n";
    cout<<"Map for first Set: ";
    x->Map_klp(func_for_my_set);
    x->print_klp();
    cout<<"\n";
    cout<<"Where for second Set(isMoreTwo): ";
    y->Where_klp(isMoreTwo);
    y->print_klp();
    cout<<"\n";
}

template<typename T>
void template_kpl(Set<T>* x, Set<T>* y){
    cout<<"First Set: ";
    x->print_kpl();
    cout<<"\n";
    cout<<"Second Set: ";
    y->print_kpl();
    cout<<"\n";
    cout<<"Union for first and second sets: ";
    Set<T> SetU = x->Sum_kpl(*y);
    SetU.print_kpl();
    cout<<"\n";
    cout<<"Cross for first and second sets: ";
    Set<T> SetC = x->Cross_kpl(*y);
    SetC.print_kpl();
    cout<<"\n";
    cout<<"Substraction for first and second sets: ";
    Set<T> SetS = x->Substraction_kpl(*y);
    SetS.print_kpl();
    cout<<"\n";
    cout<<"Map for first Set: ";
    x->Map_kpl(func_for_my_set);
    x->print_kpl();
    cout<<"\n";
    cout<<"Where for second Set(isMoreTwo): ";
    y->Where_kpl(isMoreTwo);
    y->print_kpl();
    cout<<"\n";
}

template<typename T>
void keyboard_set_test(){
    int type = 0;
    T value1;
    cout<<"Input Root of first Set: ";
    cin>>value1;
    auto first = new Set<T>(value1);
    cout<<"Input dimension of First Set: ";
    int dimension;
    cin>>dimension;
    if(dimension <= 0){
        cout<<"Input correct dimension"<<"\n";
    }
    for(int i = 0; i < dimension - 1; i++){
        T x;
        cin>>x;
        first->Insert(x);
    }
    T value2;
    cout<<"Input Root of second Set: ";
    cin>>value2;
    auto second = new Set<T>(value2);
    cout<<"Input dimension of Second Set: ";
    int dim;
    cin>>dim;
    if(dim <= 0){
        cout<<"Input correct dimension"<<"\n";
    }
    for(int i = 0; i < dim - 1; i++){
        T x;
        cin>>x;
        second->Insert(x);
    }
    while(type != 7){
        cout<<endl<<"Choice type"<<endl;
        cout << "1. Lkp" << endl << "2. Lpk" << endl << "3. Plk"<<endl <<"4. Pkl"<<endl<<"5. Klp"<<endl<<"6. Kpl"<<endl<<"7. Back"<<endl;
        cin >> type;
        cout << endl;
        switch(type){
            case 1: {
                template_lkp(first, second);
                break;
            }
            case 2: {
                template_lpk(first, second);
                break;
            }
            case 3: {
                template_plk(first, second);
                break;
            }
            case 4: {
                template_pkl(first, second);
                break;
            }
            case 5: {
                template_klp(first, second);
                break;
            }
            case 6: {
                template_kpl(first, second);
                break;
            }
            case 7:{
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
                break;
            }
        }
    }
}
