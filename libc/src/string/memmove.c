
#include <string.h>

void *memmove(void *dst, const void *src, size_t n){

	char *d = (char *) dst;
	char *s = (char *) src;
	size_t i;

	if (d < s) {
		for (i = 0; i < n; i++)
			d[i] = s[i];
	} else {
		i = n;
		while (i-- > 0){
			d[i] = s[i];
		}
	}

	return dst;
}