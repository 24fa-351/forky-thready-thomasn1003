#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void pattern2(int num_processes) {

    pid_t pid;

    printf("** Pattern 2: creating %d processes\n", num_processes);

    for (int i = 0; i < num_processes; i++) {

        pid = fork();

        if (pid == 0) {  

            srand(time(NULL) ^ (getpid()<<16));

            int sleep_time = rand() % 8 + 1;

            printf("Child %d (pid %d): starting\n", i, getpid());

            if (i < num_processes - 1) {

                printf("Child %d (pid %d), sleeping %d seconds after creating child %d \n", i, getpid(), sleep_time, i + 1);

            } else {

                printf("Child %d (pid %d) [no children created] sleeping %d seconds\n", i, getpid(), sleep_time);

            }



            sleep(sleep_time);

            printf("Process %d (pid %d): exiting\n", i, getpid());

            exit(0);

        } else if (pid > 0) {

            wait(NULL);

            printf("Parent: created child %d (pid %d)\n", i, pid);

        } else {

            perror("Fork failed");

            exit(EXIT_FAILURE);

        }


    }

    printf("** Pattern 2: All children have exited\n");
}
