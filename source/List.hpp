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
	m_value(v), m_prev(prev), m_next (next) {}

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
		return m_node->m_value;
	} 
	pointer operator ->() const 
	{
		return *m_node;
	} 
	Self & operator ++() 
	{
		m_node = m_node -> m_next;
		return *this;
	} 
	Self operator ++( int ) 
	{
		m_node = m_node -> m_next;
		return *this;
	}
	bool operator ==( const Self & x ) const 
	{
		return m_node == x.m_node;
	} 
	bool operator !=( const Self & x ) const 
	{
		return m_node != x.m_node;
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
	typedef T value_type ;
	typedef T * pointer ;
	typedef const T * const_pointer ;
	typedef T & reference ;
	typedef const T & const_reference ;
	typedef ListIterator <T > iterator ;
	typedef ListConstIterator <T > const_iterator ;
	friend class ListIterator <T >;
	friend class ListConstIterator <T >;
	List(): m_size{0}, m_first {nullptr}, m_last {nullptr}{};
	//erste idee: List(): m_size{origin.size()}, m_first {origin.m_first}, m_last {origin.m_last}{}; <- wäre aber keine kope sondern verknüpfung
	List(List<T> const& origin): m_size{0},m_first {nullptr}, m_last {nullptr}
	{
		for(auto i = origin.begin(); i!= origin.end() ; i++)
		{
			push_back(*i);
		}
	}
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
			m_first = new ListNode<T>{val, nullptr, nullptr};
			m_last  = m_first;
		}
		else
		{
			ListNode <T>* newFirst = new ListNode<T>{val, nullptr , m_first};
			
			m_first = newFirst ;
			m_first->m_next->m_prev=m_first;
		}
		++m_size;
	}

	void push_back(T const & val)
	{	
		if(empty())
		{
			m_first = new ListNode<T>{val, nullptr, nullptr};
			m_last  = m_first;
		}
		else
		{
			ListNode <T>* newLast= new ListNode<T>{val, m_last , nullptr };

			m_last = newLast;
			m_last->m_prev->m_next=m_last;
		}
		++m_size;
	}

	void pop_front()
	{
		if(m_first != nullptr)
		{
			assert(m_first != nullptr); // makro
			delete m_first;
			m_first = m_first->m_next;

			--m_size;
		}
	}

	void pop_back()
	{
		if(m_last != nullptr)
		{
			assert(m_last != nullptr); // makro
			delete m_last;
			m_last = m_last->m_prev;
			
			--m_size;
		}
	}

	void clear()
	{
		while(!empty())
		{
			pop_back();
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

	iterator begin() const
	{
		iterator itr{m_first};
		return (itr);
	}

	iterator end  () const
	{
		if(empty())
		{
			return nullptr; 		//fals leer								
		}else if (m_last->m_next == nullptr) // nach dem letzten element? !SOLLTE MAN DAS nicht schon im pushback habe...
		{ 		
					ListNode<T>* node = new ListNode<T> (); 	//leeres node
					node->m_prev = m_last; 							
					m_last->m_next = node; 					
					return node;
				} else { //letztes element exist bereits!
					return m_last->m_next;										
				}
			
	}




private :
	std :: size_t m_size = 0;
	ListNode <T>* m_first = nullptr ;
	ListNode <T>* m_last = nullptr ;
};

template < typename T >
	bool operator ==( List <T> const & xs , List <T > const & ys )
	{
		if(xs.size() != ys.size()){return false;}
		else
		{
			ListIterator<T> x = xs.begin();
			ListIterator<T> y = ys.begin();
			while(x!= xs.end() and y!= ys.end())
			{
				if(*x != *y){return false;}
				
				x++;
				y++;
			}
		}
		return true;
	}

	template < typename T >
	bool operator !=( List <T > const & xs , List <T > const & ys )
	{
		return !(xs==ys);	
	}
# endif