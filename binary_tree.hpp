#pragma once
#include<iostream>
#include<string>
#include "tree_elem.hpp"
#include<vector>
using namespace std;
template<typename T>
class BinaryTree {
private:
    tree_elem<T>* m_root;
    int size;
public:
    //конструкторы
    BinaryTree() {
        m_root = nullptr;
        size = 0;
    }

    //конструктор с добавлением корня
    BinaryTree(T value) {
        m_root = new tree_elem<T>(value);
        size = 1;
    }

    BinaryTree(const BinaryTree<T> &tree) {
        m_root = new tree_elem<T>(m_root);
        size = tree.size;
    }

    //Геттеры
    int GetSize() {
        return size;
    }
    tree_elem<T>* GetRoot() {
        return m_root;
    }
    //Функции, которые не зависят от обхода
    void Insert(T value) {//добавление нового элемента в дерево
        if (m_root == nullptr) {
            m_root = new tree_elem<T>(value);
            size = 1;
        } else {
            tree_elem<T>* current = m_root;
            while(current && current->m_value != value) {
                if (current->m_value > value) {//переход в левое поддерево
                    if (current->m_left)//если есть возможность,то так как добавляемое значение меньше того,
                        //что в узле current,
                        //то мы спускаемся в левое поддерево ещё раз(переход для следующей итерации)
                        current = current->m_left;
                    else {//если же возможность спуститься ещё ниже нет,то мы добавляем новый элемент в дерево
                        //(так как мы уже находимся на том месте,куда нужно добавить новый элемент)
                        current->m_left = new tree_elem<T>(value);
                        size++;
                        return;
                    }
                }//для правого поддерева аналогично
                else{//переход в правое поддерево
                    if (current->m_right)
                        current = current->m_right;
                    else{
                        current->m_right = new tree_elem<T>(value);
                        size++;
                        return;
                    }
                }
            }
        }
    }
    void DeleteElement(T value) {
        tree_elem<T>* curr = m_root;
        tree_elem<T>* parent = NULL;
        while (curr && curr->m_value != value)
        {
            parent = curr;
            if (curr->m_value > value)
            {
                curr = curr->m_left;
            }
            else
            {
                curr = curr->m_right;
            }
        }
        if (!curr)
            return;
        if (curr->m_left == NULL)
        {
            // Вместо curr подвешивается его правое поддерево
            if (parent && parent->m_left == curr)
                parent->m_left = curr->m_right;
            if (parent && parent->m_right == curr)
                parent->m_right = curr->m_right;
            --size;
            delete curr;
            return;
        }
        if (curr->m_right == NULL)
        {
            // Вместо curr подвешивается его левое поддерево
            if (parent && parent->m_left == curr)
                parent->m_left = curr->m_left;
            if (parent && parent->m_right == curr)
                parent->m_right = curr->m_left;
            --size;
            delete curr;
            return;
        }
        // У элемента есть два потомка, тогда на место элемента поставим
        // наименьший элемент из его правого поддерева
        tree_elem<T>* replace = curr->m_right;
        while (replace->m_left)
            replace = replace->m_left;
        T replace_value = replace->m_value;
        DeleteElement(replace_value);
        curr->m_value = replace_value;
    }
    //Вообще она зависит от обхода, но зачем ее менять?
    void DeleteTree(tree_elem<T>* current) {
        if(current) {
            DeleteTree(current->m_left);
            DeleteTree(current->m_right);
            delete[] current;
        }
    }
    bool Find(T value) {//поиск значения

        tree_elem<T>* current = m_root;
        while(current && current->m_value != value){
            if(current->m_value > value)
                current = current->m_left;
            else
                current = current->m_right;
        }
        return (bool)current;
    }
    static bool IsEquals(tree_elem<T>* first, tree_elem<T>* second) {//обход реализован корректно
        //проверки на разные поддеревья у предположительно
        //совпадающих узлов
        if (second->m_right == nullptr && second->m_left == nullptr && first->m_value == second->m_value) {
            //проверка случая,когда в искомом дереве нет возможности идти влево/вправо
            // и значения с узлом дерева,в котором ищем совпадают
            return true;
        }

        if (second->m_left != nullptr && first->m_left == nullptr) {//влево нельзя/можно
            return false;
        }

        if (second->m_right != nullptr && first->m_right == nullptr)//вправо нельзя/можно
            return false;

        if (first->m_value != second->m_value)//несовпадающие значения
            return false;

        if (first->m_right != nullptr && second->m_right!= nullptr && second->m_left == nullptr)//в том дереве,которое ищу,могу двигаться только вправо
            return IsEquals(first->m_right,second->m_right);

        if (first->m_left != nullptr && second->m_left!= nullptr && second->m_right == nullptr)//в том дереве,которое ищу,могу двигаться только влево
            return IsEquals(first->m_left,second->m_left);

        //возможность двигаться влево/вправо в случае ненулевых указателей и совпадающих значений
        if (first->m_left != nullptr && second->m_left != nullptr && first->m_value == second->m_value)
            return IsEquals(first->m_left,second->m_left);

        if (first->m_right != nullptr && second->m_right != nullptr && first->m_value == second->m_value)
            return IsEquals(first->m_right,second->m_right);

    }
    tree_elem<T> *CloneElement(tree_elem<T>* element) {
        tree_elem<T>* result = new tree_elem(element->m_value);
        if (element->m_left) result->m_left = CloneElement(element->m_left);
        else result->m_left = nullptr;
        if (element->m_right) result->m_right = CloneElement(element->m_right);
        else result->m_right = nullptr;
        return result;
    }

    BinaryTree<T> *Clone() {
        auto *result = new BinaryTree<T>();
        result->m_root = CloneElement(m_root);
        result->size = this->GetSize();
        return result;
    }
    bool IsSubtree(BinaryTree<T>* second) {

        tree_elem<T>* current = m_root;//проверка того,что корень искомого дерева находится в том,
        while(current && current->m_value != second->m_root->m_value){// в котором мы ищем
            if(current->m_value > second->m_root->m_value)
                current = current->m_left;
            else
                current = current->m_right;
        }

        return IsEquals(current,second->m_root);
    }
    //получение поддерева по узлу
    BinaryTree<T>* GetSubTree(T value) {

        tree_elem<T>* current = m_root;
        while (current && current->m_value!=value)
            if (current->m_value < value) current = current->m_right;
            else current = current->m_left;
        auto* result = new BinaryTree<T>(current->m_value);
        UpgradeSubTree(result,current);

        return result;
    }
    //Функции, которые зависят от обхода В данном случае обход лево корень право
    void PrintTree_lkp(tree_elem<T>* current) {
        if (current) {
            if (current->m_left) {
                PrintTree_lkp(current->m_left);
            }
            cout << current->m_value << " ";
            if (current->m_right) PrintTree_lkp(current->m_right);
        }
    }
    void Print_lkp() {
        PrintTree_lkp(m_root);
        cout<<"\n";
    }

    void UpgradeSubTree_lkp(BinaryTree<T>* result,tree_elem<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            UpgradeSubTree_lkp(result,current->m_left);
            result->Insert(current->m_value);
            UpgradeSubTree_lkp(result,current->m_right);
        }
    }

    void TreeToStringHelp_lkp(tree_elem<T>* current,vector<string>& current_str) {
        if(current){
            TreeToStringHelp_lkp(current->m_left,current_str);
            current_str.push_back(to_string(current->m_value));
            TreeToStringHelp_lkp(current->m_right,current_str);
        }
    }
    string TreeToString_lkp() {

        tree_elem<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp_lkp(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }
    void TreeToArrayHelp_lkp(tree_elem<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayHelp_lkp(current->m_left, array);
            array.push_back(current->m_value);
            TreeToArrayHelp_lkp(current->m_right, array);
        }
    }
    vector<T> TreeToArray_lkp() {
        tree_elem<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp_lkp(current, result);

        return result;
    }
    void ForMap_lkp(void(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            ForMap_lkp(func, current->m_left);
            func(current);
            ForMap_lkp(func, current->m_right);
        }
    }

    void Map_lkp(void(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForMap_lkp(func,current);
    }
    void ForWhere_lkp(bool(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            ForWhere_lkp(func, current->m_left);
            ForWhere_lkp(func, current->m_right);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }

    // Where
    void Where_lkp(bool(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForWhere_lkp(func,current);
    }
    //Функции, которые зависят от обхода В данном случае обход право корень лево
    void PrintTree_pkl(tree_elem<T>* current) {
        if (current) {
            if (current->m_right) PrintTree_pkl(current->m_right);
            cout << current->m_value << " ";
            if (current->m_left) PrintTree_pkl(current->m_left);
        }
    }
    void Print_pkl() {
        PrintTree_pkl(m_root);
        cout<<"\n";
    }

    void UpgradeSubTree_pkl(BinaryTree<T>* result,tree_elem<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            UpgradeSubTree_pkl(result,current->m_right);
            result->Insert(current->m_value);
            UpgradeSubTree_pkl(result,current->m_left);
        }
    }

    void TreeToStringHelp_pkl(tree_elem<T>* current,vector<string>& current_str) {
        if(current){
            TreeToStringHelp_pkl(current->m_right,current_str);
            current_str.push_back(to_string(current->m_value));
            TreeToStringHelp_pkl(current->m_left,current_str);
        }
    }
    string TreeToString_pkl() {

        tree_elem<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp_pkl(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }
    void TreeToArrayHelp_pkl(tree_elem<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayHelp_pkl(current->m_right, array);
            array.push_back(current->m_value);
            TreeToArrayHelp_pkl(current->m_left, array);
        }
    }
    vector<T> TreeToArray_pkl() {
        tree_elem<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp_pkl(current, result);

        return result;
    }
    void ForMap_pkl(void(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            ForMap_pkl(func, current->m_right);
            func(current);
            ForMap_pkl(func, current->m_left);
        }
    }

    void Map_pkl(void(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForMap_pkl(func,current);
    }
    void ForWhere_pkl(bool(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            ForWhere_pkl(func, current->m_right);
            ForWhere_pkl(func, current->m_left);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }
    // Where
    void Where_pkl(bool(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForWhere_pkl(func,current);
    }
    //Функции, которые зависят от обхода В данном случае обход корень право лево
    void PrintTree_kpl(tree_elem<T>* current) {
        if (current) {
            cout << current->m_value << " ";
            if (current->m_right) PrintTree_kpl(current->m_right);
            if (current->m_left) PrintTree_kpl(current->m_left);
        }
    }
    void Print_kpl() {
        PrintTree_kpl(m_root);
        cout<<"\n";
    }

    void UpgradeSubTree_kpl(BinaryTree<T>* result,tree_elem<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            result->Insert(current->m_value);
            UpgradeSubTree_kpl(result,current->m_right);
            UpgradeSubTree_kpl(result,current->m_left);
        }
    }

    void TreeToStringHelp_kpl(tree_elem<T>* current,vector<string>& current_str) {
        if(current){
            current_str.push_back(to_string(current->m_value));
            TreeToStringHelp_kpl(current->m_right,current_str);
            TreeToStringHelp_kpl(current->m_left,current_str);
        }
    }
    string TreeToString_kpl() {

        tree_elem<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp_kpl(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }
    void TreeToArrayHelp_kpl(tree_elem<T>* current,vector<T> &array) {
        if (current) {
            array.push_back(current->m_value);
            TreeToArrayHelp_kpl(current->m_right, array);
            TreeToArrayHelp_kpl(current->m_left, array);
        }
    }
    vector<T> TreeToArray_kpl() {
        tree_elem<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp_kpl(current, result);

        return result;
    }
    void ForMap_kpl(void(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            func(current);
            ForMap_kpl(func, current->m_right);
            ForMap_kpl(func, current->m_left);
        }
    }

    void Map_kpl(void(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForMap_kpl(func,current);
    }
    void ForWhere_kpl(bool(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            ForWhere_kpl(func, current->m_right);
            ForWhere_kpl(func, current->m_left);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }

        }
    }
    // Where
    void Where_kpl(bool(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForWhere_kpl(func,current);
    }
    //Функции, которые зависят от обхода В данном случае обход лево право корень
    void PrintTree_lpk(tree_elem<T>* current) {
        if (current) {
            if (current->m_left) PrintTree_lpk(current->m_left);
            if (current->m_right) PrintTree_lpk(current->m_right);
            cout << current->m_value << " ";
        }
    }
    void Print_lpk() {
        PrintTree_lpk(m_root);
        cout<<"\n";
    }

    void UpgradeSubTree_lpk(BinaryTree<T>* result,tree_elem<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            UpgradeSubTree_lpk(result,current->m_left);
            UpgradeSubTree_lpk(result,current->m_right);
            result->Insert(current->m_value);
        }
    }

    void TreeToStringHelp_lpk(tree_elem<T>* current,vector<string>& current_str) {
        if(current){
            TreeToStringHelp_lpk(current->m_left,current_str);
            TreeToStringHelp_lpk(current->m_right,current_str);
            current_str.push_back(to_string(current->m_value));
        }
    }
    string TreeToString_lpk() {

        tree_elem<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp_lpk(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }
    void TreeToArrayHelp_lpk(tree_elem<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayHelp_lpk(current->m_left, array);
            TreeToArrayHelp_lpk(current->m_right, array);
            array.push_back(current->m_value);
        }
    }
    vector<T> TreeToArray_lpk() {
        tree_elem<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp_lpk(current, result);

        return result;
    }
    void ForMap_lpk(void(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            ForMap_lpk(func, current->m_left);
            ForMap_lpk(func, current->m_right);
            func(current);
        }
    }

    void Map_lpk(void(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForMap_lpk(func,current);
    }
    void ForWhere_lpk(bool(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            ForWhere_lpk(func, current->m_left);
            ForWhere_lpk(func, current->m_right);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }
    // Where
    void Where_lpk(bool(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForWhere_lpk(func,current);
    }
    //Функции, которые зависят от обхода В данном случае обход корень лево право
    void PrintTree_klp(tree_elem<T>* current) {
        if (current) {
            cout << current->m_value << " ";
            if (current->m_left) PrintTree_klp(current->m_left);
            if (current->m_right) PrintTree_klp(current->m_right);
        }
    }
    void Print_klp() {
        PrintTree_klp(m_root);
        cout<<"\n";
    }

    void UpgradeSubTree_klp(BinaryTree<T>* result,tree_elem<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            result->Insert(current->m_value);
            UpgradeSubTree_klp(result,current->m_left);
            UpgradeSubTree_klp(result,current->m_right);
        }
    }

    void TreeToStringHelp_klp(tree_elem<T>* current,vector<string>& current_str) {
        if(current){
            current_str.push_back(to_string(current->m_value));
            TreeToStringHelp_klp(current->m_left,current_str);
            TreeToStringHelp_klp(current->m_right,current_str);
        }
    }
    string TreeToString_klp() {

        tree_elem<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp_klp(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }
    void TreeToArrayHelp_klp(tree_elem<T>* current,vector<T> &array) {
        if (current) {
            array.push_back(current->m_value);
            TreeToArrayHelp_klp(current->m_left, array);
            TreeToArrayHelp_klp(current->m_right, array);
        }
    }
    vector<T> TreeToArray_klp() {
        tree_elem<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp_klp(current, result);

        return result;
    }
    void ForMap_klp(void(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            func(current);
            ForMap_klp(func, current->m_left);
            ForMap_klp(func, current->m_right);
        }
    }

    void Map_klp(void(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForMap_klp(func,current);
    }
    void ForWhere_klp(bool(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            ForWhere_klp(func, current->m_left);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
            ForWhere_klp(func, current->m_right);
        }
    }
    // Where
    void Where_klp(bool(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForWhere_klp(func,current);
    }
    //Функции, которые зависят от обхода В данном случае обход право лево корень
    void PrintTree_plk(tree_elem<T>* current) {
        if (current) {
            if (current->m_right) PrintTree_plk(current->m_right);
            if (current->m_left) PrintTree_plk(current->m_left);
            cout << current->m_value << " ";
        }
    }
    void Print_plk() {
        PrintTree_plk(m_root);
        cout<<"\n";
    }

    void UpgradeSubTree_plk(BinaryTree<T>* result,tree_elem<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            UpgradeSubTree_plk(result,current->m_right);
            UpgradeSubTree_plk(result,current->m_left);
            result->Insert(current->m_value);
        }
    }

    void TreeToStringHelp_plk(tree_elem<T>* current,vector<string>& current_str) {
        if(current){
            TreeToStringHelp_plk(current->m_right,current_str);
            TreeToStringHelp_plk(current->m_left,current_str);
            current_str.push_back(to_string(current->m_value));
        }
    }
    string TreeToString_plk() {

        tree_elem<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp_plk(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }
    void TreeToArrayHelp_plk(tree_elem<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayHelp_plk(current->m_right, array);
            TreeToArrayHelp_plk(current->m_left, array);
            array.push_back(current->m_value);
        }
    }
    vector<T> TreeToArray_plk() {
        tree_elem<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp_plk(current, result);

        return result;
    }
    void ForMap_plk(void(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            ForMap_plk(func, current->m_right);
            ForMap_plk(func, current->m_left);
            func(current);
        }
    }

    void Map_plk(void(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForMap_plk(func,current);
    }
    void ForWhere_plk(bool(*func)(tree_elem<T>*),tree_elem<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            ForWhere_plk(func, current->m_right);
            ForWhere_plk(func, current->m_left);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }
    // Where
    void Where_plk(bool(*func)(tree_elem<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_elem<T>* current = m_root;
        ForWhere_plk(func,current);
    }
    ~BinaryTree() {
        DeleteTree(m_root);
    }
};

