#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(){
        left = NULL;
        right = NULL;
    }
    Node(int x){
        left = NULL;
        right = NULL;
        data = x;
    }
};


// Function to insert a node into BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to convert BST to an array
void inorder(Node *root, vector<int> &v)
{
   if (root == NULL)
   {
      return ;
   }
   else
   {
      inorder(root->left, v);
      v.push_back(root->data);
      inorder(root->right, v);
   }
}
//Function to print array in inorder fashion
void bstPrint(Node *root){
    if(root == NULL){
        return;
    }
    bstPrint(root->left);
    cout << root->data << " ";
    bstPrint(root->right);
}

// Function to display the array elements
void displayArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Node* insert_in_order(vector<int> arr,int start,int end){
    Node* root = new Node;
    root->data = arr[(start+end)/2];
    if(start>end){
        return NULL;
    }else{
        int mid = (start+end)/2;
        root = new Node;
        root->data = arr[mid];
        root->left = insert_in_order(arr,start,mid-1);
        root->right = insert_in_order(arr,mid+1,end);
    }
    return root;
}


int main() {
    Node* root = NULL;
    vector<int> bstArray;
    Node *newroot = NULL;
    // Insert nodes into the BST
    root = insertNode(root, 8);
    root->left = new Node(3);
    root->left->left = new Node(10);
    root->left->right = new Node(2);
    root->right = new Node(5);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    
    int index = 0;
    // Convert the BST to an array
    inorder(root,bstArray);

    // Display the array
    //displayArray(bstArray);
    sort(bstArray.begin(),bstArray.end());
    //displayArray(bstArray);
    newroot = insert_in_order(bstArray,0,bstArray.size()-1);
    bstPrint(newroot);
    return 0;
}
