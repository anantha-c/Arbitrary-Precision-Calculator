#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include "calc.h"

void addition(Node **head1,Node **tail1,Node **head2,Node **tail2,int n1_sign,int n2_sign,Node_res **res_h,Node_res **res_t,int res_sign){
    Node *list1 = *tail1;
    Node *list2 = *tail2;
    
        
        int carry = 0;
        int sum;

        while(list1 != NULL || list2 != NULL || carry!=0){
            sum = carry ;
            if(list1 != NULL){
                sum += list1->number;
                list1 = list1->prev;
            }

            if(list2 != NULL){
                sum += list2->number;
                list2 = list2->prev;
            }

            insert(res_h,res_t,(sum%10));

            carry = sum/10;


        }       
    
    if(res_sign == 1){
        char ch = '-';
        Node_res *newnode = malloc(sizeof(*newnode));
        if(newnode == NULL){
            return ;
        }
        newnode->number = ch;
        newnode->prev = NULL;
        newnode->next = *res_h;

        (*res_h)->prev = newnode;
        *res_h = newnode;
    }
    

}

void addition_int(Node **head1,Node **tail1,Node **head2,Node **tail2,Node **res_h,Node **res_t){
    Node *list1 = *tail1;
    Node *list2 = *tail2;
    
        
        int carry = 0;
        int sum;

        while(list1 != NULL || list2 != NULL || carry!=0){
            sum = carry ;
            if(list1 != NULL){
                sum += list1->number;
                list1 = list1->prev;
            }

            if(list2 != NULL){
                sum += list2->number;
                list2 = list2->prev;
            }

            insert_int(res_h,res_t,(sum%10));

            carry = sum/10;


        }       
    
    
    

}

void subtraction(Node **head1,Node **tail1,Node **head2,Node **tail2,int n1_sign,int n2_sign,Node_res **res_h,Node_res **res_t,int res_sign){

    
    Node *list1 = *tail1;
    Node *list2 = *tail2;

    int borrow =0;
    
    while(list1!=NULL){
        int left = list1->number - borrow;
        int right =0;

        if(list2!=NULL){
            right = list2->number;
            list2 = list2->prev;

        }

        if(left < right){
            left += 10;
            borrow = 1;
        }
        else{
            borrow =0;
        }
        
        insert(res_h,res_t, left-right);
        list1 = list1->prev;

    }

    if(res_sign == 1){
        char ch = '-';
        Node_res *newnode = malloc(sizeof(*newnode));
        if(newnode == NULL){
            return ;
        }
        newnode->number = ch;
        newnode->prev = NULL;
        newnode->next = *res_h;

        (*res_h)->prev = newnode;
        *res_h = newnode;
    }

}



void multiplication(Node **head1,Node **tail1,Node **head2,Node **tail2,int n1_sign,int n2_sign,Node_res **res_h,Node_res **res_t,int res_sign){

   
    Node *temp2_head = NULL;
    Node *temp2_tail = NULL;

    

    Node *list1 = *tail1;
    Node *list2 = *tail2;

    int carry =0;
    int mul =0;
    int zeros =0;
    while(list2 != NULL){
        Node *list1 = *tail1;
        carry = 0;
        Node *temp1_head = NULL;
        Node *temp1_tail = NULL;

        Node *final_res_h = NULL;
        Node *final_res_t = NULL;


        while(list1!=NULL){

            mul = carry;

            mul += list1->number * list2->number;

            insert_int(&temp1_head,&temp1_tail,(mul%10));

            carry = mul/10;

            list1 = list1->prev;

        }

        if(carry!=0){
            insert_int(&temp1_head,&temp1_tail,carry);
        }

        for(int i=0;i<zeros;i++){
            insert_tail(&temp1_head,&temp1_tail,0);
        }

        addition_int(&temp1_head,&temp1_tail,&temp2_head,&temp2_tail,&final_res_h,&final_res_t);

        temp2_head = final_res_h;
        temp2_tail = final_res_t;

        zeros++;
        list2 = list2->prev;




    }
    while(temp2_tail!=NULL){
        insert(res_h,res_t,temp2_tail->number);
        temp2_tail= temp2_tail->prev;
    }

    
    if(res_sign == 1){
        char ch = '-';
        Node_res *newnode = malloc(sizeof(*newnode));
        if(newnode == NULL){
            return ;
        }
        newnode->number = ch;
        newnode->prev = NULL;
        newnode->next = *res_h;

        (*res_h)->prev = newnode;
        *res_h = newnode;
    }




}

void division(int num1,int num2,Node_res **res_h,Node_res **res_t,int res_sign){

    

    unsigned int count =0;
    int res = num1;
    while(res>=num2){
        res = res - num2;
        count++;
    }

    if(count == 0){
        insert(res_h,res_t, 0);
    }

    while(count>0){
        insert(res_h,res_t, count % 10);
        count/=10;
    }


    if(res_sign == 1){
        char ch = '-';
        Node_res *newnode = malloc(sizeof(*newnode));
        if(newnode == NULL){
            return ;
        }
        newnode->number = ch;
        newnode->prev = NULL;
        newnode->next = *res_h;

        (*res_h)->prev = newnode;
        *res_h = newnode;
    }



}