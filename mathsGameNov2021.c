/*

Name: Grace MacDonnell
Date due: 28/11/2021

Program description:
A menu-driven program that simulates a mathematics quiz game.
The user is presented with a menu with 4 option, and is prompted to enter a number based on the options.

Option 1: Chosing the number of questions -- Maximum of 5 questions per play
Option 2: Starting the quiz -- Adding randomly generated numbers from 1 - 10
Option 3: Seeing the correct / incorrect answers from the last round
Option 4: Exiting the program 


*/
// _________________________________

#include <stdio.h>
#include <stdlib.h> // Header file needed for the rand() function
#include <time.h> // Used in srand() function

#define MAXLIMIT 5 // Maximum amount of questions allowed in quiz
#define MINLIMIT 1 // Minimum amount of questions allowed in quiz

int main() 
{
    // ________ VARIABLES _______________

    int loop;
    int i;
    int userOption;
    int userQuestionNo;
    int userAnswer;
    int answer;
    int correctCount;
    int incorrectCount;
    int random1;
    int random2;

    loop = 1;
    // Intialisation of all variables to 0
    i = 0;
    userOption = userQuestionNo = userAnswer = 0;
    correctCount = incorrectCount = 0;
    random1 = random2 = 0;

    // __________ MAIN __________________

    printf("\n      Welcome to the maths quiz!  \n  ");

    // While loop is True / on
    while (loop == 1)
    {
        printf("\n\t  >  MAIN MENU  <\t\t\n");
        printf("-------------------------------------\n"); // 37
        printf("|  1. Enter number of questions     |\n");
        printf("|  2. Start and play quiz\t    |\n");
        printf("|  3. Display correct and incorrect |\n");
        printf("|     answers from last round\t    |\n");
        printf("|  4. ... Exit program\t\t    |\n");
        printf("-------------------------------------\n\n");

        // Gets input from user
        userOption = 0;
        printf("> Option: ");
        

        // ___ Error Check ____
        // Checks if input is character
        // While True
        while(1)
        {
            // 
            scanf("%1d", &userOption);
            // 1 isn't a character so its not seen in the getchar() scan
            // If the character after the 1 is a new line (enter) it exits the loop
            // If not it will keep asking for a menu option
            if(getchar() == '\n')
            {
                break;
            }
            else
            {
                printf("> Invalid option, please try again: ");
            }

        } // End while getchar()

        // Different user options
        switch(userOption)
        {
        // _________  CASE 1 __________
            // Option 1 - No. of Questions
            case 1: 
            {
                printf("\n   ------------------------------\n");
                printf("   | Select number of questions |\n");
                printf("   ------------------------------\n");
                printf("\nHow many questions would you like for this round?");

                // _______ Error check ________
                
                // Checks if number is valid
                do
                {
                    printf("\n> Number of questions (maximium of 5): ");
                    scanf("%d", &userQuestionNo);

                    // Checks if input is integer
                    // Same as menu - will keep asking for integer input
                    while(1)
                    {
                        if(getchar() == '\n')
                        {
                            //printf("%c", getchar());
                            break;
                        } // End if (getchar())

                        else
                        {
                            printf("\n> Please enter a valid number between 1 - 5: ");
                        } // End else (getchar())

                    } // End while(getchar())

                } // End do

                // While the number is not in the range 1-5
                while(userQuestionNo < MINLIMIT  || userQuestionNo > MAXLIMIT);
            
                printf("\nNumber of questions saved!\n");

                break; 
            } // End case 1

        // _________  CASE 2 __________
            // Option 2 - Start quiz
            case 2:
            {
                // _______ Error check ______

                // Checks if theres a question count logged
                if (userQuestionNo == 0)
                {
                    printf("\n\n ... You haven't entered the number of questions for the quiz!");
                    printf("\nPlease go back and enter a valid number\n");

                    break;
                } // End if(userQuestionNo error check)

                // _____ Quiz start _____
                printf("\n\t---------------\n");
                printf("\t| Start quiz! |\n");
                printf("\t---------------\n");
                
                // Resets counter, correct answer and incorrect answer count before quiz starts
                i = 0;
                correctCount = incorrectCount = 0;

                while (i < userQuestionNo)
                {
                    // ______ Number generation ________
                    // Generates random integers from 0 - 10 (based on system time) and adds them together
                    srand(time(NULL)); 
                    random1 = rand() % 10 + 1;
                    random2 = rand() % 10 + 1;
                    answer = random1 + random2;

                    // _____ Screen display ____________

                    // Displays question to user as +1 because program begins counting at 0
                    printf("\n\nQUESTION %d\n", i + 1);

                    printf("\n%d + %d = ?\n", random1, random2);
                    printf("> Answer: ");
                    scanf("%d", &userAnswer);

                    // Checks if input is integer
                    // Keeps asking for integer only input
                    while(1)
                    {
                        if(getchar() == '\n')
                        {
                            break;
                        }
                        else
                        {
                            printf("> Please enter answer in integer form: ");
                        }
                    }
                    printf("You entered: %d", userAnswer);

                    // _____ User answer paths ________
                    // Correct answer
                    if (userAnswer == answer)
                    {
                        printf("\nCorrect!");
                        correctCount++;
                    } // End if(userAnswer)

                    // Incorrect answer
                    else
                    {
                        printf("\nIncorrect! The answer was %d", answer);
                        incorrectCount++;
                    } // End else(userAnswer)

                    // Counter for loop
                    i++;

                } // End while(userQuestionNo)

                printf("\n\n\t----------------");
                printf("\n\t| END OF QUIZ! |");
                printf("\n\t----------------\n");
                
                break;                
            } // End case 2         

        // _________  CASE 3 __________
            // Option 3: Correct and incorrect answers
            case 3:
            {
                // ____ Error check _______

                // Checks if there is data from last quiz
                if (incorrectCount == 0 && correctCount == 0)
                {
                    printf("\n\n ... You haven't played the quiz yet!");
                    printf("\nGo back and play the quiz to see your score\n");

                    break;
                } // End if(answer count error check)

                printf("\n   -------------------------------\n");
                printf("   | Correct & Incorrect answers |\n");
                printf("   -------------------------------\n");

                printf("\nThese are the answer totals from the last round:");
                printf("\nCorrect answers: %d", correctCount);
                printf("\nIncorrect answers: %d \n", incorrectCount);

                break;
            } // End case 3

            // _________  CASE 4 __________
            // Option 4: Exit program
            case 4:
            {
                printf("\n\t-------------------\n");
                printf("\t| Exiting quiz... |\n");
                printf("\t-------------------\n");

                loop = 0; // Ends program loop

                break; 
            } // End case 4

            // __________ DEFAULT __________
            // Error check for valid input
            default:
            {
                printf("\n Invalid option\n");

                break;
            } // End default         

        } // End switc1h

    } // End while

    return 0;

} // End main