---
title: "Classe queue | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std.queue"
  - "std::queue"
  - "queue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe queue"
ms.assetid: 28c20ab0-3a72-4185-9e0f-5a44eea0e204
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe queue
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador de contêiner de modelo que fornece uma restrição da funcionalidade de algum tipo de contêiner subjacente, limitando o acesso aos elementos frontal e traseiro. Elementos podem ser adicionados na parte traseira ou removidos da frente e elementos podem ser inspecionados até o final da fila.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type, class Container = deque <Type>>  
class queue  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de dados do elemento a ser armazenado na fila  
  
 `Container`  
 O tipo do contêiner subjacente usado para implementar a fila.  
  
## <a name="remarks"></a>Comentários  
 Os elementos da classe **tipo** estipulado no modelo do primeiro parâmetro de um objeto de fila é sinônimo de [value_type](#queue__value_type) e deve corresponder ao tipo de elemento na classe de contêiner subjacente **contêiner** estipulado, o segundo parâmetro de modelo. O **tipo** deve ser atribuível, para que seja possível copiar objetos desse tipo e atribuir valores a variáveis desse tipo.  
  
 Classes de contêiner subjacente adequadas para a fila incluem [deque](../standard-library/deque-class.md) e [lista](../standard-library/list-class.md), ou qualquer outro contêiner de sequência que oferece suporte às operações de `front`, **novamente**, `push_back`, e `pop_front`. A classe de contêiner subjacente é encapsulada dentro do adaptador do contêiner, que expõe apenas o conjunto limitado de funções de membro de contêiner de sequência como uma interface pública.  
  
 Objetos de fila são igualdade comparável se e somente se os elementos da classe **tipo** são comparáveis a igualdade e têm menos-que comparável se e somente se os elementos da classe **tipo** menores-que comparável.  
  
 Há três tipos de adaptadores de contêiner definidos pela STL: priority_queue de pilha e fila. Cada restringe a funcionalidade de uma classe de contêiner subjacente para fornecer uma interface com precisão controlada a uma estrutura de dados padrão.  
  
-   O [classe de pilha](../standard-library/stack-class.md) oferece suporte a uma estrutura de dados da primeira a sair (UEPS) last-in. Um bom análogo para ter em mente seria uma pilha de pratos. Elementos (pratos) podem inseridos, inspecionados ou removidos somente da parte superior da pilha, o que é o último elemento no final do recipiente de base. A restrição para acessar apenas o primeiro elemento é o motivo para usar a classe de pilha.  
  
-   A classe de fila dá suporte a uma estrutura de dados da fila (FIFO) primeiro a entrar. Um bom análogo para ter em mente seria pessoas alinhar um caixa eletrônico. Elementos (pessoas) podem ser adicionados à parte traseira da linha e são removidos do início da linha. Frente e verso de uma linha podem ser inspecionadas. A restrição para acessar apenas os elementos frontal e traseiro dessa maneira é o motivo para usar a classe de fila.  
  
-   O [classe priority_queue](../standard-library/priority-queue-class.md) ordena seus elementos de modo que sempre é o maior elemento na posição superior. Ele oferece suporte à inserção de um elemento e a inspeção e a remoção do elemento superior. Um bom análogo para ter em mente seria pessoas alinhar onde eles estão organizados por idade, altura ou algum outro critério.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[fila](#queue__queue)|Constrói um `queue` que é vazio ou que é uma cópia de um objeto de contêiner de base.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[container_type](#queue__container_type)|Um tipo que fornece um contêiner para ser adaptado por base o `queue`.|  
|[size_type](#queue__size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `queue`.|  
|[value_type](#queue__value_type)|Um tipo que representa o tipo de objeto armazenado como um elemento em um `queue`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[Voltar](#queue__back)|Retorna uma referência para a última e mais recentemente adicionado um elemento na parte de trás do `queue`.|  
|[vazio](#queue__empty)|Testa se o `queue` está vazia.|  
|[frente](#queue__front)|Retorna uma referência para o primeiro elemento da frente do `queue`.|  
|[pop](#queue__pop)|Remove um elemento na parte frontal do `queue`.|  
|[envio por push](#queue__push)|Adiciona um elemento para trás o `queue`.|  
|[tamanho](#queue__size)|Retorna o número de elementos no `queue`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< fila>  
  
 **Namespace:** std  
  
##  <a name="a-namequeuebacka-queueback"></a><a name="queue__back"></a>  Queue:: back  
 Retorna que uma referência para a última e mais recentemente adicionado um elemento na parte posterior da fila.  
  
```  
reference back();

const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O último elemento da fila. Se a fila estiver vazia, o valor de retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno **novamente** é atribuído a um `const_reference`, o objeto de fila não pode ser modificado. Se o valor de retorno **novamente** é atribuído a um **referência**, o objeto de fila pode ser modificado.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento em uma fila vazia.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_back.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   queue <int> q1;  
  
   q1.push( 10 );  
   q1.push( 11 );  
  
   int& i = q1.back( );  
   const int& ii = q1.front( );  
  
   cout << "The integer at the back of queue q1 is " << i   
        << "." << endl;  
   cout << "The integer at the front of queue q1 is " << ii   
        << "." << endl;  
}  
```  
  
##  <a name="a-namequeuecontainertypea-queuecontainertype"></a><a name="queue__container_type"></a>  Queue:: container_type  
 Um tipo que fornece o recipiente base ser adaptada.  
  
```  
typedef Container container_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo `Container`. Duas classes de contêiner de sequência STL — a classe de lista e a classe deque padrão — atendem aos requisitos de ser usado como o contêiner de base para um objeto de fila. Tipos definidos pelo usuário que satisfazem os requisitos também podem ser usados.  
  
 Para obter mais informações sobre `Container`, consulte a seção comentários a [classe queue](../standard-library/queue-class.md) tópico.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [fila](#queue__queue) para obter um exemplo de como declarar e usar `container_type`.  
  
##  <a name="a-namequeueemptya-queueempty"></a><a name="queue__empty"></a>  Queue:: Empty  
 Testa se uma fila está vazia.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se a fila está vazia; **False** se a fila está vazia.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_empty.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
using namespace std;  
  
   // Declares queues with default deque base container  
   queue <int> q1, q2;  
  
   q1.push( 1 );  
  
   if ( q1.empty( ) )  
      cout << "The queue q1 is empty." << endl;  
   else  
      cout << "The queue q1 is not empty." << endl;  
  
   if ( q2.empty( ) )  
      cout << "The queue q2 is empty." << endl;  
   else  
      cout << "The queue q2 is not empty." << endl;  
}  
```  
  
```Output  
The queue q1 is not empty.  
The queue q2 is empty.  
```  
  
##  <a name="a-namequeuefronta-queuefront"></a><a name="queue__front"></a>  Queue:: front  
 Retorna uma referência para o primeiro elemento na frente da fila.  
  
```  
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro elemento da fila. Se a fila estiver vazia, o valor de retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `front` é atribuído a um `const_reference`, o objeto de fila não pode ser modificado. Se o valor de retorno de `front` é atribuído a um **referência**, o objeto de fila pode ser modificado.  
  
 A função de membro retorna um **referência** para o primeiro elemento da sequência controlada, que deve ser não vazio.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento em uma fila vazia.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_front.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main() {  
   using namespace std;  
   queue <int> q1;  
  
   q1.push( 10 );  
   q1.push( 20 );  
   q1.push( 30 );  
  
   queue <int>::size_type i;  
   i = q1.size( );  
   cout << "The queue length is " << i << "." << endl;  
  
   int& ii = q1.back( );  
   int& iii = q1.front( );  
  
   cout << "The integer at the back of queue q1 is " << ii   
        << "." << endl;  
   cout << "The integer at the front of queue q1 is " << iii   
        << "." << endl;  
}  
```  
  
##  <a name="a-namequeuepopa-queuepop"></a><a name="queue__pop"></a>  Queue:: pop  
 Remove um elemento do início da fila.  
  
```  
void pop();
```  
  
### <a name="remarks"></a>Comentários  
 A fila deve ser não vazia para aplicar a função de membro. O início da fila é a posição ocupada pelo elemento adicionado mais recentemente e o último elemento no final do contêiner.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_pop.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   queue <int> q1, s2;  
  
   q1.push( 10 );  
   q1.push( 20 );  
   q1.push( 30 );  
  
   queue <int>::size_type i;  
   i = q1.size( );  
   cout << "The queue length is " << i << "." << endl;  
  
   i = q1.front( );  
   cout << "The element at the front of the queue is "  
        << i << "." << endl;  
  
   q1.pop( );  
  
   i = q1.size( );  
   cout << "After a pop the queue length is "   
        << i << "." << endl;  
  
   i = q1. front ( );  
   cout << "After a pop, the element at the front of the queue is "  
        << i << "." << endl;  
}  
```  
  
```Output  
The queue length is 3.  
The element at the front of the queue is 10.  
After a pop the queue length is 2.  
After a pop, the element at the front of the queue is 20.  
```  
  
##  <a name="a-namequeuepusha-queuepush"></a><a name="queue__push"></a>  Queue:: push  
 Adiciona um elemento na parte traseira da fila.  
  
```  
void push(const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 O elemento adicionado à parte traseira da fila.  
  
### <a name="remarks"></a>Comentários  
 Parte de trás da fila é a posição ocupada pelo elemento adicionado mais recentemente e o último elemento no final do contêiner.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_push.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   queue <int> q1;  
  
   q1.push( 10 );  
   q1.push( 20 );  
   q1.push( 30 );  
  
   queue <int>::size_type i;  
   i = q1.size( );  
   cout << "The queue length is " << i << "." << endl;  
  
   i = q1.front( );  
   cout << "The element at the front of the queue is "  
        << i << "." << endl;  
}  
```  
  
```Output  
The queue length is 3.  
The element at the front of the queue is 10.  
```  
  
##  <a name="a-namequeuequeuea-queuequeue"></a><a name="queue__queue"></a>  Queue:: Queue  
 Constrói uma fila que está vazio ou é uma cópia de um objeto de contêiner de base.  
  
```  
queue();

explicit queue(const container_type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O **const** contêiner do qual a fila construída é uma cópia.  
  
### <a name="remarks"></a>Comentários  
 Contêiner de fila de base padrão é deque. Você também pode especificar a lista como um contêiner de base, mas não é possível especificar o vetor, porque ele não tem a necessário `pop_front` função de membro.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_queue.cpp  
// compile with: /EHsc  
#include <queue>  
#include <vector>  
#include <list>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares queue with default deque base container  
   queue <char> q1;  
  
   // Explicitly declares a queue with deque base container  
   queue <char, deque<char> > q2;  
  
   // These lines don't cause an error, even though they  
   // declares a queue with a vector base container  
   queue <int, vector<int> > q3;  
   q3.push( 10 );  
   // but the following would cause an error because vector has   
   // no pop_front member function  
   // q3.pop( );  
  
   // Declares a queue with list base container  
   queue <int, list<int> > q4;  
  
   // The second member function copies elements from a container  
   list<int> li1;  
   li1.push_back( 1 );  
   li1.push_back( 2 );  
   queue <int, list<int> > q5( li1 );  
   cout << "The element at the front of queue q5 is "  
        << q5.front( ) << "." << endl;  
   cout << "The element at the back of queue q5 is "  
        << q5.back( ) << "." << endl;  
}  
```  
  
```Output  
The element at the front of queue q5 is 1.  
The element at the back of queue q5 is 2.  
```  
  
##  <a name="a-namequeuesizea-queuesize"></a><a name="queue__size"></a>  Queue:: Size  
 Retorna o número de elementos na fila.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento atual da fila.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_size.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   queue <int> q1, q2;  
   queue <int>::size_type i;  
  
   q1.push( 1 );  
   i = q1.size( );  
   cout << "The queue length is " << i << "." << endl;  
  
   q1.push( 2 );  
   i = q1.size( );  
   cout << "The queue length is now " << i << "." << endl;  
}  
```  
  
```Output  
The queue length is 1.  
The queue length is now 2.  
```  
  
##  <a name="a-namequeuesizetypea-queuesizetype"></a><a name="queue__size_type"></a>  Queue:: size_type  
 Um tipo de inteiro não assinado que pode representar o número de elementos em uma fila.  
  
```  
typedef typename Container::size_type size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o `size_type` do contêiner base adaptado pela fila.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [Queue:: front](#queue__front) para obter um exemplo de como declarar e usar `size_type`.  
  
##  <a name="a-namequeuevaluetypea-queuevaluetype"></a><a name="queue__value_type"></a>  Queue:: value_type  
 Um tipo que representa o tipo de objeto armazenado como um elemento em uma fila.  
  
```  
typedef typename Container::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o `value_type` do contêiner base adaptado pela fila.  
  
### <a name="example"></a>Exemplo  
  
```  
// queue_value_type.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
using namespace std;  
  
   // Declares queues with default deque base container  
   queue<int>::value_type AnInt;  
  
   AnInt = 69;  
   cout << "The value_type is AnInt = " << AnInt << endl;  
  
   queue<int> q1;  
   q1.push(AnInt);  
   cout << "The element at the front of the queue is "  
        << q1.front( ) << "." << endl;  
}  
```  
  
```Output  
The value_type is AnInt = 69  
The element at the front of the queue is 69.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

