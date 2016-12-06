#include <iostream>
#include "DoubleLinkedList.h"

Node* DoubleLinkedList::addNode(Node* node, Node* pre, Node* next) {
    if (NULL == node) return NULL;
    node->pre = pre;
    node->next = next;
    if (NULL == pre) { // head is NULL
        this->head = node;
    } else {
        pre->next = node;
    }
    if (NULL == next) { // tail is NULL
        this->tail = node;
    } else {
        next->pre = node;
    }
    ++this->size;
    return node;
}


void DoubleLinkedList::removeNode(Node* node) {
    if (NULL == node) return;

    if (NULL != node->pre) {
        node->pre->next = node->next;
    }

    if (NULL != node->next) {
        node->next->pre = node->pre;
    }


    if (node == this->head) {
        this->head = node->next;
        if (NULL != this->head) {
            this->head->pre = NULL;
        }
    }

    if (node == this->tail) {
        this->tail = node->pre;
        if (NULL != this->tail) {
            this->tail->next = NULL;
        }
    }

    --this->size;
}

