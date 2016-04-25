#ifndef RECEIPT_BAG
#define RECEIPT_BAG

#include<iostream>
using std::ostream;
#include<random>
using std::mt19937_64; using std::uniform_int_distribution;

// forward declaration
template<typename T>
class RBag;

/*
  Node struct has templated data_ field and an int receipt_ field
  The two-arg constructor fills in the data_ and receipt_ from its args
*/
template <typename T>
struct Node{
public:
  T data_;
  Node* next_;
  int receipt_;

  Node() : : next_(nullptr) {};
  Node (T datA, int receiT): data_(datA), receipt_(receipT), next_(nullptr) {};
  friend ostream& operator<<(ostream& out, Node& n){
    out << n.data_;
	return out;
  };
  friend class RBag<T>;
};


/*
  RBag class. Has only a head_ to the first Node. Empty list has head_ == nullptr
  Both the random engine and uniform distribution are provided. When a random
  number is required elsewhere in the RBag, call dist_(reng_)
*/

template<typename T>
class RBag{
private:
  Node<T>* head_;
  mt19937_64 reng_;
  uniform_int_distribution<int> dist_;
public:
  RBag();
  // rule of three
  RBag(const RBag& b){
	      if (sl.head_ == nullptr){
			head_ = nullptr;
		}else{
		}
  RBag& operator=(RBag  RbaG){
	  swap(head_, sl.head_);
  }
  ~RBag(){
	Node* to_del = head_;
    while (to_del !=nullptr){
		head_ = head_->next_;
		delete to_del;
		to_del = head_;
    }
    head_ = nullptr;
}
  // returns nullptr if not found, else returns pointer to the Node
  // and places the found Node at the front of the RBag linked list
  Node<T>* find(long receipt){
	  	while (head_ !=nullptr){
		/* Check whether it is the head node?
		if it is, delete and update the head node */
			if (head_->data_ == val) {
				head_ = head_->next;
				return true;
			}else{
				return false;
			}
		}
  // Make a new Node using dat and generating a random number receipt
  // then append to the front of the RBag linked list
  long append_front(T dat);
  
  // Node already exists, append to the front of the RBag linked list
  long append_front(Node<T>* n);

  // if Node is not found, return false, else delete the found Node
  // and return true
  bool remove(long receipt);
  
  friend ostream& operator<<(ostream& out, RBag& b){
	for(auto ptr = b.head_; ptr != nullptr; ptr = ptr->next_)
	    out << ptr->data_ << ",";
	return out;
    }
  };
};
    
#endif
