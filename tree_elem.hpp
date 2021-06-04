#pragma once
template<typename T>
class tree_elem{
public:
    T m_value;
    tree_elem* m_left;
    tree_elem* m_right;

    tree_elem(T key){//конструктор для создания нового узла
        m_value = key;
        m_left = NULL;
        m_right = NULL;
    }
    tree_elem(T key,tree_elem<T>* left,tree_elem<T>* right){//конструктор для копирования конкретного узла
        m_value = key;
        m_left = left;
        m_right = right;
    }
};