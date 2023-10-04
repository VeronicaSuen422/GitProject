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
   char tryagain; // Decide whether the user want to play again

   do {

      // User input
      do {
         fflush(stdin);
         printf("p for Paper\nv for Scissors\ns for Stone\nWhat is your input? ");
         scanf("%c", &user);
      } while (!((user == 'p' || user == 'v') || user == 's'));

      // Generate computer's input
      srand(time(NULL));
      n = rand() % 100;
      if (n < 33) {
         computer = 'p'; // Paper
         printf("Computer input is Paper\n");
      } else if (n >= 33 && n < 66) {
         computer = 'v'; // Scissors
         printf("Computer input is Scissors\n");
      } else {
         computer = 's'; // Stone
         printf("Computer input is Stone\n");
      }

      // Show result
      result = gameplay(user, computer);
      if (result == 'u') {
         printf("User wins!\n");
      } else if (result == 'c') {
         printf("Computer wins!\n");
      } else {
         printf("Draw\n");
      }

      // Ask for Replay
      do {
         fflush(stdin);
         printf("y for Yes\nn for No\nDo you want to play again? ");
         scanf("%s", &tryagain);
      } while (!(tryagain == 'y' || tryagain == 'n'));
      
   } while (tryagain == 'y');

   return 0;
}
