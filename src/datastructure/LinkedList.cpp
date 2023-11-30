#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {
    private:
        T data;
        Node<T> *next;
        template <class U>
        friend class LinkedList;

    public:
    Node() {this->next = nullptr;}
};

template <class T>
class LinkedList {
    public:
        Node<T> *head;

    public:
        LinkedList() {this->head = nullptr;}

        void addLast(T item) {
            Node<T> *node = new Node<T>[1];
            node->data = item;
            if (head == nullptr) {
                head = node;
                return;
            }
            Node<T> *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = node;
        }

        void addFirst(T item) {
            Node<T> *node = new Node<T>[1];
            node->data = item;
            if (head == nullptr) {
                head = node;
                return;
            }
            node->next = head;
            head = node;
        }

        void addAtIndex(int index, T item) {
            if (index > size() || index < 0) return;
            
            Node<T> *node = new Node<T>[1];
            node->data = item;
            int count = 0;
            Node<T> *temp = head;
            while (temp != nullptr && count < index) {
                if (count == index - 1) {
                    if (temp->next != nullptr)
                        node->next = temp->next;
                    temp->next = node;
                    break;
                }
                count ++;
                temp = temp->next;
            }
        }

        int size() {
            int len = 0;
            Node<T> *temp = head;
            while (temp != nullptr) {
                len ++;
                temp = temp->next;
            }
            return len;
        }

        void remove() {
            if (head == nullptr) return;
            if (head->next == nullptr) {
                head = nullptr;
                return;
            }
            Node<T> *temp = head;
            while (temp != nullptr) {
                if (temp->next->next == nullptr) {
                    temp->next = nullptr;
                    break;
                }
                temp = temp->next;
            }
        }

        void removeAtIndex(int index) {
            if (head == nullptr) return;
            if (index >= size() || index < 0) return;
            if (index == 0) {
                removeFirst();
                return;
            }
            int count = 0;
            Node<T> *temp = head;
            while (temp != nullptr) {
                if (count == index - 1) {
                    temp->next = temp->next->next;
                    break;
                }
                count ++;
                temp = temp->next;
            }
        }

        void removeFirst() {
            if (head == nullptr) return;
            head = head->next;
        }

        T* get(int index) {
            T* res = new T();

            if (head == nullptr) return nullptr;
            if (index >= size() || index < 0) return nullptr;
            if (index == 0) {
                cout << "AAA" << endl;
                *res = head->data;
                return res;
            }
            
            int count = 0;
            Node<T> *temp = head;
            while (temp != nullptr) {
                if (count++ == index) {
                    *res = temp->data;
                    break;
                }
                temp = temp->next;
            }
            return res;
        }

        bool empty() {
            if (head == nullptr) return true;
            return false;
        }
};
