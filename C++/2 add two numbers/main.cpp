#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    int cCarry = 0;
    ListNode* node1 = l1;
    ListNode* node2 = l2;

    ListNode *resultNode = new ListNode;
    ListNode* currentNode = resultNode;

    //if not all the nodes come to an end
    while ((node1 != nullptr) || (node2 != nullptr)) {

        //judge if any linked list has run out
        if (node1 == nullptr) { //if l1 is running out
            int tSum = node2->val + cCarry;

            //judge if carry is needed
            if (tSum >= 10) { //need carry
                cCarry = 1;
                tSum -= 10;
            }
            else { //no need to carry
                cCarry = 0;
            }

            currentNode->val = tSum;
            node2 = node2->next;


        }
        else if (node2 == nullptr) { //if l2 is running out
            int tSum = node1->val + cCarry;

            //judge if carry is needed
            if (tSum >= 10) { //need carry
                cCarry = 1;
                tSum -= 10;
            }
            else { //no need to carry
                cCarry = 0;
            }

            currentNode->val = tSum;
            node1 = node1->next;

        }
        else { //case that no one is nullpty
            int tSum = node1->val + node2->val + cCarry;

            //judge if carry is needed
            if (tSum >= 10) { //need carry
                cCarry = 1;
                tSum -= 10;
            }
            else { //no need to carry
                cCarry = 0;
            }

            //std::cout << currentNode->val << std::endl;
            currentNode->val = tSum;
            //std::cout << tSum << std::endl;
            node2 = node2->next;
            node1 = node1->next;
        }

        //proceed currentNode
        currentNode -> next = new ListNode;
        currentNode = currentNode->next;
    }

    //backpuch
    if (cCarry == 1) { //still need one step
        currentNode->val = 1;
    }
    else { //need to delete last node
        ListNode* currentNode2 = resultNode;
        while (currentNode2->next->next != nullptr) { //if we are heading the last one
            currentNode2 = currentNode2->next;
        }
        currentNode2->next = nullptr;
        delete currentNode;
        currentNode = nullptr;
    }

    //return
    return resultNode;
}

int main() {

    ListNode init1(0), init2(0);
    ListNode* num1P = &init1;
    ListNode* num2P = &init2;

    int num1[3] = { 9, 9, 9 };
    int num2[4] = { 9, 9, 9, 9 };
    
    for (int numI : num1) {
        ListNode *nextNode = new ListNode;
        num1P->next = nextNode;
        num1P = num1P->next;

        num1P->val = numI;
    }
    for (int numI : num2) {
        ListNode* nextNode = new ListNode;
        num2P->next = nextNode;
        num2P = num2P->next;

        num2P->val = numI;
    }

    ListNode *testP = addTwoNumbers(( & init1)->next, ( & init2) ->next);

    //ListNode* testP = (&init2)->next;

    while (testP != nullptr) {
        std::cout << testP->val << std::endl;
        testP = testP->next;
    }


    return 0;
}




