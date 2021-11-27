#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  register struct passwd *pw;
  register uid_t uid;
  int c;

  uid = geteuid ();
  printf("%d\n", uid);
  pw = getpwuid (uid);
  if (pw)
    {
      puts (pw->pw_name);
      exit (EXIT_SUCCESS);
    }
  fprintf (stderr,"cannot find username for UID %u\n", (unsigned) uid);
  exit (EXIT_FAILURE);
}


