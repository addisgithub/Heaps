/**
 * @file main.cpp
 * @brief This is a Heap Implementation.
 * @author Addis Bogale
 * @date 3/29/2021
 * 
 */

#include <iostream>
#include <random>
using namespace std;

/**
 * Add two integers (brief)
 * 
 * Adds a and b, two integers (long description)
 * @param a integer
 * @param b integer
 * @returns integer sum of a and b
 */

class BTNode{
public:
    BTNode* parent;
    BTNode* right;
    BTNode* left;
    int x;
    int count;
    BTNode* r = NULL;

    BTNode() {
        left = NULL;
        right = NULL;
        parent = NULL;
        x = 0;
        r = NULL;
        count = 0;
    }

int nodeData() {
        return(x);
    }

int compare(int y, int z){
    if (z > y)
        return z;
    if (y > z)
        return y;
}

BTNode* merge(BTNode* h1, BTNode* h2){
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    if ((h2->x - h1->x) < 0)
        return merge(h2,h1);

    if (rand() % 2){
        h1->left = merge(h1->left, h2);
        if (h1->left != NULL)
            h1->left->parent = h1;
    }else{
        h1->right = merge(h1->right, h2);
        if (h1->right != NULL)
            h1->right->parent = h1;}
    return h1;
    }

bool add(int x){
    BTNode* u = new BTNode();
    u->left = u->right = u->parent = NULL;
    parent = NULL;
    u->x = x;
    r = merge(u, r);
    r->parent = NULL;
    count++;
    return true;
}

bool remove(){
    int x = r->x;
    BTNode* tmp = r;
    r = merge(r->left, r->right);
    delete tmp;
    if (r != NULL)
        r->parent = NULL;
    count--;
    return r;
}
void printBT(const string& prefix, BTNode* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "--" );

        // print the value of the node
        //cout << node->nodeName() << ':' << node->nodeData() << std::endl;
        cout << node->nodeData() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void printBT()
{
    printBT("", r, false);
}

};

int main() {
    BTNode value;
    
    value.add(3);
    value.add(6);
    value.add(2);
    value.printBT();
    value.add(7);
    value.add(8);
    value.printBT();
    value.remove();
    value.remove();
    value.printBT();

}

