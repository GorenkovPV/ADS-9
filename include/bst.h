// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *rght;
    Node *lft;
    int count;
  };
  Node *rt;
  Node *addNode(Node *rt, T x) {
      if (rt == nullptr) {
          rt = new Node;
          rt->val = x;
          rt->lft = nullptr;
          rt->rght = nullptr;
      } else {
          if (rt->val > x) rt->lft = addNode(rt->lft, x);
          if (rt->val < x) rt->rght = addNode(rt->rght, x);
          if (rt->val == x) (rt->count)++;
      }
      return rt;
    }

  int searchValue(Node* rt, T x) {
    if (rt == nullptr) {
      return 0;
    } else if (rt->val == x) {
        return rt->count;
    } else if (rt->val < x) {
        return searchValue(rt->rght, x);
    } else {
        return searchValue(rt->lft, x);
    }
  }

  int dpth(Node* rt) {
      if (rt == nullptr)
        return 0;
      if (rt->lft == nullptr && rt->rght == nullptr) return 0;
      int rt = dpth(rt->rght), lt = dpth(rt->lft);
      if (rt > lt)
        return rt + 1;
      else
        return lt + 1;
  }

 public:
  BST():rt(nullptr) {}
  void add(T x) {
      rt = addNode(rt, x);
  }
  int depth() {
      return dpth(rt);
  }
  int search(T x) {
      return searchValue(rt, x) + 1;
  }
};

#endif  // INCLUDE_BST_H_
