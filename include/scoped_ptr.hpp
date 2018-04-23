#include <iostream>

template <typename T>
class scoped_ptr{
private:
	size_t * counter_;
	T * ptr_;
public:
	shared_ptr(T * ptr = nullptr){
		ptr_ = ptr;
		if(ptr){
			*counter_ = new size_t (1);
		}
		else{
			counter_ = nullptr;
		}
	}
	~shared_ptr(){
		if(ptr_){
			delete ptr_;
			*counter_--;
		}
		if(*counter_ == 0){
			delete counter_;
		}
	}
	shared_ptr(shared_ptr <T> const & other){
		if(other.ptr_){
			new T * t = other.ptr_;
			
	void reset(T * ptr){
		if(ptr_){
			delete ptr_;
		}
		ptr_ = ptr;
	}
	T & operator *() const{
		return *ptr_;
	}
	T * operator ->() const{
		return ptr_;
	}
	T * get() const{
		return ptr_;
	}
	void swap(scoped_ptr & other){
		std::swap(ptr_, other.ptr_);
	}
	scoped_ptr & operator=(scoped_ptr const &) = delete;
	scoped_ptr(scoped_ptr const &) = delete;
};
