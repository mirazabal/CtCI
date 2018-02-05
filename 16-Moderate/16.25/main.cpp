#include <iostream>
#include <unordered_map>
#include "Node.h"

using namespace mirazabal;


template<typename T>
class DoubleLinkList{
    public:
    DoubleLinkList() : oldestNode{nullptr}, newestNode{nullptr}
    {
    
    }

    ~DoubleLinkList(){

        while(oldestNode){
            Node<T>* temp = oldestNode;
            oldestNode = temp->next;
            delete temp;
        }
    }


    Node<T>* insertNode(T val)
    {
        if(oldestNode == nullptr)
        {
            oldestNode = new Node<T>(val);
            newestNode = oldestNode;
        }else {
            Node<T>* tempNode = new Node<T>(val);
            tempNode->previous = newestNode;
            newestNode->next = tempNode;
            newestNode = tempNode;
        }
        return newestNode;
    }

    void deleteOldest()
    {
        if(oldestNode == nullptr)
            return;
        
        Node<T>* delNode = oldestNode;
        oldestNode = oldestNode->next;
        deleteNode(delNode);
    }

    void deleteNode(Node<T>* node)
    {
        if(node->previous != nullptr){
            node->previous->next = node->next;
        } 
        if(node->next != nullptr) 
            node->next->previous = node->previous;
        delete node; 
    }       
    
    T getOldestVal(){
        return  oldestNode->val_;
    }
    
    void setNewestNode(Node<T>* node)
    {
        if(node->previous != nullptr) 
            node->previous->next = node->next;
        if(node->next != nullptr)
            node->next->previous = node->previous;

        node->next = nullptr;
        node->previous = newestNode;
        newestNode->next = node;
        newestNode = node;

    }


    private:
        Node<T>* oldestNode;
        Node<T>* newestNode;

};


template<typename TKey, typename TVal>
class LRUCache //: private std::list<TVal>, private std::unordered_map<TKey, std::size_t*> 
{
    public:
    explicit LRUCache(uint64_t capacity) : capacity_ {capacity}, size_{0}
    {

    } 

    TVal getVal(TKey key)
    {
        auto retIt = uMap_.find(key);
        if(retIt == std::end(uMap_)){
            std::runtime_error("Value not found"); 
        }
        list_.setNewestNode(retIt->second);
        return retIt->second->val_;
    }

    void insertKeyVal(TKey key, TVal val)
    {
        Node<TVal>* pos = list_.insertNode(val);
        if(capacity_ == size_){
            TVal key = list_.getOldestVal();

            uMap_.erase(key);
            list_.deleteOldest();
        } else {
            ++size_;
        } 
        uMap_.insert( std::pair<TKey, Node<TVal>*>(key, pos) );
    }

    private:
    DoubleLinkList<TVal> list_;
    std::unordered_map<TKey, Node<TVal>* > uMap_;
    uint64_t capacity_;
    uint64_t size_;
};



int main()
{
    LRUCache<int,int> cache_(50);

    for(auto i = 0u; i < 50; ++i)
        cache_.insertKeyVal(i,i*50);

    cache_.getVal(0);
    cache_.insertKeyVal(51, 510);



    return 0;
}
