/* project.h */


#define DCO_FREQ 1*1e6
#define TIMER_INTERVAL 500 // Given in ms

#define DIVIDER 8
#define TMRC (DCO_FREQ / DIVIDER / 1000 * TIMER_INTERVAL)
