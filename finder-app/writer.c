#include <stdio.h>
#include <syslog.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

int main(int argc, char *argv[])
{
  openlog("writer_utility", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

  // Process the input arguments for errors
  if(argc != 3)
    {
      syslog(LOG_ERR,
	     "The writer utility expects two input arguments | usage: %s filepath writestr",
	     argv[0]);
      return 1;
    }

  // Create new file (or replace existing one)
  int fd = open(
		argv[1],
		O_CREAT | O_TRUNC | O_RDWR,
		S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd == -1)
    {
      syslog(LOG_ERR,
	     "Error opening the file descriptor\n");
      return 1;
    }

  // Write input string to file
  int ret = write(fd, argv[2], strlen(argv[2]));
  if (ret == -1)
    {
      syslog(LOG_ERR,
	     "Error writing to the file\n");
      return 1;
    }
  syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2], argv[1]);

  close(fd);
  closelog();

  return 0;
}
