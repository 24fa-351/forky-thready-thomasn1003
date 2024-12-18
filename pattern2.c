#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void pattern2(int num_processes) {
    printf("** Pattern 2: creating %d processes\n", num_processes);

    pid_t pid = 0; 

    if (pid == 0) { 
        pid = fork();
        

        for (int i = 0; i < num_processes; i++) {

            if (pid == 0) { 
                
                srand(time(NULL) ^ (getpid() << 16));

                int sleep_time = rand() % 8 + 1;

                printf("Process %d (pid %d): started\n", i, getpid());

                if (i < num_processes - 1) {

                    printf("Process %d (pid %d) creating Process %d\n", i, getpid(), i + 1);

                } else {

                    printf("Process %d (pid %d) no child created sleeping %d seconds\n", i, getpid(), sleep_time);

                }

                sleep(sleep_time);

                printf("Process %d (pid %d): exiting\n", i, getpid());

            } 
            
            else if (pid > 0) {

                wait(NULL);

                break;

            } else {

                perror("Fork failed");

                exit(EXIT_FAILURE);

            }

        }

    }


    if (pid > 0) {

        printf("** Pattern 2: All children have exited\n");

    }

}
