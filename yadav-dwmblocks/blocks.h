/* time interval in seconds to sleep before looking for updates in the main loop */
#define SLEEPINTERVAL                   2

#define PATH(name)                      "/home/mario/.local/bin/blocks/"name

/* If interval of a block is set to 0, the block will only be updated once at startup.
 * If interval is set to a negative value, the block will never be updated in the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the block.
 * Signal must be less than 10 for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be delivered first. */

/* pathu - path of the program whose output is to be used for status text
 *         output of the program should have a null or newline character at the end
 * pathc - path of the program to be executed on clicks */
static Block blocks[] = {
/*      pathu                           pathc                                   interval        signal */
//        { PATH("sb-packages"),          PATH("sb-packages"),                   0,              8},

        { PATH("sb-forecast"),          PATH("sb-forecast"),                   18000,          5},

        { PATH("sb-mailbox"),           PATH("sb-mailbox"),                    180,            6},

        { PATH("sb-volume"),            PATH("sb-volume"),                     0,              7},

        { PATH("sb-disk"),              PATH("sb-disk"),                       0,              8},

        { PATH("sb-cputemp"),           PATH("sb-cputemp"),                    1,              3},

        { PATH("sb-battery"),           PATH("sb-battery"),                    30,             2},

        { PATH("sb-clock"),             PATH("sb-clock"),                      1,              1},

        { PATH("sb-nettraf"),           PATH("sb-nettraf"),                    1,              10},

        { PATH("sb-internet"),          PATH("sb-internet"),                   5,              4},

        { PATH("sb-help-icon"),         PATH("sb-help-icon"),                  0,              9},
//        { PATH("calendar"),          NULL,                                   30,             3},

        { NULL } /* just to mark the end of the array */
};

static const char *delim =  " ";
