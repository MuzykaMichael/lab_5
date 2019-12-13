#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int verbose_flag;

int main (int argc, char **argv)
{
  int c;
  int aapt = 0, bapt = 0, lflag = 0, fflag = 0;

  while (true)
    {
      static struct option long_options[] =
        {
          {"verbose", no_argument,       &verbose_flag, 1},
          {"option1",     no_argument,       0, 'a'},
          {"option2",  no_argument,       0, 'A'},
          {"list", no_argument, 0, 'l'},
          {"file", no_argument, 0, 'f'},
          {0, 0, 0, 0}
        };
      int option_index = 0;

      c = getopt_long (argc, argv, "aAlf",
                       long_options, &option_index);

      if (c == -1)
        break;

      switch (c)
        {
        case 0:
	  if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'a':
	  if (aapt == 0) {
          	puts ("option -a");
		aapt = 1;
	  }
          break;

        case 'A':
	  if (bapt == 0) {
          	puts ("option -A");
		bapt = 1;
	  }
          break;

        case 'l':
	  if (lflag == 0) {
          	puts ("option -l");
		lflag = 1;
	  }	
	  break;

        case 'f':
	  if (fflag == 0) {
          	puts ("option -f");
          	fflag = 1;
	  }	
	  break;


        case '?':
          break;

        default:
          abort ();
        }
    }

  if (verbose_flag)
    puts ("\nverbose flag is set");

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
