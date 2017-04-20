// file: TwoPipesTwoChildren.cpp
// author: Jonathan Creech
// date: 4/3/17
// purpose: CS3376
// description: This program executes "ls -ltr | grep 3376 | wc -l", by dividing the two
// commands among the two child and parent processes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv){
  int status;
  int pid1, pid2;

  char *cat_args[] = {"ls", "-ltr", NULL};
  char *grep_args[] = {"grep", "3376", NULL};
  char *wc_args[] = {"wc", "-l", NULL};

  //create two pipes to send the output of "ls" process to "grep" process, and the output
  //of "grep" process to "wc" process
  int pipe1[2];
  int pipe2[2];
  pipe(pipe1);
  pipe(pipe2);

  //fork the first child (to execute cat)
  if(!(pid1 = fork())){
  	//replace cat's stdout with write part of 1st pipe
	dup2(pipe1[1], 1);

	//close all pipes (very important), end we're using was safely copied
	close(pipe1[0]);
	close(pipe1[1]);

	//execute the ls command with arguments
	execvp(*cat_args, cat_args);
	exit(0);
  }
  else if(!(pid2 = fork())){
  	//make sure pipe1's write end is closed
  	close(pipe1[1]);

  	//replace grep's stdin with read end of 1st pipe
	dup2(pipe1[0], 0);
	
	//close pipe1's read and pipe2's read
	close(pipe1[0]);
	close(pipe2[0]);
	
	//replace grep's stdout with pipe2's write
	dup2(pipe2[1],1);

	//close pipe2's write after we are done using it
	close(pipe2[1]);

	//execute the grep command with arguments
	execvp(*grep_args, grep_args);
  }
  else{
  	//close pipe1's read and write, close pipe2's write
  	close(pipe1[1]);
	close(pipe1[0]);
	close(pipe2[1]);

	//replace wc's stdin with pipe2's read
	dup2(pipe2[0], 0);

	//close pipe2's read
	close(pipe2[0]);

	//execute the wc command with arguments
	execvp(*wc_args, wc_args);
  }
  //closes pipe2's read and write
  close(pipe2[1]);
  close(pipe2[0]);
  return(0);
}
