#include <iostream>
#include <sstream>

using namespace std;

void input();
double operation (double numb1, double numb2, char oper);

int main () {
   cout<<"********************** WELCOME TO THE SIMPLE CALCULATOR **********************\n";
   //calling the input function
   input();
   return 0;
}

double operation (double numb1, double numb2, char oper) {
   //creating a variable for the result
   double result = 0;
   
   //switch cases for selection 
   switch(oper){
      //addition case
      case ('+'):
         result = numb1 + numb2;
         break;
      //substraction case
      case('-'):
         result = numb1 - numb2;
         break;
      //multiplication case
      case('*'):
         result = numb1 * numb2;
         break;
      //division case
      case('/'):
         //checking if the denominator is equal zero or not
         while(numb2 == 0){
            cout<<"division by zero , please enter a new number as denominator\n";
            //having a new input
            cin>>numb2;}
         result = numb1 / numb2;
   }
   //printing the numbers and the operator
   cout<<endl<<numb1<<" "<<oper<<" "<<numb2<<" = ";
   //returning the result value
   return result;
}

void input (){
   //creating variables for the inputs and the result
   double number1 = 0, number2 = 0, result = 0;
   //creating a character variable for the oprator 
   char operators;
   
   cout<<"\nPlease enter the first number\n";
   //reading the first input from the user
   cin>>number1;
   //if the user enters innvalid input 
   while(cin.fail()){
      cout<<"Enter valid input !\nPlease enter a number\n";
      //clear the cin object
      cin.clear();
      //skip to the new input
      cin.ignore(10000, '\n');
      cin>>number1;
   }

   
   cout<<"\nPlease enter the operator \nIt should be one of these operators + - * / \n";
   //reading the operator from the user 
   cin>>operators;
   //if the user enters innvalid input 
   bool op = operators != '+' &&  operators != '-' &&  operators != '*' &&  operators != '/';
   while(isdigit(operators) || op){
      cout<<"Enter valid input !\nIt should be one of these operators + - * / \n";
      //clear the cin object
      cin.clear();
      //skip to the new input
      cin.ignore(10000, '\n');
      cin>>operators;
      op = operators != '+' &&  operators != '-' &&  operators != '*' &&  operators != '/';
   }
   
   cout<<"\nPlease enter the second number\n";
   //reading the second input from the user
   cin>>number2;
   //if the user enters innvalid input 
   while(cin.fail()){
      cout<<"Enter valid input !\nPlease enter a number\n";
      //clear the cin object
      cin.clear();
      //skip to the new input
      cin.ignore(10000, '\n');
      cin>>number2;
   }
   
   //calling the operation function and store the value in the variable result
   result = operation (number1, number2, operators);
   
   //printing the result
   cout<<result<<endl;
}
