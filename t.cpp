#include <iostream>
#include <stdlib.h>

struct NodeBase
{
    NodeBase *prev;             // ��������� �� ���������� ������� �������� ������
    NodeBase *next;             // ��������� �� ��������� ������� �������� ������
                                // ��� �������� ������� ������ ����������� ��-���������
                                // ��������� ��������� � ���������� ������� ��������� �� ���� 
  NodeBase() : prev(this), next(this) {}
                                // ��� �������� � ����� ������������, ������� ��������� ��� ����
                                // � ������� ������, ����������� ���� ����������� � ���������� ��������
  NodeBase(NodeBase *prev_, NodeBase *next_)
    : prev(prev_), next(next_)
  {                             // ����������� ���������� � ��������� ��������
                                // � ����������� �������� ��������� ��������� ����������� ������ �������
                                // � � ���������� �������� ���������� ��������� ����������� ������ �������
    prev->next = next->prev = this;
  }
                                // ����������. ��� �������� �������� �������� ������, 
                                // ������� ������� ��� ���� �� ������
  virtual ~NodeBase()
  {
    prev->next = next;
    next->prev = prev;
  }
};
 
                                // ������� �������� ������, ��� ���������� ������.
template <typename ValueType>
struct Node: public NodeBase
{
  ValueType value;              // �� ��������, ������� ������ �����
                                // ����������� ����������� �������� � �������� ���������� ������
  Node(NodeBase *prev_, NodeBase *next_, ValueType value)
    : NodeBase(prev_, next_), value(value) {}
};
 
                                // ����������, ������ ����������� ������
template <typename ValueType>
class List
{
  private:
  // ������� ��������.
  // ��� ���� next ��������� �� ������ ������� ������
  // ���� prev ���������� �� ��������� ������� ������
  // ���� ������ ����, next == prev == &base
  NodeBase base;
 public:
                                // ������������ ��-��������� ������ � �������� ������, �� ������ ���� ��������
  List() : base() {};
 
  ~List()                       // ���������� ������� ������ �������� Clear
  {
    Clear();
  }
                                
  bool Empty()                  // ������� ���������, ������ �� ������
  {
                                // ������ ������, ���� ������� ������� ��������� ��� �� ����
    return ((base.next == &base) && (base.prev == &base));
  }
  void Clear()
  {
                                // ���� ������ �� ����
    while (!Empty())
                                // ��������� ������ �������
                                // ������ �� �������� �� ������ ������� ���������� ������ ��������
      delete base.next;
  }
                                
  void PushBack(const ValueType &value) // ���������� �������� � ����� ������
  {
                                        // ������ ��������� ����� ������� ������,
                                        // �� ��������� ������� ����������� ������ NodeBase
    new Node<ValueType>(base.prev, &base, value);
  }
                                        // �������� ���������� ��������
  void PopBack()
  {
    // ��������� ������� �������� ������ 
    // (� ������ ������ ���������, �� � ��������, ��������� � �����)
    // ������ �� ������������ �������� �������� �� ������ �������� ����������
    // ������ NodeBase
    delete base.prev;
  }
  void PrintAll()
  {
    // ������� ���� ��������� � ����� �����
    for (NodeBase *node = base.next; node != &base; node = node->next)
      // ��� ��������� �������� ������� ������ ���������� � ���� Node*
      std::cout << static_cast< Node<ValueType>* >(node)->value;
  }
  void search(string par_search)//�-��� ������
  {
      Bus *E = A;
      if (A == 0)
          return;
      while(E)
      {
          if (par_search ==  E->number)
          {
              cout<<endl<<A->number 
                  <<"\t"<<A->driver
                  <<"\t"<<A->route
                  <<"\t"<<A->deport
                  <<endl;
              break;
          }
                E = E->next;
      }
  }
};
		
};


using namespace std;
int main(){
	list2<int> li;
	
		
}
