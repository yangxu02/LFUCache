#ifndef __LFU_CACHE_DOUBLE_LINKED_LIST_H__
#define __LFU_CACHE_DOUBLE_LINKED_LIST_H__

#include "Node.h"

class DoubleLinkedList {
    public:
        DoubleLinkedList():head(NULL), tail(NULL), size(0) {}

        Node* addNode(Node* node, Node* pre, Node* next);

        void removeNode(Node* node);

        Node* getHead() {
            return this->head;
        }

        void setHead(Node* head) {
            this->head = head;
        }

        void setTail(Node* tail) {
            this->tail = tail;
        }

        Node* getTail() {
            return this->tail;
        }

        Node* addNode(Node* node) {
            return this->addNode(node, NULL, this->head);
        }
            
        int count() {
            return this->size;
        }

        int empty() {
            return 0 == this->size;
        }


    private:
        Node* head;
        Node* tail;
        int size;

};

#endif
