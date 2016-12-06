#ifndef __LFU_CACHE_ITEM_NODE_H__
#define __LFU_CACHE_ITEM_NODE_H__

#include <sstream>
#include "Node.h"

struct ItemNode : Node {
    int key;
    int data;
    Node* parent;

    ItemNode(int key, int data): key(key), data(data) {}

    ~ItemNode() {
        parent = NULL;
    }

    void setParent(Node* parent) {
        this->parent = parent;
    }

    void setData(int data) {
        this->data = data;
    }

    std::string repr() {
        std::stringstream ss;
        ss << "{k=" << key << ",v=" << data << "," << parent->repr() << "}";
        return ss.str();
    }
};


#endif
