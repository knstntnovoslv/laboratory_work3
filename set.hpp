#pragma once
#include <stdexcept>
#include "binary_tree.hpp"
template<class T>
class Set{
private:
    BinaryTree<T> *m_set;
public:
    //конструкторы
    Set() {
        m_set = new BinaryTree<T>();
    }
    Set(T value){
        m_set = new BinaryTree<T>(value);
    }
    Set(BinaryTree<T> *tree) {
        m_set = tree->clone();
    }

    Set(Set<T> const &y) {
        m_set = new BinaryTree<T>();
    }
    BinaryTree<T>* Get_m_set(){
        return m_set;
    }
    int getsize(){
        return m_set->GetSize();
    }

    void Insert(T value) {
        m_set->Insert(value);
    }

    bool Find(T value) {
        return m_set->Find(value);
    }

    void DeleteElement(T value) {
        m_set->DeleteElement(value);
    }

    void DeleteSet() {
        m_set->DeleteTree(m_set->GetRoot());

    }

    T GetFirst() {
        tree_elem<T> *current = m_set->GetRoot();
        while (current->m_left) current = current->m_left;
        return current->m_value;
    }

    T GetLast() {
        tree_elem<T> *current = m_set->GetRoot();
        while (current->m_right) current = current->m_right;
        return current->m_value;
    }


    Set<T> *SubSequence(int StartIndex, int EndIndex) {
        auto set = new Set<T>();
        if (StartIndex >= 0 && EndIndex < m_set->GetSize()) {
            vector <T> array = m_set->TreeToArray();
            for (int i = StartIndex; i <= EndIndex; i++) {
                set->Insert(array[i]);
            }
        } else {
            throw out_of_range("Index out of range");
        }
        return set;
    }

    bool FindSubSequence(Set<T> *set) {
        if (set->GetSize() <= m_set->GetSize()) {
            int k = 0;
            vector <T> array1 = m_set->TreeToArray(); // sorted
            vector <T> array2 = set->m_set->TreeToArray(); // sorted
            for (int i = 0; i < array1.size(); i++) {
                if (array1[i] == array2[0]) {
                    for (int j = 0; j < array2.size(); j++) {
                        if (j < m_set->GetSize()) {
                            if (array1[i + j] == array2[j]) {
                                k++;
                            }
                        }
                    }
                    if (k == set->GetSize()) return true;
                }
                k = 0;
            }

        } else {
            return false;
        }
        return false;
    }
    //для лево корень право|||||||||||||||||||||||||||||||||||||||||||||
    void Map_lkp(void(*func)(tree_elem<T>*)) {
        m_set->Map_lkp(func);
    }

    void Where_lkp(bool(*func)(tree_elem<T> *)) {
        m_set->Where_lkp(func);
    }
    Set<T> operator=(const Set<T>& x){
        Set<T> c;
        c.m_set->DeleteTree();
        c.m_set->UpgradeSubTree(c.m_set, x.m_set->GetRoot());
        return c;
    }
    //объединение двух множеств
    Set<T> operator+(const Set<T>& x){
        Set<T> c;
        c.m_set->UpgradeSubTree_lkp(c.m_set, this->m_set->GetRoot());
        c.m_set->UpgradeSubTree_lkp(c.m_set, x.m_set->GetRoot());
        return c;
    }
    T operator[](int index){
        vector<T> c = this->m_set->TreeToArray_lkp();
        return c[index];
    }
    Set<T> operator*(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_lkp();
        vector<T> d = x.m_set->TreeToArray_lkp();
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(c[i] == d[j] && !q.Find(c[i])){
                    q.Insert(c[i]);
                }
            }
        }
        return q;
    }
    Set<T> operator -(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_lkp();
        for(int i = 0; i < c.size(); i++){
            if(!x.m_set->Find(c[i])){
                q.Insert(c[i]);
            }
        }
        return q;
    }

    void print_lkp(){
        m_set->Print_lkp();
    }
    //Для обхода право корень лево|||||||||||||||||||||||||||||||||||||||||||||
    void Map_pkl(void(*func)(tree_elem<T>*)) {
        m_set->Map_pkl(func);
    }
    void Where_pkl(bool(*func)(tree_elem<T> *)) {
        m_set->Where_pkl(func);
    }
    Set<T> Sum_pkl(const Set<T>& x){
        Set<T> c;
        c.m_set->UpgradeSubTree_pkl(c.m_set, this->m_set->GetRoot());
        c.m_set->UpgradeSubTree_pkl(c.m_set, x.m_set->GetRoot());
        return c;
    }
    Set<T> Cross_pkl(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_pkl();
        vector<T> d = x.m_set->TreeToArray_pkl();
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(c[i] == d[j] && !q.Find(c[i])){
                    q.Insert(c[i]);
                }
            }
        }
        return q;
    }
    Set<T> Substraction_pkl(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_lkp();
        for(int i = 0; i < c.size(); i++){
            if(!x.m_set->Find(c[i])){
                q.Insert(c[i]);
            }
        }
        return q;
    }
    void print_pkl(){
        m_set->Print_pkl();
    }
    T Getel_pkl(int index){
        vector<T> c = this->m_set->TreeToArray_pkl();
        return c[index];
    }
    //Для обхода корень право лево|||||||||||||||||||||||||||||||||||||||||||
    void Map_kpl(void(*func)(tree_elem<T>*)) {
        m_set->Map_kpl(func);
    }
    void Where_kpl(bool(*func)(tree_elem<T> *)) {
        m_set->Where_kpl(func);
    }
    Set<T> Sum_kpl(const Set<T>& x){
        Set<T> c;
        c.m_set->UpgradeSubTree_kpl(c.m_set, this->m_set->GetRoot());
        c.m_set->UpgradeSubTree_kpl(c.m_set, x.m_set->GetRoot());
        return c;
    }
    Set<T> Cross_kpl(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_kpl();
        vector<T> d = x.m_set->TreeToArray_kpl();
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(c[i] == d[j] && !q.Find(c[i])){
                    q.Insert(c[i]);
                }
            }
        }
        return q;
    }
    Set<T> Substraction_kpl(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_kpl();
        for(int i = 0; i < c.size(); i++){
            if(!x.m_set->Find(c[i])){
                q.Insert(c[i]);
            }
        }
        return q;
    }
    void print_kpl(){
        m_set->Print_kpl();
    }
    T Getel_kpl(int index){
        vector<T> c = this->m_set->TreeToArray_kpl();
        return c[index];
    }
    //Для обхода право лево корень|||||||||||||||||||||||||||||||||||||||||||
    void Map_plk(void(*func)(tree_elem<T>*)) {
        m_set->Map_plk(func);
    }
    void Where_plk(bool(*func)(tree_elem<T> *)) {
        m_set->Where_plk(func);
    }
    Set<T> Sum_plk(const Set<T>& x){
        Set<T> c;
        c.m_set->UpgradeSubTree_plk(c.m_set, this->m_set->GetRoot());
        c.m_set->UpgradeSubTree_plk(c.m_set, x.m_set->GetRoot());
        return c;
    }
    Set<T> Cross_plk(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_plk();
        vector<T> d = x.m_set->TreeToArray_plk();
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(c[i] == d[j] && !q.Find(c[i])){
                    q.Insert(c[i]);
                }
            }
        }
        return q;
    }
    Set<T> Substraction_plk(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_plk();
        for(int i = 0; i < c.size(); i++){
            if(!x.m_set->Find(c[i])){
                q.Insert(c[i]);
            }
        }
        return q;
    }
    void print_plk(){
        m_set->Print_plk();
    }
    T Getel_plk(int index){
        vector<T> c = this->m_set->TreeToArray_plk();
        return c[index];
    }
    //Для обхода корень лево право|||||||||||||||||||||||||||||||||||||||||||
    void Map_klp(void(*func)(tree_elem<T>*)) {
        m_set->Map_klp(func);
    }
    void Where_klp(bool(*func)(tree_elem<T> *)) {
        m_set->Where_klp(func);
    }
    Set<T> Sum_klp(const Set<T>& x){
        Set<T> c;
        c.m_set->UpgradeSubTree_klp(c.m_set, this->m_set->GetRoot());
        c.m_set->UpgradeSubTree_klp(c.m_set, x.m_set->GetRoot());
        return c;
    }
    Set<T> Cross_klp(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_klp();
        vector<T> d = x.m_set->TreeToArray_klp();
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(c[i] == d[j] && !q.Find(c[i])){
                    q.Insert(c[i]);
                }
            }
        }
        return q;
    }
    Set<T> Substraction_klp(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_klp();
        for(int i = 0; i < c.size(); i++){
            if(!x.m_set->Find(c[i])){
                q.Insert(c[i]);
            }
        }
        return q;
    }
    void print_klp(){
        m_set->Print_klp();
    }
    T Getel_klp(int index){
        vector<T> c = this->m_set->TreeToArray_klp();
        return c[index];
    }
    //Для обхода лево право корень|||||||||||||||||||||||||||||||||||||||||||
    void Map_lpk(void(*func)(tree_elem<T>*)) {
        m_set->Map_lpk(func);
    }
    void Where_lpk(bool(*func)(tree_elem<T> *)) {
        m_set->Where_lpk(func);
    }
    Set<T> Sum_lpk(const Set<T>& x){
        Set<T> c;
        c.m_set->UpgradeSubTree_lpk(c.m_set, this->m_set->GetRoot());
        c.m_set->UpgradeSubTree_lpk(c.m_set, x.m_set->GetRoot());
        return c;
    }
    Set<T> Cross_lpk(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_lpk();
        vector<T> d = x.m_set->TreeToArray_lpk();
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(c[i] == d[j] && !q.Find(c[i])){
                    q.Insert(c[i]);
                }
            }
        }
        return q;
    }
    Set<T> Substraction_lpk(const Set<T>& x){
        Set<T> q;
        vector<T> c = this->m_set->TreeToArray_lpk();
        for(int i = 0; i < c.size(); i++){
            if(!x.m_set->Find(c[i])){
                q.Insert(c[i]);
            }
        }
        return q;
    }
    void print_lpk(){
        m_set->Print_lpk();
    }
    T Getel_lpk(int index){
        vector<T> c = this->m_set->TreeToArray_lpk();
        return c[index];
    }
    ~Set() {
        DeleteSet();
    }
};

