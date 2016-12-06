#ifndef __LFU_CACHE_NODE_H__
#define __LFU_CACHE_NODE_H__

#include <string>

struct Node {
    Node* pre;
    Node* next;

    Node() : pre(NULL), next(NULL) {}

    Node(Node* pre, Node* next)
        : pre(pre), next(next) {}

    virtual std::string repr() {
        return "";
    }

    virtual ~Node() {
        pre = NULL;
        next = NULL;
    }
};


#endif
