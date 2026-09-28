#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include "calc.h"

int main(int argc , char *argv[]){

    if(argc != 4){
        return 1;
    }
    // num1 and num2 signs;
    int n1_sign =0, n2_sign=0;
    if(argv[1][0] == '-' ){
        n1_sign = 1;
        
    }
    if(argv[3][0] == '-'){
        n2_sign =1;
    }
    // Validating CLA ;
    char *end;
    errno = 0;
    long number1 = strtol(argv[1],&end,10);
    if(end == argv[1] || *end != '\0' || errno == ERANGE ){
        return 1;
    }
    errno =0;
    long number2 = strtol(argv[3],&end,10);
    if(end == argv[3] || *end != '\0' || errno == ERANGE ){
        return 1;
    }
    
    // creating list from args
    Node *head1  = NULL;
    Node *tail1 = NULL;
    create_list(&head1,&tail1,argv[1]);

    Node *head2  = NULL;
    Node *tail2 = NULL;
    create_list(&head2,&tail2,argv[3]);

    Node_res *res_h= NULL;
    Node_res *res_t = NULL;

    switch(*argv[2]){
        case '+' : 
        if(n1_sign == 0 && n2_sign ==0 ){
            addition(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,0); 
        }
        if(n1_sign == 1 && n2_sign ==1){
            addition(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,1);
        }

        if(n1_sign == 0 && n2_sign == 1){

            if(abs(number1) > abs(number2)){
                subtraction(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,0);
            }
            else if(abs(number2) > abs(number1)){
                subtraction(&head2,&tail2,&head1,&tail1,n2_sign,n1_sign,&res_h,&res_t,1);
            }
            else if(abs(number2) == abs(number1)){
                insert(&res_h,&res_t,0);
            }
        }
        if(n1_sign == 1 && n2_sign == 0){

            if(abs(number1) > abs(number2)){
                subtraction(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,1);
            }
            else if(abs(number2) > abs(number1)){
                subtraction(&head2,&tail2,&head1,&tail1,n2_sign,n1_sign,&res_h,&res_t,0);
            }
            else if(abs(number2) == abs(number1)){
                insert(&res_h,&res_t,0);
            }
        }
        break;


        case '-' : if(n1_sign ==0 && n2_sign == 1){
            addition(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,0);
        }

        if(n1_sign ==1 && n2_sign == 0){
            addition(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,1);
        }
        if(n1_sign == 1 && n2_sign == 1){

            if(abs(number1) > abs(number2)){
                subtraction(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,1);
            }
            else if(abs(number2) > abs(number1)){
                subtraction(&head2,&tail2,&head1,&tail1,n2_sign,n1_sign,&res_h,&res_t,0);
            }
            else if(abs(number2) == abs(number1)){
                insert(&res_h,&res_t,0);
            }
        }
        if(n1_sign == 0 && n2_sign == 0){
            if(number1 > number2){
                subtraction(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,0);
            }
            else if(number2 > number1){
                subtraction(&head2,&tail2,&head1,&tail1,n2_sign,n1_sign,&res_h,&res_t,1);
            }
            else if(abs(number2) == abs(number1)){
                insert(&res_h,&res_t,0);
            }
        }

        break ;

        case 'x' : if((n1_sign == 0 && n2_sign ==0) || (n1_sign == 1 && n2_sign == 1)){
            multiplication(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,0);
        }
        else if((n1_sign == 0 && n2_sign ==1) || (n1_sign == 1 && n2_sign == 0)){
            multiplication(&head1,&tail1,&head2,&tail2,n1_sign,n2_sign,&res_h,&res_t,1);
        }

        break;
        
        case '/' : 
        if(abs(number1)>abs(number2)){
            if((n1_sign == 0 && n2_sign ==0) || (n1_sign == 1 && n2_sign == 1)){
                division(abs(number1),abs(number2),&res_h,&res_t,0);
            }
            else if((n1_sign == 0 && n2_sign ==1) || (n1_sign == 1 && n2_sign == 0)){
                division(abs(number1),abs(number2),&res_h,&res_t,1);
            }
        }
        else{
            insert(&res_h,&res_t,0);
        }

        break;
        
        

    }
    Node_res *temp = res_h;
    while(temp != NULL){
        printf("%c",temp->number);
        temp = temp->next;
    }

    return 0;
}