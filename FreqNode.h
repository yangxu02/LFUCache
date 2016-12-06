#ifndef __LFU_CACHE_FREQ_NODE_H__
#define __LFU_CACHE_FREQ_NODE_H__

#include <iostream>
#include <sstream>
#include "ItemNode.h"
#include "DoubleLinkedList.h"

struct FreqNode : Node {
    DoubleLinkedList itemList;
    int freq;

    FreqNode(int freq): freq(freq) {}

    ~FreqNode() {
        itemList.setHead(NULL);
        itemList.setTail(NULL);
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

    Node* removeTail() {
        Node* node = this->itemList.getTail();
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
