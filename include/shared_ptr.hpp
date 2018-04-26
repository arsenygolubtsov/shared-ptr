#include <iostream>

template <typename T>
class shared_ptr{
private:
	size_t * counter_;
	T * ptr_;
public:
	shared_ptr(T * ptr = nullptr){
		ptr_ = ptr;
		if(ptr){
			*counter_ = new std::size_t(1);
		}
		else{
			counter_ = nullptr;
		}
	}
	~shared_ptr(){
		if(ptr_){
			delete ptr_;
			--*counter_;
		}
		if(*counter_ == 0){
			delete counter_;
		}
	}
	shared_ptr(shared_ptr <T> const & other){
		ptr_ = other.ptr_;
		if(ptr_){
			counter_ = other.counter_;
			++*counter_;
		}
		else{
			counter_ = nullptr;
		}
	}
	shared_ptr & operator =(shared_ptr <T> const & other){
		if (ptr_ != other.ptr_){
			if(ptr_){
				if(*counter_ == 1){
					delete ptr_;
					delete counter_;
				}
				else{
					--*counter_;
				}
			}
			ptr_ = other.ptr_;
			counter_ = other.counter_;
			++*counter_;
		}
		return *this;
	}
			
	void reset(T * ptr){
		if(ptr_){
			if(*counter_ == 1){
				delete ptr_;
				delete conter_;
			}
			else{
				--*counter_;
			}
		}
		ptr_ = other.ptr_;
		if(ptr_){
			counter_ = new std::size_t(1);
		}
		else{
			counter_ = nullptr;
		}
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
	void swap(shared_ptr & other){
		std::swap(ptr_, other.ptr_);
		std::swap(counter_, other.counter_);
	}
};
