#ifndef __LFU_CACHE_H__
#define __LFU_CACHE_H__

#include <map>
#include <string>
#include <iostream>
#include <sstream>

#include "DoubleLinkedList.h"
#include "ItemNode.h"
#include "Node.h"
#include "FreqNode.h"

class LFUCache {
    public:
        LFUCache(int capacity):capacity(capacity), size(0) {}

        ~LFUCache() {
            Node* cur = freqList.getHead();
            Node* next;
            while (NULL != cur) {
                next = cur->next;
                delete cur;
                cur = next;
            }

            if (dataSet.empty()) return;

            for (std::map<int, ItemNode*>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
                Node* node = it->second;
                dataSet.erase(it);
                delete node;
            }

        }

        void set(int k, int v); 

        int get(int k);

        std::string repr();

    private:
        void updateFreq(ItemNode* node);

    private:
        std::map<int, ItemNode*> dataSet;
        DoubleLinkedList freqList;
        int capacity;
        int size;

};


#endif
