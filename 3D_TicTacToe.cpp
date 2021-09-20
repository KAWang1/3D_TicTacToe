/*
Name: Kevin Wang
Student ID: 5350662
Lab #10
Class: CSE 130-05
Date: 11/20/2020
Description: This program creates a 3-D tic tac toe game.
*/

#include<stdio.h> //input and output

#include<iostream> //input  output stream

#include <string> //string functions

#include <time.h> //time functions

#include <stdlib.h> //standard library

using namespace std;

//declare board
int board1[3][3];
int board2[3][3];
int board3[3][3];

void fill() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board1[i][j] = 0;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board2[i][j] = 0;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board3[i][j] = 0;
    }
  }
}

int n = 0;

//win conditions for both players
int win() {
  for (int i = 0; i < 3; i++) {
    if (board1[i][0] == board1[i][1] && board1[i][1] == board1[i][2]) {
      if (board1[i][0] != 0) {
        n = board1[i][0];
        return 1;
      }
    }
    if (board1[0][i] == board1[1][i] && board1[1][i] == board1[2][i]) {
      if (board1[0][i] != 0) {
        n = board1[0][i];
        return 1;
      }
    }
    if (board2[i][0] == board2[i][1] && board2[i][1] == board2[i][2]) {
      if (board2[i][0] != 0) {
        n = board2[i][0];
        return 1;
      }
    }
    if (board2[0][i] == board2[1][i] && board2[1][i] == board2[2][i]) {
      if (board2[0][i] != 0) {
        n = board2[0][i];
        return 1;
      }
    }
    if (board3[i][0] == board3[i][1] && board3[i][1] == board3[i][2]) {
      if (board3[i][0] != 0) {
        n = board3[i][0];
        return 1;
      }
    }
    if (board3[0][i] == board3[1][i] && board3[1][i] == board3[2][i]) {
      if (board3[0][i] != 0) {
        n = board3[0][i];
        return 1;
      }
    }
  }
  if (board1[0][0] == board1[1][1] && board1[1][1] == board1[2][2]) {
    if (board1[0][0] != 0) {
      n = board1[0][0];
      return 1;
    }
  }
  if (board1[0][2] == board1[1][1] && board1[1][1] == board1[2][0]) {
    if (board1[0][2] != 0) {
      n = board1[0][2];
      return 1;
    }
  }
  
  if (board2[0][0] == board2[1][1] && board2[1][1] == board2[2][2]) {
    if (board2[0][0] != 0) {
      n = board2[0][0];
      return 1;
    }
  }
  if (board2[0][2] == board2[1][1] && board2[1][1] == board2[2][0]) {
    if (board2[0][2] != 0) {
      n = board2[0][2];
      return 1;
    }
  }
  if (board3[0][0] == board3[1][1] && board3[1][1] == board3[2][2]) {
    if (board3[0][0] != 0) {
      n = board3[0][0];
      return 1;
    }
  }
  if (board3[0][2] == board3[1][1] && board3[1][1] == board3[2][0]) {
    if (board3[0][2] != 0) {
      n = board3[0][2];
      return 1;
    }
  }
  
  if (board1[0][0] == board2[1][1] && board2[1][1] == board3[2][2]) {
    if (board1[0][0] != 0) {
      n = board1[0][0];
      return 1;
    }
  }
  if (board1[0][2] == board2[1][1] && board2[1][1] == board3[2][0]) {
    if (board1[0][2] != 0) {
      n = board1[0][2];
      return 1;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
    	
    	if (board1[i][j] == board2[i][j] && board2[i][j] == board3[i][j]) {
    if (board1[i][j] != 0) {
      n = board1[i][j];
      return 1;
    }
  }
    }
  }
  return 0;
}

//player either x or o
void print_table(int i) {
  if (i == 0) std::cout << " ";
  if (i == 1) std::cout << "X";
  if (i == 2) std::cout << "O";
}
//prints out board
void printboard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      print_table(board1[i][j]);
      if (j < 2) printf("|");
    }
    printf("\n");
  }
  cout<<endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      print_table(board2[i][j]);
      if (j < 2) printf("|");
    }
    printf("\n");
  }
  cout<<endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      print_table(board3[i][j]);
      if (j < 2) printf("|");
    }
    printf("\n");
  }
}

//turn selector
int turn_sel() {
  srand(time(NULL));
  int r = rand() % 2 + 1;
  return r;
}

int r = turn_sel();

//ai player (randomly select play)
void ai(int XO) {
  int i = rand() % 3;
  int j = rand() % 3;
  int k = rand() % 3;
  int u = 0;
  while (u == 0) {
    if (k == 0 && board1[i][j] == 0) {
      board1[i][j] = XO;
      u = 1;
    }
    if (k == 1 && board2[i][j] == 0) {
      board2[i][j] = XO;
      u = 1;
    }
    if (k == 2 && board3[i][j] == 0) {
      board3[i][j] = XO;
      u = 1;
    }
	else {
      i = rand() % 3;
      j = rand() % 3;
      k = rand() % 3;
    }
  }
  printboard();
  cout<<endl;
}

//player input
void player(int XO) {
  int x = 0;
  int y = 0;
  int z = 0;
  int i = 0;
  printf("Your turn.\n");
  while (i == 0) {
    printf("X Coordinate: ");
    std::cin >> x;
    printf("Y Coordinate: ");
    std::cin >> y;
    printf("Z Coordinate: ");
    std::cin >> z;
	
	if(x>2){
		printf("Try again.\n");
		printboard();
	}
	else if(y>2){
		printf("Try again.\n");
		printboard();
	}
	else if (z>2){
		printf("Try again.\n");
		printboard();
	}
    else if (z == 0 && board1[x][y] == 0) {
      board1[x][y] = XO;
      i++;

    }
    else if (z == 1 && board2[x][y] == 0) {
      board2[x][y] = XO;
      i++;

    }
    else if (z == 2 && board3[x][y] == 0) {
      board3[x][y] = XO;
      i++;

    }
	else {
      printf("Try again.\n");
      printboard();
    }
  }
}

//start game
void play() {
  int x = 0;
  int y = 0;
  if (r == 1) {
    printf("You are X\n");
    printf("Select Your Coordinates: (0,1,2)(0,1,2)(0,1,2)\n");
    player(1);
    if (win() != 1) ai(2);
  } else {
    printf("You are O\n");
    printf("Select Your Coordinates: (0,1,2)(0,1,2)(0,1,2)\n");
    ai(1);
    if (win() != 1) player(2);

  }
}

//main function
int main() {
  fill();
  int i = 0;
  int j = 0;
  while (1) {
    printboard();
    play();
    if (win() == 1) {
      printboard();
      if (r == 1) {
        if (n == 1) {
        printf("Win!\n");
		i++; }
        if (n == 2){
         printf("Lose!\n");
		 j++;
		 }
      } else if (r == 2) {
        if (n == 1){
         printf("Lose!\n");
		 j++;
		 }
        if (n == 2) {
         printf("Win!\n");
		 i++;
		 }
      } else if (n == 0) printf("Draw.\n");
      fill();
      cout<<"Player Score: "<<i<<" AI Score: "<<j<<endl;
    }
  }
  return 0;
}
