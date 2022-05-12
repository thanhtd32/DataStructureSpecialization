/*
Author: TRAN DUY THANH (thanhtd@uel.edu.vn)
Student code: 20207144
Professor:Kil-Woong Jang (jangkw@kmou.ac.kr)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_NAME 256
#define MAX_SIZE_PHONE 14
/*
The structure of a Contact
name is contact name
phone is phone number
*/
typedef struct Contact
{
    char name[MAX_SIZE_NAME];
    char phone[MAX_SIZE_PHONE];
}Contact;
/*
The TreeNode for Binary Tree
Key is a contact
and left, right pointer of the TreeNode
*/
typedef struct TreeNode {
    Contact * key;
    struct TreeNode *left, *right;
} TreeNode;
/*
This function use to create a new Contact
name and phone are the inputting parameters
*/
Contact *new_contact(char *name,char *phone)
{
    Contact *contact=(Contact *)malloc(sizeof(Contact));
    strcpy(contact->name,name);
    strcpy(contact->phone,phone);
    return contact;
}
/*
This function use to search a contact from the name
if not found the name, the function will return null
and if found the name, the function will return the TreeNode
we will compare ignore case string
this function is recursive
*/
TreeNode *search(TreeNode *node, char *name)
{
    if ( node == NULL ) return NULL;
    int ret=strcmpi(name,node->key->name);
    if ( ret==0)
        return node; 
    else if ( ret<0)
        return search(node->left, name); 
    else
        return search(node->right, name); 
}
/*
This function use to search a contact from the name
if not found the name, the function will return null
and if found the name, the function will return the TreeNode
we will compare ignore case string
this function is iterator
*/
TreeNode *search_iterator(TreeNode *node, char *name) 
{ 
    while(node != NULL)
    { 
        int ret=strcmpi(name,node->key->name);
        if( ret==0 ) 
            return node; 
        else if( ret < 0) 
            node = node->left; 
        else 
            node = node->right; 
    } 
    return NULL;  
} 
/*
This function use to create a new TreeNode
the key is a contact
*/
TreeNode * new_node(Contact *contact)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = contact;
    temp->left = temp->right = NULL;
    return temp;
}
/*
This function use to insert a new node in TreeNode with
Binary Tree format
*/
TreeNode * insert_node(TreeNode * node, Contact * contact)
{
    if (node == NULL) return new_node(contact);
    int ret=strcmpi(contact->name,node->key->name);
    if (ret<0)
        node->left = insert_node(node->left, contact);
    else if (ret>0)
        node->right = insert_node(node->right, contact);
    return node;
}
/*
 This function use to find the leftmost terminal node
*/
TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;    
    while (current->left != NULL)
        current = current->left;
    return current;
}
/*
This function use to delete a contact from the BinaryTree
name is contact name that we want to delete
*/
TreeNode * delete_node(TreeNode * root, char *name)
{
    if (root == NULL) return root;
    int ret=strcmpi(name,root->key->name);
    // If the name is less than the root, it is in the left subtree.
    if (ret<0)
        root->left = delete_node(root->left, name);
    // If the name is greater than the root, it is in the right subtree.
    else if (ret>0)
        root->right = delete_node(root->right, name);
    // If the name is the same as the root, just delete this node
    else 
    {
        // first or second case
        if (root->left == NULL) 
        {
            TreeNode * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        // third case
        TreeNode * temp = min_value_node(root->right);
        // Copies the successor node when traversing mid-foreign.
        root->key = temp->key;
        // Deleting successor nodes during traversal.
        root->right = delete_node(root->right, temp->key->name);
    }
    return root;
}
/*
This function use to print the contact information
*/
void print_contact(Contact *contact)
{
    printf("%s\t%s\n",contact->name,contact->phone);
}
/*
This function use to print all contact in dictionary
*/
void print_all_contact( TreeNode *root ){
    if ( root ){
        // left subtree traversal
        print_all_contact( root->left ); 
        // print the contact information
        print_contact(root->key);
        // traverse right subtree
        print_all_contact( root->right ); 
    }
}
/*
This function use to allow user enter string 
*/
char * input_string(int size)
{
    char *s = malloc(size);
    fgets(s, size, stdin);

    // Remove trailing newline, if there.
    if ((strlen(s) > 0) && (s[strlen (s) - 1] == '\n'))
        s[strlen (s) - 1] = '\0';
    return s;        
}
/*
This function use to input information for a contact
it reuse the input_string and new_contact function 
*/
Contact *input_contact()
{
    printf("Name of friend:");
    char *name=input_string(MAX_SIZE_NAME);    
    printf("Phone Number:");
    char *phone=input_string(MAX_SIZE_PHONE);    
    Contact *contact= new_contact(name,phone);
    return contact;
}
/*
The main function to use whole the program for Contact application
I create a while loop with 5 option:
-Insert(i)
-Search(s)
-Delete(d)
-View all(a)
-Exit(e)
*/
int main(int argc, char const *argv[])
{
    //Create a root of binary tree
    TreeNode * root = NULL;
    //call while loop for using the Contact application
    while (1)
    {
        char c;
        printf("Insert(i)\nSearch(s)\nDelete(d)\nView all(a)\nExit(e)\nYou choose:");
        scanf("%c",&c);
        getchar();
        switch (c)
        {
            case 'i'://input new contact
                {
                    Contact *contact= input_contact();
                    root = insert_node(root, contact);
                }
                break;
            case 's'://search contact
                {
                    printf("Name of friend:");
                    char *name=input_string(MAX_SIZE_NAME);
                    TreeNode *found= search(root,name);
                    if(found!=NULL)
                    {
                        printf("%s's Phone Number: %s\n",found->key->name,found->key->phone);
                    }
                    else
                    {
                        printf("Not found [%s]\n",name);
                    }
                }
                break;
            case 'd'://delete contact
                {
                    printf("Name of friend:");
                    char *name=input_string(MAX_SIZE_NAME);
                    TreeNode *found= delete_node(root,name);
                    if(found!=NULL)
                    {
                        printf("Delete contact [%s] successfully\n",found->key->name);
                    }
                    else
                    {
                        printf("Not found [%s]\n",name);
                    }
                }
                break;
            case 'a'://print all contacts
                {
                    printf("Contact name\tPhone number\n");
                    print_all_contact(root);
                }
                break;
            case 'e'://exit application
                printf("Thank you for your using this software!\n");
                exit(0);
                break;
            break;
            default://notify the error when input choosing is not matching
                printf("Please enter [i,s,d,a,e]\n");
                break;
        }
    }    
    return 0;
}
