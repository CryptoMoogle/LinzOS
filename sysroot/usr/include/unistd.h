#ifndef UNISTD_H
#define UNISTD_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif
int execv(const char*, char* const[]);
int execve(const char*, char* const[], char* const[]);
int execvp(const char*, char* const[]);
pid_t fork(void);
#ifdef __cplusplus
}
#endif

#ifndef __ASSEMBLER__

extern char **environ;  /**< Pointer to the environment strings */

#endif /* _ASSEMBLER_ */

#endif /* UNISTD_H */