/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class BST
*/

#include "BSTree.h"

// ============Constructor====================
// set to NULL

BSTree::BSTree() {
    root = nullptr;
    movieCode = 0;
}
// ============End of constructor=============

// ============Deconstructor==================
BSTree::~BSTree() {
    // if the tree is empty
    if (isEmpty()) {
        return;
    }
    // not empty then call empty function
    makeEmpty();
}
// ============End of Deconstructor===========

// ============isEmpty Function===============
// check if the root is empty or not
// return true if its empty (null)
// else return false
bool  BSTree::isEmpty() const {
    return (root == nullptr);
}
// ============End of isEmpty Function========

// ============MakeEmpty()====================
// Call the recursive function to empty
void BSTree::makeEmpty() {
    emptyHelper(root);
}
// ============End of MakeEmpty Function======

// ============Empty Helper===================
// helper function for makeEmpty
// recursively delete and set to null
void BSTree::emptyHelper(Node* & node) {
    // if the node is null just return
    if (node == nullptr) {
        return;
    }
    // recursive delete the data and node
    emptyHelper(node->leftPtr);
    emptyHelper(node->rightPtr);
    delete node->data;
    node->data = nullptr;
    delete node;
}
// ============End of empty helper Function===

// ============Retrieve=======================
// return true if the data is in the BST
// return false if the data is not in BST
// the found data will be store in the second param
Movie* BSTree::retrieve(const Movie* find) {
    return retrieveBSTHelper(root, find);
}
// Helper function for retrieve
// find the given obj recursively
Movie* BSTree::retrieveBSTHelper(Node*& node, const Movie* find) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data->isEqual(find)) {
        return node->data;
    } else if (node->data->compareMovie(find)) {
        return retrieveBSTHelper(node->leftPtr, find);
    } else {
        return retrieveBSTHelper(node->rightPtr, find);
    }
}
// ============End of Retrieve Function=======

// ============Insert function================
// Use helper function to insert the data to tree
bool BSTree::putIntoBST(Movie* data) {
    return putIntoBSTHelper(root, data);
}
// ============End of Insert==================

// ============Insert Function Helper=========
// Insert Helper
// Recursive insert the data
// No duplicate
bool BSTree::putIntoBSTHelper(Node*& node, Movie* m_data) {
    // find the right spot to insert
    if (node == nullptr) {
        node = new Node();
        node->data = m_data;
        node->leftPtr = node->rightPtr = nullptr;
        return true;
    }
    // duplicate
    // no duplicate
    if (node->data->isEqual(m_data)) {
        // increase the stock
        bool stock = node->data->stockIncrease(m_data->getStock());
        // delete the duplicated
        delete m_data;
        return stock;
    }
    if (node->data->compareMovie(m_data)) {
        return putIntoBSTHelper(node->leftPtr, m_data);
    } else {
        return putIntoBSTHelper(node->rightPtr, m_data);
    }
}
// ============End of Insert Function Helper==

// ===============Print=======================
// inorder
// helper for the showOutput
// displays the BST in inorder traversal
void BSTree::inorderOutput(Node* node) const {
    if (node == nullptr) { return; }
    inorderOutput(node->leftPtr);
    cout << node->data->dataOutput();
    inorderOutput(node->rightPtr);
}
// overload operator<< display inorder traversal
void BSTree::showMeTheOutput() {
    inorderOutput(root);
    cout << endl;
}
// ==============End of Print=================
