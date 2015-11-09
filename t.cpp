#include <iostream>
#include <stdlib.h>

struct NodeBase
{
    NodeBase *prev;             // указатель на предыдущий элемент связного списка
    NodeBase *next;             // указатель на следующий элемент связного списка
                                // при создании объекта класса конструктор по-умолчанию
                                // назначает следующий и предыдущий элемент указывать на себя 
  NodeBase() : prev(this), next(this) {}
                                // при создании с таким констуктором, элемент добавляет сам себя
                                // в связный список, представляя себя предыдущему и следующему элементу
  NodeBase(NodeBase *prev_, NodeBase *next_)
    : prev(prev_), next(next_)
  {                             // назначаются предыдущий и следующий элементы
                                // у предыдущего элемента следующим элементом назначается данный элемент
                                // и у следующего элемента предыдущим элементом назначается данный элемент
    prev->next = next->prev = this;
  }
                                // деструктор. при удалении элемента связного списка, 
                                // элемент убирает сам себя из списка
  virtual ~NodeBase()
  {
    prev->next = next;
    next->prev = prev;
  }
};
 
                                // элемент связного списка, уже содержащий данные.
template <typename ValueType>
struct Node: public NodeBase
{
  ValueType value;              // то значение, которое хранит класс
                                // конструктор подставляет значения и вызывает конструтор предка
  Node(NodeBase *prev_, NodeBase *next_, ValueType value)
    : NodeBase(prev_, next_), value(value) {}
};
 
                                // собственно, шаблон двусвязного списка
template <typename ValueType>
class List
{
  private:
  // базовый эелемент.
  // его поле next указывает на первый элемент списка
  // поле prev указываеты на последний элемент списка
  // если список пуст, next == prev == &base
  NodeBase base;
 public:
                                // конструктору по-умолчанию делать в принципе нечего, он должен быть объявлен
  List() : base() {};
 
  ~List()                       // деструктор удаляет список функцией Clear
  {
    Clear();
  }
                                
  bool Empty()                  // функция проверяет, пустой ли список
  {
                                // список пустой, если базовый элемент указывает сам на себя
    return ((base.next == &base) && (base.prev == &base));
  }
  void Clear()
  {
                                // пока список не пуст
    while (!Empty())
                                // удаляется первый элемент
                                // работу по удалению из списка сделает деструктор класса элемента
      delete base.next;
  }
                                
  void PushBack(const ValueType &value) // добавление элемента в конец списка
  {
                                        // просто создается новый элемент списка,
                                        // всё остальное сделает конструктор класса NodeBase
    new Node<ValueType>(base.prev, &base, value);
  }
                                        // удаление последнего элемента
  void PopBack()
  {
    // удаляется элемент связного списка 
    // (в данном случае последний, но в принципе, сработает с любым)
    // работу по фактическому удалению элемента из списка выполнит деструктор
    // класса NodeBase
    delete base.prev;
  }
  void PrintAll()
  {
    // перебор всех элементов в одном цикле
    for (NodeBase *node = base.next; node != &base; node = node->next)
      // для получения значения элемент списка приводится к типу Node*
      std::cout << static_cast< Node<ValueType>* >(node)->value;
  }
  void search(string par_search)//ф-ция поиска
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
