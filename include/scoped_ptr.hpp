#include <iostream>

template <typename T>
class scoped_ptr{
pravate:
	T * ptr_;
public:
	scoped_ptr(){
		ptr_ = nullptr;
	}
	~scoped_ptr(){
		if(ptr_){
			delete ptr_;
		}
	}
	void reset(T * ptr){
		if(ptr_){
			delete ptr_;
		}
		ptr_ = ptr;
	}
	T & operator *(){
		return *ptr_;
	}
	T * operator ->(){
		return ptr_;
	}
	T * get(){
		return ptr_;
	}
	void swap(scoped_ptr & other){
		std::swap(ptr_, other.ptr_);
	}
	scoped_ptr & operator=(scoped_ptr const &) = delete;
	scoped_ptr(scoped_ptr const &) = delete;
};
