#ifndef __LFU_CACHE_FREQ_NODE_H__
#define __LFU_CACHE_FREQ_NODE_H__

#include <sstream>
#include "ItemNode.h"
#include "DoubleLinkedList.h"

struct FreqNode : Node {
    DoubleLinkedList itemList;
    int freq;

    FreqNode(int freq): freq(freq) {}

    ~FreqNode() {
        Node* cur = itemList.getHead();
        Node* next;
        while (NULL != cur) {
            next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void addItem(ItemNode* node) {
        node->parent = this;
        this->itemList.addNode(node);
    }

    void removeItem(ItemNode* node) {
        this->itemList.removeNode(node);
    }

    Node* removeHeader() {
        Node* node = this->itemList.getHead();
        this->itemList.removeNode(node);
        return node;
    }

    int count() {
        return this->itemList.count();
    }

    std::string repr() {
        std::stringstream ss;
        ss << "freq=" << freq;
        return ss.str();
    }
};




#endif
