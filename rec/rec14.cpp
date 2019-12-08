//
//  rec14.cpp
//  rec14
//
//  Created by Zhengyi Li on 12/14/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <exception>
#include <string>
using namespace std;

void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left = nullptr, *right = nullptr;
};

struct Node{
    Node(int data =0): data(data){}
    int data;
    Node* next = nullptr;
};

int max(TNode* root) {
    if (root == nullptr) throw invalid_argument("not passing the nullptr");
    if(root -> left == nullptr && root -> right ==nullptr){
        return root -> data;
    }
    if(root -> left != nullptr && root -> right != nullptr){
        return max(max(max(root -> left),max(root -> right)), root -> data);
    }else if (root -> left == nullptr && root -> right != nullptr){
        return max(max(root -> right), root -> data);
    }else{
        return max(max(root->left), root -> data);
    }
    
    
};

bool palindrome(char words[], int number){
    
    if (number == 1 || number == 0){
        return true;
    }
    return (words[number-1] == words[0] &&  palindrome(words+1, number - 2));
}

int towers(int number){
    if(number == 1) return 1;
    
    return towers(number-1) + towers(number-1) + 1;
}

bool evenBinary(int number){
    if(number == 0) return true;
    
    if (number %2 == 0){return evenBinary(number/2);}
    
    return !(evenBinary(number/2));
    
};

Node* sumTwoList(Node* left,Node* right){
    
    if (left == nullptr && right == nullptr){
        return nullptr;
    }
    
    Node* one;
    if(left != nullptr && right != nullptr){
        one = new Node(left -> data + right -> data);
        one -> next= sumTwoList(left -> next, right -> next);
    }else if(left == nullptr && right != nullptr){
        one = new Node(right -> data);
        one -> next= sumTwoList(nullptr, right -> next);
    }else {
        one = new Node(left -> data);
        one -> next= sumTwoList(left -> next, right);
    }
    
    return one;
}

Node* addLists(Node* list1, Node* list2){
    if(list1 == nullptr || list2 == nullptr){
        return nullptr;
    }
    Node* temp;
    temp = new Node(list1 ->  data + list2 -> data);
    temp -> next = addLists(list1 ->  next, list2 -> next);
    return temp;
}

void listPrint(Node* head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next;
    }
}





int main() {
    cout << "========================question 1========================" << endl;
    cout << "testing the numebrs that have ==even== number of ones in binary" << endl;
    cout << "0 : " << evenBinary(0) << endl;
    cout << "3 : " << evenBinary(3) << endl;
    cout << "5 : " << evenBinary(5) << endl;
    cout << "6 : " << evenBinary(6) << endl;
    cout << "10 : " << evenBinary(10) << endl;
    cout << "18 : " << evenBinary(18) << endl;
    
    cout << "testing the numebrs that have ==odd== number of ones in binary" << endl;
    cout << "1 : " << evenBinary(1) << endl;
    cout << "2 : " << evenBinary(2) << endl;
    cout << "7 : " << evenBinary(7) << endl;
    cout << "11 : " << evenBinary(11) << endl;
    cout << "13 : " << evenBinary(13) << endl;
    cout << "19 : " << evenBinary(19) << endl;

    
    cout << "========================question 2========================" << endl;
    cout << "create two node list" << endl;
    Node* oneHead = new Node(1);
    oneHead -> next = new Node(2);
    oneHead -> next -> next = new Node(3);
    oneHead -> next -> next -> next = new Node(4);
    cout << "list 1 have : ";
    listPrint(oneHead);
    cout << endl;
    
    Node* twoHead = new Node(1);
    twoHead -> next = new Node(2);
    twoHead -> next -> next = new Node(2);
    cout << "list 2 have : ";
    listPrint(twoHead);
    cout << endl;
    
    
    Node* sum = sumTwoList(oneHead, twoHead);
    cout << "sum of the list 1 and list 2 is : ";
    listPrint(sum);
    cout << endl;
    
    Node* sum2 = addLists(oneHead,twoHead);
    cout << "sum of list sum2 is : ";
    listPrint(sum2);
    cout << endl;
    
    cout << "========================question 3========================" << endl;
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    
    cout << "the largest number is : " << 32 << endl;
    
    cout << "the max finding the largest number is " << max(&f) << endl;
    try{
        max(nullptr);
    }catch(exception &e){
        cout << "the exception : " << e.what() << endl;
    }
    
    cout << "========================question 4========================" << endl;
    
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    
    cout << "========================question 5========================" << endl;
    cout << towers(3) << endl;
    
    cout << " towers(1, 'a', 'b', 'c') : " <<  towers(1) << endl;
    cout << " towers(2, 'a', 'b', 'c') : "  <<  towers(2) << endl;
    cout << " towers(3, 'a', 'b', 'c') : "  <<  towers(3) << endl;
    cout << " towers(4, 'a', 'b', 'c') : "  <<  towers(4) << endl;
    cout << " towers(5, 'a', 'b', 'c') : "  <<  towers(5) << endl;
    cout << " towers(6, 'a', 'b', 'c') : "  <<  towers(6) << endl;
    cout << " towers(7, 'a', 'b', 'c') : "  <<  towers(7) << endl;
    cout << " towers(8, 'a', 'b', 'c') : "  <<  towers(8) << endl;
    cout << " towers(9, 'a', 'b', 'c') : "  <<  towers(9) << endl;
    cout << " towers(10, 'a', 'b', 'c' : "  <<  towers(10) << endl;
    
    cout << "========================question 6========================" << endl;

    for(int i = 1; i <= 10 ; ++i){
        cout << "mystery() of " << i << " is ";
        mystery(i);
        cout << endl;
    }
    
}



