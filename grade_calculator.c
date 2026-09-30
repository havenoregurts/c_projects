/*
  * Author: Josh Fassett
  * Course: CS 1380-601
  * Assignment: Module 3.1
  * Description: Small program that calculates a grade from 3 input scores
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_SCORES_TO_GRAB 3

double calculate_average(int score1, int score2, int score3) {
  return ((double) score1 + (double) score2 + (double) score3) / 3.0;
}

char determine_grade(double average) {
  if (average >= 90) {
    return 'A';
  } else if (average >= 80 && average < 90) {
    return 'B';
  } else if (average >= 70 && average < 80) {
    return 'C';
  } else if (average >= 60 && average < 70) {
    return 'D';
  } else {
    return 'F';
  }
}

void display_result(double average, char grade) {
  printf("With an average of: %.2f, the grade is: %c\n", average, grade);
}

void display_highest_score(int score1, int score2, int score3) {
  int highest = score1;
  if (score2 > highest) {
    highest = score2;
  }
  if (score3 > highest) {
    highest = score3;
  }
  printf("The highest score was: %d\n", highest);
}

int main(void) {
  int scores[NUMBER_OF_SCORES_TO_GRAB] = {};
  int scanf_result, clear_char;
  bool invalid_input;

  for (int i = 0; i < NUMBER_OF_SCORES_TO_GRAB; i++) {
    printf("Enter score #%d: ", i + 1);
    do {
      scanf_result = scanf("%d", &scores[i]);

      if (scanf_result == EOF) {
        fprintf(stderr, "\nInput ended before something valid was entered\n");
        return EXIT_FAILURE;
      } else if (scanf_result != 1) {
        invalid_input = true;
        printf("Not an integer. Try again: ");

        // Clear the invalid input from the buffer to prevent infinite loops
        do {
          clear_char = getchar();
        } while (clear_char != '\n' && clear_char != EOF);
      } else if (scores[i] < 0 || scores[i] > 100) {
        invalid_input = true;
        printf("Scores must be between 0 and 100. Try again: ");
      } else {
        invalid_input = false;
      }
    } while (invalid_input);
  }

  double average = calculate_average(scores[0], scores[1], scores[2]);
  char grade = determine_grade(average);
  display_highest_score(scores[0], scores[1], scores[2]);
  display_result(average, grade);
  return EXIT_SUCCESS;
}
