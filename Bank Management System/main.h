#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main_exit;

struct date
{
    int month,day,year;
};
struct
 {
	char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
  }add,upd,check,rem,transaction;


void new_acc();
void menu(void);
void edit(void);
void see(void);
void view_list();
void erase(void);
void transact(void);
float calculateInterest(float time, float principalAmount, int rate);
void close_program(void);
