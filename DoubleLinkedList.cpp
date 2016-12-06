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

    if (node == this->head) {
        this->head = this->head->next;
        if (NULL != this->head) {
            this->head->pre = NULL;
        }
    } else {
        if (NULL != node->next) {
            node->next->pre = node->pre;
        }
    }

    if (node == this->tail) {
        this->tail = this->tail->pre;
        if (NULL != this->tail) {
            this->tail->next = NULL;
        }
    } else {
        if (NULL != node->pre) {
            node->pre->next = node->next;
        }
    }

    --this->size;
}

