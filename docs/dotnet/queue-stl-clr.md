---
title: fila (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::queue
- cliext::operator!=
- cliext::operator<
- cliext::operator<=
- cliext::operator==
- cliext::operator>
- cliext::operator>=
- cliext::queue::assign
- cliext::queue::back
- cliext::queue::back_item
- cliext::queue::const_reference
- cliext::queue::container_type
- cliext::queue::difference_type
- cliext::queue::empty
- cliext::queue::front
- cliext::queue::front_item
- cliext::queue::generic_container
- cliext::queue::generic_value
- cliext::queue::get_container
- cliext::queue::operator=
- cliext::queue::pop
- cliext::queue::push
- cliext::queue::queue
- cliext::queue::reference
- cliext::queue::size
- cliext::queue::size_type
- cliext::queue::to_array
- cliext::queue::value_type
dev_langs:
- C++
helpviewer_keywords:
- <queue> header [STL/CLR]
- queue class [STL/CLR]
- <cliext/queue> header [STL/CLR]
- operator!= member [STL/CLR]
- operator< member [STL/CLR]
- operator<= member [STL/CLR]
- operator== member [STL/CLR]
- operator> member [STL/CLR]
- operator>= member [STL/CLR]
- assign member [STL/CLR]
- back member [STL/CLR]
- back_item member [STL/CLR]
- const_reference member [STL/CLR]
- container_type member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- front member [STL/CLR]
- front_item member [STL/CLR]
- generic_container member [STL/CLR]
- generic_value member [STL/CLR]
- get_container member [STL/CLR]
- operator= member [STL/CLR]
- pop member [STL/CLR]
- push member [STL/CLR]
- queue member [STL/CLR]
- reference member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- to_array member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: 9ea7dec3-ea98-48ff-87d0-a5afc924aaf2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1ae23bf845e3fa78a1971def6ea0034c94b57991
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37079701"
---
# <a name="queue-stlclr"></a>queue (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso primeiro na fila. Usar o adaptador de contêiner `queue` para gerenciar um contêiner subjacente como uma fila.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`. Da mesma forma, `GContainer` é o mesmo que `Container` , a menos que o último é um tipo de referência, caso em que é `Container^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    ref class queue  
        :   public  
        System::ICloneable,  
        Microsoft::VisualC::StlClr::IQueue<GValue, GContainer>  
    { ..... };  
```  
  
### <a name="parameters"></a>Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
 Contêiner  
 O tipo do contêiner subjacente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/fila >  
  
 **Namespace:** cliext  

## <a name="declarations"></a>Declarações  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[queue::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|  
|[queue::container_type (STL/CLR)](#container_type)|O tipo do contêiner subjacente.|  
|[queue::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[queue::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o adaptador de contêiner.|  
|[queue::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|  
|[queue::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|  
|[queue::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[queue::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[queue::assign (STL/CLR)](#assign)|Substitui todos os elementos.|  
|[queue::back (STL/CLR)](#back)|Acessa o último elemento.|  
|[queue::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|  
|[queue::front (STL/CLR)](#front)|Acessa o primeiro elemento.|  
|[queue::get_container (STL/CLR)](#get_container)|Acessa o contêiner subjacente.|  
|[queue::pop (STL/CLR)](#pop)|Remove o primeiro elemento.|  
|[queue::push (STL/CLR)](#push)|Adiciona um novo elemento de última.|  
|[queue::queue (STL/CLR)](#queue)|Constrói um objeto contêiner.|  
|[queue::size (STL/CLR)](#size)|Conta o número de elementos.|  
|[queue::to_array (STL/CLR)](#to_array)|Copia uma nova matriz sequência controlada.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[queue::back_item (STL/CLR)](#back_item)|Acessa o último elemento.|  
|[queue::front_item (STL/CLR)](#front_item)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[queue::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|  
|[operator!= (queue) (STL/CLR)](#op_neq)|Determina se um `queue` objeto não é igual a outro `queue` objeto.|  
|[operator< (queue) (STL/CLR)](#op_lt)|Determina se um `queue` objeto é menor que outro `queue` objeto.|  
|[operator<= (queue) (STL/CLR)](#op_lteq)|Determina se um `queue` objeto é menor ou igual a outro `queue` objeto.|  
|[operator== (queue) (STL/CLR)](#op_eq)|Determina se um `queue` objeto é igual a outro `queue` objeto.|  
|[operator> (queue) (STL/CLR)](#op_gt)|Determina se um `queue` objeto é maior que outro `queue` objeto.|  
|[operator>= (queue) (STL/CLR)](#op_gteq)|Determina se um `queue` objeto é maior que ou igual a outro `queue` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|IFila\<valor, o contêiner >|Manter o adaptador de contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência controla por meio de um contêiner subjacente, do tipo `Container`, que armazena `Value` elementos e sob demanda. O objeto restringe o acesso ao enviar apenas o primeiro elemento e retirar o último elemento, implementando uma primeiro a sair na primeira fila (também conhecido como uma fila FIFO, ou simplesmente uma fila).  
  
## <a name="members"></a>Membros

## <a name="assign"></a> Queue::Assign (STL/CLR)
Substitui todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void assign(queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 Adaptador de contêiner para inserir.  
  
### <a name="remarks"></a>Comentários  
 Atribui a função de membro `right.get_container()` para o contêiner subjacente. Você pode usá-lo para alterar o conteúdo inteiro da fila.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_assign.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign a repetition of values   
    Myqueue c2;   
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

## <a name="back"></a> Queue:: back (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference back();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma referência para o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para acessar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_back.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("back() = {0}", c1.back());   
  
// alter last item and reinspect   
    c1.back() = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
back() = c  
 a b x  
```  

## <a name="back_item"></a> Queue::back_item (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
property value_type back_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_back_item.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("back_item = {0}", c1.back_item);   
  
// alter last item and reinspect   
    c1.back_item = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
back_item = c  
 a b x  
```  

## <a name="const_reference"></a> Queue::const_reference (STL/CLR)
O tipo de uma referência de constante para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência constante a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_const_reference.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for (; !c1.empty(); c1.pop())   
        {   // get a const reference to an element   
        Myqueue::const_reference cref = c1.front();   
        System::Console::Write(" {0}", cref);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="container_type"></a> Queue:: container_type (STL/CLR)
O tipo do contêiner subjacente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Container value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Container`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_container_type.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c" using container_type   
    Myqueue::container_type wc1 = c1.get_container();   
    for each (wchar_t elem in wc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="difference_type"></a> Queue::difference_type (STL/CLR)
Os tipos de uma distância assinado entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef int difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elementos possivelmente negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_difference_type.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute negative difference   
    Myqueue::difference_type diff = c1.size();   
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

## <a name="empty"></a> Queue:: Empty (STL/CLR)
Testa se nenhum elemento está presente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool empty();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [Queue:: Size (STL/CLR)](../dotnet/queue-size-stl-clr.md)`() == 0`. Você pode usá-lo para testar se a fila está vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_empty.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
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

## <a name="front"></a> Queue:: front (STL/CLR)
Acessa o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference front();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma referência para o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para acessar o primeiro elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_front.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first item   
    System::Console::WriteLine("front() = {0}", c1.front());   
  
// alter first item and reinspect   
    c1.front() = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
front() = a  
 x b c  
```  

## <a name="front_item"></a> Queue::front_item (STL/CLR)
Acessa o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
property value_type front_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_front_item.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("front_item = {0}", c1.front_item);   
  
// alter last item and reinspect   
    c1.front_item = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
front_item = a  
 x b c  
```  

## <a name="generic_container"></a> Queue::generic_container (STL/CLR)
O tipo da interface genérica para o adaptador de contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::IQueue<Value>  
    generic_container;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve a interface genérica para esta classe de adaptador de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_generic_container.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myqueue::generic_container^ gc1 = %c1;   
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

## <a name="generic_value"></a> Queue::generic_value (STL/CLR)
O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef GValue generic_value;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenados para uso com a interface genérica para esta classe de contêiner do modelo. (`GValue` é `value_type` ou `value_type^` se `value_type` é um tipo de referência.)  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_generic_value.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// get interface to container   
    Myqueue::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1->get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display in order using generic_value   
    for (; !gc1->empty(); gc1->pop())   
        {   
        Myqueue::generic_value elem = gc1->front();   
  
        System::Console::Write(" {0}", elem);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
a b c  
a b c  
```  

## <a name="get_container"></a> Queue::get_container (STL/CLR)
Acessa o contêiner subjacente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
container_type^ get_container();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna o contêiner subjacente. Você pode usá-lo para ignorar as restrições impostas pelo wrapper do contêiner.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_get_container.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="op_as"></a> Queue::Operator = (STL/CLR)
Substitui a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
queue <Value, Container>% operator=(queue <Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 Adaptador de contêiner para copiar.  
  
### <a name="remarks"></a>Comentários  
 As cópias de operador de membro `right` para o objeto, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada em `right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_as.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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

## <a name="pop"></a> Queue:: pop (STL/CLR)
Remove o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void pop();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro remove o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para reduzir a fila por um elemento na parte traseira.  
  
### <a name="example"></a>Exemplo  
  
```  
// cliext_queue_pop.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
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
b c  
```  

## <a name="push"></a> Queue:: push (STL/CLR)
Adiciona um novo elemento de última.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void push(value_type val);  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro adiciona um elemento com o valor `val` no final da fila. Você pode usá-lo para acrescentar um elemento para a fila.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_push.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
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

## <a name="queue"></a> Queue:: Queue (STL/CLR)
Constrói um objeto de adaptador do contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
queue();  
queue(queue<Value, Container>% right);  
queue(queue<Value, Container>^ right);  
explicit queue(container_type% wrapped);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 Objeto a ser copiado.  
  
 encapsulado  
 Contêiner encapsulado para usar.  
  
### <a name="remarks"></a>Comentários  
 O construtor:  
  
 `queue();`  
  
 cria um contêiner encapsulado vazio. Você pode usá-lo para especificar uma sequência vazia de controlado inicial.  
  
 O construtor:  
  
 `queue(queue<Value, Container>% right);`  
  
 cria um contêiner encapsulado que é uma cópia do `right.get_container()`. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila `right`.  
  
 O construtor:  
  
 `queue(queue<Value, Container>^ right);`  
  
 cria um contêiner encapsulado que é uma cópia do `right->get_container()`. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila `*right`.  
  
 O construtor:  
  
 `explicit queue(container_type wrapped);`  
  
 usa o contêiner existente `wrapped` como o contêiner encapsulado. Você pode usá-lo para construir uma fila de um contêiner existente.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_construct.cpp   
// compile with: /clr   
#include <cliext/queue>   
#include <cliext/list>   
  
typedef cliext::queue<wchar_t> Myqueue;   
typedef cliext::list<wchar_t> Mylist;   
typedef cliext::queue<wchar_t, Mylist> Myqueue_list;   
int main()   
    {   
// construct an empty container   
    Myqueue c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct from an underlying container   
    Mylist v2(5, L'x');   
    Myqueue_list c2(v2);       
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Myqueue_list c3(c2);   
    for each (wchar_t elem in c3.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container through handle   
    Myqueue_list c4(%c2);   
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

## <a name="reference"></a> Queue::Reference (STL/CLR)
O tipo de uma referência para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_reference.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify back of queue and redisplay   
    Myqueue::reference ref = c1.back();   
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

## <a name="size"></a> Queue:: Size (STL/CLR)
Conta o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
size_type size();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada. Você pode usá-lo para determinar o número de elementos no momento na sequência controlada. Se você se preocupa se a sequência tem tamanho diferente de zero, consulte [Queue:: Empty (STL/CLR)](../dotnet/queue-empty-stl-clr.md)`()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_size.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
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

## <a name="size_type"></a> Queue:: size_type (STL/CLR)
O tipo de uma distância assinado entre dois elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef int size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elementos não-negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_size_type.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    Myqueue::size_type diff = c1.size();   
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

## <a name="to_array"></a> Queue::to_array (STL/CLR)
Copia uma nova matriz sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
cli::array<Value>^ to_array();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma matriz que contém a sequência controlada. Você pode usá-lo para obter uma cópia da sequência controlada no formulário de matriz.  
  
### <a name="example"></a>Exemplo  
  
```  
// cliext_queue_to_array.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
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

## <a name="value_type"></a> Queue:: value_type (STL/CLR)
O tipo de um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Value value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Value`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_value_type.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display reversed contents " a b c" using value_type   
    for (; !c1.empty(); c1.pop())   
        {   // store element in value_type object   
        Myqueue::value_type val = c1.front();   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="op_neq"></a> operador! = (queue) (STL/CLR)
Fila não igual a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator!=(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left == right)`. Você pode usá-lo para testar se `left` não for ordenado igual `right` quando as duas filas são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_ne.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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

## <a name="op_lt"></a> operador&lt; (queue) (STL/CLR)
Menos de comparação da fila.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator<(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 O operador função retornará true se, para a posição mais baixa `i` para o qual `!(right[i] < left[i])` é verdade que também `left[i] < right[i]`. Caso contrário, retornará `left->` [Queue:: Size (STL/CLR)](../dotnet/queue-size-stl-clr.md) `() <` `right->size()` usá-lo para testar se `left` são ordenados antes `right` quando as duas filas são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_lt.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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

## <a name="op_lteq"></a> operador&lt;= (queue) (STL/CLR)
Fila menor ou igual comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator<=(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(right < left)`. Você pode usá-lo para testar se `left` não for ordenado após `right` quando as duas filas são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_le.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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

## <a name="op_eq"></a> operador = = (queue) (STL/CLR)
Comparação de igual de fila.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator==(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 A função de operador retorna true somente se as sequências controlados por `left` e `right` ter o mesmo comprimento e, para cada posição `i`, `left[i] ==` `right[i]`. Você pode usá-lo para testar se `left` é ordenado igual `right` quando as duas filas são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_eq.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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

## <a name="op_gt"></a> operador&gt; (queue) (STL/CLR)
Fila de maior que a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator>(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `right` `<` `left`. Você pode usá-lo para testar se `left` é solicitada após `right` quando as duas filas são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_gt.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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

## <a name="op_gteq"></a> operador&gt;= (queue) (STL/CLR)
Fila de maior que ou igual a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator>=(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left < right)`. Você pode usá-lo para testar se `left` não for ordenado antes `right` quando as duas filas são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_queue_operator_ge.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
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