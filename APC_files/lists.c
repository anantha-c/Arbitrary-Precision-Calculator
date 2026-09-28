#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include "calc.h"

void create_list(Node **head,Node **tail,char *num){

    int i=0;
    if(num[i] == '+' || num[i] == '-'){
        i++;
    }

    while(num[i]!= '\0'){
        
        if(!isdigit((unsigned char)num[i])){
            return ;
        }
        int number = num[i] - '0';
        
        Node *newnode = malloc(sizeof(*newnode));
        if(newnode == NULL){
            return ;
        }
        newnode->number = number;
        newnode->next = NULL;
        newnode->prev = *tail;

        if(*head == NULL && *tail == NULL){
            *head = newnode;
            *tail = newnode;
        }
        else{
            
            (*tail)->next = newnode;
            
            *tail = newnode;

        }

        i++;
    }
    
}
void insert_int(Node **temp_h,Node **temp_t,int num){

    Node *newnode = malloc(sizeof(*newnode));
    if(newnode == NULL){
        return ;
    }
    newnode->number = num;
    newnode->next= *temp_h;
    newnode->prev = NULL;
    if(*temp_h == NULL && *temp_t == NULL){
        *temp_h = newnode;
        *temp_t = newnode;
    }
    else{
        (*temp_h)->prev = newnode;
        *temp_h = newnode; 
    }
}
void insert(Node_res **res_h,Node_res **res_t,int num){

    Node_res *newnode = malloc(sizeof(*newnode));
    if(newnode == NULL){
        return ;
    }
    newnode->number = (char)('0' + num);
    newnode->next= *res_h;
    newnode->prev = NULL;
    if(*res_h == NULL && *res_t == NULL){
        *res_h = newnode;
        *res_t = newnode;
    }
    else{
        (*res_h)->prev = newnode;
        *res_h = newnode; 
    }
}


void insert_tail(Node **head1,Node **tail,int num){

    Node *newnode = malloc(sizeof(*newnode));
    if(newnode==NULL){
        return;
    }
    newnode->number =num;
    newnode->prev = (*tail);
    newnode->next = NULL;

    (*tail)->next = newnode;

    *tail = newnode;


}