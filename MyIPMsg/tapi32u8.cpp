#include "tapi32u8.h"

/*=========================================================================
UCS2(W) - UTF-8(U8) - ANSI(A) Ïà»¥‰ä“Q
=========================================================================*/
int WtoU8(const WCHAR *src, char *dst, int bufsize, int max_len)
{
	if (bufsize == 1) {
		*dst = 0;
		return	0;
	}
	else if (bufsize >= 2) { // clear for UTF8
		int len = min(bufsize, 3);
		memset(dst + bufsize - len, 0, len);
	}

	int affect_len = bufsize ? bufsize - 1 : 0;
	int len = ::WideCharToMultiByte(CP_UTF8, 0, src, max_len, dst, affect_len, 0, 0);
	if (len < bufsize && dst) dst[len] = 0;

	return	len;
}

//UTF-8µ½¿í×Ö·û×ª»»
int U8toW(const char *src, WCHAR *dst, int bufsize, int max_len)
{
	int len = ::MultiByteToWideChar(CP_UTF8, 0, src, max_len, dst, bufsize);

	if (len == 0 && max_len != 0) {
		if (dst && bufsize > 0) {
			if ((len = (int)wcsnlen(dst, bufsize)) == bufsize) dst[--len] = 0;
		}
	}
	else if (len < bufsize) {
		dst[len] = 0;
	}

	return	len;
}