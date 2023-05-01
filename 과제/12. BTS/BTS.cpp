#include <iostream>
#include <cstring>

using namespace std;

class BTS {
private:
    string data;
    BTS *left, *right;
public:
    BTS() { }
    BTS(string value) { 
        data = value;
        left = right = NULL;
    }    
    // Insert
    BTS* Insert(BTS* root, string value) {
        if (!root) {
            return new BTS(value);
        } 
        if (value < root->data) {
            root->left = Insert(root->left, value);
        } else if (value > root->data) {
            root->right = Insert(root->right, value);
        }
        return root;
    }
    // Delete (segmentation fault)
    void Delete(BTS* root, string value) {
        
        if (root->left->data.empty() && root->right->data.empty() && value != root->data) {
            return;
        } else if (value < root->data) {
            Delete(root->left, value);
        } else if (value > root->data) {
            Delete(root->right, value);
        } else if (value == root->data) {
            while(root->left->data.empty() && root->right->data.empty()) {
                root->data.clear();
                if (!root->right->data.empty()) {
                    root->data = root->right->data;
                    root = root->right;
                } else if (!root->left->data.empty()) {
                    root->data = root->left->data;
                    root = root->left;
                }
            }
        }
        
    }
    void PrintKthDepth(int depth) {
        //while()
        // cout << endl;
    }
    void PrintLeaf() {
        //while()
        // cout << endl;
    }

};
int main() {
    int N;
    cin >> N;
    BTS bts, *root = NULL;
    for (int i=0; i<N; i++) {
        string k;
        cin >> k;
        if (k == "+" || k == "-") {
            if (k == "+") {     // k == "+"
                string v;
                cin >> v;
                bts.Insert(root, v);
            } else {            // k == "-"
                string v;
                cin >> v;
                // delete -> segmentation fault
                bts.Delete(root, v);
            }
        } else {
            if (k == "leaf") {                   // k == "leaf"
                bts.PrintLeaf();
            } else if (k == "depth"){            // k == "depth"
                int d;
                cin >> d;
                bts.PrintKthDepth(d);
            } else {
                cout << "예외 상황 발생함" << endl;
            }
        }
    }
    return 0;
}