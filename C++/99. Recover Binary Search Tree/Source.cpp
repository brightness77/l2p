#include<vector>
#include<iostream>


using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};




void inOrder(TreeNode* currentP, vector<TreeNode*>& replaceCouple, vector<int>& replaceInt) {

    if (!currentP || replaceInt[2] == 2) {
        return;
    }

    inOrder(currentP->left, replaceCouple, replaceInt);

    //replacing part
    if (replaceInt[2] == 0) {
        //if the first node is not found

        if (currentP->val < replaceInt[0]) {
            //if it is the first discrepancy
            replaceInt[2] = 1; //proceed phase
            replaceInt[1] = currentP->val; //update second finding
            replaceCouple[1] = currentP;
        }
        else {
            //continue finding first discrepancy
            replaceInt[0] = currentP->val;
            replaceCouple[0] = currentP;
        }

    }
    else if (replaceInt[2] == 1) {
        //if first found but second do not

        if (currentP->val < replaceInt[1]) {
            //if it is the secound discrepancy
            replaceCouple[1] = currentP;
            replaceInt[2] = 2;
        }
        else {
            replaceInt[1] = currentP->val;
        }
    }


    inOrder(currentP->right, replaceCouple, replaceInt);

}



void recoverTree(TreeNode* root) {

    //do in-order traversal and swap

    vector<TreeNode*> replaceCouple = {
        nullptr, nullptr
    };

    vector<int> replaceInt = {
        INT_MIN, INT_MIN, 0,
    };

    inOrder(root, replaceCouple, replaceInt);
    //cout << replaceCouple[0]->val << " " << replaceCouple[1]->val << endl;
    swap(replaceCouple[0]->val, replaceCouple[1]->val);

}


void inOrderPrint(TreeNode* cP) {

    if (!cP) {
        return;
    }

    inOrderPrint(cP->left);
    cout << " " << cP->val << " ";
    inOrderPrint(cP->right);
}







int main() {


    TreeNode test0(3);
    TreeNode test1(1);
    TreeNode test2(4);
    TreeNode test5(2);

    //build tree
    test0.left = &test1;
    test0.right = &test2;
    test2.left = &test5;

    recoverTree(&test0);

    inOrderPrint(&test0);


	return 0;
}

