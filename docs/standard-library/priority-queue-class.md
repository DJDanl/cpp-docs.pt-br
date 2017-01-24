---
title: "Classe priority_queue | Microsoft Docs"
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
  - "std.priority_queue"
  - "priority_queue"
  - "std::priority_queue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe priority_queue"
ms.assetid: 69fca9cc-a449-4be4-97b7-02ca5db9cbb2
caps.latest.revision: 25
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe priority_queue
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para limitar o acesso ao elemento superior de algum tipo de contêiner subjacente, que é sempre o maior ou de maior prioridade. Novos elementos podem ser adicionados para o priority_queue e o elemento superior do priority_queue pode ser inspecionado ou removido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type, class Container= vector <Type>, class Compare= less <typename Container ::value_type>>  
class priority_queue  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de dados do elemento a ser armazenado na priority_queue.  
  
 `Container`  
 O tipo do contêiner subjacente usado para implementar o priority_queue.  
  
 *Comparar*  
 O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no priority_queue. Esse argumento é opcional e o predicado binário **menos***\<***typename** *contêiner***:: value_type***>* é o valor padrão.  
  
## <a name="remarks"></a>Comentários  
 Os elementos da classe **tipo** estipulado no modelo do primeiro parâmetro de um objeto de fila é sinônimo de [value_type](#priority_queue__value_type) e deve corresponder ao tipo de elemento na classe de contêiner subjacente **contêiner** estipulado, o segundo parâmetro de modelo. O **tipo** deve ser atribuível, para que seja possível copiar objetos desse tipo e atribuir valores a variáveis desse tipo.  
  
 O priority_queue ordena a sequência que controla chamando um objeto de função armazenado da classe **características**. De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão.  
  
 Incluem classes de contêiner subjacente adequadas para priority_queue [classe deque](../standard-library/deque-class.md) e o padrão [classe vector](../standard-library/vector-class.md) ou qualquer outro contêiner de sequência que oferece suporte às operações de `front`, `push_back`, e `pop_back` e um iterador de acesso aleatório. A classe de contêiner subjacente é encapsulada dentro do adaptador do contêiner, que expõe apenas o conjunto limitado de funções de membro de contêiner de sequência como uma interface pública.  
  
 Adicionando elementos e removendo elementos de um `priority_queue` têm complexidade logarítmica. Acessando elementos em um `priority_queue` tem complexidade constante.  
  
 Há três tipos de adaptadores de contêiner definidos pela STL: priority_queue de pilha e fila. Cada restringe a funcionalidade de uma classe de contêiner subjacente para fornecer uma interface com precisão controlada a uma estrutura de dados padrão.  
  
-   O [classe de pilha](../standard-library/stack-class.md) oferece suporte a uma estrutura de dados da primeira a sair (UEPS) last-in. Um bom análogo para ter em mente seria uma pilha de pratos. Elementos (pratos) podem inseridos, inspecionados ou removidos somente da parte superior da pilha, o que é o último elemento no final do recipiente de base. A restrição para acessar apenas o primeiro elemento é o motivo para usar a classe de pilha.  
  
-   O [classe queue](../standard-library/queue-class.md) oferece suporte a uma estrutura de dados da fila (FIFO) primeiro a entrar,. Um bom análogo para ter em mente seria pessoas alinhar um caixa eletrônico. Elementos (pessoas) podem ser adicionados à parte traseira da linha e são removidos do início da linha. Frente e verso de uma linha podem ser inspecionadas. A restrição para acessar apenas os elementos frontal e traseiro dessa maneira é o motivo para usar a classe de fila.  
  
-   A classe priority_queue ordena seus elementos para que sempre é o maior elemento na posição superior. Ele oferece suporte à inserção de um elemento e a inspeção e a remoção do elemento superior. Um bom análogo para ter em mente seria pessoas alinhar onde eles estão organizados por idade, altura ou algum outro critério.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[priority_queue](#priority_queue__priority_queue)|Constrói um `priority_queue` que é vazio ou que é uma cópia de um intervalo de um objeto de contêiner de base ou de outros `priority_queue`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[container_type](#priority_queue__container_type)|Um tipo que fornece um contêiner para ser adaptado por base uma `priority_queue`.|  
|[size_type](#priority_queue__size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `priority_queue`.|  
|[value_type](#priority_queue__value_type)|Um tipo que representa o tipo de objeto armazenado como um elemento em um `priority_queue`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[vazio](#priority_queue__empty)|Testa se o `priority_queue` está vazia.|  
|[pop](#priority_queue__pop)|Remove o elemento maior do `priority_queue` da posição superior.|  
|[envio por push](#priority_queue__push)|Adiciona um elemento para a fila de prioridade com base na prioridade do elemento de operador <.|  
|[tamanho](#priority_queue__size)|Retorna o número de elementos no `priority_queue`.|  
|[Início](#priority_queue__top)|Retorna uma constante fazem referência ao elemento maior na parte superior do `priority_queue`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< fila>  
  
 **Namespace:** std  
  
##  <a name="a-namepriorityqueuecontainertypea-priorityqueuecontainertype"></a><a name="priority_queue__container_type"></a>  priority_queue:: container_type  
 Um tipo que fornece o recipiente base ser adaptada.  
  
```  
typedef Container container_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo `Container`. O deque de classe de contêiner de sequência STL e o vetor de classe padrão atendem aos requisitos para ser usado como o contêiner de base para um objeto priority_queue. Tipos definidos pelo usuário que satisfazem os requisitos também podem ser usados.  
  
 Para obter mais informações sobre `Container`, consulte a seção comentários a [classe priority_queue](../standard-library/priority-queue-class.md) tópico.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [priority_queue](#priority_queue__priority_queue) para obter um exemplo de como declarar e usar `container_type`.  
  
##  <a name="a-namepriorityqueueemptya-priorityqueueempty"></a><a name="priority_queue__empty"></a>  priority_queue:: Empty  
 Testa se um priority_queue está vazia.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se o priority_queue está vazia; **False** se o priority_queue está vazia.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_empty.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares priority_queues with default deque base container  
   priority_queue <int> q1, s2;  
  
   q1.push( 1 );  
  
   if ( q1.empty( ) )  
      cout << "The priority_queue q1 is empty." << endl;  
   else  
      cout << "The priority_queue q1 is not empty." << endl;  
  
   if ( s2.empty( ) )  
      cout << "The priority_queue s2 is empty." << endl;  
   else  
      cout << "The priority_queue s2 is not empty." << endl;  
}  
```  
  
```Output  
The priority_queue q1 is not empty.  
The priority_queue s2 is empty.  
```  
  
##  <a name="a-namepriorityqueuepopa-priorityqueuepop"></a><a name="priority_queue__pop"></a>  priority_queue:: pop  
 Remove o elemento maior do que o priority_queue da posição superior.  
  
```  
void pop();
```  
  
### <a name="remarks"></a>Comentários  
 O priority_queue deve ser não vazio para aplicar a função de membro. Parte superior do priority_queue sempre está ocupado por maior elemento no contêiner.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_pop.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   priority_queue <int> q1, s2;  
  
   q1.push( 10 );  
   q1.push( 20 );  
   q1.push( 30 );  
  
   priority_queue <int>::size_type i, iii;  
   i = q1.size( );  
   cout << "The priority_queue length is " << i << "." << endl;  
  
   const int& ii = q1.top( );  
   cout << "The element at the top of the priority_queue is "  
        << ii << "." << endl;  
  
   q1.pop( );  
  
   iii = q1.size( );  
   cout << "After a pop, the priority_queue length is "   
        << iii << "." << endl;  
  
   const int& iv = q1.top( );  
   cout << "After a pop, the element at the top of the "  
        << "priority_queue is " << iv << "." << endl;  
}  
```  
  
```Output  
The priority_queue length is 3.  
The element at the top of the priority_queue is 30.  
After a pop, the priority_queue length is 2.  
After a pop, the element at the top of the priority_queue is 20.  
```  
  
##  <a name="a-namepriorityqueuepriorityqueuea-priorityqueuepriorityqueue"></a><a name="priority_queue__priority_queue"></a>  priority_queue:: priority_queue  
 Constrói um priority_queue que está vazio ou é uma cópia de um intervalo de um objeto de contêiner de base ou de outro priority_queue.  
  
```  
priority_queue();

explicit priority_queue(const Traits&_comp);

priority_queue(const Traits&_comp, const container_type& _Cont);

priority_queue(const priority_queue& right);

template <class InputIterator>  
priority_queue(InputIterator first, InputIterator last);

template <class InputIterator>  
priority_queue(InputIterator first, InputIterator last, const Traits&_comp);

template <class InputIterator>  
priority_queue(InputIterator first, InputIterator last, const Traits&_comp, const container_type& _Cont);
```  
  
### <a name="parameters"></a>Parâmetros  
 *_ comp*  
 A função de comparação do tipo **constTraits** usado para ordenar os elementos no priority_queue, cujo padrão é a função do contêiner base compare.  
  
 `_Cont`  
 O contêiner de base do qual o priority_queue construído é uma cópia.  
  
 ` right`  
 O priority_queue do qual o conjunto construído é uma cópia.  
  
 ` first`  
 A posição do primeiro elemento no intervalo de elementos a serem copiados.  
  
 ` last`  
 A posição do primeiro elemento além do intervalo de elementos a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 Cada um dos três primeiros construtores Especifica um priority_queue inicial vazio, o segundo também especificam o tipo de função de comparação ( ` comp`) a ser usado para estabelecer a ordem dos elementos e o terceiro especificar explicitamente o `container_type` ( `_Cont`) a ser usado. A palavra-chave **explícita** suprime determinados tipos de conversão de tipo automática.  
  
 O quarto construtor Especifica uma cópia do priority_queue ` right`.  
  
 Os últimos três construtores copiam o intervalo [ * Sobrenome*) de um contêiner e use os valores para inicializar um priority_queue com o aumento explicitness para especificar o tipo de função de comparação da classe **características** e `container_type`.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_ctor.cpp  
// compile with: /EHsc  
#include <queue>  
#include <vector>  
#include <deque>  
#include <list>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The first member function declares priority_queue  
   // with a default vector base container  
   priority_queue <int> q1;  
   cout << "q1 = ( ";  
   while ( !q1.empty( ) )  
   {  
      cout << q1.top( ) << " ";  
      q1.pop( );  
   }  
   cout << ")" << endl;  
  
   // Explicitly declares a priority_queue with nondefault  
   // deque base container  
   priority_queue <int, deque <int> > q2;  
   q2.push( 5 );  
   q2.push( 15 );  
   q2.push( 10 );  
   cout << "q2 = ( ";  
   while ( !q2.empty( ) )  
   {  
      cout << q2.top( ) << " ";  
      q2.pop( );  
   }  
   cout << ")" << endl;  
  
   // This method of printing out the elements of a priority_queue  
   // removes the elements from the priority queue, leaving it empty  
   cout << "After printing, q2 has " << q2.size( ) << " elements." << endl;  
  
   // The third member function declares a priority_queue   
   // with a vector base container and specifies that the comparison   
   // function greater is to be used for ordering elements  
   priority_queue <int, vector<int>, greater<int> > q3;  
   q3.push( 2 );  
   q3.push( 1 );  
   q3.push( 3 );  
   cout << "q3 = ( ";  
   while ( !q3.empty( ) )  
   {  
      cout << q3.top( ) << " ";  
      q3.pop( );  
   }  
   cout << ")" << endl;  
  
   // The fourth member function declares a priority_queue and  
   // initializes it with elements copied from another container:  
   // first, inserting elements into q1, then copying q1 elements into q4  
   q1.push( 100 );  
   q1.push( 200 );  
   priority_queue <int> q4( q1 );  
   cout << "q4 = ( ";     
   while ( !q4.empty( ) )  
   {  
      cout << q4.top( ) << " ";  
      q4.pop( );  
   }  
   cout << ")" << endl;  
  
   // Creates an auxiliary vector object v5 to be used to initialize q5  
   vector <int> v5;  
   vector <int>::iterator v5_Iter;  
   v5.push_back( 10 );  
   v5.push_back( 30 );  
   v5.push_back( 20 );  
   cout << "v5 = ( " ;  
   for ( v5_Iter = v5.begin( ) ; v5_Iter != v5.end( ) ; v5_Iter++ )  
      cout << *v5_Iter << " ";  
   cout << ")" << endl;  
  
   // The fifth member function declares and  
   // initializes a priority_queue q5 by copying the  
   // range v5[ first,  last) from vector v5  
   priority_queue <int> q5( v5.begin( ), v5.begin( ) + 2 );  
   cout << "q5 = ( ";  
   while ( !q5.empty( ) )  
   {  
      cout << q5.top( ) << " ";  
      q5.pop( );  
   }  
   cout << ")" << endl;  
  
   // The sixth member function declares a priority_queue q6  
   // with a comparison function greater and initializes q6  
   // by copying the range v5[ first,  last) from vector v5  
   priority_queue <int, vector<int>, greater<int> >   
      q6( v5.begin( ), v5.begin( ) + 2 );  
   cout << "q6 = ( ";  
   while ( !q6.empty( ) )  
   {  
      cout << q6.top( ) << " ";  
      q6.pop( );  
   }  
   cout << ")" << endl;  
}  
```  
  
##  <a name="a-namepriorityqueuepusha-priorityqueuepush"></a><a name="priority_queue__push"></a>  priority_queue:: push  
 Adiciona um elemento para a fila de prioridade com base na prioridade do elemento de operador <.  
  
```  
void push(const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` val`  
 O elemento adicionado à parte superior da priority_queue.  
  
### <a name="remarks"></a>Comentários  
 A parte superior do priority_queue é a posição ocupada pelo elemento maior no contêiner.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_push.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   priority_queue<int> q1;  
  
   q1.push( 10 );  
   q1.push( 30 );  
   q1.push( 20 );  
  
   priority_queue<int>::size_type i;  
   i = q1.size( );  
   cout << "The priority_queue length is " << i << "." << endl;  
  
   const int& ii = q1.top( );  
   cout << "The element at the top of the priority_queue is "  
        << ii << "." << endl;  
}  
```  
  
```Output  
The priority_queue length is 3.  
The element at the top of the priority_queue is 30.  
```  
  
##  <a name="a-namepriorityqueuesizea-priorityqueuesize"></a><a name="priority_queue__size"></a>  priority_queue:: Size  
 Retorna o número de elementos no priority_queue.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento atual do priority_queue.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_size.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   priority_queue <int> q1, q2;  
   priority_queue <int>::size_type i;  
  
   q1.push( 1 );  
   i = q1.size( );  
   cout << "The priority_queue length is " << i << "." << endl;  
  
   q1.push( 2 );  
   i = q1.size( );  
   cout << "The priority_queue length is now " << i << "." << endl;  
}  
```  
  
```Output  
The priority_queue length is 1.  
The priority_queue length is now 2.  
```  
  
##  <a name="a-namepriorityqueuesizetypea-priorityqueuesizetype"></a><a name="priority_queue__size_type"></a>  priority_queue:: size_type  
 Um tipo de inteiro não assinado que pode representar o número de elementos em um priority_queue.  
  
```  
typedef typename Container::size_type size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o `size_type` do contêiner base adaptado pelo priority_queue.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [tamanho](#priority_queue__size) para obter um exemplo de como declarar e usar `size_type`.  
  
##  <a name="a-namepriorityqueuetopa-priorityqueuetop"></a><a name="priority_queue__top"></a>  priority_queue:: Top  
 Retorna uma referência const para o maior elemento na parte superior do priority_queue.  
  
```  
const_reference top() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao elemento maior, conforme determinado pelo **características** função, objeto de priority_queue.  
  
### <a name="remarks"></a>Comentários  
 O priority_queue deve ser não vazio para aplicar a função de membro.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_top.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   priority_queue<int> q1;  
  
   q1.push( 10 );  
   q1.push( 30 );  
   q1.push( 20 );  
  
   priority_queue<int>::size_type i;  
   i = q1.size( );  
   cout << "The priority_queue length is " << i << "." << endl;  
  
   const int& ii = q1.top( );  
   cout << "The element at the top of the priority_queue is "  
        << ii << "." << endl;  
}  
```  
  
```Output  
The priority_queue length is 3.  
The element at the top of the priority_queue is 30.  
```  
  
##  <a name="a-namepriorityqueuevaluetypea-priorityqueuevaluetype"></a><a name="priority_queue__value_type"></a>  priority_queue:: value_type  
 Um tipo que representa o tipo de objeto armazenado como um elemento em um priority_queue.  
  
```  
typedef typename Container::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o `value_type` do contêiner base adaptado pelo priority_queue.  
  
### <a name="example"></a>Exemplo  
  
```  
// pqueue_value_type.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares priority_queues with default deque base container  
   priority_queue<int>::value_type AnInt;  
  
   AnInt = 69;  
   cout << "The value_type is AnInt = " << AnInt << endl;  
  
   priority_queue<int> q1;  
   q1.push( AnInt );  
   cout << "The element at the top of the priority_queue is "  
        << q1.top( ) << "." << endl;  
}  
```  
  
```Output  
The value_type is AnInt = 69  
The element at the top of the priority_queue is 69.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

