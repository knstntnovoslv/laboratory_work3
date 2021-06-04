#pragma once
#include<set>
#include<iostream>
using namespace std;

set<int> sum_int_stl(set<int>& x, set<int>& y){
    set<int> z;
    set<int>:: iterator it;
    for(it = x.begin(); it != x.end(); it++){
        z.insert(*it);
    }
    set<int>:: iterator ite;
    for(ite = y.begin(); ite != y.end(); ite++){
        if(!z.count(*ite)){
            z.insert(*ite);
        }
    }
    return z;
}
set<double> sum_double_stl(const set<double>& x, const set<double>& y){
    set<double> z;
    set<double>:: iterator it;
    for(it = x.begin(); it != x.end(); it++){
        z.insert(*it);
    }
    set<double>:: iterator ite;
    for(ite = y.begin(); ite != y.end(); ite++){
        if(!z.count(*ite)){
            z.insert(*ite);
        }
    }
    return z;
}
set<int> cross_int(const set<int>& x, const set<int>& y){
    set<int> z;
    set<int>::iterator it;
    set<int>::iterator ite;
    for(it = x.begin(); it != x.end(); it++){
        for(ite = y.begin(); ite != y.end(); ite++){
            if(*it == *ite && !z.count(*it)){
                z.insert(*it);
            }
        }
    }
    return z;
}
set<double> cross_double(const set<double>& x, const set<double>& y){
    set<double> z;
    set<double>::iterator it;
    set<double>::iterator ite;
    for(it = x.begin(); it != x.end(); it++){
        for(ite = y.begin(); ite != y.end(); ite++){
            if(*it == *ite && !z.count(*it)){
                z.insert(*it);
            }
        }
    }
    return z;
}
set<int> substraction_int(const set<int>& x, const set<int>& y){
    set<int> z;
    set<int>::iterator it;
    for(it = x.begin(); it != x.end(); it++){
        if(!y.count(*it)){
            z.insert(*it);
        }
    }
    return z;
}
set<double> substraction_double(const set<double>& x, const set<double>& y){
    set<double> z;
    set<double>::iterator it;
    set<double>::iterator ite;
    for(it = x.begin(); it != x.end(); it++){
        if(!y.count(*it)){
            z.insert(*it);
        }
    }
    return z;
}

set<int> Map_int(set<int>& x, int (*function)(int)){
    set<int> z;
    set<int>::iterator it;
    for(it = x.begin(); it != x.end(); it++){
        z.insert(function(*it));
    }
    return z;
}
set<double> Map_double(set<double>& x, double (*function)(double)){
    set<double> z;
    set<double>::iterator it;
    for(it = x.begin(); it != x.end(); it++){
        z.insert(function(*it));
    }
    return z;
}

set<int> Where_int(set<int>& x, bool (*function)(int)){
    set<int> z;
    set<int>::iterator it = x.begin();
    for(int i = 0; i < x.size(); i++){
        if(function(*it)){
            z.insert(*it);
        }
        it++;
    }
    return z;
}
set<double> Where_double(set<double>& x, bool (*function)(double)){
    set<double> z;
    set<double>::iterator it = x.begin();
    for(int i = 0; i < x.size(); i++){
        if(function(*it)){
            z.insert(*it);
        }
    }
    return z;
}
void print_stl_set_int(set<int>& x){
    set<int>::iterator it;
    for(it = x.begin(); it != x.end(); it++){
        cout<<*it<<" ";
    }
}
void print_stl_set_double(set<double>& x){
    set<double>::iterator it;
    for(it = x.begin(); it != x.end(); it++){
        cout<<*it<<" ";
    }
}

