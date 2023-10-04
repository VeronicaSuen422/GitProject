#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char gameplay(char user, char computer) {

   char result = 'd';

   if ((user == 'p' && computer == 's') || (user == 'v' && computer == 'p') || (user == 's' && computer == 'v')) {
      return result = 'u'; // User wins
   } else if ((user == 'p' && computer == 'v') || (user == 'v' && computer == 's') || (user == 's' && computer == 'p')) {
      return result = 'c'; // Computer wins
   } else {
      return result; // Draw
   }
}

int main() {
   
   // Declare variables
   char user; // Store user's input
   char computer; // Store computer's input
   char result; // Store the result
   int n; // Store the random number used for computer's input

   // Generate computer's input
   srand(time(NULL));
   n = rand() % 100;
   if (n < 33) {
      computer = 'p'; // Paper
   } else if (n >= 33 && n < 66) {
      computer = 'v'; // Scissors
   } else {
      computer = 's'; // Stone
   }

   // User input
   printf("p for Paper\nv for Scissors\ns for Stone\nWhat is your input? ");
   scanf("%c", &user);

   // Show result
   result = gameplay(user, computer);
   if (result == 'u') {
      printf("User wins!");
   } else if (result == 'c') {
      printf("Computer wins!");
   } else {
      printf("Draw");
   }

   return 0;
}
