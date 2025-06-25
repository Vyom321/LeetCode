#include<iostream>
#include<vector>
using namespace std;
class MinHeap{
private:
vector<int>vt;
int parent(int i){
    return ((i-1)/2);
}
void heapifyUp(int index){
    while(index > 0 && vt[parent(index)]>vt[index]){
        swap(vt[parent(index)],vt[index]);
        index = parent(index);
    }
}
public:
void insert(int val){
    vt.push_back(val);
    heapifyUp(vt.size()-1);
}
void display(){
    for(int i:vt){
        cout<<i<<" ";
    }
    cout<<endl;
}

};
int main() {
    MinHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(0);

    cout << "Min Heap after insertions: ";
    h.display();

    return 0;
}