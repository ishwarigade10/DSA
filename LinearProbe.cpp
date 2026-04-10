#include <iostream>
using namespace std;

// Structure for music track
struct Track {
    int id;
    string name;
    string artist;
    string album;
};

class HashTable {
private:
    Track *table;
    int *chain;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new Track[size];
        chain = new int[size];

        for (int i = 0; i < size; i++) {
            table[i].id = -1;
            chain[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % size;
    }

    // Overflow check
    bool isFull() {
        for (int i = 0; i < size; i++) {
            if (table[i].id == -1)
                return false;
        }
        return true;
    }

    
    void insert(Track t) {

        if (isFull()) {
            cout << "Hash Table Overflow!\n";
            return;
        }

        int idx = hashFunction(t.id);
        if (table[idx].id == -1) {
            table[idx] = t;
        }
        else {
            
            int newIdx = idx;
            while (table[newIdx].id != -1) {
                newIdx = (newIdx + 1) % size;
            }

            table[newIdx] = t;

            // Create chain
            int temp = idx;
            while (chain[temp] != -1) {
                temp = chain[temp];
            }

            chain[temp] = newIdx;
        }
    }

    
    void search(int id) {
        int idx = hashFunction(id);
        int temp = idx;

        while (temp != -1) {
            if (table[temp].id == id) {
                cout << "\nTrack Found:\n";
                cout << "ID: " << table[temp].id << endl;
                cout << "Name: " << table[temp].name << endl;
                cout << "Artist: " << table[temp].artist << endl;
                cout << "Album: " << table[temp].album << endl;
                return;
            }
            temp = chain[temp];
        }

        cout << "Track not found\n";
    }

    void display() {
        cout << "\nIndex\tID\tName\tChain\n";
        for (int i = 0; i < size; i++) {
            cout << i << "\t" << table[i].id << "\t"
                 << table[i].name << "\t"
                 << chain[i] << endl;
        }
    }

    ~HashTable() {
        delete[] table;
        delete[] chain;
    }
};

int main() {
    int n;

    cout << "Enter size of hash table: ";
    cin >> n;

    HashTable ht(n);

    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Track\n";
        cout << "2. Display Table\n";
        cout << "3. Search Track\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            Track t;
            cout << "\nEnter Track ID: ";
            cin >> t.id;
            cout << "Enter Name: ";
            cin >> t.name;
            cout << "Enter Artist: ";
            cin >> t.artist;
            cout << "Enter Album: ";
            cin >> t.album;

            ht.insert(t);
            break;
        }

        case 2:
            ht.display();
            break;

        case 3: {
            int searchId;
            cout << "Enter Track ID to search: ";
            cin >> searchId;
            ht.search(searchId);
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}