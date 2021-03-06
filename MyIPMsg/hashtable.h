#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<Windows.h>
#include"tlib.h"


template<typename T> class THashTblT;

template<typename T>
class THashObjT {
public:
	THashObjT	*prevHash;
	THashObjT	*nextHash;
	T				hashId;

public:
	THashObjT() { prevHash = nextHash = NULL; hashId = 0; }
	virtual ~THashObjT() { if (prevHash && prevHash != this) UnlinkHash(); }

	virtual BOOL LinkHash(THashObjT *top) {//遊峨隈褒�鯀官�
		if (prevHash) return FALSE;
		this->nextHash = top->nextHash;
		this->prevHash = top;
		top->nextHash->prevHash = this;
		top->nextHash = this;
		return TRUE;
	}
	virtual BOOL UnlinkHash() {//評茅匯倖准泣
		if (!prevHash) return FALSE;
		prevHash->nextHash = nextHash;
		nextHash->prevHash = prevHash;
		prevHash = nextHash = NULL;
		return TRUE;
	}
	friend THashTblT<T>;
};

//込錬燕
template<typename T>
class THashTblT {
protected:
	THashObjT<T>	*hashTbl;
	int				hashNum;
	int				registerNum;
	BOOL			isDeleteObj;
	virtual BOOL	IsSameVal(THashObjT<T> *, const void *val) = 0;
public:
	THashTblT(int _hashNum = 0, BOOL _isDeleteObj = TRUE) {
		hashTbl = NULL;
		registerNum = 0;
		isDeleteObj = _isDeleteObj;
		if ((hashNum = _hashNum) > 0) Init(hashNum);
	}
	virtual ~THashTblT() { UnInit(); }
	virtual BOOL Init(int _hashNum) {//幹秀燕
		if ((hashTbl = new THashObjT<T>[hashNum = _hashNum]) == NULL) {//幹秀込錬燕
			return	FALSE;	// VC4's new don't occur exception
		}
		for (int i = 0; i < hashNum; i++) {
			THashObjT<T>	*obj = hashTbl + i;
			obj->prevHash = obj->nextHash = obj;
		}
		registerNum = 0;
		return	TRUE;
	
	}
	virtual void UnInit() {//��支燕
		if (!hashTbl) return;
		if (isDeleteObj) {
			for (int i = 0; i < hashNum && registerNum > 0; i++) {
				THashObjT<T>	*start = hashTbl + i;
				for (THashObjT<T> *obj = start->nextHash; obj != start; ) {
					THashObjT<T> *next = obj->nextHash;
					delete obj;
					obj = next;
					registerNum--;
				}
			}
		}
		delete[] hashTbl;
		hashTbl = NULL;
		registerNum = 0;
	}
	virtual void Register(THashObjT<T> *obj, T hash_id) {//峨秘匯倖圷殆
		obj->hashId = hash_id;
		if (obj->LinkHash(hashTbl + (hash_id % hashNum))) registerNum++;
	}
	virtual void UnRegister(THashObjT<T> *obj) {
		if (obj->UnlinkHash()) registerNum--;
	}
	virtual THashObjT<T> *Search(const void *data, T hash_id) {//壓込錬燕嶄臥孀匯倖圷殆
		THashObjT<T> *top = hashTbl + (hash_id % hashNum);//孀欺燕遊
		for (THashObjT<T> *obj = top->nextHash; obj != top; obj = obj->nextHash) {
			if (obj->hashId == hash_id && IsSameVal(obj, data)) return obj;
		}
		return	NULL;
	}

	virtual int		GetRegisterNum() { return registerNum; }//資誼込錬燕嶄圷殆倖方


};
typedef THashObjT<u_int>	THashObj;
typedef THashTblT<u_int>	THashTbl;
typedef THashObjT<unsigned long long > THashObj64;
typedef THashTblT<unsigned long long> THashTbl64;


/* for internal use start */
struct TResHashObj : THashObj {
	void	*val;
	TResHashObj(UINT _resId, void *_val) { hashId = _resId; val = _val; }
	~TResHashObj() { free(val); }

};


class TResHash : public THashTbl {
protected:
	virtual BOOL IsSameVal(THashObj *obj, const void *val) {
		return obj->hashId == *(u_int *)val;
	}

public:
	TResHash(int _hashNum) : THashTbl(_hashNum) {}
	TResHashObj	*Search(UINT resId) { return (TResHashObj *)THashTbl::Search(&resId, resId); }
	void		Register(TResHashObj *obj) { THashTbl::Register(obj, obj->hashId); }
};


#define PAGE_SIZE	(4 * 1024)





//class Condition {
//protected:
//	enum Kind { INIT_EVENT = 0, WAIT_EVENT, DONE_EVENT };
//
//	struct Event {
//		HANDLE	hEvent;
//		u_int	kind;	// Kind が秘るが compare and swap喘に u_int に。
//		Event() { hEvent = 0; kind = INIT_EVENT; }
//	};
//	static Event			*gEvents;
//	static volatile LONG	gEventMap;
//	static BOOL				InitGlobalEvents();
//	static const int		MaxThreads = 32;
//
//	BOOL			isInit;
//	CRITICAL_SECTION cs;
//	u_int			waitBits;
//
//public:
//	Condition(void);
//	~Condition();
//
//	BOOL Initialize(void);
//	void UnInitialize(void);
//
//	void Lock(void) { ::EnterCriticalSection(&cs); }
//	void UnLock(void) { ::LeaveCriticalSection(&cs); }
//
//	// ロックを函誼してから旋喘すること
//	int  IsWait() { return waitBits ? TRUE : FALSE; }
//
//	BOOL Wait(DWORD timeout = INFINITE);
//	void Notify(void);
//};












#endif 