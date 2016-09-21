#include   "../../C/UTILITY.H"
template <class Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node<Node_entry> *next;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link = NULL);
};
 
template <class List_entry>
class List {
public:
//  Specifications for the methods of the list ADT go here.
 
   List();
   int size() const;
   bool full() const;
   bool empty() const;
   void clear();
   void traverse(void (*visit)(List_entry &));
   Error_code retrieve(int position, List_entry &x) const;
   Error_code replace(int position, const List_entry &x);
   Error_code remove(int position, List_entry &x);
   Error_code insert(int position, const List_entry &x);
 
//  The following methods replace compiler-generated defaults.
   ~List();
   List(const List<List_entry> &copy);
   void operator =(const List<List_entry> &copy);
protected:
//  Data members for the linked list implementation now follow.
   int count;
   Node<List_entry> *head;

//  The following auxiliary function is used to locate list positions
   Node<List_entry> *set_position(int position) const;
};
 
template <class List_entry>
Node<List_entry>::Node()
{
   next = NULL;
}

template <class List_entry>
Node<List_entry>::Node (List_entry data, Node<List_entry> *link)
{
   entry = data;
   next = link;
}
