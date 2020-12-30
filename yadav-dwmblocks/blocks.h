#define PATH(name)                      "/home/mario/.local/bin/blocks/"name

/* DELIMITERENDCHAR must be less than 32.
 * At max, DELIMITERENDCHAR - 1 number of clickable blocks will be allowed.
 * Raw characters larger than DELIMITERENDCHAR and smaller than ' ' in ASCII
   character set can be used for signaling color change in status.
 * The character corresponding to DELIMITERENDCHAR + 1 ('\x0b' when
   DELIMITERENDCHAR is 10) will switch the active colorscheme to the first one
   defined in colors array in dwm's config.h and so on.
 * If you wish to change DELIMITERENDCHAR, don't forget to update its value in
   dwm.c and color codes in your pathu programs. */
#define DELIMITERENDCHAR                16

/* If interval of a block is set to 0, the block will only be updated once at
   startup.
 * If interval is set to a negative value, the block will never be updated in
   the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the
   block.
 * Signal must be less than DELIMITERENDCHAR for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be
   delivered first. */

/* pathu - path of the program whose output is used as status text of the block
           (output of the program should end in a null or newline character)
 * pathc - path of the program used for handling clicks on the block */


/* 1 Interval = INTERVALs seconds , INTERVALn nanoseconds */
#define INTERVALs                       1
#define INTERVALn                       0
static Block blocks[] = {
/*      pathu                           pathc                                   interval        signal */
        { PATH("sb-packages"),          PATH("sb-packages"),                   0,              9},

        { PATH("sb-news"),              PATH("sb-news"),                       0,              10},

        { PATH("sb-torrent"),           PATH("sb-torrent"),                    20,             12},

        { PATH("sb-forecast"),          PATH("sb-forecast"),                   18000,          7},

        { PATH("sb-mailbox"),           PATH("sb-mailbox"),                    180,            6},

        { PATH("sb-volume"),            PATH("sb-volume"),                     0,              5},

        { PATH("sb-disk"),              PATH("sb-disk"),                       0,              8},

        { PATH("sb-cputemp"),           PATH("sb-cputemp"),                    1,              3},

        { PATH("sb-battery"),           PATH("sb-battery"),                    5,              2},

        { PATH("sb-clock"),             PATH("sb-clock"),                      60,             1},

        { PATH("sb-tasks"),             PATH("sb-tasks"),                      10,             13},

        { PATH("sb-nettraf"),           PATH("sb-nettraf"),                    1,              11},

        { PATH("sb-internet"),          PATH("sb-internet"),                   5,              4},

        { PATH("sb-help-icon"),         PATH("sb-help-icon"),                  0,              14},

//        { PATH("calendar"),          NULL,                                   30,             3},

        { NULL } /* just to mark the end of the array */
};
/* Default Delimiter string */
/* static const char *delim =  " "; */
#define DELIMITER                       " "
