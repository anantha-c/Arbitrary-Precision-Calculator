#ifndef CALCULATOR_H
#define CALCULATOR_H


typedef struct Node{

    int number;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Node_res{

    char number;
    struct Node_res *next;
    struct Node_res *prev;
}Node_res;


void create_list(Node **head,Node **tail,char *num);

void insert_int(Node **temp_h,Node **temp_t,int num);

void insert(Node_res **res_h,Node_res **res_t,int num);

void addition(Node **head1,Node **tail1,Node **head2,Node **tail2,int n1_sign,int n2_sign,Node_res **res_h,Node_res **res_t,int res_sign);

void addition_int(Node **head1,Node **tail1,Node **head2,Node **tail2,Node **res_h,Node **res_t);

void subtraction(Node **head1,Node **tail1,Node **head2,Node **tail2,int n1_sign,int n2_sign,Node_res **res_h,Node_res **res_t,int res_sign);

void insert_tail(Node **head1,Node **tail,int num);

void multiplication(Node **head1,Node **tail1,Node **head2,Node **tail2,int n1_sign,int n2_sign,Node_res **res_h,Node_res **res_t,int res_sign);

void division(int num1,int num2,Node_res **res_h,Node_res **res_t,int res_sign);

#endif