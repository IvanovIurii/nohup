#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Invalid amount of arguments!" << endl;
        return 1;
    }

    char *path = argv[1];

    if (!filesystem::exists(path))
    {
        cout << "'" << path << "' executable does not exist!" << endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0)
    {
        int nfd = open("/dev/null", O_WRONLY);
        if (nfd == -1)
        {
            cout << "Failed to open '/dev/null' for writing" << endl;
            return 1;
        }
        dup2(nfd, STDOUT_FILENO);
        dup2(nfd, STDIN_FILENO);

        execl(path, "nohup process", NULL);

        close(nfd);
        return 0;
    }
    else if (pid > 0)
    {
        return 0;
    }
    else
    {
        cout << "Failed to fork" << endl;
        return 1;
    }
}
