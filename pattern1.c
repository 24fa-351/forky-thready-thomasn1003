#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void pattern1(int num_processes) {

    pid_t pids[num_processes];

    printf("** Pattern 1: creating %d processes\n", num_processes);

    for (int i = 0; i < num_processes; i++) {

        pids[i] = fork();

        if (pids[i] == 0) {  

            srand(time(NULL) ^ (getpid()<<16));

            int sleep_time = rand() % 8 + 1;

            printf("Process %d (pid %d) created: will sleep for %d seconds\n", i, getpid(), sleep_time);

            sleep(sleep_time);

            printf("Process %d (pid %d): exiting\n", i, getpid());

            exit(0);

        } else if (pids[i] < 0) {

            perror("Fork failed");

            exit(EXIT_FAILURE);

        }

        printf("Parent: created child %d (pid %d)\n", i, pids[i]);

    }

    printf("** Pattern 1: All processes created\n");

    for (int i = 0; i < num_processes; i++) {

        waitpid(pids[i], NULL, 0);
        
    }

    printf("** Pattern 1: All children have exited\n");
}
