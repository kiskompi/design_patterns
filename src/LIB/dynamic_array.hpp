#pragma once
#include <stdexcept>      // std::out_of_range, may implement my own later (just for fun)
#include <functional>
namespace own{
	template<typename val_t>
	class forward_iterator {
		val_t* pointed;
	public:
		forward_iterator  ();
		~forward_iterator ();

		forward_iterator (val_t*);
		forward_iterator (const forward_iterator&);

		bool operator== (const forward_iterator&) const;
		bool operator!= (const forward_iterator&) const;

		forward_iterator& operator=  (const forward_iterator&);
		forward_iterator& operator++ ();
		const val_t& operator*		 () const;
		forward_iterator* operator-> ();

//			void accept_visitor(Visitor& v);
	};
	template<typename val_t>
	class dynamic_array
	{
		typedef val_t* array_ptr;

		array_ptr m_start;		// the adress of the 0th element;
		size_t	  m_size;		// the # of elements in the array
		size_t	  m_capacity;	// the reserved size of the array

	public:
		friend class forward_iterator<val_t>;
		typedef forward_iterator<val_t> iterator;
		dynamic_array();
		dynamic_array(size_t const &);
		~dynamic_array();

		// Capacity
		size_t	size();
		size_t	capacity();
		void	resize(size_t const &);
		void	reserve(size_t const &);
		bool	empty();

		// Element access
		val_t& at(size_t  const &);
		val_t& front();
		val_t& back();
		val_t& operator[](size_t const &);

		// Modifiers
		dynamic_array<val_t>& operator=(dynamic_array<val_t>  const &);
		void push_back(val_t);
		void pop_back();
		void insert(iterator pos, const val_t& va);
		iterator erease(iterator pos);
		void clear();

		// Iterators
		const iterator& begin () const;
		const iterator& end   () const;

		iterator begin ();
		iterator end   ();
	};

	// class Visitor {
	// 	std::function<void ()> m_func;
	// 	Visitor (std::function<void ()> func) {
	// 		m_func = func;
	// 	}
	// public:
	// 	template<typename T>
	// 	void visit (T& v) {
	// 		v.accept_visitor(this);
	// 	} 
	// }

	template<typename val_t>
	inline dynamic_array<val_t>::dynamic_array():
		m_start(new val_t()),	// later could be replaced with allocator
		m_capacity(0),
		m_size(0)
	{	
	}

	template<typename val_t>
	inline dynamic_array<val_t>::dynamic_array(size_t const &capacity):
		m_start(new val_t[capacity]), // later could be replaced with allocator
		m_capacity(capacity),
		m_size(0)
	{
	}

	template<typename val_t>
	inline dynamic_array<val_t>::~dynamic_array()
	{
		delete[] m_start;
	}

	template<typename val_t>
	size_t	dynamic_array<val_t>::size()
	{
		return m_size;
	}
	
	template<typename val_t>
	size_t	dynamic_array<val_t>::capacity()
	{
		return m_capacity;
	}
	
	template<typename val_t>
	void	dynamic_array<val_t>::resize(size_t const &newm_size)
	{
		m_size = newm_size;
	}
	
	template<typename val_t>
	void	dynamic_array<val_t>::reserve(size_t const &new_cap)
	{
		m_capacity = new_cap;
	}
	
	template<typename val_t>
	bool	dynamic_array<val_t>::empty()
	{
		return m_size == 0;
	}

	
	template<typename val_t>
	dynamic_array<val_t>& dynamic_array<val_t>::operator=(dynamic_array<val_t>  const & other)
	{
		m_size = other.m_size;
		m_capacity = other.m_capacity;

		m_start = new val_t[m_capacity];
		
		for (size_t i = 0; i < m_size; i++)
		{
			m_start[i] = other.m_start[i];
		}
	}
	
	template<typename val_t>
	void dynamic_array<val_t>::push_back(val_t value)
	{
		if (m_capacity  == m_size) {
			if (m_capacity == 0) ++m_capacity;
			m_capacity += m_capacity;
			val_t* tmp = m_start;
			val_t* tmp2 = new val_t[m_capacity];
			
			for (size_t i = 0; i < m_size; ++i)
			{
				tmp2[i] = tmp[i];
			}
			tmp2[m_size] = value;

			m_start = tmp2;
		}
		else {
			m_start[m_size] = value;
		}
		++m_size;
	}
	
	template<typename val_t>
	void dynamic_array<val_t>::pop_back(){
		--m_size;
	}
	
	template<typename val_t>
	void dynamic_array<val_t>::insert(iterator pos, const val_t& value)
	{
		// TODO insert
	}
	
	template<typename val_t>
	typename dynamic_array<val_t>::iterator dynamic_array<val_t>::erease(iterator pos)
	{
		// An iterator pointing to the new location of the element 
		// that followed the last element erased by the function call.
		// This is the container end if the operation erased the last 
		// element in the sequence.
		size_t pos_num = pos->pointed - m_start; // distance between the two pointers
		--m_size;

		for (size_t i = pos_num; i < m_size; ++i)
		{
			m_start[i] = m_start[i + 1];
		}

		return iterator(&m_start[pos_num]);
	}
	
	template<typename val_t>
	void dynamic_array<val_t>::clear()
	{
		m_size = 0;
	}

	template<typename val_t>
	val_t& dynamic_array<val_t>::at(size_t const &pos)
	{
		if (pos < m_size)
			return m_start[pos];
		throw new std::out_of_range("OoR");
	}
	
	template<typename val_t>
	val_t& dynamic_array<val_t>::front()
	{
		return m_start[0];
	}
	
	template<typename val_t>
	val_t& dynamic_array<val_t>::back()
	{
		return m_start[m_size - 1];
	}
	
	// template<typename val_t>
	// val_t* dynamic_array<val_t>::begin()
	// {
	// 	return &m_start[0];
	// }
	// 
	// template<typename val_t>
	// val_t* dynamic_array<val_t>::end()
	// {
	// 	return &m_start[m_size - 1];
	// }

	template<typename val_t>
	val_t& dynamic_array<val_t>::operator[](size_t const &pos)
	{
		return m_start[pos];
	}

	template<typename val_t>
	const typename dynamic_array<val_t>::iterator& dynamic_array<val_t>::iterator() const
	{
		return iterator(m_start[0]);
	}
	
	template<typename val_t>
	const typename dynamic_array<val_t>::iterator& dynamic_array<val_t>::end() const
	{
		return iterator(m_start [m_size]);
	}

	template<typename val_t>
	typename dynamic_array<val_t>::iterator dynamic_array<val_t>::begin() 
	{
		return iterator(m_start[0]);
	}
	
	template<typename val_t>
	typename dynamic_array<val_t>::iterator dynamic_array<val_t>::end() 
	{
		return iterator(m_start[m_size]);
	}
	// --------- iterator ---------- //

	template<typename val_t>
	forward_iterator<val_t>::forward_iterator()
	{
		pointed = nullptr;
	}

	template<typename val_t>
	forward_iterator<val_t>::~forward_iterator() 
	{
	}

	template<typename val_t>
	forward_iterator<val_t>::forward_iterator(val_t* point)
	{
		pointed = point;
	}

	template<typename val_t>
	forward_iterator<val_t>::forward_iterator (const forward_iterator<val_t>& other) 
	{
		pointed = other.pointed;
	}

	template<typename val_t>
	bool forward_iterator<val_t>::operator==(const forward_iterator<val_t>& other) const 
	{
		return pointed == other.pointed;
	}

	template<typename val_t>
	bool forward_iterator<val_t>::operator!=(const forward_iterator<val_t>& other) const 
	{
		return pointed != other.pointed;
	}

	template<typename val_t>
	forward_iterator<val_t>& forward_iterator<val_t>::operator=(const forward_iterator<val_t>& other) 
	{
		pointed = other.pointed;
	}

	template<typename val_t>
	forward_iterator<val_t>& forward_iterator<val_t>::operator++() 
	{
		pointed += sizeof(val_t);
		return *this;
	}

	template<typename val_t>
	const val_t& forward_iterator<val_t>::operator*() const 
	{
		return *pointed;
	}

	template<typename val_t>
	forward_iterator<val_t><val_t>* forward_iterator<val_t>::operator->() 
	{
		return (this);
	}
	
	// template<typename val_t>
	// void dynamic_array<val_t>::iterator::accept_visitor(Visitor& v) 
	// {
	// 	v.visit(this);
	// }
}
