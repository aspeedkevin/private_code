#include <ctype.h>
#include <lib/malloc.h>
#include <lib/string.h>
#include <types.h>

/**
 * strncasecmp - Case insensitive, length-limited string comparison
 * @s1: One string
 * @s2: The other string
 * @len: the maximum number of characters to compare
 */
int strncasecmp(const char *s1, const char *s2, size_t len)
{
	/* Yes, Virginia, it had better be unsigned */
	unsigned char c1, c2;

	c1 = 0;
	c2 = 0;
	if (len) {
		do {
			c1 = *s1;
			c2 = *s2;
			s1++;
			s2++;
			if (!c1)
				break;
			if (!c2)
				break;
			if (c1 == c2)
				continue;
			c1 = tolower(c1);
			c2 = tolower(c2);
			if (c1 != c2)
				break;
		} while (--len);
	}
	return (int)c1 - (int)c2;
}

/**
 * strcasecmp - Case insensitive string comparison
 * @s1: One string
 * @s2: The other string
 */
int strcasecmp(const char *s1, const char *s2)
{
	return strncasecmp(s1, s2, -1U);
}

char *___strtok;

/**
 * strcpy - Copy a %NUL terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 */
char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while ((*dest++ = *src++) != '\0')
		/* nothing */;
	return tmp;
}

/**
 * strncpy - Copy a length-limited, %NUL-terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 * @count: The maximum number of bytes to copy
 *
 * Note that unlike userspace strncpy, this does not %NUL-pad the buffer.
 * However, the result is not %NUL-terminated if the source exceeds
 * @count bytes.
 */
char *strncpy(char *dest, const char *src, size_t count)
{
	char *tmp = dest;

	while (count-- && (*dest++ = *src++) != '\0')
		/* nothing */;

	return tmp;
}

/**
 * strlcpy - Copy a C-string into a sized buffer
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 * @size: size of destination buffer
 *
 * Compatible with *BSD: the result is always a valid
 * NUL-terminated string that fits in the buffer (unless,
 * of course, the buffer size is zero). It does not pad
 * out the result like strncpy() does.
 *
 * Return: the number of bytes copied
 */
size_t strlcpy(char *dest, const char *src, size_t size)
{
	if (size) {
		size_t srclen = strlen(src);
		size_t len = (srclen >= size) ? size - 1 : srclen;

		memcpy(dest, src, len);
		dest[len] = '\0';
		return len + 1;
	}

	return 0;
}

/**
 * strcat - Append one %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 */
char *strcat(char *dest, const char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0')
		;

	return tmp;
}

/**
 * strncat - Append a length-limited, %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 * @count: The maximum numbers of bytes to copy
 *
 * Note that in contrast to strncpy, strncat ensures the result is
 * terminated.
 */
char *strncat(char *dest, const char *src, size_t count)
{
	char *tmp = dest;

	if (count) {
		while (*dest)
			dest++;
		while ((*dest++ = *src++)) {
			if (--count == 0) {
				*dest = '\0';
				break;
			}
		}
	}

	return tmp;
}

/**
 * strlcat - Append a length-limited, %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 * @size: The size of @dest
 *
 * Compatible with *BSD: the result is always a valid NUL-terminated string that
 * fits in the buffer (unless, of course, the buffer size is zero). It does not
 * write past @size like strncat() does.
 */
size_t strlcat(char *dest, const char *src, size_t size)
{
	size_t len = strnlen(dest, size);

	return len + strlcpy(dest + len, src, size - len);
}

/**
 * strcmp - Compare two strings
 * @cs: One string
 * @ct: Another string
 */
int strcmp(const char *cs, const char *ct)
{
	register signed char __res;

	while (1) {
		if ((__res = *cs - *ct++) != 0 || !*cs++)
			break;
	}

	return __res;
}

/**
 * strncmp - Compare two length-limited strings
 * @cs: One string
 * @ct: Another string
 * @count: The maximum number of bytes to compare
 */
int strncmp(const char *cs, const char *ct, size_t count)
{
	register signed char __res = 0;

	while (count) {
		if ((__res = *cs - *ct++) != 0 || !*cs++)
			break;
		count--;
	}

	return __res;
}

/**
 * strchr - Find the first occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to search for
 */
char *strchr(const char *s, int c)
{
	for (; *s != (char)c; ++s)
		if (*s == '\0')
			return NULL;
	return (char *)s;
}

const char *strchrnul(const char *s, int c)
{
	for (; *s != (char)c; ++s)
		if (*s == '\0')
			break;
	return s;
}

/**
 * strrchr - Find the last occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to search for
 */
char *strrchr(const char *s, int c)
{
	const char *p = s + strlen(s);
	do {
		if (*p == (char)c)
			return (char *)p;
	} while (--p >= s);
	return NULL;
}

/**
 * strlen - Find the length of a string
 * @s: The string to be sized
 */
size_t strlen(const char *s)
{
	const char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}

/**
 * strnlen - Find the length of a length-limited string
 * @s: The string to be sized
 * @count: The maximum number of bytes to search
 */
size_t strnlen(const char *s, size_t count)
{
	const char *sc;

	for (sc = s; count-- && *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}

/**
 * strcspn - Calculate the length of the initial substring of @s which does
 * not contain letters in @reject
 * @s: The string to be searched
 * @reject: The string to avoid
 */
size_t strcspn(const char *s, const char *reject)
{
	const char *p;
	const char *r;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p) {
		for (r = reject; *r != '\0'; ++r) {
			if (*p == *r)
				return count;
		}
		++count;
	}
	return count;
}

char *strdup(const char *s)
{
	char *new;

	if ((s == NULL) || ((new = malloc(strlen(s) + 1)) == NULL)) {
		return NULL;
	}

	strcpy(new, s);
	return new;
}

char *strndup(const char *s, size_t n)
{
	size_t len;
	char *new;

	if (s == NULL)
		return NULL;

	len = strlen(s);

	if (n < len)
		len = n;

	new = malloc(len + 1);
	if (new == NULL)
		return NULL;

	strncpy(new, s, len);
	new[len] = '\0';

	return new;
}

/**
 * strspn - Calculate the length of the initial substring of @s which only
 *	contain letters in @accept
 * @s: The string to be searched
 * @accept: The string to search for
 */
size_t strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p) {
		for (a = accept; *a != '\0'; ++a) {
			if (*p == *a)
				break;
		}
		if (*a == '\0')
			return count;
		++count;
	}

	return count;
}

/**
 * strpbrk - Find the first occurrence of a set of characters
 * @cs: The string to be searched
 * @ct: The characters to search for
 */
char *strpbrk(const char *cs, const char *ct)
{
	const char *sc1, *sc2;

	for (sc1 = cs; *sc1 != '\0'; ++sc1) {
		for (sc2 = ct; *sc2 != '\0'; ++sc2) {
			if (*sc1 == *sc2)
				return (char *)sc1;
		}
	}
	return NULL;
}

/**
 * strtok - Split a string into tokens
 * @s: The string to be searched
 * @ct: The characters to search for
 *
 * WARNING: strtok is deprecated, use strsep instead.
 */
char *strtok(char *s, const char *ct)
{
	char *sbegin, *send;

	sbegin = s ? s : ___strtok;
	if (!sbegin) {
		return NULL;
	}
	sbegin += strspn(sbegin, ct);
	if (*sbegin == '\0') {
		___strtok = NULL;
		return (NULL);
	}
	send = strpbrk(sbegin, ct);
	if (send && *send != '\0')
		*send++ = '\0';
	___strtok = send;
	return (sbegin);
}

/**
 * strsep - Split a string into tokens
 * @s: The string to be searched
 * @ct: The characters to search for
 *
 * strsep() updates @s to point after the token, ready for the next call.
 *
 * It returns empty tokens, too, behaving exactly like the libc function
 * of that name. In fact, it was stolen from glibc2 and de-fancy-fied.
 * Same semantics, slimmer shape. ;)
 */
char *strsep(char **s, const char *ct)
{
	char *sbegin = *s, *end;

	if (sbegin == NULL)
		return NULL;

	end = strpbrk(sbegin, ct);
	if (end)
		*end++ = '\0';
	*s = end;

	return sbegin;
}

/**
 * strswab - swap adjacent even and odd bytes in %NUL-terminated string
 * s: address of the string
 *
 * returns the address of the swapped string or NULL on error. If
 * string length is odd, last byte is untouched.
 */
char *strswab(const char *s)
{
	char *p, *q;

	if ((NULL == s) || ('\0' == *s)) {
		return (NULL);
	}

	for (p = (char *)s, q = p + 1; (*p != '\0') && (*q != '\0'); p += 2, q += 2) {
		char tmp;

		tmp = *p;
		*p = *q;
		*q = tmp;
	}

	return (char *)s;
}

/**
 * memset - Fill a region of memory with the given value
 * @s: Pointer to the start of the area.
 * @c: The byte to fill the area with
 * @count: The size of the area.
 *
 * Do not use memset() to access IO space, use memset_io() instead.
 */
void *memset(void *s, int c, size_t count)
{
	unsigned long *sl = (unsigned long *)s;
	char *s8;

	unsigned long cl = 0;
	int i;

	/* do it one word at a time (32 bits or 64 bits) while possible */
	if (((ulong)s & (sizeof(*sl) - 1)) == 0) {
		for (i = 0; i < sizeof(*sl); i++) {
			cl <<= 8;
			cl |= c & 0xff;
		}
		while (count >= sizeof(*sl)) {
			*sl++ = cl;
			count -= sizeof(*sl);
		}
	}

	s8 = (char *)sl;
	while (count--)
		*s8++ = c;

	return s;
}

typedef	int WORD;		/* "WORD" used for optimal copy speed */

#define	WORD_SIZE	sizeof(WORD)
#define	WORD_MASK	(WORD_SIZE - 1)

void *memcpy(void *dst0, const void *src0, size_t length)
{
	char *dst = dst0;
	const char *src = src0;
	size_t t;

	if (length == 0 || dst == src)		/* nothing to do */
		goto done;

	/*
	 * Macros: loop-t-times; and loop-t-times, t>0
	 */
#define	TLOOP(s) if (t) TLOOP1(s)
#define	TLOOP1(s) do { s; } while (--t)

	/*
	 * Copy forward.
	 */
	t = (uintptr_t)src;	/* only need low bits */
	if ((t | (uintptr_t)dst) & WORD_MASK) {
		/*
		 * Try to align operands.  This cannot be done
		 * unless the low bits match.
		 */
		if ((t ^ (uintptr_t)dst) & WORD_MASK || length < WORD_SIZE)
			t = length;
		else
			t = WORD_SIZE - (t & WORD_MASK);
		length -= t;
		TLOOP1(*dst++ = *src++);
	}
	/*
	 * Copy whole WORDs, then mop up any trailing bytes.
	 */
	t = length / WORD_SIZE;
	TLOOP(*(WORD *)dst = *(WORD *)src; src += WORD_SIZE; dst += WORD_SIZE);
	t = length & WORD_MASK;
	TLOOP(*dst++ = *src++);

done:
	return (dst0);
}

/**
 * memmove - Copy one area of memory to another
 * @dest: Where to copy to
 * @src: Where to copy from
 * @count: The size of the area.
 *
 * Unlike memcpy(), memmove() copes with overlapping areas.
 */
void *memmove(void *dest, const void *src, size_t count)
{
	char *tmp, *s;

	if (dest <= src || (src + count) <= dest) {
		/*
	 * Use the fast memcpy implementation (ARCH optimized or lib/string.c) when it is possible:
	 * - when dest is before src (assuming that memcpy is doing forward-copying)
	 * - when destination don't overlap the source buffer (src + count <= dest)
	 *
	 * WARNING: the first optimisation cause an issue, when __HAVE_ARCH_MEMCPY is defined,
	 *          __HAVE_ARCH_MEMMOVE is not defined and if the memcpy ARCH-specific
	 *          implementation is not doing a forward-copying.
	 *
	 * No issue today because memcpy is doing a forward-copying in lib/string.c and for ARM32
	 * architecture; no other arches use __HAVE_ARCH_MEMCPY without __HAVE_ARCH_MEMMOVE.
	 */
		memcpy(dest, src, count);
	} else {
		tmp = (char *)dest + count;
		s = (char *)src + count;
		while (count--)
			*--tmp = *--s;
	}

	return dest;
}

/**
 * memcmp - Compare two areas of memory
 * @cs: One area of memory
 * @ct: Another area of memory
 * @count: The size of the area.
 */
int memcmp(const void *cs, const void *ct, size_t count)
{
	const unsigned char *su1, *su2;
	int res = 0;

	for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}

/**
 * memscan - Find a character in an area of memory.
 * @addr: The memory area
 * @c: The byte to search for
 * @size: The size of the area.
 *
 * returns the address of the first occurrence of @c, or 1 byte past
 * the area if @c is not found
 */
void *memscan(void *addr, int c, size_t size)
{
	unsigned char *p = (unsigned char *)addr;

	while (size) {
		if (*p == c)
			return (void *)p;
		p++;
		size--;
	}
	return (void *)p;
}

char *memdup(const void *src, size_t len)
{
	char *p;

	p = malloc(len);
	if (!p)
		return NULL;

	memcpy(p, src, len);

	return p;
}

/**
 * strstr - Find the first substring in a %NUL terminated string
 * @s1: The string to be searched
 * @s2: The string to search for
 */
char *strstr(const char *s1, const char *s2)
{
	int l1, l2;

	l2 = strlen(s2);
	if (!l2)
		return (char *)s1;
	l1 = strlen(s1);
	while (l1 >= l2) {
		l1--;
		if (!memcmp(s1, s2, l2))
			return (char *)s1;
		s1++;
	}
	return NULL;
}

/**
 * memchr - Find a character in an area of memory.
 * @s: The memory area
 * @c: The byte to search for
 * @n: The size of the area.
 *
 * returns the address of the first occurrence of @c, or %NULL
 * if @c is not found
 */
void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	while (n-- != 0) {
		if ((unsigned char)c == *p++) {
			return (void *)(p - 1);
		}
	}
	return NULL;
}

static void *check_bytes8(const u8 *start, u8 value, unsigned int bytes)
{
	while (bytes) {
		if (*start != value)
			return (void *)start;
		start++;
		bytes--;
	}
	return NULL;
}
/**
 * memchr_inv - Find an unmatching character in an area of memory.
 * @start: The memory area
 * @c: Find a character other than c
 * @bytes: The size of the area.
 *
 * returns the address of the first character other than @c, or %NULL
 * if the whole buffer contains just @c.
 */
void *memchr_inv(const void *start, int c, size_t bytes)
{
	u8 value = c;
	u64 value64;
	unsigned int words, prefix;

	if (bytes <= 16)
		return check_bytes8(start, value, bytes);

	value64 = value;
	value64 |= value64 << 8;
	value64 |= value64 << 16;
	value64 |= value64 << 32;

	prefix = (unsigned long)start % 8;
	if (prefix) {
		u8 *r;

		prefix = 8 - prefix;
		r = check_bytes8(start, value, prefix);
		if (r)
			return r;
		start += prefix;
		bytes -= prefix;
	}

	words = bytes / 8;

	while (words) {
		if (*(u64 *)start != value64)
			return check_bytes8(start, value, 8);
		start += 8;
		words--;
	}

	return check_bytes8(start, value, bytes % 8);
}
