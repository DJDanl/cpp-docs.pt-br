---
title: lista (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::list
- cliext::list::assign
- cliext::list::assign
- cliext::list::back
- cliext::list::back_item
- cliext::list::begin
- cliext::list::clear
- cliext::list::const_iterator
- cliext::list::const_reference
- cliext::list::const_reverse_iterator
- cliext::list::difference_type
- cliext::list::empty
- cliext::list::end
- cliext::list::erase
- cliext::list::front
- cliext::list::front_item
- cliext::list::generic_container
- cliext::list::generic_iterator
- cliext::list::generic_reverse_iterator
- cliext::list::generic_value
- cliext::list::insert
- cliext::list::iterator
- cliext::list::list
- cliext::list::merge
- cliext::list::operator=
- cliext::list::pop_back
- cliext::list::pop_front
- cliext::list::push_back
- cliext::list::push_front
- cliext::list::rbegin
- cliext::list::reference
- cliext::list::remove
- cliext::list::remove_if
- cliext::list::rend
- cliext::list::resize
- cliext::list::reverse
- cliext::list::reverse_iterator
- cliext::list::size
- cliext::list::size_type
- cliext::list::sort
- cliext::list::splice
- cliext::list::swap
- cliext::list::to_array
- cliext::list::unique
- cliext::list::value_type
- cliext::operator!=(list)
- cliext::operator<(list)
- cliext::operator<=(list)
- cliext::operator==(list)
- cliext::operator>(list)
- cliext::operator>=(list)
dev_langs:
- C++
helpviewer_keywords:
- <cliext/list> header [STL/CLR]
- list class [STL/CLR]
- <list> header [STL/CLR]
- assign member [STL/CLR]
- assign member [STL/CLR]
- back member [STL/CLR]
- back_item member [STL/CLR]
- begin member [STL/CLR]
- clear member [STL/CLR]
- const_iterator member [STL/CLR]
- const_reference member [STL/CLR]
- const_reverse_iterator member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- end member [STL/CLR]
- erase member [STL/CLR]
- front member [STL/CLR]
- front_item member [STL/CLR]
- generic_container member [STL/CLR]
- generic_iterator member [STL/CLR]
- generic_reverse_iterator member [STL/CLR]
- generic_value member [STL/CLR]
- insert member [STL/CLR]
- iterator member [STL/CLR]
- list member [STL/CLR]
- merge member [STL/CLR]
- operator= member [STL/CLR]
- pop_back member [STL/CLR]
- pop_front member [STL/CLR]
- push_back member [STL/CLR]
- push_front member [STL/CLR]
- rbegin member [STL/CLR]
- reference member [STL/CLR]
- remove member [STL/CLR]
- remove_if member [STL/CLR]
- rend member [STL/CLR]
- resize member [STL/CLR]
- reverse member [STL/CLR]
- reverse_iterator member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- sort member [STL/CLR]
- splice member [STL/CLR]
- swap member [STL/CLR]
- to_array member [STL/CLR]
- unique member [STL/CLR]
- value_type member [STL/CLR]
- operator!=(list) member [STL/CLR]
- operator<(list) member [STL/CLR]
- operator<=(list) member [STL/CLR]
- operator==(list) member [STL/CLR]
- operator>(list) member [STL/CLR]
- operator>=(list) member [STL/CLR]
ms.assetid: a70c45c8-a257-4f6b-8434-b27ff6685bac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8eb64c41db0e6062f2be636ddce7e8cefe0bb32b
ms.sourcegitcommit: bad2441d1930275ff506d44759d283d94cccd1c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2018
ms.locfileid: "39376284"
---
# <a name="list-stlclr"></a>list (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos que tem acesso bidirecional. Você pode usar o contêiner `list` para gerenciar uma sequência de elementos como uma lista vinculada de bidirecional de nós, cada armazenar um elemento.  
  
 Na descrição abaixo, `GValue` é o mesmo que *valor* , a menos que o último é um tipo ref, nesse caso, ele é `Value^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    ref class list  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        Microsoft::VisualC::StlClr::IList<GValue>  
    { ..... };  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Value*  
 O tipo de um elemento na sequência controlada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext 

## <a name="declarations"></a>Declarações  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[list::const_iterator (STL/CLR)](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|  
|[list::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|  
|[list::const_reverse_iterator (STL/CLR)](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[list::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[list::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o contêiner.|  
|[list::generic_iterator (STL/CLR)](#generic_iterator)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[list::generic_reverse_iterator (STL/CLR)](#generic_reverse_iterator)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[list::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[list::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|  
|[list::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|  
|[list::reverse_iterator (STL/CLR)](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|  
|[list::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[list::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[list::assign (STL/CLR)](#assign)|Substitui todos os elementos.|  
|[list::back (STL/CLR)](#back)|Acessa o último elemento.|  
|[list::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|  
|[list::clear (STL/CLR)](#clear)|Remove todos os elementos.|  
|[list::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|  
|[list::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|  
|[list::erase (STL/CLR)](#erase)|Remove os elementos em posições especificadas.|  
|[list::front (STL/CLR)](#front)|Acessa o primeiro elemento.|  
|[list::insert (STL/CLR)](#insert)|Adiciona os elementos em uma posição especificada.|  
|[list::list (STL/CLR)](#list)|Constrói um objeto contêiner.|  
|[list::merge (STL/CLR)](#merge)|Mescla duas sequências controladas ordenadas.|  
|[list::pop_back (STL/CLR)](#pop_back)|Remove o último elemento.|  
|[list::pop_front (STL/CLR)](#pop_front)|Remove o primeiro elemento.|  
|[list::push_back (STL/CLR)](#push_back)|Adiciona um novo último elemento.|  
|[list::push_front (STL/CLR)](#push_front)|Adiciona um novo elemento primeiro.|  
|[list::rbegin (STL/CLR)](#rbegin)|Designa o início da sequência controlada invertida.|  
|[list::remove (STL/CLR)](#remove)|Remove um elemento com um valor especificado.|  
|[list::remove_if (STL/CLR)](#remove_if)|Remove elementos que passarem um teste especificado.|  
|[list::rend (STL/CLR)](#rend)|Designa o fim da sequência controlada invertida.|  
|[list::resize (STL/CLR)](#resize)|Altera o número de elementos.|  
|[list::reverse (STL/CLR)](#reverse)|Inverte a sequência controlada.|  
|[list::size (STL/CLR)](#size)|Conta o número de elementos.|  
|[list::sort (STL/CLR)](#sort)|Ordena a sequência controlada.|  
|[list::splice (STL/CLR)](#splice)|Costura novamente links entre os nós.|  
|[list::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|  
|[list::to_array (STL/CLR)](#to_array)|Copia a sequência controlada para uma nova matriz.|  
|[list::unique (STL/CLR)](#unique)|Remove elementos adjacentes que são passados a um teste especificado.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[list::back_item (STL/CLR)](#back_item)|Acessa o último elemento.|  
|[list::front_item (STL/CLR)](#front_item)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[list::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|  
|[operator!= (list) (STL/CLR)](#op_neq)|Determina se um `list` objeto não é igual a outro `list` objeto.|  
|[operator< (list) (STL/CLR)](#op_lt)|Determina se um `list` objeto é menor que outro `list` objeto.|  
|[operator<= (list) (STL/CLR)](#op_lteq)|Determina se um `list` objeto é menor ou igual a outro `list` objeto.|  
|[operator== (list) (STL/CLR)](#op_eq)|Determina se um `list` objeto é igual a outro `list` objeto.|  
|[operator> (list) (STL/CLR)](#op_gt)|Determina se um `list` objeto é maior que outro `list` objeto.|  
|[operator>= (list) (STL/CLR)](#op_gteq)|Determina se um `list` objeto é maior que ou igual a outro `list` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Por meio de elementos de sequência.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Por meio de elementos com tipo de sequência.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|IList\<valor >|Manter o contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla como nós individuais em uma lista de links bidirecional. Ele reorganiza elementos alterando os links entre nós nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente sem prejudicar os elementos restantes. Portanto, uma lista é um bom candidato para o contêiner subjacente para a classe de modelo [queue (STL/CLR)](../dotnet/queue-stl-clr.md) ou a classe de modelo [stack (STL/CLR)](../dotnet/stack-stl-clr.md).  
  
 Um `list` objeto dá suporte a iteradores bidirecionais, que significa que você pode passar para elementos adjacentes, dado um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde ao iterador retornado por [List:: end (STL/CLR)](../dotnet/list-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se estiver presente. Você pode incrementar um iterador de lista para alcançar o nó principal e, em seguida, compare igual a `end()`. Mas você não é possível desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de lista diretamente, dado sua posição numérica – o que exige um iterador de acesso aleatório. Portanto, é uma lista *não* pode ser usado como contêiner para a classe de modelo subjacente [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md).  
  
 Um iterador de lista armazena um identificador para o seu nó lista associada, que por sua vez armazena um identificador para o contêiner associado. Você pode usar iteradores somente com seus objetos de contêiner associado. Um iterador de lista permanece válido desde que seu nó da lista associada é associada a alguma lista. Além disso, um iterador válido é dereferencable – você pode usá-lo para acessar ou alterar o valor do elemento que ele designa – desde que não é igual a `end()`.  
  
 Apagando ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Portanto, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento sobreviver além do contêiner. No entanto, observe que um contêiner de identificadores não *não* destruir seus elementos.  
  
## <a name="members"></a>Membros

## <a name="assign"></a> List:: Assign (STL/CLR)
Substitui todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void assign(size_type count, value_type val);  
template<typename InIt>  
    void assign(InIt first, InIt last);  
void assign(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *count*  
 Número de elementos a inserir.  
  
 *first*  
 Início do intervalo a ser inserido.  
  
 *last*  
 Fim do intervalo a inserir.  
  
 *right*  
 Enumeração a ser inserido.  
  
 *Val*  
 Valor do elemento a ser inserido.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro substitui a sequência controlada por uma repetição de *contagem* elementos de valor *val*. Você usá-lo para preencher o contêiner com elementos tudo que tem o mesmo valor.  
  
 Se `InIt` é um tipo inteiro, a segunda função membro se comporta da mesma como `assign((size_type)first, (value_type)last)`. Caso contrário, ele substitui a sequência controlada pela sequência [`first`, `last`). Você usá-lo para tornar o controlado uma cópia de sequência outra sequência.  
  
 A terceira função membro substitui a sequência controlada pela sequência designada pelo enumerador *certa*. Você pode usá-lo para fazer uma cópia de uma sequência descrita por um enumerador a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_assign.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// assign a repetition of values   
    cliext::list<wchar_t> c2;   
    c2.assign(6, L'x');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an iterator range   
    cliext::list<wchar_t>::iterator it = c1.end();   
    c2.assign(c1.begin(), --it);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an enumeration   
    c2.assign(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
x x x x x x  
a b  
a b c  
```  
 
## <a name="back"></a> List (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
reference back();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna uma referência ao último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para acessar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_back.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("back() = {0}", c1.back());   
  
// alter last item and reinspect   
    c1.back() = L'x';   
    for each (wchar_t elem in c1)   
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

## <a name="back_item"></a> List::back_item (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
property value_type back_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_back_item.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("back_item = {0}", c1.back_item);   
  
// alter last item and reinspect   
    c1.back_item = L'x';   
    for each (wchar_t elem in c1)   
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

## <a name="begin"></a> List:: Begin (STL/CLR)
Designa o início da sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
iterator begin();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um iterador de acesso aleatório que designa o primeiro elemento da sequência controlada ou logo após o fim de uma sequência vazia. Você pode usá-lo para obter um iterador que designa o `current` início da sequência controlada, mas seu status pode alterar se o comprimento da sequência controlada for alterado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_begin.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items   
    cliext::list<wchar_t>::iterator it = c1.begin();   
    System::Console::WriteLine("*begin() = {0}", *it);   
    System::Console::WriteLine("*++begin() = {0}", *++it);   
  
// alter first two items and reinspect   
    *--it = L'x';   
    *++it = L'y';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
 a b c  
*begin() = a  
*++begin() = b  
 x y c  
```  

## <a name="clear"></a> List:: Clear (STL/CLR)
Remove todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void clear();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro chama efetivamente [List:: Erase (STL/CLR)](../dotnet/list-erase-stl-clr.md) `(` [List:: Begin (STL/CLR)](../dotnet/list-begin-stl-clr.md) `(),` [List:: end (STL/CLR)](../dotnet/list-end-stl-clr.md) `())`. Você pode usá-lo para garantir que a sequência controlada vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_clear.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// add elements and clear again   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
  
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    return (0);   
    }  
```  
  
```Output  
 a b c  
size() = 0  
 a b  
size() = 0  
```  

## <a name="const_iterator"></a> List:: const_iterator (STL/CLR)
O tipo de um iterador de constante para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef T2 const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo não especificado `T2` que pode servir como um iterador de acesso aleatório constante para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_const_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    cliext::list<wchar_t>::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        System::Console::Write(" {0}", *cit);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
```  

## <a name="const_reference"></a> List:: const_reference (STL/CLR)
O tipo de uma referência de constante para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef value_type% const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência constante para um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_const_reference.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    cliext::list<wchar_t>::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        {   // get a const reference to an element   
        cliext::list<wchar_t>::const_reference cref = *cit;   
        System::Console::Write(" {0}", cref);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
```  

## <a name="const_reverse_iterator"></a> List:: const_reverse_iterator (STL/CLR)
O tipo de um iterador inverso constante para a sequência controlada...  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef T4 const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo não especificado `T4` que pode servir como um iterador inverso constante para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_const_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" reversed   
    cliext::list<wchar_t>::const_reverse_iterator crit = c1.rbegin();   
    cliext::list<wchar_t>::const_reverse_iterator crend = c1.rend();   
    for (; crit != crend; ++crit)   
        System::Console::Write(" {0}", *crit);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
c b a  
```  

## <a name="difference_type"></a> List:: difference_type (STL/CLR)
Os tipos de uma distância com sinal entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef int difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem com sinal de elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// cliext_list_difference_type.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    cliext::list<wchar_t>::difference_type diff = 0;   
    for (cliext::list<wchar_t>::iterator it = c1.begin();   
        it != c1.end(); ++it) ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
  
// compute negative difference   
    diff = 0;   
    for (cliext::list<wchar_t>::iterator it = c1.end();   
        it != c1.begin(); --it) --diff;   
    System::Console::WriteLine("begin()-end() = {0}", diff);   
    return (0);   
    }  
```  
  
```Output  
 a b c  
end()-begin() = 3  
begin()-end() = -3  
```  

## <a name="empty"></a> List:: Empty (STL/CLR)
Testa se nenhum elemento está presente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
bool empty();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [List:: Size (STL/CLR)](../dotnet/list-size-stl-clr.md)`() == 0`. Você pode usá-lo para testar se a lista estiver vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_empty.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
  
// clear the container and reinspect   
    c1.clear();   
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

## <a name="end"></a> List:: end (STL/CLR)
Designa o fim da sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
iterator end();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um iterador de acesso aleatório que aponta para logo após o fim da sequência controlada. Você pode usá-lo para obter um iterador que designa o fim da sequência controlada; seu status alteração não se o comprimento da sequência controlada for alterado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_end.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last two items   
    cliext::list<wchar_t>::iterator it = c1.end();   
    --it;   
    System::Console::WriteLine("*-- --end() = {0}", *--it);   
    System::Console::WriteLine("*--end() = {0}", *++it);   
  
// alter first two items and reinspect   
    *--it = L'x';   
    *++it = L'y';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
 a b c  
*-- --end() = b  
*--end() = c  
 a x y  
```  

## <a name="erase"></a> List:: Erase (STL/CLR)
Remove os elementos em posições especificadas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *first*  
 Início do intervalo a ser apagado.  
  
 *last*  
 Fim do intervalo a ser apagado.  
  
 *where*  
 Elemento a ser apagado.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro remove o elemento da sequência controlada apontada por *onde*. Você pode usá-lo para remover um único elemento.  
  
 A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). Você pode usá-lo para remover a zero ou mais elementos contíguos.  
  
 Ambas as funções membro retornam um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [List:: end (STL/CLR)](../dotnet/list-end-stl-clr.md) `()` se não houver tal elemento.  
  
 Ao apagar elementos, o número de cópias de elemento é linear no número de elementos entre o fim de apagamento e final da sequência mais próximo. (Ao apagar uma ou mais elementos em ambas as extremidades da sequência, nenhuma cópia do elemento ocorre.)  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_erase.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    System::Console::WriteLine("erase(begin()) = {0}",   
        *c1.erase(c1.begin()));   
  
// add elements and display " b c d e"   
    c1.push_back(L'd');   
    c1.push_back(L'e');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase all but end   
    cliext::list<wchar_t>::iterator it = c1.end();   
    System::Console::WriteLine("erase(begin(), end()-1) = {0}",   
        *c1.erase(c1.begin(), --it));   
    System::Console::WriteLine("size() = {0}", c1.size());   
    return (0);   
    }  
```  
  
```Output  
 a b c  
erase(begin()) = b  
 b c d e  
erase(begin(), end()-1) = e  
size() = 1  
```  

## <a name="front"></a> List:: front (STL/CLR)
Acessa o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
reference front();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna uma referência para o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_front.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first item   
    System::Console::WriteLine("front() = {0}", c1.front());   
  
// alter first item and reinspect   
    c1.front() = L'x';   
    for each (wchar_t elem in c1)   
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

## <a name="front_item"></a> List::front_item (STL/CLR)
Acessa o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
property value_type front_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_front_item.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first item   
    System::Console::WriteLine("front_item = {0}", c1.front_item);   
  
// alter first item and reinspect   
    c1.front_item = L'x';   
    for each (wchar_t elem in c1)   
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

## <a name="generic_container"></a> List::generic_container (STL/CLR)
O tipo da interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Microsoft::VisualC::StlClr::  
    IList<generic_value>  
    generic_container;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve a interface genérica para essa classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_generic_container.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::list<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    gc1->insert(gc1->end(), L'd');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify original and display generic   
    c1.push_back(L'e');   
  
    System::Collections::IEnumerator^ enum1 =   
        gc1->GetEnumerator();   
    while (enum1->MoveNext())   
        System::Console::Write(" {0}", enum1->Current);   
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

## <a name="generic_iterator"></a> List::generic_iterator (STL/CLR)
O tipo de um iterador para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Microsoft::VisualC::StlClr::Generic::  
    ContainerBidirectionalIterator<generic_value>  
    generic_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um iterador genérico que pode ser usado com a interface genérica para essa classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_generic_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::list<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    cliext::list<wchar_t>::generic_iterator gcit = gc1->begin();   
    cliext::list<wchar_t>::generic_value gcval = *gcit;   
    *++gcit = gcval;   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
a a c  
```  

## <a name="generic_reverse_iterator"></a> List::generic_reverse_iterator (STL/CLR)
O tipo de um iterador inverso para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Microsoft::VisualC::StlClr::Generic::  
    ReverseBidirectionalIterator<generic_value> generic_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um iterador inverso genérico que pode ser usado com a interface genérica para essa classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_generic_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::list<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    cliext::list<wchar_t>::generic_reverse_iterator gcit = gc1->rbegin();   
    cliext::list<wchar_t>::generic_value gcval = *gcit;   
    *++gcit = gcval;   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
a c c  
```  

## <a name="generic_value"></a> List::generic_value (STL/CLR)
O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef GValue generic_value;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor de elemento armazenado para uso com a interface genérica para essa classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_generic_value.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::list<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    cliext::list<wchar_t>::generic_iterator gcit = gc1->begin();   
    cliext::list<wchar_t>::generic_value gcval = *gcit;   
    *++gcit = gcval;   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
a a c  
```  

## <a name="insert"></a> List:: Insert (STL/CLR)
Adiciona os elementos em uma posição especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
iterator insert(iterator where, value_type val);  
void insert(iterator where, size_type count, value_type val);  
template<typename InIt>  
    void insert(iterator where, InIt first, InIt last);  
void insert(iterator where,  
    System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *count*  
 Número de elementos a inserir.  
  
 *first*  
 Início do intervalo a ser inserido.  
  
 *last*  
 Fim do intervalo a inserir.  
  
 *right*  
 Enumeração a ser inserido.  
  
 *Val*  
 Valor do elemento a ser inserido.  
  
 *where*  
 Onde no contêiner antes da qual inserir.  
  
### <a name="remarks"></a>Comentários  
 Cada um dos membro funções inserções, antes do elemento apontado por *onde* na sequência controlada, uma sequência especificada pelos operandos restantes.  
  
 A primeira função membro insere um elemento com o valor *val* e retorna um iterador que designa o elemento recém-inserido. Você pode usá-lo para inserir um único elemento antes de um local designado por um iterador.  
  
 A segunda função membro insere uma repetição de *contagem* elementos de valor *val*. Você pode usá-lo para inserir zero ou mais elementos adjacentes que são todas as cópias do mesmo valor.  
  
 Se `InIt` for um tipo inteiro, a terceira função membro se comportará da mesma forma que `insert(where, (size_type)first, (value_type)last)`. Caso contrário, ele insere a sequência [`first`, `last`). Você pode usá-lo para inserir a zero ou mais elementos contíguos copiados de outra sequência.  
  
 A quarta função membro insere a sequência designada pela *certa*. Você pode usá-lo para inserir uma sequência descrita por um enumerador.  
  
 Ao inserir um único elemento, o número de cópias de elemento é linear no número de elementos entre o ponto de inserção e a extremidade mais próximo da sequência. (Ao inserir um ou mais elementos em ambas as extremidades da sequência, não há cópias de elemento ocorrem). Se `InIt` é um iterador de entrada, a terceira função membro efetivamente executa uma inserção única para cada elemento na sequência. Caso contrário, quando inserindo `N` elementos, o número de cópias de elemento é linear no `N` mais o número de elementos entre o ponto de inserção e a extremidade mais próximo da sequência.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_insert.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value using iterator   
    cliext::list<wchar_t>::iterator it = c1.begin();   
    System::Console::WriteLine("insert(begin()+1, L'x') = {0}",   
        *c1.insert(++it, L'x'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a repetition of values   
    cliext::list<wchar_t> c2;   
    c2.insert(c2.begin(), 2, L'y');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    it = c1.end();   
    c2.insert(c2.end(), c1.begin(), --it);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    c2.insert(c2.begin(),   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value using index   
    it = c2.begin();   
    ++it, ++it, ++it;   
    c2.insert(it, L'z');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    return (0);   
    }  
```  
  
```Output  
 a b c  
insert(begin()+1, L'x') = x  
 a x b c  
 y y  
 y y a x b  
 a x b c y y a x b  
```  

## <a name="iterator"></a> List:: Iterator (STL/CLR)
O tipo de um iterador para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef T1 iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo não especificado `T1` que pode servir como um iterador de acesso aleatório para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    cliext::list<wchar_t>::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        System::Console::Write(" {0}", *it);   
    System::Console::WriteLine();   
  
// alter first element and redisplay   
    it = c1.begin();   
    *it = L'x';   
    for (; it != c1.end(); ++it)   
        System::Console::Write(" {0}", *it);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
x b c  
```  

## <a name="list"></a> List:: List (STL/CLR)
Constrói um objeto contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
list();  
list(list<Value>% right);  
list(list<Value>^ right);  
explicit list(size_type count);  
list(size_type count, value_type val);  
template<typename InIt>  
    list(InIt first, InIt last);  
list(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *count*  
 Número de elementos a inserir.  
  
 *first*  
 Início do intervalo a ser inserido.  
  
 *last*  
 Fim do intervalo a inserir.  
  
 *right*  
 Objeto ou intervalo a inserir.  
  
 *Val*  
 Valor do elemento a ser inserido.  
  
### <a name="remarks"></a>Comentários  
  
 O construtor:  
  
 `list();`  
  
 inicializa a sequência controlada com nenhum elemento. Você pode usá-lo para especificar uma sequência controlada inicial vazia.  
  
 O construtor:  
  
 `list(list<Value>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de lista *certa*.  
  
 O construtor:  
  
 `list(list<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de lista cujo identificador é *certa*.  
  
 O construtor:  
  
 `explicit list(size_type count);`  
  
 inicializa a sequência controlada com *contagem* elementos com valor `value_type()`. Você usá-lo para preencher o contêiner com elementos tudo que tem o valor padrão.  
  
 O construtor:  
  
 `list(size_type count, value_type val);`  
  
 inicializa a sequência controlada com *contagem* elementos com valor de *val*. Você usá-lo para preencher o contêiner com elementos tudo que tem o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `list(InIt first, InIt last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`). Você pode usá-lo para fazer uma cópia de outra sequência a sequência controlada.  
  
 O construtor:  
  
 `list(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador *certa*. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_construct.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
// construct an empty container   
    cliext::list<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::list<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::list<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::list<wchar_t>::iterator it = c3.end();   
    cliext::list<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::list<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::list<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::list<wchar_t> c8(%c3);   
    for each (wchar_t elem in c8)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    return (0);   
    }  
```  
  
```Output  
size() = 0  
 0 0 0  
 x x x x x x  
 x x x x x  
 x x x x x x  
 x x x x x x  
 x x x x x x  
```  

## <a name="merge"></a> List:: Merge (STL/CLR)
Mescla duas sequências controladas ordenadas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void merge(list<Value>% right);  
template<typename Pred2>  
    void merge(list<Value>% right, Pred2 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Pred*  
 Comparador para pares de elementos.  
  
 *right*  
 Contêiner de mesclagem.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro remove todos os elementos da sequência controlada por *certa* e inseri-los na sequência controlada. As duas sequências devem ser ordenadas anteriormente pelo `operator<` – elementos não devem diminuir em valor conforme você percorre a sequência. A sequência resultante também é ordenada por `operator<`. Você pode usar essa função de membro para mesclar duas sequências que aumentam o valor em uma sequência que aumenta também de valor.  
  
 A segunda função membro se comporta da mesma maneira que a primeira, exceto que as sequências são ordenadas por `pred`  --  `pred(X, Y)` deve ser false para qualquer elemento `X` que segue o elemento `Y` na sequência. Você pode usá-lo para mesclar duas sequências ordenadas por uma função de predicado ou delegado que você especificar.  
  
 As funções de executam uma mesclagem estável – nenhum par de elementos das sequências de controlado originais é revertido na sequência controlada resultante. Além disso, se um par de elementos `X` e `Y` na sequência controlada resultante tem ordenação equivalente – `!(X < Y) && !(X < Y)` – um elemento da sequência controlada original aparecerá antes de um elemento da sequência controlada por *certa*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_merge.cpp   
// compile with: /clr   
#include <cliext/list>   
  
typedef cliext::list<wchar_t> Mylist;   
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'c');   
    c1.push_back(L'e');   
  
// display initial contents " a c e"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    cliext::list<wchar_t> c2;   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
    c2.push_back(L'f');   
  
// display initial contents " b d f"   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// merge and display   
    cliext::list<wchar_t> c3(c1);   
    c3.merge(c2);   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c2.size() = {0}", c2.size());   
  
// sort descending, merge descending, and redisplay   
    c1.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    c3.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    c3.merge(c1, cliext::greater<wchar_t>());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c1.size() = {0}", c1.size());   
    return (0);   
    }  
```  
  
```Output  
 a c e  
 b d f  
 a b c d e f  
c2.size() = 0  
 e c a  
 f e d c b a  
 f e e d c c b a a  
c1.size() = 0  
```  

## <a name="op_as"></a> List::Operator = (STL/CLR)
Substitui a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
list<Value>% operator=(list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *right*  
 O contêiner a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 As cópias de operador de membro *certa* ao objeto, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada no *certa*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_as.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2 = c1;   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
```  

## <a name="pop_back"></a> List:: pop_back (STL/CLR)
Remove o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void pop_back();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro remove o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para diminuir a lista por um elemento na parte traseira.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_pop_back.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// pop an element and redisplay   
    c1.pop_back();   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b  
```  

## <a name="pop_front"></a> List:: pop_front (STL/CLR)
Remove o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void pop_front();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro remove o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para diminuir a lista por um elemento na frente.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_pop_front.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// pop an element and redisplay   
    c1.pop_front();   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
b c  
```  

## <a name="push_back"></a> List:: push_back (STL/CLR)
Adiciona um novo último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void push_back(value_type val);  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro insere um elemento com valor `val` no final da sequência controlada. Você pode usá-lo para acrescentar a outro elemento à lista.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_push_back.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
```  
  
## <a name="push_front"></a> List:: push_front (STL/CLR)
Adiciona um novo elemento primeiro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void push_front(value_type val);  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro insere um elemento com valor `val` no início da sequência controlada. Você pode usá-lo para preceder a outro elemento à lista.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_push_front.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_front(L'a');   
    c1.push_front(L'b');   
    c1.push_front(L'c');   
  
// display contents " c b a"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
c b a  
```  

## <a name="rbegin"></a> List:: rbegin (STL/CLR)
Designa o início da sequência controlada invertida.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
reverse_iterator rbegin();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um iterador inverso que designa o último elemento da sequência controlada ou logo após o início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` início da sequência controlada visto na ordem inversa, mas seu status pode alterar se o comprimento da sequência controlada for alterado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_rbegin.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items in reversed sequence   
    cliext::list<wchar_t>::reverse_iterator rit = c1.rbegin();   
    System::Console::WriteLine("*rbegin() = {0}", *rit);   
    System::Console::WriteLine("*++rbegin() = {0}", *++rit);   
  
// alter first two items and reinspect   
    *--rit = L'x';   
    *++rit = L'y';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
 a b c  
*rbegin() = c  
*++rbegin() = b  
 a y x  
```  

## <a name="reference"></a> List:: Reference (STL/CLR)
O tipo de uma referência para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef value_type% reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_reference.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    cliext::list<wchar_t>::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        {   // get a reference to an element   
        cliext::list<wchar_t>::reference ref = *it;   
        System::Console::Write(" {0}", ref);   
        }   
    System::Console::WriteLine();   
  
// modify contents " a b c"   
    for (it = c1.begin(); it != c1.end(); ++it)   
        {   // get a reference to an element   
        cliext::list<wchar_t>::reference ref = *it;   
  
        ref += (wchar_t)(L'A' - L'a');   
        System::Console::Write(" {0}", ref);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
A B C  
```  

## <a name="remove"></a> List:: Remove (STL/CLR)
Remove um elemento com um valor especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void remove(value_type val);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Val*  
 Valor do elemento a ser removido.  
  
### <a name="remarks"></a>Comentários  
 A função membro remove um elemento na sequência controlada para as quais `((System::Object^)val)->Equals((System::Object^)x)` for verdadeira (se houver). Você pode usá-lo para apagar um elemento arbitrário com o valor especificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_remove.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// fail to remove and redisplay   
    c1.remove(L'A');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();  
  
// remove and redisplay   
    c1.remove(L'b');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
a b c  
a c  
```  

## <a name="remove_if"></a> List:: remove_if (STL/CLR)
Remove elementos que passarem um teste especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Pred1>  
    void remove_if(Pred1 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Pred*  
 Teste de elementos a serem removidos.  
  
### <a name="remarks"></a>Comentários  
 A função membro remove da sequência controlada (apaga) todos os elementos `X` para o qual `pred(X)` é verdadeiro. Você pode usá-lo para remover todos os elementos que satisfazem uma condição a que você especificar como uma função ou um delegado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_remove_if.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'b');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b b b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// fail to remove and redisplay   
    c1.remove_if(cliext::binder2nd<cliext::equal_to<wchar_t> >(   
        cliext::equal_to<wchar_t>(), L'd'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// remove and redisplay   
    c1.remove_if(cliext::binder2nd<cliext::not_equal_to<wchar_t> >(   
        cliext::not_equal_to<wchar_t>(), L'b'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b b b c  
a b b b c  
b b b  
``` 

## <a name="rend"></a> List:: rend (STL/CLR)
Designa o fim da sequência controlada invertida.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
reverse_iterator rend();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um iterador inverso que aponta logo após o início da sequência controlada. Portanto, ele designa o `end` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada visto na ordem inversa, mas seu status pode alterar se o comprimento da sequência controlada for alterado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_rend.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items   
    cliext::list<wchar_t>::reverse_iterator rit = c1.rend();   
    --rit;   
    System::Console::WriteLine("*-- --rend() = {0}", *--rit);   
    System::Console::WriteLine("*--rend() = {0}", *++rit);   
  
// alter first two items and reinspect   
    *--rit = L'x';   
    *++rit = L'y';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
 a b c  
*-- --rend() = b  
*--rend() = a  
 y x c  
```  

## <a name="resize"></a> List:: Resize (STL/CLR)
Altera o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void resize(size_type new_size);  
void resize(size_type new_size, value_type val);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *new_size*  
 Novo tamanho da sequência controlada.  
  
 *Val*  
 Valor do elemento de preenchimento.  
  
### <a name="remarks"></a>Comentários  
 As funções membro de ambos os Verifique [List:: Size (STL/CLR)](../dotnet/list-size-stl-clr.md) `()` daqui em diante retorna *new_size*. Se for necessário tornar a sequência controlada mais longa, a primeira função membro acrescentará elementos com valor `value_type()`, enquanto a segunda função membro acrescentará elementos com valor *val*. Para tornar a sequência controlada mais curta, ambas as funções membro efetivamente apagar o último elemento [List:: Size (STL/CLR)](../dotnet/list-size-stl-clr.md) `() -` `new_size` vezes. Você pode usá-lo para garantir que a sequência controlada tem tamanho *new_size*, filtragem ou preenchimento atual sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_resize.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
// construct an empty container and pad with default values   
    cliext::list<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
    c1.resize(4);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// resize to empty   
    c1.resize(0);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// resize and pad   
    c1.resize(5, L'x');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
size() = 0  
 0 0 0 0  
size() = 0  
 x x x x x  
```  

## <a name="reverse"></a> List:: reverse (STL/CLR)
Inverte a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void reverse();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro inverte a ordem de todos os elementos na sequência controlada. Você pode usá-lo para refletir uma lista de elementos.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_reverse.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// reverse and redisplay   
    c1.reverse();   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
c b a  
```  

## <a name="reverse_iterator"></a> List:: reverse_iterator (STL/CLR)
O tipo de um iterador inverso para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef T3 reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo não especificado `T3` que pode servir como um iterador inverso para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" reversed   
    cliext::list<wchar_t>::reverse_iterator rit = c1.rbegin();   
    for (; rit != c1.rend(); ++rit)   
        System::Console::Write(" {0}", *rit);   
    System::Console::WriteLine();   
  
// alter first element and redisplay   
    rit = c1.rbegin();   
    *rit = L'x';   
    for (; rit != c1.rend(); ++rit)   
        System::Console::Write(" {0}", *rit);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
c b a  
x b a  
```  
  
## <a name="size"></a> List:: Size (STL/CLR)
Conta o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
size_type size();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada. Você pode usá-lo para determinar o número de elementos que estão na sequência controlada. Se você se preocupa se a sequência tem tamanho diferente de zero, consulte [List:: Empty (STL/CLR)](../dotnet/list-empty-stl-clr.md)`()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_size.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0} after clearing", c1.size());   
  
// add elements and clear again   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());   
    return (0);   
    }  
```  
  
```Output  
 a b c  
size() = 3 starting with 3  
size() = 0 after clearing  
size() = 2 after adding 2  
```  

## <a name="size_type"></a> List:: size_type (STL/CLR)
O tipo de uma distância com sinal entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef int size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elemento não negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_size_type.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    cliext::list<wchar_t>::size_type diff = 0;   
    for (cliext::list<wchar_t>::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
    return (0);   
    }  
```  
  
```Output  
 a b c  
end()-begin() = 3  
```

## <a name="sort"></a> List:: Sort (STL/CLR)
Ordena a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void sort();  
template<typename Pred2>  
    void sort(Pred2 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Pred*  
 Comparador para pares de elementos.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro reorganiza os elementos na sequência controlada para que eles são ordenados por `operator<` – elementos não diminuir em valor conforme você percorre a sequência. Você pode usar essa função de membro para classificar a sequência em ordem crescente.  
  
 A segunda função membro se comporta da mesma maneira que a primeira, exceto que a sequência é ordenada pelo `pred`  --  `pred(X, Y)` é false para qualquer elemento `X` que segue o elemento `Y` na sequência resultante. Você pode usá-lo para classificar a sequência em uma ordem especificada por uma função de predicado ou delegado.  
  
 As funções executam uma classificação estável, pois nenhum par de elementos na sequência controlada original é revertido na sequência controlada resultante.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_sort.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// sort descending and redisplay   
    c1.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// sort ascending and redisplay   
    c1.sort();   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
c b a  
a b c  
``` 

## <a name="splice"></a> List:: splice (STL/CLR)
Restitch links entre os nós.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void splice(iterator where, list<Value>% right);  
void splice(iterator where, list<Value>% right,  
    iterator first);  
void splice(iterator where, list<Value>% right,  
    iterator first, iterator last);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *first*  
 Início do intervalo a ter splice.  
  
 *last*  
 Final do intervalo a ter splice.  
  
 *right*  
 Contêiner do qual realizar splice.  
  
 *where*  
 Onde no contêiner a ter splice antes.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro insere a sequência controlada por *certa* antes do elemento na sequência controlada apontado por *onde*. Ele também remove todos os elementos de *certa*. (`%right` não deve ser igual a `this`.) Você pode usá-lo a ter splice todos de uma lista em outra.  
  
 A segunda função membro remove o elemento apontado por *primeira* na sequência controlada por *à direita* e insere-o antes do elemento na sequência controlada apontada por *onde* . (Se `where` `==` `first` `||` `where` `== ++first`, nenhuma alteração ocorrerá.) Você pode usá-lo a ter splice um único elemento de uma lista em outra.  
  
 A terceira função membro insere o subintervalo designado por [`first`, `last`) da sequência controlada por *à direita* antes do elemento na sequência controlada apontada por *onde*. Ele também remove o subintervalo original da sequência controlada por *certa*. (Se `right` `==` `this`, o intervalo de [`first`, `last`) não deve incluir o elemento apontado por *onde*.) Você pode usá-lo a ter splice uma subsequência de zero ou mais elementos de uma lista em outra.  
  
### <a name="example"></a>Exemplo  
  
```cpp
// cliext_list_splice.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// splice to a new list   
    cliext::list<wchar_t> c2;   
    c2.splice(c2.begin(), c1);   
    System::Console::WriteLine("c1.size() = {0}", c1.size());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// return one element   
    c1.splice(c1.end(), c2, c2.begin());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// return remaining elements   
    c1.splice(c1.begin(), c2, c2.begin(), c2.end());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c2.size() = {0}", c2.size());   
    return (0);   
    }  
```  
  
```Output  
 a b c  
c1.size() = 0  
 a b c  
 a  
 b c  
 b c a  
c2.size() = 0  
```    

## <a name="swap"></a> List:: swap (STL/CLR)
Alterna o conteúdo de dois contêineres.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void swap(list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *right*  
 Contêiner com o qual trocar conteúdos.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `*this` e *direito*. Ele faz isso em tempo constante e não gera exceções. Você pode usá-lo como uma maneira rápida para trocar o conteúdo de dois contêineres.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// cliext_list_swap.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct another container with repetition of values   
    cliext::list<wchar_t> c2(5, L'x');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// swap and redisplay   
    c1.swap(c2);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
x x x x x  
x x x x x  
a b c  
```   

## <a name="to_array"></a> List::to_array (STL/CLR)
Copia a sequência controlada para uma nova matriz.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
cli::array<Value>^ to_array();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna uma matriz que contém a sequência controlada. Você pode usá-lo para obter uma cópia da sequência controlada em forma de matriz.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_to_array.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// copy the container and modify it   
    cli::array<wchar_t>^ a1 = c1.to_array();   
  
    c1.push_back(L'd');   
    for each (wchar_t elem in c1)   
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

## <a name="unique"></a> List:: Unique (STL/CLR)
Remove elementos adjacentes que são passados a um teste especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
void unique();  
template<typename Pred2>  
    void unique(Pred2 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Pred*  
 Comparador para pares de elementos.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro remove da sequência controlada (apaga) todos os elementos que comparam igual ao elemento anterior - se elemento `X` precede o elemento `Y` e `X == Y`, a função membro remove `Y`. Você usá-lo para remover apenas uma cópia de cada subsequência dos elementos adjacentes que compare igual. Observe que, se a sequência controlada for ordenado, por exemplo, chamando [List:: Sort (STL/CLR)](../dotnet/list-sort-stl-clr.md)`()`, a função membro deixa apenas elementos com valores exclusivos. (Portanto, o nome).  
  
 A segunda função membro se comporta da mesma maneira que a primeira, exceto que ele remove cada elemento `Y` após um elemento `X` para o qual `pred(X, Y)`. Você pode usá-lo para remover apenas uma cópia de cada subsequência dos elementos adjacentes que satisfazem a uma função de predicado ou delegado que você especificar. Observe que, se a sequência controlada for ordenado, como ao chamar `sort(pred)`, a função membro deixa apenas os elementos que não têm uma ordenação equivalente com todos os outros elementos.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_unique.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display contents after unique   
    cliext::list<wchar_t> c2(c1);   
    c2.unique();   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display contents after unique(not_equal_to)   
    c2 = c1;   
    c2.unique(cliext::not_equal_to<wchar_t>());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a a b c  
a b c  
a a  
```  

## <a name="value_type"></a> List:: value_type (STL/CLR)
O tipo de um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
typedef Value value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo *valor*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_value_type.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" using value_type   
    for (cliext::list<wchar_t>::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        {   // store element in value_type object   
        cliext::list<wchar_t>::value_type val = *it;   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
```  
  
```Output  
a b c  
``` 

## <a name="op_neq"></a> operador! = (list) (STL/CLR)
Lista de comparação de diferença.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    bool operator!=(list<Value>% left,  
        list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left == right)`. Você pode usá-lo para testar se *esquerdo* não for ordenado igual *à direita* quando as duas listas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_ne.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
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

## <a name="op_lt"></a> operador&lt; (list) (STL/CLR)
Lista inferior a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    bool operator<(list<Value>% left,  
        list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 O operador função retornará true se, para a posição mais baixa `i` para o qual `!(right[i] < left[i])` é verdade também que `left[i] < right[i]`. Caso contrário, retornará `left->size() < right->size()` usá-lo para testar se *esquerdo* é ordenado antes *direita* quando as duas listas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_lt.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
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

## <a name="op_lteq"></a> operador&lt;= (list) (STL/CLR)
Listar menor ou igual comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    bool operator<=(list<Value>% left,  
        list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(right < left)`. Você pode usá-lo para testar se *esquerdo* não for ordenado após *à direita* quando as duas listas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_le.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
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

## <a name="op_eq"></a> operador = = (list) (STL/CLR)
Comparação de igualdade de lista.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp 
template<typename Value>  
    bool operator==(list<Value>% left,  
        list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 A função de operador retornará true somente se as sequências controladas por *esquerdo* e *à direita* têm o mesmo tamanho e, para cada posição `i`, `left[i] ==` `right[i]`. Usá-lo para testar se *esquerdo* é ordenada igual *direita* quando as duas listas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_eq.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
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

## <a name="op_gt"></a> operador&gt; (list) (STL/CLR)
Lista de comparação de maior que.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    bool operator>(list<Value>% left,  
        list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `right` `<` `left`. Usá-lo para testar se *esquerdo* é ordenada após *direita* quando as duas listas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_gt.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
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

## <a name="op_gteq"></a> operador&gt;= (list) (STL/CLR)
Listar maior que ou igual a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    bool operator>=(list<Value>% left,  
        list<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *left*  
 Contêiner esquerdo a comparar.  
  
 *right*  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left` `<` `right)`. Você pode usá-lo para testar se *esquerdo* não for ordenado antes *à direita* quando as duas listas são comparado elemento por elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_list_operator_ge.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
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