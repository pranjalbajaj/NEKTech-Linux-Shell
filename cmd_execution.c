/*
 * cmd_execution.c - Linux Shell 
 *
 * Copyright (C) NEK Tech 2013
 * Developers V1.0:  	Pallavi Gadge
 *
 * Developers V2.0:     Jitendra Khasdev    
 * run_cmd is renamed as nektech_run_cmd()
 *
 * Author and Architect: Pankaj Saraf
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms and conditions of NEK Tech.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY` WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include "nektech_shell.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/*
 *NEKTech Research Labs
 *
 *Function name : nektech_run_cmd()
 *Description   : This fuction forks a new process and exec() it with the 
 *                respective binaries provided in the arguments.
 *Developer     : Pallavi Gadge
 *		: jitendra khasdev
 */
void nektech_run_cmd(char *argv[]) 
{
pid_t child_pid;

   child_pid=fork();

   if(child_pid<0){
      printf("SOME ERROR HAPPENED IN FORK\n");
      exit(2);
   }else if(child_pid==0){
         if(execvp(argv[0],argv)<0)
         switch(errno){
            case ENOENT:
               printf("COMMAND OR FILENAME NOT FOUND\n");
               break;
            case EACCES:
               printf("YOU DO NOT HAVE RIGHT TO ACCESS\n");
               break;
            default:
              printf("SOME ERROR HAPPENED IN EXEC\n");
        }
         exit(3);                           
      }else                                                                                                                                
         wait(NULL);                                                                                                            
                                                                                                                                
}
