/*18BCE101 - Labdhi Sheth
Aim : Implementation of Binomial heap
*/

/*Operation	Running Time
Insert	        O(1)
Remove	        O(log n)
Find Min	    O(1)
Extract Min	    O(logn)
Decrease Key    O(logn)
Merge           O(logn)
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INT64_MIN -9223372036854775808

// Structure of Node
struct Node
{
    int val;                                //data value
    int degree;                             //degree of the node
    struct Node* parent;                    //pointer to parent node
    struct Node* child;                     //pointer to leftmost child
    struct Node* sibling;                   //pointer to node just right to current node
};

struct Node *root = NULL;

void binomialLink(struct Node *h1, struct Node *h2)
{
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree = h2->degree + 1;
}

// create a Node
struct Node *createNode(int n)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    ;
    new_node->val = n;
    new_node->parent = NULL;
    new_node->sibling = NULL;
    new_node->child = NULL;
    new_node->degree = 0;
    return new_node;
}

// This function merge two Binomial Heaps
struct Node *mergeBHeaps(struct Node *h1, struct Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    struct Node *res = NULL;

    if (h1->degree <= h2->degree)
        res = h1;

    else if (h1->degree > h2->degree)
        res = h2;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->degree < h2->degree)
            h1 = h1->sibling;

        else if (h1->degree == h2->degree)
        {
            struct Node *sib = h1->sibling;
            h1->sibling = h2;
            h1 = sib;
        }

        // if h2 is greater
        else
        {
            struct Node *sib = h2->sibling;
            h2->sibling = h1;
            h2 = sib;
        }
    }
    return res;
}

// This function perform union operation on two
// binomial heap i.e. h1 & h2
struct Node *unionBHeaps(struct Node *h1, struct Node *h2)
{
    if (h1 == NULL && h2 == NULL)
        return NULL;

    struct Node *res = mergeBHeaps(h1, h2);

    struct Node *prev = NULL, *curr = res,
                *next = curr->sibling;
    while (next != NULL)
    {
        if ((curr->degree != next->degree) ||
            ((next->sibling != NULL) &&
             (next->sibling)->degree ==
                 curr->degree))
        {
            prev = curr;
            curr = next;
        }

        else
        {
            if (curr->val <= next->val)
            {
                curr->sibling = next->sibling;
                binomialLink(next, curr);
            }
            else
            {
                if (prev == NULL)
                    res = next;
                else
                    prev->sibling = next;
                binomialLink(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return res;
}

// Function to insert a Node
void insert(int x)
{
    root = unionBHeaps(root, createNode(x));
}

// Function to display the tree
void printTree(struct Node *h)
{
    while (h)
    {
        printf(" %d ", h->val);
        printTree(h->child);
        h = h->sibling;
    }
}

void revertList(struct Node *h)
{
    if (h->sibling != NULL)
    {
        revertList(h->sibling);
        (h->sibling)->sibling = h;
    }
    else
        root = h;
}

// Function to extract minimum value
struct Node *extractMinBHeap(struct Node *h)
{
    if (h == NULL)
        return NULL;

    struct Node *min_node_prev = NULL;
    struct Node *min_node = h;

    // Find minimum value
    int min = h->val;
    struct Node *curr = h;
    while (curr->sibling != NULL)
    {
        if ((curr->sibling)->val < min)
        {
            min = (curr->sibling)->val;
            min_node_prev = curr;
            min_node = curr->sibling;
        }
        curr = curr->sibling;
    }

    if (min_node_prev == NULL &&
        min_node->sibling == NULL)
        h = NULL;

    else if (min_node_prev == NULL)
        h = min_node->sibling;

    // Remove min node from list
    else
        min_node_prev->sibling = min_node->sibling;

    if (min_node->child != NULL)
    {
        revertList(min_node->child);
        (min_node->child)->sibling = NULL;
    }

    root = unionBHeaps(h, root);
    return min_node;
}

// Function to search for an element
struct Node *findNode(struct Node *h, int val)
{
    if (h == NULL)
        return NULL;

    if (h->val == val)
        return h;

    // Recur for child
    struct Node *res = findNode(h->child, val);
    if (res != NULL)
        return res;

    return findNode(h->sibling, val);
}

//to decrease a specific key of the heap
void decreaseKeyBHeap(struct Node *H, int old_val,
                      int new_val)
{
    struct Node *node = findNode(H, old_val);

    if (node == NULL)
        return;

    node->val = new_val;
    struct Node *parent = node->parent;

    while (parent != NULL && node->val < parent->val)
    {
        int temp = node->val;
        node->val = parent->val;
        parent->val = temp;
        //swap(node->val, parent->val);
        node = parent;
        parent = parent->parent;
    }
}

// Function to delete an element
struct Node *deleteKey(struct Node *h, int val)
{
    if (h == NULL)
        return NULL;

    decreaseKeyBHeap(h, val, INT64_MIN);
    return extractMinBHeap(h);
}


// Main Function
int main()
{
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\tBinomial Heap\n");

    int ans = -1, choice = -1;
    int i, n, m,l;
    struct Node* p;

    printf("\nHow many elements do you wish to enter: ");
    scanf("%d", &n);
    printf("\nEnter %d elements one by one:\n", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        insert(m);
    }

    printf("\n-----------------------------------------------------------\nHeap Elements:");
    printTree(root);
    printf("\n-----------------------------------------------------------\n");

    while (ans != 0)
    {
       printf("\n\t\t\t\t\t\t\t\t MENU ");
       printf("\n1. Insert an element");
       printf("\n2. Delete an element");
       printf("\n3. Decrease key value");
       printf("\n4. Extracting Min value");
       printf("\n5. Displaying the heap");
       printf("\n6. EXIT\n");
       scanf("%d", &choice);

       switch (choice)
       {
            case 1:
                printf("\nEnter the key:");
                scanf("%d", &m);
                insert(m);
                printf("\n-----------------------------------------------------------\n");
                printf("\nThe contents of the heap after insertion are:\n");
                printTree(root);
                printf("\n-----------------------------------------------------------\n");
            break;

            case 2:
                printf("\nEnter the key of the node to be deleted(it should be present in the heap): ");
                scanf("%d", &m);
                root = deleteKey(root, m);
                printf("\n-----------------------------------------------------------\n");
                printf("\nThe contents of the heap after deleting the node are:\n");
                printTree(root);
                printf("\n-----------------------------------------------------------\n");
            break;

            case 3:
                printf("\nEnter the key to be reduced: ");
                scanf("%d",&m);
                printf("Enter the new key value: ");
                scanf("%d",&l);
                decreaseKeyBHeap(root, m, l);
                printf("\n-----------------------------------------------------------\n");
                printTree(root);
                printf("\n-----------------------------------------------------------\n");
            break;

            case 4:
                p = extractMinBHeap(root);
                printf("Minimum element is %d",p->val);
            break;

            case 5:
                printf("\n-----------------------------------------------------------\n");
                printTree(root);
                printf("\n-----------------------------------------------------------\n");
            break;

            case 6:
                printf("Exiting...");
            break;

            default:
                printf("Choose a Valid value!");
            break;
        }

        if(choice != 6)
        {
            printf("\nDo you wish continue : (y = 1,n = 0) ");
            scanf("%d", &ans);
        }
        else
        {
            ans = 0;
        }


    }

    return 0;
}
