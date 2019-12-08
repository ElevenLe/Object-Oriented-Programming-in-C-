// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

void printList(const list<int>& oneList){
//    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); iter++){
//        cout << *iter << " ";
//    }
    for(list<int>::const_iterator iter = oneList.begin(); iter != oneList.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}


void printListRange(const list<int>& oneList ){
    for(int oneInt : oneList){
        cout << oneInt << " ";
    }
    cout << endl;
}

void printListAuto(const list<int> oneList){
    // int index = 0;
    for(auto iter = oneList.begin(); iter != oneList.end(); ++++iter){
        
            cout << *iter << " ";
        
    }
    cout << endl;
}

list<int>::const_iterator findInList(const list<int>& oneList, int nFind){
    for(list<int>::const_iterator iter = oneList.begin(); iter != oneList.end(); iter ++){
        if( *iter == nFind ){
            return iter;
        }
    }
    return oneList.end();
}

auto findInListAuto(const list<int>& oneList, int nFind){
    for(auto iter = oneList.begin(); iter != oneList.end(); iter ++){
        if( *iter == nFind ){
            return iter;
        }
    }
    return oneList.end();
}

bool isEven(int n){
    return  n%2== 0;
}

class isEvenFunctor{
public:
    bool operator()(int n){
        return n%2== 0;
    };
};

list<int>::iterator ourFind(list<int>::iterator begin, list<int>::iterator end, int n){
    cout << "this is our find function" << endl;
    for(list<int>::iterator iter = begin; iter != end ; iter++){
        if(*iter == n) return iter;
    }
    return end;
}
template <typename T, typename U>
T ourFind(T begin, T end, U n){
    cout << "this is our template function" << endl;
    for(T iter = begin; iter != end ; iter++){
        if(*iter == n) return iter;
    }
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> oneVect{10,9,8,7,6,5,4,3,2,1};
    for (size_t i = 0; i< oneVect.size() ; i++){
        cout<< oneVect[i] << " ";
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> oneList(oneVect.begin(),oneVect.end());
    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); iter++){
        cout << *iter << " ";
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(oneVect.begin(),oneVect.end());
    for (size_t i = 0; i< oneVect.size() ; i++){
        cout<< oneVect[i] << " ";
    }
    cout << endl;
    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); iter++){
        cout << *iter << " ";
    }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for(size_t i = 0; i != oneVect.size(); i++){
        if (i %2 == 0){
            cout << oneVect[i] << " ";
        }
    }
    
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
//    for(size_t i = 0; i != oneVect.size(); i++){
//        if (i %2 == 0){
//            cout << oneList[i] << " ";
//        }
//    }

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for(vector<int>::iterator iter = oneVect.begin(); iter != oneVect.end(); iter = iter + 2){
        cout << *iter << " ";
    }
    // what is random access iterator? the vector iterator is random access iterator
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
//    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); iter = iter + 2){
//        cout << *iter << " ";
//    }
    // list iterator is not the random access iterator, so cannot iter = iter +2
    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); ++++iter){
        
            cout << *iter << " ";
        
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    cout << "before sort: ";
    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); iter++){
        cout << *iter << " ";
    }
    cout <<endl;
    oneList.sort();
    cout << "after sort: ";
    for(list<int>::iterator iter = oneList.begin(); iter != oneList.end(); iter++){
        cout << *iter << " ";
    }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printList(oneList);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListRange(oneList);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printListAuto(oneList);
    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    
    if(findInList(oneList, 2) != oneList.end()){
        cout << *findInList(oneList, 2)<< endl;
    }else{
        cout << "not found" << endl;
    }
    
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    
    if(findInListAuto(oneList, 2) != oneList.end()){
        cout << *findInListAuto(oneList, 2)<< endl;
    }else{
        cout << "not found" << endl;
    }
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    
    if(find(oneList.begin(),oneList.end(),4) != oneList.end()){
        cout << *find(oneList.begin(),oneList.end(),4)<< endl;
    }else{
        cout << "not found" << endl;
    }
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    
    
    if(find_if(oneList.begin(),oneList.end(),isEven) != oneList.end()){
        cout << *find_if(oneList.begin(),oneList.end(),isEven)<< endl;
    }else{
        cout << "not found" << endl;
    }
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    if(find_if(oneList.begin(),oneList.end(),isEvenFunctor()) != oneList.end()){
        cout << *find_if(oneList.begin(),oneList.end(),isEvenFunctor())<< endl;
    }else{
        cout << "not found" << endl;
    }
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    [] { cout << "Hello Lambda!" << endl; }();
    
    [] (int a, int b) { cout << a + b << endl; } (4, 5);
    
    int result = [] (int a, int b) { return a + b; } (4, 5);
    cout << "the result is: " << result << endl;
    
    int result2 = [] (int a, int b) -> int { return a + b; } (4, 5);
    cout << "the result is: " << result2 << endl;
    
    if(find_if(oneList.begin(),oneList.end(),[](int x){return x%2 == 0;}) != oneList.end()){
        cout << *find_if(oneList.begin(),oneList.end(),[](int x){return x%2 == 0;})<< endl;
    }else{
        cout << "not found" << endl;
    }
    
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[10];
    copy(oneList.begin(), oneList.end(), arr);
    for(int& oneInt : arr){
        cout << oneInt << " ";
    }
    cout << endl;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    if(ourFind(oneList.begin(),oneList.end(),4) != oneList.end()){
        cout << *ourFind(oneList.begin(),oneList.end(),4)<< endl;
    }else{
        cout << "not found" << endl;
    }
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    if(ourFind(oneList.begin(),oneList.end(),4) != oneList.end()){
        cout << *ourFind(oneList.begin(),oneList.end(),4)<< endl;
    }else{
        cout << "not found" << endl;
    }
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs) {
        cerr << "File not opened" << endl;
        exit(1);
    }
    
    vector<string> wordsVector;
    
    string word;
//    while(ifs >> word){
//        auto check = find(wordsVector.begin(), wordsVector.end(), word);
//        if(check == wordsVector.end()){
//            wordsVector.push_back(word);
//        }
//    }
//    cout << wordsVector.size() << endl;
    

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> wordsSet;
    
//    while(ifs >> word){
//        wordsSet.insert(word);
//    }
    
    cout << wordsSet.size()<<endl;
    
    
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordsMap;
    
    int index = 0;
    while(ifs >> word){
        wordsMap[word].push_back(index);
        index ++;
    }
    
//    for(pair<string, vector<int>> item: wordsMap){
//        cout << item.first << ": ";
//        for (size_t i = 0; i< item.second.size() ; i++){
//            cout<< item.second[i] << " ";
//        }
//        cout << endl;
//
//    }
    
    cout << wordsMap.size() << endl;

    
    cout << "=======\n";
}
