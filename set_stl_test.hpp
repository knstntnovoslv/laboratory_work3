#pragma once
#include "set_stl.hpp"
template<typename T>
T func(T n){
    return 3*n + 1;
}
template<typename T>
bool isMoreTwo_stl(T n){
    if(n > 2){
        return true;
    }
    else{
        return false;
    }
}
void int_stl_set_test(int n){
    set<int> c;
    for(int i = 0; i < n; i++){
        c.insert(i);
    }
    cout<<"First stl set: ";
    print_stl_set_int(c);
    cout<<"\n";
    set<int> d;
    for(int i = 0; i < n + 5; i++){
        d.insert(i);
    }
    cout<<"Second stl set: ";
    print_stl_set_int(d);
    cout<<"\n";
    set<int> e = sum_int_stl(c, d);
    cout<<"Union stl Test for First and Second Sets: ";
    print_stl_set_int(e);
    cout<<"\n";
    set<int> f = cross_int(c, d);
    cout<<"Cross stl Test for First and Second Sets: ";
    print_stl_set_int(f);
    cout<<"\n";
    set<int> g = substraction_int(d, c);
    cout<<"Substraction stl Test for first and Second Sets: ";
    print_stl_set_int(g);
    cout<<"\n";
    set<int> h = Map_int(c, func);
    cout<<"Map stl Test for First Set: ";
    print_stl_set_int(h);
    cout<<"\n";
    set<int> i = Where_int(d, isMoreTwo_stl);
    cout<<"Where stl Test for Second Set: ";
    print_stl_set_int(i);
    cout<<"\n";
}

void double_stl_set_test(int n){
    set<double> c;
    for(int i = 0; i < n; i++){
        c.insert(i+0.25);
    }
    cout<<"First stl set: ";
    print_stl_set_double(c);
    cout<<"\n";
    set<double> d;
    for(int i = 0; i < n + 5; i++){
        d.insert(i+0.25);
    }
    cout<<"Second stl set: ";
    print_stl_set_double(d);
    cout<<"\n";
    set<double> e = sum_double_stl(c, d);
    cout<<"Union stl Test for First and Second Sets: ";
    print_stl_set_double(e);
    cout<<"\n";
    set<double> f = cross_double(c, d);
    cout<<"Cross stl Test for First and Second Sets: ";
    print_stl_set_double(f);
    cout<<"\n";
    set<double> g = substraction_double(d, c);
    cout<<"Substraction stl Test for first and Second Sets: ";
    print_stl_set_double(g);
    cout<<"\n";
    set<double> h = Map_double(c, func);
    cout<<"Map stl Test for First Set: ";
    print_stl_set_double(h);
    cout<<"\n";
    set<double> i = Where_double(d, isMoreTwo_stl);
    cout<<"Where stl Test for Second Set: ";
    print_stl_set_double(i);
    cout<<"\n";
}


