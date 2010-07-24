/************************************************************************
*
*  LibTLib
*  Copyright (C) 2010  Thor Qin
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* Author: Thor Qin
* Bug Report: thor.qin@gmail.com
*
**************************************************************************/

#ifndef _TLIBPTR_H_
#define _TLIBPTR_H_

#include "tlibbase.h"

namespace tlib
{

// Derive from `Object` to use `RefPtr`.
class Object
{
protected:
	inline Object();
	inline virtual ~Object() = 0;
private:
	Object(const Object&);
public:
	void reference(void);
	void dereference(void);
private:
#ifdef WIN32
	volatile long _ref;
#else
	volatile int _ref;
#endif
};

inline
Object::Object() : _ref(1)
{
}

inline
Object::~Object()
{
}



template <class T> 
class RefPtr
{
public:
	template <class Q>
	friend class RefPtr;
	
	inline RefPtr();

	inline RefPtr(const RefPtr<T>& src);

	template <class Q> 
	inline RefPtr(const RefPtr<Q>& src);

	explicit inline RefPtr(T* p);

	inline ~RefPtr();

	inline RefPtr<T>& operator = (const RefPtr<T>& src);

	template <class Q>
	inline RefPtr<T>& operator = (const RefPtr<Q>& src);

	inline bool operator == (const RefPtr<T>& other) const;

	inline bool operator != (const RefPtr<T>& other) const;

	inline operator bool() const throw();

	inline bool operator !() const throw();

	inline T* operator ->() const throw();

	inline T& operator *() const throw(std::runtime_error);

	inline void swap(RefPtr<T>& other);

	inline void reset();

	template <class Q>
	static inline RefPtr<T> cast_dynamic(const RefPtr<Q>& src);

	template <class Q>
	static inline RefPtr<T> cast_static(const RefPtr<Q>& src);

	template <class Q>
	static inline RefPtr<T> cast_const(const RefPtr<Q>& src);
private:
	T* _p;
};


template <class T> inline
RefPtr<T>::RefPtr(): _p(0)
{
}

template <class T> inline
RefPtr<T>::RefPtr(T* p): _p(p)
{
}

template <class T> inline
RefPtr<T>::RefPtr(const RefPtr<T>& src): _p(src._p)
{
	if(_p)
		_p->reference();
}

template <class T>
	template <class Q> inline
RefPtr<T>::RefPtr(const RefPtr<Q>& src): _p(src._p)
{
	if(_p)
		_p->reference();
}

template <class T> inline
RefPtr<T>::~RefPtr()
{
	if (_p)
		_p->dereference();
}

template <class T> inline
RefPtr<T>& RefPtr<T>::operator = (const RefPtr<T>& src)
{
	RefPtr<T> temp(src);
	this->swap(temp);
	return *this;
}

template <class T>
template <class Q> inline
RefPtr<T>& RefPtr<T>::operator = (const RefPtr<Q>& src)
{
	RefPtr<T> temp(src);
	this->swap(temp);
	return *this;
}

template <class T> inline
bool RefPtr<T>::operator == (const RefPtr<T>& other) const
{
	return (_p == other._p);
}

template <class T> inline
bool RefPtr<T>::operator != (const RefPtr<T>& other) const
{
	return (_p != other._p);
}

template <class T> inline
RefPtr<T>::operator bool() const throw()
{
	return (_p != 0);
}

template <class T> inline
bool RefPtr<T>::operator !() const throw()
{
	return (_p == 0);
}

template <class T> inline
T* RefPtr<T>::operator ->() const throw()
{
	return _p;
}

template <class T> inline
T& RefPtr<T>::operator *() const throw(std::runtime_error)
{
	if (!_p)
		throw std::runtime_error("pointer error.");
	return (*_p);
}

template <class T> inline
void RefPtr<T>::swap(RefPtr<T>& other)
{
  T *const temp = _p;
  _p = other._p;
  other._p = temp;
}

template <class T> inline
void RefPtr<T>::reset()
{
	RefPtr<T> temp;
	this->swap(temp);
}

template <class T>
template <class Q> inline
RefPtr<T> RefPtr<T>::cast_dynamic(const RefPtr<Q>& src)
{
	T *const p = dynamic_cast<T*>(src.operator->());
	if(p)
		p->reference();
	return RefPtr<T>(p);
}

template <class T>
template <class Q> inline
RefPtr<T> RefPtr<T>::cast_static(const RefPtr<Q>& src)
{
	T *const p = static_cast<T*>(src.operator->());
	if(p)
		p->reference();
	return RefPtr<T>(p);
}

template <class T>
template <class Q> inline
RefPtr<T> RefPtr<T>::cast_const(const RefPtr<Q>& src)
{
	T *const p = const_cast<T*>(src.operator->());
	if(p)
		p->reference();
	return RefPtr<T>(p);
}

template <class T> inline
void swap(RefPtr<T>& lhs, RefPtr<T>& rhs)
{
	lhs.swap(rhs);
}

} // namespace

#endif
