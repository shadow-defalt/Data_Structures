#include <iostream>


using namespace std;

template <class sType>

class Queue

{
	private: 
	List<sType> list;

	public:
		Queue()
		{
			list.First();

		}

		Queue(const Queue& s)
		{
			*this = s;

		}

		void operator=(const Queue& s)
		{
			list = s.list;
			list.First();
		}

		void Enqueue(sType data)
		{
			list.Last();
			list.InsertAfter(data);
		}

		sType Dequeue()
		{
			sType top = Peek();
			list.Remove();
			return top;
		}

		sType Peek()
		{
			list.First();
			return list.GetValue();
		}

		int Size()
		{
			return list.GetSize();
		}

		bool IsEmpty()
		{
			return list.IsEmpty();
		}

		bool IsFull()
		{
			return list.IsFull();
		}

		Queue operator+(const Queue& s) const
		{
			Queue newQueue = *this;

			newQueue.list = newQueue.list + s.list;

			return newQueue;
		}

		bool operator==(const Queue& s) const
		{
			return ((*this).list == s.list);
		}

		bool operator!=(const Queue& s) const
		{
			return(!(s==(*this)));
		}

		friend ostream& operator<<(ostream& out, const Queue& s)
		{
			out << s.list;
			return out;
		}
};