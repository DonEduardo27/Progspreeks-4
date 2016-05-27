# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP

# include <cstddef>
// List . hpp
template < typename T >
struct List ;

template < typename T >
struct ListNode
{
	ListNode(): 
	m_value(), m_prev(nullptr), m_next(nullptr) {}

	ListNode(T const& v, ListNode *prev, ListNode *next ): 
	m_value ( v ) , m_prev ( prev ) , m_next ( next )

	{}
	T m_value ;
	ListNode * m_prev ;
	ListNode * m_next ;
};

template < typename T >
struct ListIterator
{
	friend class List <T >;
	// not implemented yet
	private :
	ListNode <T >* m_node = nullptr ;
};

template < typename T >
struct ListConstIterator
{
	friend class List <T >;
	public :
	// not implemented yet
	private :
	ListNode <T >* m_node = nullptr ;
};




template < typename T >
class List
{

public :
List():
m_size{0}, m_first {nullptr}, m_last {nullptr}{};

bool empty () const 
{
	return m_size == 0;
}

std :: size_t size () const 
{
	return m_size;
}

void push_front(T const& val)
{	
	if(empty())
	{
		ListNode <T>* newNodeFirst = new ListNode<T>{val, nullptr, nullptr};

		m_first = newNodeFirst;
		m_last  = newNodeFirst;
		
	}
	else
	{
		ListNode <T>* newNodeFirst = new ListNode<T>{val, nullptr, m_first};
		 m_first = newNodeFirst;
		(*m_first).m_prev = newNodeFirst;
		
	}
	++m_size;
}


void push_back(T const & v)
{	
	if(empty())
	{
		ListNode <T>* newright= new ListNode<T>{v, nullptr, nullptr};
		m_first = newright;
		m_last  = newright;
		
	}else
	{
		ListNode <T>* newright= new ListNode<T>{v, m_last , nullptr};
		 m_last=newright;
		(*m_first).m_next=newright;
	}
	++m_size;
}

void pop_front()
{
	if(!empty())
	{
		
		assert(m_first!=nullptr); // makro
		delete m_first;
		m_first = (*m_first).m_next;

		--m_size;
	}
}
void pop_back()
{
	if(!empty())
	{
		
		assert(m_last!=nullptr); // makro
		delete m_last;
		m_first = (*m_first).m_next;
		
		--m_size;
	}
}


T & front() const
{
	return((*m_first).m_value);
}
T & back() const
{
	return((*m_last).m_value);
}
/*void push_front() 
{

} 
push_back() 

front()
back()*/


	typedef T value_type ;
	typedef T * pointer ;
	typedef const T * const_pointer ;
	typedef T & reference ;
	typedef const T & const_reference ;
	typedef ListIterator <T > iterator ;
	typedef ListConstIterator <T > const_iterator ;
	friend class ListIterator <T >;
	friend class ListConstIterator <T >;// not implemented yet




private :
	std :: size_t m_size = 0;
	ListNode <T >* m_first = nullptr ;
	ListNode <T >* m_last = nullptr ;
};
# endif