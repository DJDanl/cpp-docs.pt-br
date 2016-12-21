---
title: "Classe de pilha | Microsoft Docs"
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
  - "std::stack"
  - "std.stack"
  - "stack"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pilha de classe de pilha"
  - "Classe stack"
ms.assetid: 02151c1e-eab0-41b8-be94-a839ead78ecf
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe de pilha
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para limitar o acesso ao elemento adicionado recentemente em algum tipo de contêiner subjacente. A classe de pilha é usada quando é importante esclarecer que apenas as operações de pilha estão sendo executadas no contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type, class Container= deque <Type>>  
class stack  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de dados do elemento a ser armazenado na pilha.  
  
 `Container`  
 O tipo do contêiner subjacente usado para implementar a pilha. O valor padrão é a classe `deque`*\< tipo>*.  
  
## <a name="remarks"></a>Comentários  
 Os elementos da classe **tipo** estipulado no modelo do primeiro parâmetro de um objeto de pilha é sinônimo de [value_type](#stack__value_type) e deve corresponder ao tipo de elemento na classe de contêiner subjacente **contêiner** estipulado, o segundo parâmetro de modelo. O **tipo** deve ser atribuível, para que seja possível copiar objetos desse tipo e atribuir valores a variáveis desse tipo.  
  
 Incluem classes de contêiner subjacente adequadas para a pilha [deque](../standard-library/deque-class.md), [classe list](../standard-library/list-class.md), e [classe vector](../standard-library/vector-class.md), ou qualquer outro contêiner de sequência que oferece suporte às operações de **novamente**, `push_back`, e `pop_back`. A classe de contêiner subjacente é encapsulada dentro do adaptador do contêiner, que expõe apenas o conjunto limitado de funções de membro de contêiner de sequência como uma interface pública.  
  
 A pilha de objetos são igualdade comparável se e somente se os elementos da classe **tipo** são comparáveis a igualdade e menor-que comparável se e somente se os elementos da classe **tipo** menores-que comparável.  
  
-   A classe de pilha dá suporte a uma estrutura de dados da primeira a sair (UEPS) last-in. Um bom análogo para ter em mente seria uma pilha de pratos. Elementos (pratos) podem inseridos, inspecionados ou removidos somente da parte superior da pilha, o que é o último elemento no final do recipiente de base. A restrição para acessar apenas o primeiro elemento é o motivo para usar a classe de pilha.  
  
-   O [classe queue](../standard-library/queue-class.md) oferece suporte a uma estrutura de dados da fila (FIFO) primeiro a entrar,. Um bom análogo para ter em mente seria pessoas alinhar um caixa eletrônico. Elementos (pessoas) podem ser adicionados à parte traseira da linha e são removidos do início da linha. Frente e verso de uma linha podem ser inspecionadas. A restrição para acessar apenas os elementos frontal e traseiro dessa maneira é o fur motivo usando a classe de fila.  
  
-   O [classe priority_queue](../standard-library/priority-queue-class.md) ordena seus elementos de modo que sempre é o maior elemento na posição superior. Ele oferece suporte à inserção de um elemento e a inspeção e a remoção do elemento superior. Um bom análogo para ter em mente seria pessoas alinhar onde eles estão organizados por idade, altura ou algum outro critério.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[pilha](#stack__stack)|Constrói um `stack` que é vazio ou que é uma cópia de um objeto de contêiner de base.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[container_type](#stack__container_type)|Um tipo que fornece um contêiner para ser adaptado por base uma `stack`.|  
|[size_type](#stack__size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `stack`.|  
|[value_type](#stack__value_type)|Um tipo que representa o tipo de objeto armazenado como um elemento em um `stack`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[vazio](#stack__empty)|Testa se o `stack` está vazia.|  
|[pop](#stack__pop)|Remove o elemento da parte superior a `stack`.|  
|[envio por push](#stack__push)|Adiciona um elemento na parte superior do `stack`.|  
|[tamanho](#stack__size)|Retorna o número de elementos no `stack`.|  
|[Início](#stack__top)|Retorna uma referência a um elemento na parte superior do `stack`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< pilha>  
  
 **Namespace:** std  
  
##  <a name="a-namestackcontainertypea-stackcontainertype"></a><a name="stack__container_type"></a>  Stack:: container_type  
 Um tipo que fornece o recipiente base ser adaptada.  
  
```  
typedef Container container_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo `Container`. Todas as classes de contêiner de sequência STL três — a classe vector, classe de lista e o deque de classe padrão — atendem aos requisitos de ser usado como o contêiner de base para um objeto de pilha. Tipos definidos pelo usuário que satisfazem esses requisitos também podem ser usados.  
  
 Para obter mais informações sobre `Container`, consulte a seção comentários a [classe de pilha](../standard-library/stack-class.md) tópico.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [Stack:: Stack](#stack__stack) para obter um exemplo de como declarar e usar `container_type`.  
  
##  <a name="a-namestackemptya-stackempty"></a><a name="stack__empty"></a>  Stack:: Empty  
 Testa se uma pilha está vazia.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se a pilha está vazia; **False** se a pilha está vazia.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_empty.cpp  
// compile with: /EHsc  
#include <stack>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   // Declares stacks with default deque base container  
   stack <int> s1, s2;  
  
   s1.push( 1 );  
  
   if ( s1.empty( ) )  
      cout << "The stack s1 is empty." << endl;  
   else  
      cout << "The stack s1 is not empty." << endl;  
  
   if ( s2.empty( ) )  
      cout << "The stack s2 is empty." << endl;  
   else  
      cout << "The stack s2 is not empty." << endl;  
}  
```  
  
```Output  
The stack s1 is not empty.  
The stack s2 is empty.  
```  
  
##  <a name="a-namestackpopa-stackpop"></a><a name="stack__pop"></a>  Stack:: pop  
 Remove o elemento na parte superior da pilha.  
  
```  
void pop();
```  
  
### <a name="remarks"></a>Comentários  
 A pilha deve estar vazia para aplicar a função de membro. Parte superior da pilha é a posição ocupada pelo elemento adicionado mais recentemente e o último elemento no final do contêiner.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_pop.cpp  
// compile with: /EHsc  
#include <stack>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   stack <int> s1, s2;  
  
   s1.push( 10 );  
   s1.push( 20 );  
   s1.push( 30 );  
  
   stack <int>::size_type i;  
   i = s1.size( );  
   cout << "The stack length is " << i << "." << endl;  
  
   i = s1.top( );  
   cout << "The element at the top of the stack is "  
        << i << "." << endl;  
  
   s1.pop( );  
  
   i = s1.size( );  
   cout << "After a pop, the stack length is "   
        << i << "." << endl;  
  
   i = s1.top( );  
   cout << "After a pop, the element at the top of the stack is "  
        << i << "." << endl;  
}  
```  
  
```Output  
The stack length is 3.  
The element at the top of the stack is 30.  
After a pop, the stack length is 2.  
After a pop, the element at the top of the stack is 20.  
```  
  
##  <a name="a-namestackpusha-stackpush"></a><a name="stack__push"></a>  Stack:: push  
 Adiciona um elemento para o topo da pilha.  
  
```  
void push(const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` val`  
 O elemento adicionado à parte superior da pilha.  
  
### <a name="remarks"></a>Comentários  
 Parte superior da pilha é a posição ocupada pelo elemento adicionado mais recentemente e o último elemento no final do contêiner.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_push.cpp  
// compile with: /EHsc  
#include <stack>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   stack <int> s1;  
  
   s1.push( 10 );  
   s1.push( 20 );  
   s1.push( 30 );  
  
   stack <int>::size_type i;  
   i = s1.size( );  
   cout << "The stack length is " << i << "." << endl;  
  
   i = s1.top( );  
   cout << "The element at the top of the stack is "  
        << i << "." << endl;  
}  
```  
  
```Output  
The stack length is 3.  
The element at the top of the stack is 30.  
```  
  
##  <a name="a-namestacksizea-stacksize"></a><a name="stack__size"></a>  Stack:: Size  
 Retorna o número de elementos na pilha.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento atual da pilha.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_size.cpp  
// compile with: /EHsc  
#include <stack>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   stack <int> s1, s2;  
   stack <int>::size_type i;  
  
   s1.push( 1 );  
   i = s1.size( );  
   cout << "The stack length is " << i << "." << endl;  
  
   s1.push( 2 );  
   i = s1.size( );  
   cout << "The stack length is now " << i << "." << endl;  
}  
```  
  
```Output  
The stack length is 1.  
The stack length is now 2.  
```  
  
##  <a name="a-namestacksizetypea-stacksizetype"></a><a name="stack__size_type"></a>  Stack:: size_type  
 Um tipo de inteiro não assinado que pode representar o número de elementos em uma pilha.  
  
```  
typedef typename Container::size_type size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para `size_type` do contêiner base adaptado pela pilha.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [tamanho](#stack__size) para obter um exemplo de como declarar e usar `size_type`.  
  
##  <a name="a-namestackstacka-stackstack"></a><a name="stack__stack"></a>  Stack:: Stack  
 Constrói uma pilha que está vazio ou é uma cópia de uma classe base do contêiner.  
  
```  
stack();

explicit stack(const container_type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O contêiner do qual a pilha construída é uma cópia.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_stack.cpp  
// compile with: /EHsc  
#include <stack>  
#include <vector>  
#include <list>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares stack with default deque base container  
   stack <char> dsc1;  
  
   //Explicitly declares a stack with deque base container  
   stack <char, deque<char> > dsc2;  
  
   // Declares a stack with vector base containers  
   stack <int, vector<int> > vsi1;  
  
   // Declares a stack with list base container  
   stack <int, list<int> > lsi;  
  
   // The second member function copies elements from a container  
   vector<int> v1;  
   v1.push_back( 1 );  
   stack <int, vector<int> > vsi2( v1 );  
   cout << "The element at the top of stack vsi2 is "  
        << vsi2.top( ) << "." << endl;  
}  
```  
  
```Output  
The element at the top of stack vsi2 is 1.  
```  
  
##  <a name="a-namestacktopa-stacktop"></a><a name="stack__top"></a>  Stack  
 Retorna uma referência a um elemento na parte superior da pilha.  
  
```  
reference top();

const_reference top() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao último elemento no contêiner na parte superior da pilha.  
  
### <a name="remarks"></a>Comentários  
 A pilha deve estar vazia para aplicar a função de membro. Parte superior da pilha é a posição ocupada pelo elemento adicionado mais recentemente e o último elemento no final do contêiner.  
  
 Se o valor de retorno **superior** é atribuído a um `const_reference`, o objeto de pilha não pode ser modificado. Se o valor de retorno **superior** é atribuído a um **referência**, o objeto de pilha pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_top.cpp  
// compile with: /EHsc  
#include <stack>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   stack <int> s1;  
  
   s1.push( 1 );  
   s1.push( 2 );  
  
   int& i = s1.top( );  
   const int& ii = s1.top( );  
  
   cout << "The top integer of the stack s1 is "  
        << i << "." << endl;  
   i--;  
   cout << "The next integer down is "<< ii << "." << endl;  
}  
```  
  
```Output  
The top integer of the stack s1 is 2.  
The next integer down is 1.  
```  
  
##  <a name="a-namestackvaluetypea-stackvaluetype"></a><a name="stack__value_type"></a>  Stack:: value_type  
 Um tipo que representa o tipo de objeto armazenado como um elemento em uma pilha.  
  
```  
typedef typename Container::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para `value_type` do contêiner base adaptado pela pilha.  
  
### <a name="example"></a>Exemplo  
  
```  
// stack_value_type.cpp  
// compile with: /EHsc  
#include <stack>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   // Declares stacks with default deque base container  
   stack<int>::value_type AnInt;  
  
   AnInt = 69;  
   cout << "The value_type is AnInt = " << AnInt << endl;  
  
   stack<int> s1;  
   s1.push( AnInt );  
   cout << "The element at the top of the stack is "  
        << s1.top( ) << "." << endl;  
}  
```  
  
```Output  
The value_type is AnInt = 69  
The element at the top of the stack is 69.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

