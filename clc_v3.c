/*
  Title: Assignment 3
  Name: Madison Gosselin
  Date: 11/30/22
*/

// include needed libraries
#include <math.h>
#include <stdio.h>

char userInput(){

  //create variables 
  char input;
  int flag = 0;
  
  printf("Please select your option ( B , U , A , V, E )\n");  // print the options again

  while(!flag){
    if(scanf(" %c", &input)){ 
      flag = 1; //set flag to indicate valid input
    }else{
      printf("Invalid input, please try again\n");  // print invalid input
      while (getchar() != '\n'); // flush new line
    }
  } //end while that loops until valid input
  return input; //retunr input
  
} // end user input

double binary(double num1, char operType, double num2, int advanced) {
  // define variables
  int flag = 0, flag1 = 0;
  double ans;

  if(!advanced){
    while (!flag1) {
      // prompt user to input num1
      printf("Please enter the first number: ");
      if (scanf("%lf", &num1)) {
        // prompt user to input operation type and num2
        printf("Please enter the operation (+ , - , * , /. %%, P, X, I): ");
        scanf(" %c", &operType);
        printf("Please enter the second number: ");
        if (scanf("%lf", &num2)) {
          
          // do operation user inputted or print invalid input if invalid operator
          if (operType == '+') {
            ans = num1 + num2;
            flag = 1;
          } else if (operType == '-') {
            ans = num1 - num2;
            flag = 1;
          } else if (operType == '*') {
            ans = num1 * num2;
            flag = 1;
          } else if (operType == '/' && num2 != 0) {
            ans = num1 / num2;
            flag = 1;
          } else if (operType == '%' && num2 != 0) {
            ans = fmod(num1, num2);
            flag = 1;
          } else if (operType == 'P' && num2 != 0) {
            ans = pow(num1, num2);
            flag = 1;
          } else if (operType == 'X' && num2 != 0) {
            ans = fmax(num1, num2);
            flag = 1;
          } else if (operType == 'I' && num2 != 0) {
            ans = fmin(num1, num2);
            flag = 1;
          } else printf("Invalid operator, please try again\n");
          
          flag1 = 1;                      // set flag to true
        }else{
          printf("Invalid input, please try again\n");  // print invalid
          while (getchar() != '\n');  // flush new line
        } //end else
      }else{
        printf("Invalid input, please try again\n");  // print invalid
        while (getchar() != '\n');  // flush new line
      } // end number 2 checker
    } // end while that loops until valid input
  }else{
    flag = 0;
    while(!flag){
      // do operation user inputted or print invalid input if invalid operator
      if (operType == '+') {
        ans = num1 + num2;
        flag = 1;
      } else if (operType == '-') {
        ans = num1 - num2;
        flag = 1;
      } else if (operType == '*') {
        ans = num1 * num2;
        flag = 1;
      } else if (operType == '/' && num2 != 0) {
        ans = num1 / num2;
        flag = 1;
      } else if (operType == '%' && num2 != 0) {
        ans = fmod(num1, num2);
        flag = 1;
      } else if (operType == 'P' && num2 != 0) {
        ans = pow(num1, num2);
        flag = 1;
      } else if (operType == 'X' && num2 != 0) {
        ans = fmax(num1, num2);
        flag = 1;
      } else if (operType == 'I' && num2 != 0) {
        ans = fmin(num1, num2);
        flag = 1;
      }else{
        //get user to re-input operator
        printf("Invalid operator, please try again\n");
        printf("Please enter the operation (+ , - , * , /. %%, P, X, I): ");
        scanf(" %c", &operType);
      } 
    } // end while that loops until valid input   
  } // end advanced checker
  return ans; //return the answer
}  // end binary

double unary(double num1, char operType, int advanced) {
  // define variables
  int flag = 0, flag1 = 0;
  double ans;

  if(!advanced){
    while(!flag1) {
      // prompt user to input num1
      printf("Please enter a number: ");
      if (scanf("%lf", &num1)) {
        // prompt user to input operation type
        printf("Please enter the operation (S, L, E, C, F):");
        if (scanf(" %c", &operType)) {
          
          // do operation user inputted or print invalid input if invalid operator type
          if (operType == 'S' && num1 >= 0) {
            ans = sqrt(num1);
            flag = 1;
          } else if (operType == 'L' && num1 > 0) {
            ans = log10(num1);
            flag = 1;
          } else if (operType == 'E') {
            ans = exp(num1);
            flag = 1;
          } else if (operType == 'C') {
            ans = ceil(num1);
            flag = 1;
          } else if (operType == 'F') {
            ans = floor(num1);
            flag = 1;
          } else printf("Invalid operator, please try again\n");
          
          flag1 = 1;               // set flag to true
        }else{
          printf("Invalid input, please try again\n");  // print invalid}
          while (getchar() != '\n');  // flush new line
        } //end else
      }else{
        printf("Invalid input, please try again\n");  // print invalid
        while (getchar() != '\n');  // flush new line
      } //end else 
    } // end while that loops until valid input
  }else{
    flag1 = 0;
    while(!flag){

      // do operation user inputted or print invalid input if invalid operator type
      if (operType == 'S' && num1 >= 0) {
        ans = sqrt(num1);
        flag = 1;
      } else if (operType == 'L' && num1 > 0) {
        ans = log10(num1);
        flag = 1;
      } else if (operType == 'E') {
        ans = exp(num1);
        flag = 1;
      } else if (operType == 'C') {
        ans = ceil(num1);
        flag = 1;
      } else if (operType == 'F') {
        ans = floor(num1);
        flag = 1;
      } else{
        //get user to re-input operator
        printf("Invalid operator, please try again\n");
        printf("Please enter the operation (S, L, E, C, F): ");
        scanf(" %c", &operType);
      }
    } // end while that loops until valid input
  } //end advanced checker
  return ans; //return the answer
}  // end unary

char varName() {
  // declare varaibles
  char char1;
  int flag = 0;

  while (!flag) {
    // prompt user to input name
    printf("Please enter a variable name between a and e: \n");
    if (scanf(" %c", &char1)) {
      if (char1 >= 'a' && char1 <= 'e')
        flag = 1;  // check if correct input
      else printf("Invalid input, please try again\n");  // print invalid input
    } else printf("Invalid input, please try again\n");  // print invalid input
  }              // end while that loops until valid input
  return char1;  // return name
}  // end variable name

double varValue() {
  // declare variables
  double num;
  int flag = 0;

  while (!flag) {
    // prompt user to enter value
    printf("Please enter variable value: \n");
    if (scanf("%lf", &num))
      flag = 1;  // check if correct input
    else {
      printf("Invalid input, please try again\n");  // print invalid input
      while (getchar() != '\n'); // flush new line
    }

  }  // end while that loops until valid input
  return num;  // return variable value
}  // end variable value

double input(double var[5]) {
  //declare variables
  char char1;
  int flag = 0;
  double num;

  while (!flag) {
    // prompt user to input typeof input
    printf("Input variable name or 'n' for number input: \n");
    if (scanf(" %c", &char1)) {
      switch (char1) {  // assign values of variables to num
        case 'a':
          num = var[0];
          flag = 1;
          break;
        case 'b':
          num = var[1];
          flag = 1;
          break;
        case 'c':
          num = var[2];
          flag = 1;
          break;
        case 'd':
          num = var[3];
          flag = 1;
          break;
        case 'e':
          num = var[4];
          flag = 1;
          break;
        case 'n':

          // prompt user for number
          printf("Please input a number: \n");
          if (scanf("%lf", &num))
            flag = 1;
          else {
            printf("Invalid input, please try again\n");  // print invalid input
            while (getchar() != '\n');  // flush new line
          }
          break;
        default:
          printf("Invalid input, please try again\n");  // print invalid input
      }  // end switch that assigns variable values or gets 1st number from user
    }    // end variable name checker
  }      // end while that loops until valid inputs
  return num;  // return number
}  // end input

void advanced(double var[5]) {
  // declare variables
  int flag = 0;
  char type;
  double num1, num2;

  while (!flag) {
    printf("Please input calculation type (B, U, E): ");
    if (scanf(" %c", &type)) {
      switch (type) {
        case 'B':

          // prompt user for number 1 and call input() to get wanted
          // number/variable
          printf("Number 1: ");
          num1 = input(var);

          // prompt user for operation type
          printf("Please enter the operation (+ , - , * , /. %%, P, X, I): ");
          scanf(" %c", &type);

          // prompt user for numer 2 and call input() to get wanted
          // numer/variable
          printf("Number 2: ");
          num2 = input(var);

          // send wanted variables to binary function
          printf("%lf\n", binary(num1, type, num2, 1));
          flag = 1;

          break;
        case 'U':

          // use input function to get wanted number/variable
          num1 = input(var);

          // prompt user to input operator type
          printf("Please enter the operation (S, L, E, C, F): ");
          scanf(" %c", &type);

          // send wanted variables to unary function
          printf("%lf\n", unary(num1, type, 1));
          flag = 1;

          break;
        case 'E':
          // send user back to main menu
          flag = 1;
          break;
        default:
          printf("Invalid input, please try again\n");  // invalid input

      }  // end switch that does specified calculation type
    }    // end if that checks char
  }      // end while that loops until valid input
}  // end advanced

void exitE(){
  printf("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");  // print a goodbye message
} //end exit

int main(void) {
  // define variables
  int flag = 0;
  double num1, num2, var[5];
  char calcType, operType;

  // print the introduction
  printf("Welcome to my Command-Line Calculator (CLC)\n");
  printf("Developer: Madison Gosselin\n");
  printf("Version 1\n");
  printf("Development Date: 11/18/22\n");
  printf("-------------------------------------------\n\n");

  // print the operation options
  printf("Select one of the following items: \n");
  printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
  printf("V) - Define variables and assign them values.\n");
  printf("E) - Exit.\n");

  while (calcType != 'E') {

    calcType = userInput();
    switch (calcType) {
      case 'B':  // call binary function

        printf("%lf\n", binary(num1, operType, num2, 0)); //print the reuslt from the binary function

        break;
      case 'U':

        printf("%lf\n", unary(num1, operType, 0)); //print the result from the unary function

        break;
      case 'V':

        switch (varName()) {
          // input value into corresponding array slot (a=1, b=2, c=3, d=4, e=5)
          case 'a':
            var[0] = varValue();
            break;
          case 'b':
            var[1] = varValue();
            break;
          case 'c':
            var[2] = varValue();
            break;
          case 'd':
            var[3] = varValue();
            break;
          case 'e':
            var[4] = varValue();
            break;

        }  // end switch that inputs variable values into an array

        break;
      case 'A':

        advanced(var);  // call advanced function

        break;
      case 'E':

        exitE(); //call exit function 
        break;
      default:  // print that it isnt a calcType that can be used and prompt to re-enter
        printf("Sorry, at this time I don't have enough knowledge to serve you in this category.\n");
        printf("Please select your option ( B , U , A , V, E )\n");  // print the options again

    }  // end switch that checks input
  }    // end while that loops while using calculator
}  // end main