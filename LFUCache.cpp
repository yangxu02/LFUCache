#include "LFUCache.h"

void LFUCache::set(int k, int v) {
    if (0 == capacity) return;
    std::map<int, ItemNode*>::iterator it;
    it = dataSet.find(k);
    if (it == dataSet.end()) {
        if (size >= capacity) { // evit
            FreqNode* freqNode = (FreqNode*)(freqList.getHead());
            Node* node = freqNode->removeTail();
            dataSet.erase(((ItemNode*)node)->key);
            delete node;
            if (0 == freqNode->count() && 1 != freqNode->freq) {
                freqList.removeNode(freqNode);
                delete freqNode;
            }
            --size;
        }
        ItemNode* node = new ItemNode(k, v);
        FreqNode* freqNode = (FreqNode*)(freqList.getHead());
        if (NULL == freqNode || freqNode->freq != 1) {
            FreqNode* freqNode = new FreqNode(1);
            freqNode->addItem(node);
            freqList.addNode(freqNode); // first freq node
        } else {
            freqNode->addItem(node);
        }
        dataSet[k] = node;
        ++size;
    } else { // update value and freq
        ItemNode* node = it->second;
        node->setData(v);
        updateFreq(node);
    }
}

int LFUCache::get(int k) {
    std::map<int, ItemNode*>::iterator it;
    it = dataSet.find(k);
    if (it == dataSet.end()) {
        return -1;
    } else { // update value and freq
        ItemNode* node = it->second;
        updateFreq(node);
        return node->data;
    }
}

void LFUCache::updateFreq(ItemNode* node) {
    if (NULL == node) return;
    // updateFreq
    FreqNode* cur = (FreqNode*)(node->parent);
    FreqNode* next = (FreqNode*)(cur->next);

    cur->removeItem(node);

    if (next == NULL || next->freq != cur->freq + 1) {
        FreqNode* freqNode = new FreqNode(cur->freq + 1);
        freqNode->addItem(node);
        freqList.addNode(freqNode, cur, next);
        node->parent = freqNode;

    } else {
        next->addItem(node);
        node->parent = next;
    }

    if (0 == cur->count()) {
        freqList.removeNode(cur);
        delete cur;
    }

}

std::string LFUCache::repr() {
    if (dataSet.empty()) {
        return "[]";
    }
    std::map<int, ItemNode*>::iterator it;
    std::string str;
    str += "[";
    for (it = dataSet.begin(); it != dataSet.end(); ++it) {
        ItemNode* node = it->second;
        str += "{";
        str += node->repr();
        str += ",pre=" + (NULL == node->pre ? "NULL" : node->pre->repr());
        str += ",next=" + (NULL == node->next ? "NULL" : node->next->repr());
        str += "},";
    }
    str += "]";

    return str;

}

