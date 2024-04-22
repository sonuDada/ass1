#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Fork the first child process
    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());

        // Simulate 'cp' command using execlp
        execlp("cp", "cp", "c1.txt", "c2.txt", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);

        // Wait for the first child process to complete
        int status;
        pid_t wait_pid = waitpid(child_pid, &status, 0);
        if (wait_pid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        printf("First child process has completed\n");

        // Fork the second child process
        child_pid = fork();

        if (child_pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // Child process
            printf("Child process: PID = %d\n", getpid());

            // Simulate 'grep' command using execlp
            execlp("grep", "grep", "pccoe", "c1.txt", NULL);

            // If execlp fails
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);

            // Wait for the second child process to complete
            wait_pid = waitpid(child_pid, &status, 0);
            if (wait_pid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            printf("Second child process has completed\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Fork the first child process
    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());

        // Simulate 'cp' command using execlp
        execlp("cp", "cp", "c1.txt", "c2.txt", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);

        // Wait for the first child process to complete
        int status;
        pid_t wait_pid = waitpid(child_pid, &status, 0);
        if (wait_pid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        printf("First child process has completed\n");

        // Fork the second child process
        child_pid = fork();

        if (child_pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // Child process
            printf("Child process: PID = %d\n", getpid());

            // Simulate 'grep' command using execlp
            execlp("grep", "grep", "pccoe", "c1.txt", NULL);

            // If execlp fails
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);

            // Wait for the second child process to complete
            wait_pid = waitpid(child_pid, &status, 0);
            if (wait_pid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            printf("Second child process has completed\n");
        }
    }

    return 0;
}