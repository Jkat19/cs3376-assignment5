// file: DynPipe.cpp
// author: Jonathan Creech
// date: 4/3/17
// purpose: CS3376
// description: This program creates a dynamic pipe that uses the arguments passed to 
// execute piped commands

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char **argv){

  if(argc < 3 || argc > 6){
  cout << "Error" << endl;
  exit(1);
  }

  int status;
  int wordCount;
  int pid1, pid2, pid3, pid4, pid5;
  string temp = " ";

  //create four pipes to send the output of one pipe to the next
  int pipe1[2];
  int pipe2[2];
  int pipe3[2];
  int pipe4[2];
  //check for 2 arguments
  if(argc == 3){
  	//cout << argv[0] << endl;
	//cout << argv[1] << endl;
 	//cout << argv[2] << endl;
	
  	pipe(pipe1);
	//first fork for first argument
	if(!(pid1 = fork())){
		temp = argv[1];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg1[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid1 executing" << endl;
		//replace arg1's stdout with write part of 1st pipe
		dup2(pipe1[1], 1);

		//close all pipes (very important), end we're using was safely copied
		close(pipe1[0]);
		close(pipe1[1]);
		//execute the command with arguments
		execvp(*arg1 , arg1);
		exit(0);
	}
	//second fork for second argument
	else if(!(pid2 = fork())){
		temp = argv[2];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg2[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;

  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe1[0], 0);
		
		//close pipe1's read and write
		close(pipe1[0]);
		close(pipe1[1]);
		
		//execute the grep command with arguments
		execvp(*arg2, arg2);
		
	}
	
  }
  //check for 3 arguments
  else if( argc == 4){
  	pipe(pipe1);
	pipe(pipe2);
	//first fork for first argument
	if(!(pid1 = fork())){
		temp = argv[1];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg1[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid1 executing" << endl;
		//replace arg1's stdout with write part of 1st pipe
		dup2(pipe1[1], 1);

		//close all pipes (very important), end we're using was safely copied
		close(pipe1[0]);
		close(pipe1[1]);
		//execute the command with arguments
		execvp(*arg1 , arg1);
		exit(0);
	}
	//second fork for second argument
	else if(!(pid2 = fork())){
		temp = argv[2];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg2[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;
		
		close(pipe1[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe1[0], 0);
		
		//close pipe1's read and write
		close(pipe1[0]);
		close(pipe2[0]);

		dup2(pipe2[1], 1);

		close(pipe2[1]);
		
		//execute the grep command with arguments
		execvp(*arg2, arg2);
		
	}
	else if(!(pid3 = fork())){
		temp = argv[3];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg3[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;

		close(pipe1[1]);
		close(pipe1[0]);
		close(pipe2[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe2[0], 0);
		
		//close pipe1's read and write
		close(pipe2[0]);
		
		//execute the grep command with arguments
		execvp(*arg3, arg3);
	}
	
  }
  else if( argc == 5){
  	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);
	//first fork for first argument
	if(!(pid1 = fork())){
		temp = argv[1];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg1[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid1 executing" << endl;
		//replace arg1's stdout with write part of 1st pipe
		dup2(pipe1[1], 1);

		//close all pipes (very important), end we're using was safely copied
		close(pipe1[0]);
		close(pipe1[1]);
		//execute the command with arguments
		execvp(*arg1 , arg1);
		exit(0);
	}
	//second fork for second argument
	else if(!(pid2 = fork())){
		temp = argv[2];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg2[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;
		
		close(pipe1[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe1[0], 0);
		
		//close pipe1's read and write
		close(pipe1[0]);
		close(pipe2[0]);

		dup2(pipe2[1], 1);

		close(pipe2[1]);
		
		//execute the grep command with arguments
		execvp(*arg2, arg2);
		
	}
	else if(!(pid3 = fork())){
		temp = argv[3];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg3[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;

		close(pipe1[1]);
		close(pipe1[0]);
		close(pipe2[1]);

		dup2(pipe2[0], 0);
		close(pipe2[0]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe3[1], 1);
		
		//close pipe1's read and write
		close(pipe3[1]);
		
		//execute the grep command with arguments
		execvp(*arg3, arg3);
	}
	else if(!(pid4 = fork())){
		temp = argv[4];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg4[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;
		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[1]);
		close(pipe2[0]);
		close(pipe3[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe3[0], 0);
		
		//close pipe1's read and write
		close(pipe3[0]);
		
		//execute the grep command with arguments
		execvp(*arg4, arg4);
	}

  }
 else if( argc == 6){
  	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);
	pipe(pipe4);
	//first fork for first argument
	if(!(pid1 = fork())){
		temp = argv[1];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg1[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid1 executing" << endl;
		//replace arg1's stdout with write part of 1st pipe
		dup2(pipe1[1], 1);

		//close all pipes (very important), end we're using was safely copied
		close(pipe1[0]);
		close(pipe1[1]);
		//execute the command with arguments
		execvp(*arg1 , arg1);
		exit(0);
	}
	//second fork for second argument
	else if(!(pid2 = fork())){
		temp = argv[2];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg2[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;
		
		close(pipe1[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe1[0], 0);
		
		//close pipe1's read and write
		close(pipe1[0]);
		close(pipe2[0]);

		dup2(pipe2[1], 1);

		close(pipe2[1]);
		
		//execute the grep command with arguments
		execvp(*arg2, arg2);
		
	}
	else if(!(pid3 = fork())){
		temp = argv[3];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg3[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;

		close(pipe1[1]);
		close(pipe1[0]);
		close(pipe2[1]);

		dup2(pipe2[0], 0);
		close(pipe2[0]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe3[1], 1);
		
		//close pipe1's read and write
		close(pipe3[1]);
		
		//execute the grep command with arguments
		execvp(*arg3, arg3);
	}
	else if(!(pid4 = fork())){
		temp = argv[4];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg4[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;
		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[1]);
		close(pipe2[0]);
		close(pipe3[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe3[0], 0);
		
		//close pipe1's read and write
		close(pipe3[0]);

		dup2(pipe4[1], 1);
		close(pipe4[1]);
		
		//execute the grep command with arguments
		execvp(*arg4, arg4);
	}
	else if(!(pid5 = fork())){
		temp = argv[5];
		//get the number of words in a string
		for(int i = 0; i < temp.length(); i++){
			if(temp.at(i) == ' '){
				wordCount++;
			}
		}
		wordCount++;
		//create an array of this size
		string *tempArray = new string[wordCount+1];
		//seperate the first arg into an arry of the individual elements
		int j = 0;
		for(int i = 0; i < wordCount; i++){
			for( j ; j < temp.length(); j++){
				if(temp.at(j) != ' '){
					tempArray[i] += temp.at(j);
				}
				else{
					j++;
					break;
				}
			}
		}
		wordCount = 0;
		char *  word1 = new char[tempArray[0].length() + 1];
		strcpy(word1, tempArray[0].c_str());
		char * word2 = new char[tempArray[1].length() + 1];
		strcpy(word2, tempArray[1].c_str());
	        char * arg5[] = {word1, word2, NULL};
		//cout << tempArray[0] << endl;
		//cout << tempArray[1] << endl;
		//cout << tempArray[2] << endl;
		//cout << "pid2 executing" << endl;
		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[1]);
		close(pipe2[0]);
		close(pipe3[1]);
		close(pipe3[0]);
		close(pipe4[1]);
  		//replace grep's stdin with read end of 1st pipe
		dup2(pipe4[0], 0);
		
		//close pipe1's read and write
		close(pipe4[0]);
		
		//execute the grep command with arguments
		execvp(*arg5, arg5);
	}

  }

  return(0);
}
