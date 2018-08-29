#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct data
    {
    char date[10];
    int id;
    float value;
    char name[20];		
    char nodeNumber[20];
    char nodeId[40];
    char referenceId[20];
    char childreferenceNoded[20];
    char genesisReferenceId[20];
    };
    struct node* left;
    struct node* right;

};

int isSumProperty(struct node *root,char name[],int id,float value,char name[],char nodeNumber[],char nodeId[],char referenceId[],char childReferenceNode[],char genesis[])
{
  int left_data = 0,  right_data = 0;
  struct node *ptr=root;
  ptr->data->date=name;
  ptr->data->id=id;
  ptr->data->value=value;
  ptr->data->name=name;
  ptr->data->nodeNumber=nodeNumber;
  ptr->data->nodeId=nodeId;
  ptr->data->referenceId=referenceId;
  ptr->data->childReferenceNoded=childReferenceNode;
  ptr->data->genesisReferenceId=genesis; 
  if(ptr == NULL || (ptr->left == NULL && ptr->right == NULL))
    return 1;
  else
  {
    if(ptr->left != NULL)
      left_data = node->left->data;
 
    if(ptr->right != NULL)
      right_data = ptr->right->data;
 
    if((ptr->data <= left_data + right_data) && isSumProperty(ptr->left) && isSumProperty(ptr->right))
      return 1;
    else
      return 0;
  }
}


struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
int main()
{
  struct node *root  = newNode("02/18/2018",1,30.00,"Rahul","1024","02","H012","2134","genesis1");
  root->left         = newNode("03/23/2018",2,17.00,"Rakesh","1044","03","U012","2194","genesis2");
  root->right        = newNode("12/08/2018",3,10.00,"Aman","1027","04","G012","2154","genesis3");
  if(isSumProperty(root))
    printHashedValues(root);
  else
    printf("Not possible");

  getchar();
  return 0;
}
void printHashedValues(struct node * root)
{
    struct node * ptr=root;
    while(ptr!=NULL)
    {
        printf("%s\t%d\t%f\t%s\t%s\t%s\t%s\t%s\t%s",ptr->data->date,ptr->data->id,ptr->data->value,ptr->data->name,ptr->data->nodeNumber,ptr->data->nodeId,ptr->data->referenceNoded,ptr->data->childReferenceId,ptr->data->genesisReferenceId);
       if (ptr->left==NULL && ptr->right==NULL) 
        {
           printf("Successfully printed");
        }
        if (ptr->right==NULL)
        {
           ptr=ptr->left;
        }
        if (ptr->right==NULL)
         ptr=ptr->right;
   }  

}
