#ifndef __STRING_H__
#define __STRING_H__

#include <types.h>

char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
size_t strlcpy(char *, const char *, size_t);
char *strcat(char *, const char *);
char *strncat(char *, const char *, size_t);
size_t strlcat(char *, const char *, size_t);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t len);
char *strchr(const char *, int);
const char *strchrnul(const char *s, int c);
char *strrchr(const char *, int);
char *strstr(const char *, const char *);
size_t strlen(const char *);
size_t strnlen(const char *, size_t);
size_t strcspn(const char *s, const char *reject);
char *strdup(const char *);
char *strndup(const char *, size_t);
char *strswab(const char *);
void *memset(void *, int, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memscan(void *, int, size_t);
int memcmp(const void *, const void *, size_t);
void *memchr(const void *, int, size_t);
void *memchr_inv(const void *, int, size_t);
char *memdup(const void *src, size_t len);
unsigned long ustrtoul(const char *cp, char **endp, unsigned int base);
unsigned long long ustrtoull(const char *cp, char **endp, unsigned int base);

#endif
