#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void create_process(int id, int max_id);

void pattern3(int num_processes) {

    printf("** Pattern 3: creating %d processes\n", num_processes);

    create_process(0, num_processes - 1);

    printf("** Pattern 3: All children have exited\n");

}

void create_process(int id, int max_id) {

    pid_t left_pid, right_pid;

    int sleep_time = rand() % 8 + 1;

    printf("Process %d (pid %d) of %d: starting\n", id, getpid(), max_id + 1);

    if (id * 2 + 1 <= max_id) {  

        left_pid = fork();

        if (left_pid == 0) {  

            printf("Process %d (pid %d) created left child %d\n", id, getpid(), id * 2 + 1);

            create_process(id * 2 + 1, max_id);

            exit(0);

        } else if (left_pid > 0) {

        } else {

            perror("Fork failed for left child");

            exit(EXIT_FAILURE);

        }
    }

    if (id * 2 + 2 <= max_id) {  

        right_pid = fork();

        if (right_pid == 0) {  

            printf("Process %d (pid %d) created right child %d\n", id, getpid(), id * 2 + 2);

            create_process(id * 2 + 2, max_id);

            exit(0);

        } else if (right_pid > 0) {
    
        } else {

            perror("Fork failed for right child");

            exit(EXIT_FAILURE);

        }
    }

    printf("Process %d (pid %d) sleeping for %d seconds\n", id, getpid(), sleep_time);

    sleep(sleep_time);

    
    if (id * 2 + 1 <= max_id) {

        waitpid(left_pid, NULL, 0);

    }

    if (id * 2 + 2 <= max_id) {

        waitpid(right_pid, NULL, 0);
        
    }

    printf("Process %d (pid %d): exiting\n", id, getpid());
}
