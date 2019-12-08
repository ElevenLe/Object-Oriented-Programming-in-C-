/*
  functions for use with CS2124 rec11
  -jbs
*/

#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;


// Node to be used a part of linked list
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listInsertHead: adds a data item to the beginning of a [possibly empty] list
void listInsertHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listInsertHead(result, vals[index-1]);
    }
    return result;
}




void splice(Node* addingListHead, Node* locationPointer){
    Node* index = addingListHead;
    while(index->next != nullptr){
        index = index -> next;
    }
//    cout << "test::: "<<index -> data << endl;
    index -> next = locationPointer -> next;
//    cout << "test2::: " << index -> next -> next -> data;
    locationPointer -> next = addingListHead;
}

void displayList(Node* head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* isSubset(Node* subListHead, Node* locationListHead){
    Node* out = nullptr;
    Node* targetIndex = locationListHead;
    Node* subIndex = subListHead;
    

    
    while(targetIndex != nullptr && subIndex != nullptr){
        if(targetIndex -> data == subIndex -> data){
            out = targetIndex;
            subIndex = subIndex -> next;
            targetIndex = targetIndex -> next;
            while(subIndex != nullptr &&  targetIndex != nullptr){
                if(subIndex -> data != targetIndex -> data){
                    targetIndex = out -> next;
                    subIndex = subListHead;
                    break;
                }else{
                    subIndex = subIndex -> next;
                    targetIndex = targetIndex -> next;
                }
            }
            
            if(targetIndex == nullptr && subIndex != nullptr){return nullptr;}
        }
        else{
            out = nullptr;
            targetIndex = targetIndex -> next;
        }
    }
    
    return out;

}

void display2(Node* traget, Node* Attempt){
    cout << "target: ";
    displayList(traget);
    cout << endl;
    cout << "Attempt match: ";
    displayList(Attempt);
    cout << endl;
    
    if(isSubset(Attempt, traget) != nullptr){
        Node* out = isSubset(Attempt, traget);
        displayList(out);
        cout << endl;
    }else{
        cout << "Failed to match" << endl;
    }
    
    cout << endl;
    
}

bool sharedListBruteForce(Node* list1Head, Node* list2Head){
    Node* index1 = list1Head;
    Node* index2 = list2Head;
    while(index1 != nullptr && index2 != nullptr){
        while(index1 != nullptr && index2 != nullptr){
            if(index1 == index2){
                displayList(index2 -> next);
                return true;
            }
            
            index2 = index2->next;
            
        }
        
        index2 = list1Head;
        index1 = index1 -> next;
    }
    
    return false;
}


bool sharedListUsingSet(Node* list1Head, Node* list2Head){
    unordered_set<Node*> checkList;
    while(list1Head != nullptr){
        checkList.insert(list1Head);
        list1Head = list1Head->next;
    }
    
    while(list2Head != nullptr){
        if(checkList.find(list2Head) == checkList.end()){
            list2Head = list2Head->next;
        }
        else{
            displayList(list2Head);
            return true;
        }
    }
    
    return false;
    
}

int main(){
    vector<int> first;
    first.push_back(5);
    first.push_back(7);
    first.push_back(9);
    first.push_back(1);
    
    vector<int> second;
    second.push_back(6);
    second.push_back(3);
    second.push_back(2);
    Node* firstSSL = listBuild(first);
    Node* secondSSL = listBuild(second);
    
    
    
    cout << "L1 : ";
    displayList(firstSSL);
    cout << endl;
    
    cout << "L2 : ";
    displayList(secondSSL);
    cout << endl;
    
    cout << "Target : ";
    displayList(firstSSL -> next);
    cout<< endl;
    
    splice(secondSSL, firstSSL->next) ;
    
    
    
    cout << "Splicing L2 at target in L1" << endl;
    
    cout << "L1 : ";
    displayList(firstSSL);
    cout << endl;
    
    cout << "L2 : ";
    displayList(secondSSL);
    cout << endl;
    
    cout << "======================PART 2"<<endl;
    
    vector<int> third = {1,2 ,3, 2, 3, 2, 4, 5, 6};
    Node* thirdSSL =listBuild(third);
    
    Node* check1SSL = listBuild({2 ,4 ,5 ,6});
    Node* check2SSL = listBuild({1});
    Node* check3SSL = listBuild({3,9});
    Node* check4SSL = listBuild({2,3});
    Node* check5SSL = listBuild({2,3,2,4});
    Node* check6SSL = listBuild({5,6,7});
    
    display2(thirdSSL,check1SSL);
    display2(thirdSSL,check2SSL);
    display2(thirdSSL,check3SSL);
    display2(thirdSSL,check4SSL);
    display2(thirdSSL,check5SSL);
    display2(thirdSSL,check6SSL);
    
    listClear(thirdSSL);
    listClear(check1SSL);
    listClear(check2SSL);
    listClear(check3SSL);
    listClear(check4SSL);
    listClear(check5SSL);
    listClear(check6SSL);
    
    cout << "============part 3==================="<<endl;
    
    Node* one = listBuild({2,3,4,5});
    Node* two = listBuild({2,3,3});
    
    Node* twoShare = two;
    twoShare -> next ->next -> next = one -> next -> next;
    
    cout << "the first list: ";
    displayList(twoShare);
    cout << endl;
    
    cout << "the second list: ";
    displayList(one);
    cout << endl;
    
    cout << "they both share 4" << endl;
    
    cout << "using brute force to find the commend node : ";
    
    sharedListBruteForce(one,twoShare);
    cout << endl;
    
    cout << "using set to find the commend node : ";
    sharedListUsingSet(one, twoShare);
    cout << endl;
    
    
}
