#pragma once
#include "set_stl_test.hpp"
#include "set.hpp"
#include"chrono"
#include "cassert"
template<typename T>
bool isMoreTwo2(tree_elem<T>* curr){
    if(curr) {
        if (curr->m_value >= 2) {
            return true;
        } else {
            return false;
        }
    }
}
template<typename T>
void func_for_my_set2(tree_elem<T>* t){
    t->m_value = 3 * t->m_value;
}
struct forTime{
    int lkp;
    int pkl;
    int kpl;
    int klp;
    int plk;
    int lpk;
    int stl;
};
typedef struct forTime ForTime;
void print_result(const string &Test, ForTime times) {
    cout<<Test<<":"<<"\n";
    cout << "Lkp time: " << times.lkp << " milliseconds" << endl;
    cout << "Pkl time: " << times.pkl << " milliseconds" << endl;
    cout << "Lpk time: " << times.lpk << " milliseconds" << endl;
    cout << "Plk time: " << times.plk << " milliseconds" << endl;
    cout << "Kpl time: " << times.kpl << " milliseconds" << endl;
    cout << "Klp time: " << times.klp << " milliseconds" << endl;
    cout << "Stl time: " << times.stl << " milliseconds" << endl;
}
ForTime test_union_int_set(int n) {
    ForTime q;
    Set<int> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    Set<int> d;
    for (int i = 0; i < n; i++)
    {
        d.Insert(n+2-i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<int> s = c + d;
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> sum = p.Sum_pkl(d);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> su = g.Sum_kpl(d);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> sun = m.Sum_klp(d);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> fun = o.Sum_plk(d);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    Set<int> funny = w.Sum_lpk(d);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<int> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    set<int> y;
    for(int i = 0; i < n; i++){
        y.insert(n + 2 - i);
    }
    start_time = chrono::steady_clock::now();
    set<int> a = sum_int_stl(e, y);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_union_double_set(int n) {
    ForTime q;
    Set<double> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    Set<double> d;
    for (int i = 0; i < n; i++)
    {
        d.Insert(n+2-i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<double> s = c + d;
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> sum = p.Sum_pkl(d);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> su = g.Sum_kpl(d);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> sun = m.Sum_klp(d);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> fun = o.Sum_plk(d);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    Set<double> funny = w.Sum_lpk(d);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<double> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    set<double> y;
    for(int i = 0; i < n; i++){
        y.insert(n + 2 - i);
    }
    start_time = chrono::steady_clock::now();
    set<double> a = sum_double_stl(e, y);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_cross_int_set(int n) {
    ForTime q;
    Set<int> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    Set<int> d;
    for (int i = 0; i < n; i++)
    {
        d.Insert(n+2-i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<int> s = c * d;
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> sum = p.Cross_pkl(d);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> su = g.Cross_kpl(d);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> sun = m.Cross_klp(d);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> fun = o.Cross_plk(d);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    Set<int> funny = w.Cross_lpk(d);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<int> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    set<int> y;
    for(int i = 0; i < n; i++){
        y.insert(n + 2 - i);
    }
    start_time = chrono::steady_clock::now();
    set<int> a = cross_int(e, y);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_cross_double_set(int n) {
    ForTime q;
    Set<double> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    Set<double> d;
    for (int i = 0; i < n; i++)
    {
        d.Insert(n+2-i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<double> s = c * d;
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> sum = p.Cross_pkl(d);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> su = g.Cross_kpl(d);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> sun = m.Cross_klp(d);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> fun = o.Cross_plk(d);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    Set<double> funny = w.Cross_lpk(d);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<double> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    set<double> y;
    for(int i = 0; i < n; i++){
        y.insert(n + 2 - i);
    }
    start_time = chrono::steady_clock::now();
    set<double> a = cross_double(e, y);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_substraction_int_set(int n) {
    ForTime q;
    Set<int> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    Set<int> d;
    for (int i = 0; i < n; i++)
    {
        d.Insert(n+2-i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<int> s = c - d;
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> sum = p.Substraction_pkl(d);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> su = g.Substraction_kpl(d);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> sun = m.Substraction_klp(d);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<int> fun = o.Substraction_plk(d);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    Set<int> funny = w.Substraction_lpk(d);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<int> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    set<int> y;
    for(int i = 0; i < n; i++){
        y.insert(n + 2 - i);
    }
    start_time = chrono::steady_clock::now();
    set<int> a = substraction_int(e, y);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_substraction_double_set(int n) {
    ForTime q;
    Set<double> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    Set<double> d;
    for (int i = 0; i < n; i++)
    {
        d.Insert(n+2-i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<double> s = c - d;
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> sum = p.Substraction_pkl(d);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> su = g.Substraction_kpl(d);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> sun = m.Substraction_klp(d);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    Set<double> fun = o.Substraction_plk(d);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    Set<double> funny = w.Substraction_lpk(d);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<double> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    set<double> y;
    for(int i = 0; i < n; i++){
        y.insert(n + 2 - i);
    }
    start_time = chrono::steady_clock::now();
    set<double> a = substraction_double(e, y);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_map_int_set(int n) {
    ForTime q;
    Set<int> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    auto start_time = chrono::steady_clock::now();
    c.Map_lkp(func_for_my_set2);
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    p.Map_pkl(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    g.Map_kpl(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    m.Map_klp(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    o.Map_plk(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<int> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    w.Map_lpk(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<int> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    start_time = chrono::steady_clock::now();
    set<int> a = Map_int(e, func);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}

ForTime test_map_double_set(int n) {
    ForTime q;
    Set<double> c;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    auto start_time = chrono::steady_clock::now();
    c.Map_lkp(func_for_my_set2);
    auto end_time = chrono::steady_clock::now();
    q.lkp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> p;
    for (int i = 0; i < n; i++)
    {
        c.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    p.Map_pkl(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.pkl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> g;
    for (int i = 0; i < n; i++)
    {
        g.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    g.Map_kpl(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.kpl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> m;
    for (int i = 0; i < n; i++)
    {
        m.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    m.Map_klp(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.klp = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> o;
    for (int i = 0; i < n; i++)
    {
        o.Insert(i);
    }
    start_time = chrono::steady_clock::now();
    o.Map_plk(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.plk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    Set<double> w;
    for (int i = 0; i < n; i++)
    {
        w.Insert(i);
    }

    start_time = chrono::steady_clock::now();
    w.Map_lpk(func_for_my_set2);
    end_time = chrono::steady_clock::now();
    q.lpk = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    set<double> e;
    for(int i = 0; i < n; i++){
        e.insert(i);
    }
    start_time = chrono::steady_clock::now();
    set<double> a = Map_double(e, func);
    end_time = chrono::steady_clock::now();
    q.stl = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return q;
}




void time_test_int(int n){
    print_result("Union int Test",test_union_int_set(n));
    print_result("Cross Int Test", test_cross_int_set(n));
    print_result("Substraction Int Test", test_substraction_int_set(n));
    print_result("Map Int Test", test_map_int_set(n));
}
void time_test_double(int n){
    print_result("Union Double Test",test_union_double_set(n));
    print_result("Cross Double Test", test_cross_double_set(n));
    print_result("Substraction Double Test", test_substraction_double_set(n));
    print_result("Map Double Test", test_map_double_set(n));
}
