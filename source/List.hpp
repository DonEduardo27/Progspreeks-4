# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP

# include <iostream>//debug
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
	typedef ListIterator <T> Self ;
	typedef T value_type ;
	typedef T * pointer ;
	typedef T & reference ;
	typedef ptrdiff_t difference_type ;
	typedef std::forward_iterator_tag iterator_category ;


	friend class List <T>;

	ListIterator():  m_node{nullptr} {} 
	ListIterator( ListNode <T> *n ): m_node{n} {} 

	reference operator* () const 
	{
		return *m_node;
	} 
	pointer operator ->() const 
	{
		return m_node;
	} 
	Self & operator ++() 
	{
		return m_node.next();
	} 

	Self operator ++( int ) 
	{
		return *m_node + 1;
	}
	bool operator ==( const Self & x ) const 
	{
		return *m_node == x;
	} 
	bool operator !=( const Self & x ) const 
	{
		return *m_node != x;
	} 
	Self next () const
	{
		if (m_node) return ListIterator (m_node -> m_next);
		else        return ListIterator (nullptr);
	}

private :
	ListNode <T> *m_node = nullptr ;
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
	List(): m_size{0}, m_first {nullptr}, m_last {nullptr}{};

	~List()
	{
		clear();
	}

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

			(*m_first).m_next = newNodeFirst;
			 m_first = newNodeFirst;
		}
		++m_size;
	}

	void push_back(T const & v)
	{	
		if(empty())
		{
			ListNode <T>* newNodeLast= new ListNode<T>{v, nullptr, nullptr};
			m_first = newNodeLast;
			m_last  = newNodeLast;
		}
		else
		{
			ListNode <T>* newNodeLast= new ListNode<T>{v, m_last , nullptr};
			(*m_first).m_prev=newNodeLast;
			 m_last=newNodeLast;
		}
		++m_size;
	}

	void pop_front()
	{
		if(!empty())
		{
			assert(m_first != nullptr); // makro
			delete m_first;
			m_first = m_first->m_next;

			--m_size;
		}
	}

	void pop_back()
	{
		if(!empty())
		{
			assert(m_last!=nullptr); // makro
			delete m_last;
			m_last = m_last->m_prev;
			
			--m_size;
		}
	}

	void clear()
	{
		while(m_size > 0)
		{
			pop_back();
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