#include<iostream>
#include<vector>
#include<list>
using namespace std;
class HashTable{
private:
static const int hashSize = 10;
list<int> table[hashSize];
int hashFunction(int key){
    return key%hashSize;
}
public:
void insert(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}
void remove(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}
void display(){
    for(int i =0;i<hashSize;i++){
        cout<<i<<"-->";
   for (auto x : table[i])
                cout << x << " --> ";
            cout << "NULL\n";
        }
    }
    bool search(int key) {
        int index = hashFunction(key);
        for (auto x : table[index]) {
            if (x == key)
                return true;
        }
        return false;
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(30);
    ht.insert(25);
    ht.insert(35);

    cout << "Hash Table after insertion:\n";
    ht.display();

    ht.remove(20);
    cout << "\nHash Table after deleting 20:\n";
    ht.display();

    int key = 25;
    cout << "\nSearching for " << key << ": " 
         << (ht.search(key) ? "Found" : "Not Found") << endl;

    return 0;
}

