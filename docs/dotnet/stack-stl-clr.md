---
title: pilha (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::stack
- cliext::operator!=
- cliext::operator<
- cliext::operator<=
- cliext::operator==
- cliext::operator>
- cliext::operator>=
- cliext::stack::assign
- cliext::stack::const_reference
- cliext::stack::container_type
- cliext::stack::difference_type
- cliext::stack::empty
- cliext::stack::generic_container
- cliext::stack::generic_value
- cliext::stack::get_container
- cliext::stack::operator=
- cliext::stack::pop
- cliext::stack::push
- cliext::stack::reference
- cliext::stack::size
- cliext::stack::size_type
- cliext::stack::stack
- cliext::stack::to_array
- cliext::stack::top
- cliext::stack::top_item
- cliext::stack::value_type
dev_langs:
- C++
helpviewer_keywords:
- <stack> header [STL/CLR]
- <cliext/stack> header [STL/CLR]
- stack class [STL/CLR]
- operator!= member [STL/CLR]
- operator< member [STL/CLR]
- operator<= member [STL/CLR]
- operator== member [STL/CLR]
- operator> member [STL/CLR]
- operator>= member [STL/CLR]
- assign member [STL/CLR]
- const_reference member [STL/CLR]
- container_type member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- generic_container member [STL/CLR]
- generic_value member [STL/CLR]
- get_container member [STL/CLR]
- operator= member [STL/CLR]
- pop member [STL/CLR]
- push member [STL/CLR]
- reference member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- stack member [STL/CLR]
- to_array member [STL/CLR]
- top member [STL/CLR]
- top_item member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: 6ee96b9f-8a33-4cf7-b7e0-6535c24bdefb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 09368f3a43a5ba7a5a1c4247fdbbccdf345b0b21
ms.sourcegitcommit: bad2441d1930275ff506d44759d283d94cccd1c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2018
ms.locfileid: "39376203"
---
# <a name="stack-stlclr"></a>stack (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos que tem acesso de último a entrar primeiro a sair. Você usar o adaptador de contêiner `stack` para gerenciar um contêiner subjacente, como uma pilha de propagação.  
  
 Na descrição abaixo, `GValue` é o mesmo que *valor* , a menos que o último é um tipo ref, nesse caso, ele é `Value^`. Da mesma forma, `GContainer` é o mesmo que *contêiner* , a menos que o último é um tipo ref, nesse caso, ele é `Container^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    ref class stack  
        :   public  
        System::ICloneable,  
        Microsoft::VisualC::StlClr::IStack<GValue, GContainer>  
    { ..... };  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Value*  
 O tipo de um elemento na sequência controlada.  
  
 *Contêiner*  
 O tipo do contêiner subjacente.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/pilha >  
  
 **Namespace:** cliext  
  
## <a name="declarations"></a>Declarações  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[stack::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|  
|[stack::container_type (STL/CLR)](#container_type)|O tipo do contêiner subjacente.|  
|[stack::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[stack::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o adaptador de contêiner.|  
|[stack::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|  
|[stack::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|  
|[stack::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[stack::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[stack::assign (STL/CLR)](#assign)|Substitui todos os elementos.|  
|[stack::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|  
|[stack::get_container (STL/CLR)](#get_container)|Acessa o contêiner subjacente.|  
|[stack::pop (STL/CLR)](#pop)|Remove o último elemento.|  
|[stack::push (STL/CLR)](#push)|Adiciona um novo último elemento.|  
|[stack::size (STL/CLR)](#size)|Conta o número de elementos.|  
|[stack::stack (STL/CLR)](#stack)|Constrói um objeto contêiner.|  
|[stack::top (STL/CLR)](#top)|Acessa o último elemento.|  
|[stack::to_array (STL/CLR)](#to_array)|Copia a sequência controlada para uma nova matriz.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[stack::top_item (STL/CLR)](#top_item)|Acessa o último elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[stack::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|  
|[operator!= (stack) (STL/CLR)](#op_neq)|Determina se um `stack` objeto não é igual a outro `stack` objeto.|  
|[operator< (stack) (STL/CLR)](#op_lt)|Determina se um `stack` objeto é menor que outro `stack` objeto.|  
|[operator<= (stack) (STL/CLR)](#op_lteq)|Determina se um `stack` objeto é menor ou igual a outro `stack` objeto.|  
|[operator== (stack) (STL/CLR)](#op_eq)|Determina se um `stack` objeto é igual a outro `stack` objeto.|  
|[operator> (stack) (STL/CLR)](#op_gt)|Determina se um `stack` objeto é maior que outro `stack` objeto.|  
|[operator>= (stack) (STL/CLR)](#op_gteq)|Determina se um `stack` objeto é maior que ou igual a outro `stack` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|IStack\<valor, o contêiner >|Manter o adaptador de contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um contêiner subjacente, do tipo *recipiente*, que armazena *valor* elementos e aumenta conforme a demanda. O objeto restringe o acesso para enviar por push e pop apenas o último elemento, implementação de uma fila de último a entrar primeiro a sair (também conhecido como uma fila LIFO ou pilha).  
 
## <a name="members"></a>Membros

## <a name="assign"></a> Stack::Assign (STL/CLR)
Substitui todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void assign(stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *right*  
 Adaptador de contêiner a ser inserido.  
  
### <a name="remarks"></a>Comentários  
 A função de membro atribui `right.get_container()` para o contêiner subjacente. Você pode usá-lo para alterar o conteúdo inteiro da pilha.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_assign.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign a repetition of values   
    Mystack c2;   
    c2.assign(c1);   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
```  

## <a name="const_reference"></a> Stack::const_reference (STL/CLR)
O tipo de uma referência de constante para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef value_type% const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência constante para um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_const_reference.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display reversed contents " c b a"   
    for (; !c1.empty(); c1.pop())   
        {   // get a const reference to an element   
        Mystack::const_reference cref = c1.top();   
        System::Console::Write(" {0}", cref);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
c b a  
```  

## <a name="container_type"></a> Stack:: container_type (STL/CLR)
O tipo do contêiner subjacente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Container value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo *Container*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_container_type.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c" using container_type   
    Mystack::container_type wc1 = c1.get_container();   
    for each (wchar_t elem in wc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }   
```  
  
```Output  
a b c  
```  

## <a name="difference_type"></a> Stack::difference_type (STL/CLR)
Os tipos de uma distância com sinal entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef int difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elemento possivelmente negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_difference_type.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute negative difference   
    Mystack::difference_type diff = c1.size();   
    c1.push(L'd');   
    c1.push(L'e');   
    diff -= c1.size();   
    System::Console::WriteLine("pushing 2 = {0}", diff);   
  
// compute positive difference   
    diff = c1.size();   
    c1.pop();   
    c1.pop();   
    c1.pop();   
    diff -= c1.size();   
    System::Console::WriteLine("popping 3 = {0}", diff);   
    return (0);   
    }  
```  
  
```Output  
 a b c  
pushing 2 = -2  
popping 3 = 3  
```  

## <a name="empty"></a> Stack:: Empty (STL/CLR)
Testa se nenhum elemento está presente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
bool empty();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [Stack:: Size (STL/CLR)](../dotnet/stack-size-stl-clr.md)`() == 0`. Você pode usá-lo para testar se a pilha está vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_empty.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
  
// clear the container and reinspect   
    c1.pop();   
    c1.pop();   
    c1.pop();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
    return (0);   
    }  
```  
  
```Output  
 a b c  
size() = 3  
empty() = False  
size() = 0  
empty() = True  
```  
  
## <a name="generic_container"></a> Stack::generic_container (STL/CLR)
O tipo da interface genérica para o adaptador de contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Microsoft::VisualC::StlClr::IStack<Value>  
    generic_container;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve a interface genérica para essa classe de adaptador de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_generic_container.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// get interface to container   
    Mystack::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1->get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    gc1->push(L'd');   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify original and display generic   
    c1.push(L'e');   
    for each (wchar_t elem in gc1->get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
a b c d  
a b c d e  
```  
  
## <a name="generic_value"></a> Stack::generic_value (STL/CLR)
O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef GValue generic_value;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor de elemento armazenado para uso com a interface genérica para essa classe de contêiner do modelo. (`GValue` seja `value_type` ou `value_type^` se `value_type` é um tipo de referência.)  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_generic_value.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// get interface to container   
    Mystack::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1->get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display in reverse using generic_value   
    for (; !gc1->empty(); gc1->pop())   
        {   
        Mystack::generic_value elem = gc1->top();   
  
        System::Console::Write(" {0}", elem);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
c b a  
```  
  
## <a name="get_container"></a> Stack::get_container (STL/CLR)
Acessa o contêiner subjacente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
container_type^ get_container();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um identificador para o contêiner subjacente. Você pode usá-lo para ignorar as restrições impostas pelo wrapper do contêiner.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_get_container.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c" using container_type   
    Mystack::container_type wc1 = c1.get_container();   
    for each (wchar_t elem in wc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
```  

## <a name="op_as"></a> Stack:: Operator = (STL/CLR)
Substitui a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
stack <Value, Container>% operator=(stack <Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *right*  
 Adaptador de contêiner para copiar.  
  
### <a name="remarks"></a>Comentários  
 As cópias de operador de membro *certa* ao objeto, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada no *certa*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_as.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2 = c1;   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }   
```  
  
```Output  
a b c  
a b c  
```  

## <a name="pop"></a> Stack:: pop (STL/CLR)
Remove o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void pop();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro remove o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para encurtar a pilha por um elemento na parte traseira.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_pop.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// pop an element and redisplay   
    c1.pop();   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b  
```  

## <a name="push"></a> Stack:: push (STL/CLR)
Adiciona um novo último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void push(value_type val);  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro insere um elemento com valor `val` no final da sequência controlada. Você pode usá-lo para acrescentar a outro elemento na pilha.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_push.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
```  

## <a name="reference"></a> Stack::Reference (STL/CLR)
O tipo de uma referência para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef value_type% reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_reference.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify top of stack and redisplay   
    Mystack::reference ref = c1.top();   
    ref = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b x  
```  
  
## <a name="size"></a> Stack:: Size (STL/CLR)
Conta o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
size_type size();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada. Você pode usá-lo para determinar o número de elementos que estão na sequência controlada. Se você se preocupa se a sequência tem tamanho diferente de zero, consulte [Stack:: Empty (STL/CLR)](../dotnet/stack-empty-stl-clr.md)`()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_size.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());   
  
// pop an item and reinspect   
    c1.pop();   
    System::Console::WriteLine("size() = {0} after popping", c1.size());   
  
// add two elements and reinspect   
    c1.push(L'a');   
    c1.push(L'b');   
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());   
    return (0);   
    }  
```  
  
```Output  
 a b c  
size() = 3 starting with 3  
size() = 2 after popping  
size() = 4 after adding 2  
```  

## <a name="size_type"></a> Stack:: size_type (STL/CLR)
O tipo de uma distância com sinal entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef int size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elemento não negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_size_type.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    Mystack::size_type diff = c1.size();   
    c1.pop();   
    c1.pop();   
    diff -= c1.size();   
    System::Console::WriteLine("size difference = {0}", diff);   
    return (0);   
    }  
```  
  
```Output  
 a b c  
size difference = 2  
```  
  
## <a name="stack"></a> Stack:: Stack (STL/CLR)
Constrói um objeto de adaptador de contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
stack();  
stack(stack<Value, Container>% right);  
stack(stack<Value, Container>^ right);  
explicit stack(container_type% wrapped);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *right*  
 Objeto a ser copiado.  
  
 *encapsulado*  
 Contêiner encapsulado para ser usado.  
  
### <a name="remarks"></a>Comentários  
 O construtor:  
  
 `stack();`  
  
 cria um contêiner encapsulado vazio. Você pode usá-lo para especificar uma sequência controlada inicial vazia.  
  
 O construtor:  
  
 `stack(stack<Value, Container>% right);`  
  
 cria um contêiner de encapsulado é uma cópia do `right.get_container()`. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de pilha *certa*.  
  
 O construtor:  
  
 `stack(stack<Value, Container>^ right);`  
  
 cria um contêiner de encapsulado é uma cópia do `right->get_container()`. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de pilha `*right`.  
  
 O construtor:  
  
 `explicit stack(container_type% wrapped);`  
  
 usa o contêiner existente *encapsulado* como o contêiner encapsulado. Você pode usá-lo para construir uma pilha de um contêiner existente.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_construct.cpp   
// compile with: /clr   
#include <cliext/stack>   
#include <cliext/vector>   
  
typedef cliext::stack<wchar_t> Mystack;   
typedef cliext::vector<wchar_t> Myvector;   
typedef cliext::stack<wchar_t, Myvector> Mystack_vec;   
int main()   
    {   
// construct an empty container   
    Mystack c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct from an underlying container   
    Myvector v2(5, L'x');   
    Mystack_vec c2(v2);       
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Mystack_vec c3(c2);   
    for each (wchar_t elem in c3.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container through handle   
    Mystack_vec c4(%c2);   
    for each (wchar_t elem in c4.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }   
```  
  
```Output  
size() = 0  
 x x x x x  
 x x x x x  
 x x x x x  
```  

## <a name="to_array"></a> Stack::to_array (STL/CLR)
Copia a sequência controlada para uma nova matriz.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
cli::array<Value>^ to_array();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna uma matriz que contém a sequência controlada. Você pode usá-lo para obter uma cópia da sequência controlada em forma de matriz.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_to_array.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// copy the container and modify it   
    cli::array<wchar_t>^ a1 = c1.to_array();   
  
    c1.push(L'd');   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display the earlier array copy   
    for each (wchar_t elem in a1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c d  
a b c  
```  

## <a name="top"></a> Top (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
reference top();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna uma referência ao último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para acessar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_top.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("top() = {0}", c1.top());   
  
// alter last item and reinspect   
    c1.top() = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
 a b c  
top() = c  
 a b x  
```  

## <a name="top_item"></a> Stack::top_item (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
property value_type top_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_top_item.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("top_item = {0}", c1.top_item);   
  
// alter last item and reinspect   
    c1.top_item = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
 a b c  
top_item = c  
 a b x  
```  

## <a name="value_type"></a> Stack:: value_type (STL/CLR)
O tipo de um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Value value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo *valor*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_value_type.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display reversed contents " a b c" using value_type   
    for (; !c1.empty(); c1.pop())   
        {   // store element in value_type object   
        Mystack::value_type val = c1.top();   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }   
```  
  
```Output  
c b a  
```  

## <a name="op_neq"></a> operador! = (stack) (STL/CLR)
A comparação não é igual a pilha.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    bool operator!=(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left == right)`. Você pode usá-lo para testar se *esquerdo* não for ordenado igual *à direita* quando as duas pilhas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_ne.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] != [a b c] is {0}",   
        c1 != c1);   
    System::Console::WriteLine("[a b c] != [a b d] is {0}",   
        c1 != c2);   
    return (0);   
    }   
```  
  
```Output  
 a b c  
 a b d  
[a b c] != [a b c] is False  
[a b c] != [a b d] is True  
```  

## <a name="op_lt"></a> operador&lt; (stack) (STL/CLR)
Pilha inferior a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    bool operator<(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 O operador função retornará true se, para a posição mais baixa `i` para o qual `!(right[i] < left[i])` é verdade também que `left[i] < right[i]`. Caso contrário, retornará `left->` [Stack:: Size (STL/CLR)](../dotnet/stack-size-stl-clr.md) `() <` `right->size()` usá-lo para testar se *esquerdo* é ordenado antes *certa* Quando as duas pilhas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_lt.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] < [a b c] is {0}",   
        c1 < c1);   
    System::Console::WriteLine("[a b c] < [a b d] is {0}",   
        c1 < c2);   
    return (0);   
    }   
```  
  
```Output  
 a b c  
 a b d  
[a b c] < [a b c] is False  
[a b c] < [a b d] is True  
```  

## <a name="op_lteq"></a> operador&lt;= (stack) (STL/CLR)
Menor ou igual de pilha comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    bool operator<=(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(right < left)`. Você pode usá-lo para testar se *esquerdo* não for ordenado após *à direita* quando as duas pilhas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_le.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] <= [a b c] is {0}",   
        c1 <= c1);   
    System::Console::WriteLine("[a b d] <= [a b c] is {0}",   
        c2 <= c1);   
    return (0);   
    }   
```  
  
```Output  
 a b c  
 a b d  
[a b c] <= [a b c] is True  
[a b d] <= [a b c] is False  
```  

## <a name="op_eq"></a> operador = = (stack) (STL/CLR)
Comparação de igualdade de pilha.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    bool operator==(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 A função de operador retornará true somente se as sequências controladas por *esquerdo* e *à direita* têm o mesmo tamanho e, para cada posição `i`, `left[i] ==` `right[i]`. Usá-lo para testar se *esquerdo* é ordenada igual *direita* quando as duas pilhas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_eq.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] == [a b c] is {0}",   
        c1 == c1);   
    System::Console::WriteLine("[a b c] == [a b d] is {0}",   
        c1 == c2);   
    return (0);   
    }   
```  
  
```Output  
 a b c  
 a b d  
[a b c] == [a b c] is True  
[a b c] == [a b d] is False  
```  
  
## <a name="op_gt"></a> operador&gt; (stack) (STL/CLR)
Comparação de maior que a pilha.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    bool operator>(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `right` `<` `left`. Usá-lo para testar se *esquerdo* é ordenada após *direita* quando as duas pilhas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_gt.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] > [a b c] is {0}",   
        c1 > c1);   
    System::Console::WriteLine("[a b d] > [a b c] is {0}",   
        c2 > c1);   
    return (0);   
    }   
```  
  
```Output  
 a b c  
 a b d  
[a b c] > [a b c] is False  
[a b d] > [a b c] is True  
```  
  
## <a name="op_gteq"></a> operador&gt;= (stack) (STL/CLR)
Pilha de maior que ou igual a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value,  
    typename Container>  
    bool operator>=(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left < right)`. Você pode usá-lo para testar se *esquerdo* não for ordenado antes *à direita* quando as duas pilhas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_stack_operator_ge.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] >= [a b c] is {0}",   
        c1 >= c1);   
    System::Console::WriteLine("[a b c] >= [a b d] is {0}",   
        c1 >= c2);   
    return (0);   
    }  
```  
  
```Output  
 a b c  
 a b d  
[a b c] >= [a b c] is True  
[a b c] >= [a b d] is False  
``` 