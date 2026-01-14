#include <iostream>
#include <stack>
using namespace std;

struct Btree {
    int data;
    Btree* lchild;
    Btree* rchild;
    int flag;   // used for postorder
};

Btree* root = NULL;

void insertNode() {
    int val;
    cout << "Enter data: ";
    cin >> val;

    Btree* temp = new Btree;
    temp->data = val;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->flag = 0;

    if (root == NULL) {
        root = temp;
        cout << "Node inserted as root\n";
        return;
    }

    Btree* ptr = root;
    char dir;

    while (true) {
        cout << "Enter Direction (l/r): ";
        cin >> dir;

        if (dir == 'l' || dir == 'L') {
            if (ptr->lchild == NULL) {
                ptr->lchild = temp;
                break;
            }
            ptr = ptr->lchild;
        }
        else if (dir == 'r' || dir == 'R') {
            if (ptr->rchild == NULL) {
                ptr->rchild = temp;
                break;
            }
            ptr = ptr->rchild;
        }
        else {
            cout << "Invalid direction! Use l or r.\n";
        }
    }
}

void inorderTraversal() {
    stack<Btree*> s;
    Btree* temp = root;

    while (temp != NULL || !s.empty()) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->lchild;
        }

        temp = s.top();
        s.pop();

        cout << temp->data << " ";
        temp = temp->rchild;
    }
}

void preorderTraversal() {
    if (root == NULL) return;

    stack<Btree*> s;
    Btree* temp = root;

    while (temp != NULL || !s.empty()) {

        while (temp != NULL) {
            cout << temp->data << " ";   // print first

            if (temp->rchild != NULL)
                s.push(temp->rchild);   // push right

            temp = temp->lchild;        // go left
        }

        if (!s.empty()) {
            temp = s.top();
            s.pop();
        }
    }
}

void postorderTraversal() {
    if (root == NULL) return;

    stack<Btree*> s;
    Btree* temp = root;

    while (temp != NULL || !s.empty()) {

        while (temp != NULL) {
            if (temp->rchild != NULL)
                s.push(temp->rchild);

            s.push(temp);
            temp = temp->lchild;
        }

        temp = s.top();
        s.pop();

        if (!s.empty() && temp->rchild == s.top() && temp->flag == 0) {
            temp->flag = 1;
            s.pop();
            s.push(temp);
            temp = temp->rchild;
        }
        else {
            cout << temp->data << " ";
            temp = NULL;
        }
    }
}

int main() {
    char choice;

    do {
        insertNode();
        cout << "Do you want to insert more nodes? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nInorder Traversal: ";
    inorderTraversal();

    cout << "\nPreorder Traversal: ";
    preorderTraversal();

    cout << "\nPostorder Traversal: ";
    postorderTraversal();

    return 0;
}
