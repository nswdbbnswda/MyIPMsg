#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<Windows.h>
#include"tlib.h"


template<class T> class THashTblT;

template<class T>
class THashObjT {
public:
	THashObjT	*prevHash;
	THashObjT	*nextHash;
	T				hashId;

public:
	THashObjT() { prevHash = nextHash = NULL; hashId = 0; }
	virtual ~THashObjT() { if (prevHash && prevHash != this) UnlinkHash(); }

	virtual BOOL LinkHash(THashObjT *top) {
		if (prevHash) return FALSE;
		this->nextHash = top->nextHash;
		this->prevHash = top;
		top->nextHash->prevHash = this;
		top->nextHash = this;
		return TRUE;
	}
	virtual BOOL UnlinkHash() {
		if (!prevHash) return FALSE;
		prevHash->nextHash = nextHash;
		nextHash->prevHash = prevHash;
		prevHash = nextHash = NULL;
		return TRUE;
	}
	friend THashTblT<T>;
};

//哈希表
template<class T>
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
	virtual BOOL Init(int _hashNum) {
		if ((hashTbl = new THashObjT<T>[hashNum = _hashNum]) == NULL) {//创建一个数组
			return	FALSE;	// VC4's new don't occur exception
		}
		for (int i = 0; i < hashNum; i++) {
			THashObjT<T>	*obj = hashTbl + i;
			obj->prevHash = obj->nextHash = obj;
		}
		registerNum = 0;
		return	TRUE;
	}
	virtual void UnInit() {
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
	virtual void Register(THashObjT<T> *obj, T hash_id) {
		obj->hashId = hash_id;
		if (obj->LinkHash(hashTbl + (hash_id % hashNum))) registerNum++;
	}
	virtual void UnRegister(THashObjT<T> *obj) {
		if (obj->UnlinkHash()) registerNum--;
	}
	virtual THashObjT<T> *Search(const void *data, T hash_id) {
		THashObjT<T> *top = hashTbl + (hash_id % hashNum);
		for (THashObjT<T> *obj = top->nextHash; obj != top; obj = obj->nextHash) {
			if (obj->hashId == hash_id && IsSameVal(obj, data)) return obj;
		}
		return	NULL;
	}
	virtual int		GetRegisterNum() { return registerNum; }
};

typedef THashObjT<unsigned int>	THashObj;
typedef THashTblT<unsigned int>	THashTbl;
typedef THashObjT<unsigned _int64> THashObj64;
typedef THashTblT<unsigned _int64> THashTbl64;


#endif 