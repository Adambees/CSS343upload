/**
 * Binary Search Tree - Template
 *
 * Store values in a BST
 * Can use Inorder, Preorder and Postorder to traverse tree
 * Can use Add/Remove to modify tree
 * Rebalance creates a balanced tree
 *
 * @author Jun Hyung Park
 * @date Jan 30 2019
 */

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>

using namespace std;

template<class T>
class BST {
  // display a sideways ascii representation of tree
  friend ostream &operator<<(ostream &os, const BST &bst) {
    bst.sideways(bst.rootPtr, 0, os);
    return os;
  }

 private:
  // Node for BST
  typedef struct node {
    T data;
    struct node *leftPtr;
    struct node *rightPtr;
  } Node;

  // root of the tree
  Node *rootPtr{nullptr};

  // Make a new BST Node
  // Make nodes
  Node *makeNode(const T &value) const {
    Node *temp = new Node;
    temp->data = value;
    temp->leftPtr = nullptr;
    temp->rightPtr = nullptr;
    return temp;
  }

  // helper function for displaying tree sideways, works recursively
  void sideways(Node *current, int level, ostream &os) const {
    static const string indents{"   "};
    if (current) {
      level++;
      sideways(current->rightPtr, level, os);

      // indent for readability, 4 spaces per depth level
      for (int i = level; i >= 0; i--)
        os << indents;

      // display information of object
      os << current->data << endl;
      sideways(current->leftPtr, level, os);
    }
  }

 public:
  // constructor, empty tree
  BST()
  // :rootPtr(nullptr)
  {}

  // constructor, tree with root
  explicit BST(const T &rootItem) {
    rootPtr = makeNode(rootItem);
  }

  // given an array of length n
  // create a tree to have all items in that array
  // with the minimum height (i.e. rebalance)
  // =================Constructor and array Helper =======================
  BST(T arr[], int n) {
    if (n <= 0) {
      return;
    } else {
      Clear();
      rootPtr = createArrayHelper(arr, 0, n);
    }
  }
  // Helper function
  // distribute the arr
  // set the sort equal to mid item of arr
  // set left child to left part of arr
  // set right child to right part of arr
  Node * createArrayHelper(T arr[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
      return nullptr;
    } else {
      int midPoint = (endIndex + startIndex) / 2;
      Node * root = makeNode(arr[midPoint]);
      root->leftPtr = createArrayHelper(arr, startIndex, midPoint);
      root->rightPtr = createArrayHelper(arr, midPoint+1, endIndex);
      return root;
    }
  }
  // =============Copy Constructor and Helper ==============================
  // copy constructor helper function
  // recursive copy
  Node * copyConstructor(const Node * copyTree) const {
    Node * otherCopy = nullptr;
    if (copyTree != nullptr) {
      otherCopy = makeNode(copyTree->data);
      otherCopy->leftPtr = copyConstructor(copyTree->leftPtr);
      otherCopy->rightPtr = copyConstructor(copyTree->rightPtr);
    }
    return otherCopy;
  }
  // copy constructor
  // require helper function
  // recursive copy struct Node
  explicit BST(const BST<T> &bst) {
    rootPtr = copyConstructor(bst.rootPtr);
  }
  // =====================Deconstructor ========================
  // destructor
  // use clear function
  // simply call clear function
  virtual ~BST() {
    Clear();
  }
  // true if no nodes in BST
  // else return false
  // ======================== IsEmpty Function=======================
  bool IsEmpty() const {
    if (this->rootPtr == nullptr) {
      return true;
    } else {
      return false;
    }
  }
  // ====================Get Height and Height Helper=====================
  // getHeight helper function
  // counts hegith of the tree
  // condition count == null return 0
  // compare and pick bigger number + 1 for root
  int getHeightCount(Node* count) const {
    if (count == nullptr) {
      return 0;
    }
    int countLeft = getHeightCount(count->leftPtr);
    int countRight = getHeightCount(count->rightPtr);
    if (countLeft > countRight) {
      return 1 + countLeft;
    } else {
      return 1 + countRight;
    }
  }
  // 0 if empty, 1 if only root, otherwise
  // height of root is max height of subtrees + 1
  int getHeight() const {
    return getHeightCount(rootPtr);
  }
  // ===================get Number of node and helper function=============
  // number of nodes in BST
  // return number of nodes
  int getNodeNumber(Node* count) const {
    if (count == nullptr) {
      return 0;
    }
    return 1 + getNodeNumber(count->leftPtr) + getNodeNumber(count->rightPtr);
  }
  // Use getNodeNumber function
  int NumberOfNodes() const {
    return getNodeNumber(rootPtr);
  }
  // =================add function with helpers========================
  // use makenode function
  // use contain function
  // use placenode fucntion
  // add a new item, return true if successful
  // add condition for root equal to null
  // if item is in the tree then return false
  bool Add(const T &item) {
    if (rootPtr == nullptr) {
      rootPtr = makeNode(item);
    } else {
      if (Contains(item)) {
        return false;
      } else {
        Node* tempNode = makeNode(item);
        placeNode(rootPtr, tempNode);
      }
    }
    return true;
  }
  // Function PlaceNode
  // Place item on the place correctly
  // current item bigger than new item
  // put new item left
  // opposite then put it right
  Node* placeNode(Node* subTree, Node* newNode) {
    // Base case
    // if the root is null then set up as newNode
    if (subTree == nullptr) {
      return newNode;
    } else {
      if (subTree->data > newNode->data) {
        if (subTree->leftPtr == nullptr) {
          subTree->leftPtr = newNode;
        } else {
          placeNode(subTree->leftPtr, newNode);
        }
      }
      if (subTree->data < newNode->data) {
        if (subTree->rightPtr == nullptr) {
          subTree->rightPtr = newNode;
        } else {
          placeNode(subTree->rightPtr, newNode);
        }
      }  // end of if
    }  // end of else
    return subTree;
  }  // end of func
  // =====================RemoveNode with helper function=================
  // find the smallest return its node
  Node* findMin(Node * find) {
    while (find->leftPtr != nullptr) {
      find = find->leftPtr;
    }
    return find;
  }
  // if its null just return node
  // Cases where the node is leaf
  // Cases where it contains of one child
  // Cases where it has mulitiple childs
  Node * removeNode(Node * removeFound, const T &item) {
    if (removeFound == nullptr) {
      return removeFound;
    }
    // search item bigger than go right
    // serach item less than go left
    if (removeFound->data < item) {
      removeFound->rightPtr = removeNode(removeFound->rightPtr, item);
    } else if (removeFound->data > item) {
      removeFound->leftPtr = removeNode(removeFound->leftPtr, item);
    } else if (removeFound->data == item) {
      if (removeFound->leftPtr == nullptr) {
        Node * temp = removeFound->rightPtr;
        delete removeFound;
        return temp;
      } else if (removeFound->rightPtr == nullptr) {
        Node * temp = removeFound->leftPtr;
        delete removeFound;
        return temp;
      } else if (removeFound->leftPtr == nullptr &&
      removeFound->rightPtr == nullptr) {
        delete removeFound;
        removeFound = nullptr;
        return removeFound;
      } else {
        Node * temp = findMin(removeFound->rightPtr);
        removeFound->data = temp->data;
        removeFound->rightPtr = removeNode(removeFound->rightPtr, temp->data);
      }
    }
    return removeFound;
  }
  // remove item, return true if successful
  // return false if it failed
  bool Remove(const T &item) {
    Node * found = nullptr;
    found = removeNode(rootPtr, item);
    rootPtr = found;
    return found;
  }
  // ===========================Contains and helper function====================
  // Contains
  // return false if not found
  // found then return true
  // Use findNode function
  bool Contains(const T &item) const {
    Node * found = nullptr;
    found = findNode(rootPtr, item);
    if (found == nullptr) {
      return false;
    } else {
      return true;
    }
  }
  // Contains helper function
  // If current item is same as the item just true
  // If not search right branch or left branch
  Node* findNode(Node* subTree, const T &item) const {
    Node * tempPtr = subTree;
    if (subTree == nullptr) {
      return nullptr;
    } else {
      if (subTree->data == item) {
        return subTree;
      } else if (item < subTree->data) {
        tempPtr = findNode(subTree->leftPtr, item);
      } else if (item > subTree->data) {
        tempPtr =  findNode(subTree->rightPtr, item);
      }
    }  // end of if
    return tempPtr;
  }
  // ========Traversal functions and helper functions ==========
  // inorder left-root-right
  // Tree Traversal (recursive)
  // used Premade visit function
  // Inorder (root ,left, right)
  void inorder(void visit(const T &item), Node * inorderTree) const {
    if (inorderTree == nullptr) {
      return;
    }
    if (inorderTree != nullptr) {
      inorder(visit, inorderTree->leftPtr);
      T item = inorderTree->data;
      visit(item);
      inorder(visit, inorderTree->rightPtr);
    }
  }
  // takes a function that takes a single parameter of type T
  // inorderTraverse left-root-right
  void InorderTraverse(void visit(const T &item)) const {
    inorder(visit, rootPtr);
  }
  // recursive function
  // preorder root-left-right
  // Used premade visit function
  void preorder(void visit(const T &item), Node * preorderTree) const {
    if (preorderTree == nullptr) {
      return;
    }
    if (preorderTree != nullptr) {
      T item = preorderTree->data;
      visit(item);
      preorder(visit, preorderTree->leftPtr);
      preorder(visit, preorderTree->rightPtr);
    }
  }
  // preorder traversal: root-left-right
  void PreorderTraverse(void visit(const T &item)) const {
    preorder(visit, rootPtr);
  }
  // recursive function
  // Postorder left-right-root
  // Used premade visit function
  void postorder(void visit(const T &item), Node * postorderTree) const {
    if (postorderTree == nullptr) {
      return;
    }
    if (postorderTree != nullptr) {
      T item = postorderTree->data;
      postorder(visit, postorderTree->leftPtr);
      postorder(visit, postorderTree->rightPtr);
      visit(item);
    }
  }
  // postorder traversal: left-right-root
  void PostorderTraverse(void visit(const T &item)) const {
    postorder(visit, rootPtr);
  }
  // =============Rebalance =================================================
  // create dynamic array, copy all the items to the array
  // and then read the array to re-create this tree from scratch
  // so that resulting tree should be balanced
  void Rebalance() {
    // save arry
    Clear();
    int size = this->NumberOfNodes();
    T *arrPtr = new T[size];
    int index = 0;
    this->rebalanceHelper(this->rootPtr, arrPtr, index);
    // build tree from arr
    // Clear();
    createArrayHelper(arrPtr, 0, size);
    delete[] arrPtr;
    arrPtr = nullptr;
  }
  // fill array
  // helper function for rebalance
  void rebalanceHelper(Node* tempPtr, T arr[], int idx) {
    if (tempPtr == nullptr) {
      return;
    }
    rebalanceHelper(tempPtr->leftPtr, arr, idx);
    arr[idx++] = tempPtr->data;
    rebalanceHelper(tempPtr->rightPtr, arr, idx);
  }
  // ==============Clear function with helper=======================
  // recursively clear
  // recursive clear helper function
  // nothing to be clear just return
  void clearHelper(Node* clearNode) {
    if (clearNode == nullptr) {
      return;
    }
    clearHelper(clearNode->leftPtr);
    clearHelper(clearNode->rightPtr);
    delete clearNode;
    clearNode = nullptr;
  }
  // delete all nodes in tree
  // use helper function
  // set root to null
  void Clear() {
    clearHelper(rootPtr);
    rootPtr = nullptr;
  }
  // ======Compare operator and helper function ===========
  // Equality compare helper function
  // Take two Node compare
  // return true if eqaul (both null is also equal)
  // recursive check equality
  bool isEqual(Node* leftTree, Node* rightTree) const {
    if (leftTree == nullptr && rightTree == nullptr) {
      return true;
    }
    if ((leftTree == nullptr) || (rightTree == nullptr)) {
      return false;
    }
    return ((leftTree->data == rightTree->data) &&
    isEqual(leftTree->leftPtr, rightTree->leftPtr) &&
    isEqual(leftTree->rightPtr, rightTree->rightPtr));
  }
  // trees are equal if they have the same structure
  // AND the same item values at all the nodes
  bool operator==(const BST<T> &other) const {
    return isEqual(rootPtr, other.rootPtr);
  }
  // not == to each other
  bool operator!=(const BST<T> &other) const {
    if (*this == other) {
      return false;
    } else {
      return true;
    }
  }
};

#endif  // BST_HPP
