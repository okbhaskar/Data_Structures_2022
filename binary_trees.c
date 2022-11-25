

/*INVARIANT- everything to the left is smaller, everything to the right is larger*/.

struct nodeType{
    int val;
    struct nodeType * left; //left child - SMALLER
    struct nodeType * right; //right child - LARGER
};
//look at the node; if value is smaller, flow down to the left. There may be 100 more nodes 
//downwards, but supposed to look at only one node at a time.

typedef struct nodeType * NodeAddress; //new datatype

//BINARY SEARCH  (ASSUME TREE HAS ALREADY BEEN CREATED)

/*EXAMPLE
4, LEFT -> 2; RIGHT-> 7

2, LEFT-> 1, RIGHT -> 3

7 LEFT-> 5, RIGHT -> 9

1,3,5,9-> LEFT AND RIGHT NULL

EVERYTHING TO THE LEFT OF 4 IS SMALLER THAN 4 AND EVERYTHING TO THE RIGHT OF 4 IS GREATER THAN 4.
*/
NodeAddress createnode(int data){
    NodeAddress newnode = (NodeAddress)malloc(sizeof(sturcut nodeType));

    newnode->val = data;
    newnode->left= NULL;
    newnode->right= NULL;
    return NULL;   
}

//creating BST from a sorted array.

NodeAddress bst_from_sorted_array(int array[], int start, int end){

    if (start>end){return NULL;}

    //make middle element as main root.
    int mid = (start+end)/2;
    NodeAddress root = createnode(array[mid]);
    root->left=bst_from_sorted_array(array, start, mid-1); //array is sorted already, therefore all elemetnts before mid are less than arrau[mid] or root
    root->right=bst_from_sorted_array(array, mid+1, end);
    return root;
}


NodeAddress search1(NodeAddress root, int val ){
    if (root==NULL)       {return NULL;}
    if (val < root->val)  {return search1(root->left, val);}
    else if(val>root->val){return search1(root->right, int val);}
    else                  {return root;} //if not greater and not smaller than value is the root->val itself
}

NodeAddress insert(NodeAddress root, int val ){
    if (root==NULL)       {return createNode(val);} //just creates a node with val and left right child are null
    if (val < root->val)  {root->left = insert(root->left, val);}
    else if(val>root->val){root->right =  insert(root->right, int val);}
    
    return root;

}

NodeAddress insert2(NodeAddress root, int val ){
    if (root==NULL)       {return createNode(val);} //just creates a node with val and left right child are null
   
    if (val < root->val){

        if (root->left){return insert2(root2->left, val);}
        else {root->left} = createNode(val);
        return root->left;
    }
    
    else if(val>root->val){

        if (root->right){return insert2(root2->right, val);}
        else {root->right} = createNode(val);
        return root->right;
    }
    
    return root;

}

void inorder(NodeAddress root){
    if (root->left){inorder(root->left);}

    if (root) {printf(" %s ", root->val);} //ultimately, just printing roots. If not root we move to right or left untul theres nothing left at right or left, in that case we jsut print the roort.
    
    if(root->right){inorder(root->right);}

}