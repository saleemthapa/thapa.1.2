#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork"); // Error handling for fork failure
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This code is executed in the child process.
        int num_iterations;

        if (argc != 2) {
            fprintf(stderr, "Usage: %s <num_iterations>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        num_iterations = atoi(argv[1]);

        for (int i = 1; i <= num_iterations; i++) {
            printf("WORKER PID:%d PPID:%d Iteration:%d before sleeping\n", 
getpid(), getppid(), i);
            sleep(1); // Sleep for one second
            printf("WORKER PID:%d PPID:%d Iteration:%d after sleeping\n", 
getpid(), getppid(), i);
        }

        exit(EXIT_SUCCESS); // Terminate the child process
    } else {
        // This code is executed in the parent process.
        // You can add parent process logic here if needed.
        int status;
        wait(&status); // Wait for the child process to finish
    }

    // Both the parent and child processes continue from here.
    // They can perform different tasks based on the value of child_pid.

    return 0;
}

