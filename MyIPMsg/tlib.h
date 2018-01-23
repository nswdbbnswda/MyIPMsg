
#ifndef  TLIB_H
#define  TLIB_H
#include<Windows.h>
#include"hashtable.h"


#define WINEXEC_ERR_MAX		31
#define TLIB_SLEEPTIMER		32000

#define TLIB_CRYPT		0x00000001
#define TLIB_PROTECT	0x00000002

#define IsNewShell()	(LOBYTE(LOWORD(TWinVersion)) >= 4)

#define IsWin31()		(LOBYTE(LOWORD(TWinVersion)) == 3 && HIBYTE(LOWORD(TWinVersion)) < 20)
#define IsWin95()		(LOBYTE(LOWORD(TWinVersion)) >= 4 && TWinVersion >= 0x80000000)

#define IsWinNT350()	(LOBYTE(LOWORD(TWinVersion)) == 3 && TWinVersion < 0x80000000 \
							&& HIBYTE(LOWORD(TWinVersion)) == 50)
#define IsWinNT()		(LOBYTE(LOWORD(TWinVersion)) >= 4 && TWinVersion < 0x80000000)
#define IsWin2K()		(LOBYTE(LOWORD(TWinVersion)) >= 5 && TWinVersion < 0x80000000)
#define IsWinXP()		((LOBYTE(LOWORD(TWinVersion)) >= 6 || LOBYTE(LOWORD(TWinVersion)) == 5 \
							&& HIBYTE(LOWORD(TWinVersion)) >= 1) && TWinVersion < 0x80000000)
#define IsWinVista()	(LOBYTE(LOWORD(TWinVersion)) >= 6 && TWinVersion < 0x80000000)
#define IsWin7()		((LOBYTE(LOWORD(TWinVersion)) >= 7 || LOBYTE(LOWORD(TWinVersion)) == 6 \
							&& HIBYTE(LOWORD(TWinVersion)) >= 1) && TWinVersion < 0x80000000)
#define IsWin8()		((LOBYTE(LOWORD(TWinVersion)) >= 7 || LOBYTE(LOWORD(TWinVersion)) == 6 \
							&& HIBYTE(LOWORD(TWinVersion)) >= 2) && TWinVersion < 0x80000000)
/* manifest ¤Ë supported OS ¤ÎÓ›Êö¤¬±Øíš */
#define IsWin81()		((LOBYTE(LOWORD(TWinVersion)) >= 7 || LOBYTE(LOWORD(TWinVersion)) == 6 \
							&& HIBYTE(LOWORD(TWinVersion)) >= 3) && TWinVersion < 0x80000000)
#define IsWin10()		(LOBYTE(LOWORD(TWinVersion)) >= 10 && TWinVersion < 0x80000000)

#define IsLang(lang)	(PRIMARYLANGID(LANGIDFROMLCID(GetThreadLocale())) == lang)
#define wsizeof(x)		(sizeof(x) / sizeof(WCHAR))

#define BUTTON_CLASS		"BUTTON"
#define COMBOBOX_CLASS		"COMBOBOX"
#define EDIT_CLASS			"EDIT"
#define LISTBOX_CLASS		"LISTBOX"
#define MDICLIENT_CLASS		"MDICLIENT"
#define SCROLLBAR_CLASS		"SCROLLBAR"
#define STATIC_CLASS		"STATIC"

#define MAX_WPATH		32000
#define MAX_PATH_EX		(MAX_PATH * 8)
#define MAX_PATH_U8		(MAX_PATH * 3)
#define MAX_FNAME_LEN	255

#define BITS_OF_BYTE	8
#define BYTE_NUM		256

#ifndef EM_SETTARGETDEVICE
#define COLOR_BTNFACE           15
#define COLOR_3DFACE            COLOR_BTNFACE
#define EM_SETBKGNDCOLOR		(WM_USER + 67)
#define EM_SETTARGETDEVICE		(WM_USER + 72)
#endif


// UTF8 string class
enum StrMode { BY_UTF8, BY_MBCS };


















typedef signed _int64 int64;
typedef unsigned _int64 uint64;
#define DWORD_RDC(x) ((DWORD)(DWORD_PTR)(x)) // REDUCE
#define LONG_RDC(x)  ((LONG)(LONG_PTR)(x))   // REDUCE
#define UINT_RDC(x)  ((UINT)(UINT_PTR)(x))   // REDUCE
#define INT_RDC(x)   ((INT)(INT_PTR)(x))     // REDUCE




/* for internal use end */
struct TRect : public RECT {
	TRect(long x = 0, long y = 0, long cx = 0, long cy = 0) { Init(x, y, cx, cy); }
	TRect(const RECT &rc) { *this = rc; }
	TRect(const POINT &tl, const POINT &br) {
		left = tl.x;
		top = tl.y;
		right = br.x;
		bottom = br.y;
	}
	TRect(const POINTS &tl, const POINTS &br) {
		left = tl.x;
		top = tl.y;
		right = br.x;
		bottom = br.y;
	}
	TRect(const POINT &tl, long cx, long cy) {
		left = tl.x;
		top = tl.y;
		right = left + cx;
		bottom = top + cy;
	}
	TRect(const POINTS &tl, long cx, long cy) {
		left = tl.x;
		top = tl.y;
		right = left + cx;
		bottom = top + cy;
	}

	void	Init(long x = 0, long y = 0, long cx = 0, long cy = 0) {
		left = x;
		top = y;
		right = x + cx;
		bottom = y + cy;
	}
	long&	x() { return left; }
	long&	y() { return top; }
	long	cx() const { return right - left; }
	long	cy() const { return bottom - top; }
	void	set_x(long  x) { left = x; }
	void	set_y(long  y) { top = y; }
	void	set_cx(long v) { right = left + v; }
	void	set_cy(long v) { bottom = top + v; }
	void	Regular() {
		if (left > right) {
			long t = left;
			left = right;
			right = t;
		}
		if (top > bottom) {
			long t = top;
			top = bottom;
			bottom = t;
		}
	}
	void	Inflate(long cx, long cy) {
		left -= cx;
		right += cx;
		top -= cy;
		bottom += cy;
	}
	void	Size(long cx, long cy) {
		right = left + cx;
		bottom = top + cy;
	}
	bool operator ==(const TRect &rc) {
		return	(left == rc.left) && (top == rc.top) &&
			(right == rc.right) && (bottom == rc.bottom);
	}
	bool operator !=(const TRect &rc) { return !(*this == rc); }
};

struct TSize : public SIZE {
	TSize(long _cx = 0, long _cy = 0) {
		cx = _cx;
		cy = _cy;
	}
	TSize(const SIZE &sz) { *this = sz; }
	void	Inflate(long x, long y) {
		cx += x;
		cy += y;
	}
};







































#endif // ! TLIB_H