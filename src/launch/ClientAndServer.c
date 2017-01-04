/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *  If not, you are juste stupid.
 */

/* 
 * File:   ClientAndServer.c
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 *
 * Created on January 4, 2017, 10:55 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include  <sys/types.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char *argtv[3];
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Welcome in Little Tank Project >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("This project was build by Corentin Morisse & Pierre-Bernard Le Roux\n\n");
    printf("This program give facility to launch both a client and a server while regulating the time between them to launch\n");
    printf("Closing the client will close the Server\n");
    printf("The server log (requete) are written in ./bin/Log_Server.txt\n\n");
    printf("If you want to launch only the server, the command is ./bin/server 8080 from the main directory of this project\n");
    printf("If you want to launch only one client, the command is ./bin/run from the main directory of this project\n");
    printf("Beware that if a server is not running, the client launch will fail\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
            
    
    pid_t pid = fork();

    if (pid == 0)
    {
        // child process
        // Will be kill when the client is stopped
        
        //the standart output go to Log_engineServer.txt
        int fd = open("./bin/Log_engineServer.txt", O_WRONLY|O_TRUNC|O_CREAT, 0644);
        if (fd < 0) { perror("open"); abort(); }
        if (dup2(fd, 1) < 0) { perror("dup2"); abort(); }
        close(fd);
        //the err output go to Log_Server.txt
        int fderr = open("./bin/Log_Server.txt", O_WRONLY|O_TRUNC|O_CREAT, 0644);
        if (fderr < 0) { perror("open"); abort(); }
        if (dup2(fderr, 2) < 0) { perror("dup2"); abort(); }
        close(fderr);
        argtv[0] = "./bin/server";
        argtv[1] = "8080";
        argtv[2] = NULL;
        execvp("./bin/server",argtv);
        
    }
    else if (pid > 0)
    {
        // parent process
        sleep(1);//wait the server
        argtv[0] = "./bin/run";
        argtv[1] = NULL;
        execvp("./bin/run",argtv);
    }
    else
    {
        // fork failed
        printf("fork failed\n");
        return 1;
    }
    
    return (EXIT_SUCCESS);
}

