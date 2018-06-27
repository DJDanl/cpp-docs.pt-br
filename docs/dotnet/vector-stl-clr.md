---
title: vetor (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::vector
- cliext::operator!=
- cliext::operator<
- cliext::operator<=
- cliext::operator==
- cliext::operator>
- cliext::operator>=
- cliext::vector::assign
- cliext::vector::at
- cliext::vector::back
- cliext::vector::back_item
- cliext::vector::begin
- cliext::vector::capacity
- cliext::vector::clear
- cliext::vector::const_iterator
- cliext::vector::const_reference
- cliext::vector::const_reverse_iterator
- cliext::vector::difference_type
- cliext::vector::empty
- cliext::vector::end
- cliext::vector::erase
- cliext::vector::front
- cliext::vector::front_item
- cliext::vector::generic_container
- cliext::vector::generic_iterator
- cliext::vector::generic_reverse_iterator
- cliext::vector::generic_value
- cliext::vector::insert
- cliext::vector::iterator
- cliext::vector::operator=
- cliext::vector::operator
- cliext::vector::pop_back
- cliext::vector::push_back
- cliext::vector::rbegin
- cliext::vector::reference
- cliext::vector::rend
- cliext::vector::reserve
- cliext::vector::resize
- cliext::vector::reverse_iterator
- cliext::vector::size
- cliext::vector::size_type
- cliext::vector::swap
- cliext::vector::to_array
- cliext::vector::value_type
- cliext::vector::vector
dev_langs:
- C++
helpviewer_keywords:
- vector class [STL/CLR]
- <cliext/vector> header [STL/CLR]
- <vector> header [STL/CLR]
- operator!= member [STL/CLR]
- operator< member [STL/CLR]
- operator<= member [STL/CLR]
- operator== member [STL/CLR]
- operator> (vector) member [STL/CLR]
- operator>= member [STL/CLR]
- assign member [STL/CLR]
- at member [STL/CLR]
- back member [STL/CLR]
- back_item member [STL/CLR]
- begin member [STL/CLR]
- capacity member [STL/CLR]
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
- operator= member [STL/CLR]
- operator member [STL/CLR]
- pop_back member [STL/CLR]
- push_back member [STL/CLR]
- rbegin member [STL/CLR]
- reference member [STL/CLR]
- rend member [STL/CLR]
- reserve member [STL/CLR]
- resize member [STL/CLR]
- reverse_iterator member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- swap member [STL/CLR]
- to_array member [STL/CLR]
- value_type member [STL/CLR]
- vector member [STL/CLR]
ms.assetid: f90060d5-097a-4e9d-9a26-a634b5b9c6c2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 973957609b56f3bcd697f650c75c59d07cc97173
ms.sourcegitcommit: 301bb19056e5bae84ff50f7d1df1e546efe225ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/21/2018
ms.locfileid: "36305765"
---
# <a name="vector-stlclr"></a>vector (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso aleatório. Você usa o contêiner `vector` para gerenciar uma sequência de elementos como um bloco contínuo de armazenamento. O bloco é implementado como uma matriz que cresce sob demanda.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    ref class vector  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        Microsoft::VisualC::StlClr::IVector<GValue>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  

## <a name="declarations"></a>Declarações  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[vector::const_iterator (STL/CLR)](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|  
|[vector::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|  
|[vector::const_reverse_iterator (STL/CLR)](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[vector::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[vector::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o contêiner.|  
|[vector::generic_iterator (STL/CLR)](#generic_iterator)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[vector::generic_reverse_iterator (STL/CLR)](#generic_reverse_iterator)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[vector::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[vector::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|  
|[vector::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|  
|[vector::reverse_iterator (STL/CLR)](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|  
|[vector::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[vector::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[vector::assign (STL/CLR)](#assign)|Substitui todos os elementos.|  
|[vector::at (STL/CLR)](#at)|Acessa um elemento em uma posição especificada.|  
|[vector::back (STL/CLR)](#back)|Acessa o último elemento.|  
|[vector::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|  
|[vector::capacity (STL/CLR)](#capacity)|Relata o tamanho do armazenamento alocado para o contêiner.|  
|[vector::clear (STL/CLR)](#clear)|Remove todos os elementos.|  
|[vector::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|  
|[vector::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|  
|[vector::erase (STL/CLR)](#erase)|Remove os elementos em posições especificadas.|  
|[vector::front (STL/CLR)](#front)|Acessa o primeiro elemento.|  
|[vector::insert (STL/CLR)](#insert)|Adiciona os elementos em uma posição especificada.|  
|[vector::pop_back (STL/CLR)](#pop_back)|Remove o último elemento.|  
|[vector::push_back (STL/CLR)](#push_back)|Adiciona um novo elemento de última.|  
|[vector::rbegin (STL/CLR)](#rbegin)|Designa o início da sequência controlada invertida.|  
|[vector::rend (STL/CLR)](#rend)|Designa o fim da sequência controlada invertida.|  
|[vector::reserve (STL/CLR)](#reserve)|Garante a capacidade de crescimento mínimo para o contêiner.|  
|[vector::resize (STL/CLR)](#resize)|Altera o número de elementos.|  
|[vector::size (STL/CLR)](#size)|Conta o número de elementos.|  
|[vector::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|  
|[vector::to_array (STL/CLR)](#to_array)|Copia uma nova matriz sequência controlada.|  
|[vector::vector (STL/CLR)](#vector)|Constrói um objeto contêiner.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[vector::back_item (STL/CLR)](#back_item)|Acessa o último elemento.|  
|[vector::front_item (STL/CLR)](#front_item)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[vector::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|  
|[vector::operator(STL/CLR)](#op)|Acessa um elemento em uma posição especificada.|  
|[operator!= (vector) (STL/CLR)](#op_neq)|Determina se um `vector` objeto não é igual a outro `vector` objeto.|  
|[operator< (vector) (STL/CLR)](#op_lt)|Determina se um `vector` objeto é menor que outro `vector` objeto.|  
|[operator<= (vector) (STL/CLR)](#op_lteq)|Determina se um `vector` objeto é menor ou igual a outro `vector` objeto.|  
|[operator== (vector) (STL/CLR)](#op_eq)|Determina se um `vector` objeto é igual a outro `vector` objeto.|  
|[operator> (vector) (STL/CLR)](#op_gt)|Determina se um `vector` objeto é maior que outro `vector` objeto.|  
|[operator>= (vector) (STL/CLR)](#op_gteq)|Determina se um `vector` objeto é maior que ou igual a outro `vector` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|<xref:System.Collections.Generic.IList%601>|Manter grupo ordenado de elementos com tipo.|  
|IVector < valor\>|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ela controla, por meio de um conjunto armazenado de `Value` elementos, o que aumenta sob demanda. O crescimento ocorre de forma que o custo da anexação de um novo elemento é amortizado tempo constante. Em outras palavras, o custo de adição de elementos no final não aumenta, em média, como o comprimento do obtém sequência controlada maior. Assim, um vetor é um bom candidato para o contêiner subjacente para a classe de modelo [pilha (STL/CLR)](../dotnet/stack-stl-clr.md).  
  
 Um `vector` iteradores de acesso aleatório dá suporte a, que significa que você pode fazer referência a um elemento diretamente considerando sua posição numérica, contando a partir de zero para o primeiro elemento (frente), para `size() - 1` para o último elemento (back). Isso também significa que um vetor é um bom candidato para o contêiner subjacente para a classe de modelo [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md).  
  
 Um iterador de vetor armazena um identificador para seu objeto de vetor associada, junto com a tendência do elemento que designa por ele. Você pode usar iteradores apenas com os objetos de contêiner associado. A diferença de um elemento de vetor é o mesmo que sua posição.  
  
 Inserindo ou apagar os elementos pode alterar o valor do elemento armazenado em uma posição especificada, portanto o valor designado por um iterador também pode alterar. (O contêiner pode ter que copiar os elementos para cima ou para baixo para criar um buraco antes de uma inserção ou para preencher um buraco após um apagamento). No entanto, um iterador de vetor permanece válido desde que o ajuste está no intervalo `[0, size()]`. Além disso, um iterador válido permanece dereferencable – você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde sua diferença não é igual a `size()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não destrói seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  

## <a name="assign"></a> Vector:: Assign (STL/CLR)
Substitui todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void assign(size_type count, value_type val);  
template<typename InIt>  
    void assign(InIt first, InIt last);  
void assign(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 count  
 Número de elementos a inserir.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Enumeração para inserir.  
  
 Val  
 Valor do elemento a ser inserido.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro substitui sequência controlada por uma repetição de `count` elementos de valor `val`. Você usá-lo para preencher o contêiner com elementos todos com o mesmo valor.  
  
 Se `InIt` é do tipo integer, a segunda função de membro se comporta como `assign((size_type)first, (value_type)last)`. Caso contrário, ele substitui a sequência controlada com a sequência [`first`, `last`). Você usá-lo para fazer o controlado de sequência de uma cópia outra sequência.  
  
 A terceira função membro substitui sequência controlada com a sequência designada pelo enumerador `right`. Você pode usá-lo para fazer uma cópia de uma sequência descrita por um enumerador de sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_assign.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// assign a repetition of values   
    cliext::vector<wchar_t> c2;   
    c2.assign(6, L'x');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an iterator range   
    c2.assign(c1.begin(), c1.end() - 1);   
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

## <a name="at"></a> Vector:: AT (STL/CLR)
Acessa um elemento em uma posição especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference at(size_type pos);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 POS  
 Posição do elemento a acessar.  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma referência para o elemento da sequência controlada na posição `pos`. Você pode usá-lo para ler ou gravar um elemento cuja posição você sabe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_at.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" using at   
    for (int i = 0; i < c1.size(); ++i)   
        System::Console::Write(" {0}", c1.at(i));   
    System::Console::WriteLine();   
  
// change an entry and redisplay   
    c1.at(1) = L'x';   
    for (int i = 0; i < c1.size(); ++i)   
        System::Console::Write(" {0}", c1[i]);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
a x c  
```  

## <a name="back"></a> Vector:: back (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference back();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma referência para o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para acessar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_back.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="back_item"></a> Vector::back_item (STL/CLR)
Acessa o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
property value_type back_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o último elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_back_item.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="begin"></a> Vector:: Begin (STL/CLR)
Designa o início da sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator begin();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador de acesso aleatório que designa o primeiro elemento da sequência controlada ou logo após o fim de uma sequência vazia. Você pode usá-lo para obter um iterador que designa o `current` pode alterá-início da sequência controlada, mas seu status se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_begin.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items   
    cliext::vector<wchar_t>::iterator it = c1.begin();   
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

## <a name="capacity"></a> Vector:: Capacity (STL/CLR)
Relata o tamanho do armazenamento alocado para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
size_type capacity();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna o armazenamento alocado no momento para manter a sequência controlada, um valor de pelo menos tão grande quanto [Vector (STL/CLR)](../dotnet/vector-size-stl-clr.md)`()`. Você pode usá-lo para determinar quanto o contêiner pode atingir antes que ele deve realocar o armazenamento para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_capacity.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for (int i = 0; i < c1.size(); ++i)   
        System::Console::Write(" {0}", c1.at(i));   
    System::Console::WriteLine();   
  
// increase capacity   
    cliext::vector<wchar_t>::size_type cap = c1.capacity();   
    System::Console::WriteLine("capacity() = {0}, ok = {1}",   
        cap, c1.size() <= cap);   
    c1.reserve(cap + 5);   
    System::Console::WriteLine("capacity() = {0}, ok = {1}",   
        c1.capacity(), cap + 5 <= c1.capacity());   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
capacity() = 4, ok = True  
capacity() = 9, ok = True  
```  

## <a name="clear"></a> Vector (STL/CLR)
Remove todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void clear();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro efetivamente chama [Vector:: Erase (STL/CLR)](../dotnet/vector-erase-stl-clr.md) `(` [Vector:: Begin (STL/CLR)](../dotnet/vector-begin-stl-clr.md) `(),` [Vector:: end (STL/CLR)](../dotnet/vector-end-stl-clr.md) `())`. Você pode usá-lo para garantir que a sequência controlada está vazia.  
  
### <a name="example"></a>Exemplo  
  
```  
// cliext_vector_clear.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="const_iterator"></a> Vector:: const_iterator (STL/CLR)
O tipo de um iterador de constante para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T2 const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T2` que pode servir como um constante iterador de acesso aleatório para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_const_iterator.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    cliext::vector<wchar_t>::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        System::Console::Write(" {0}", *cit);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="const_reference"></a> Vector:: const_reference (STL/CLR)
O tipo de uma referência de constante para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência constante a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_const_reference.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    cliext::vector<wchar_t>::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        {   // get a const reference to an element   
        cliext::vector<wchar_t>::const_reference cref = *cit;   
        System::Console::Write(" {0}", cref);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="const_reverse_iterator"></a> Vector:: const_reverse_iterator (STL/CLR)
O tipo de um iterador inverso constante para sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T4 const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T4` que pode servir como um constante iterador inverso para sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_const_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" reversed   
    cliext::vector<wchar_t>::const_reverse_iterator crit = c1.rbegin();   
    cliext::vector<wchar_t>::const_reverse_iterator crend = c1.rend();   
    for (; crit != crend; ++crit)   
        System::Console::Write(" {0}", *crit);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
c b a  
```  

## <a name="difference_type"></a> Vector:: difference_type (STL/CLR)
Os tipos de uma distância assinado entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef int difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elementos assinados.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_difference_type.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    cliext::vector<wchar_t>::difference_type diff = 0;   
    for (cliext::vector<wchar_t>::iterator it = c1.begin();   
        it != c1.end(); ++it) ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
  
// compute negative difference   
    diff = 0;   
    for (cliext::vector<wchar_t>::iterator it = c1.end();   
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

## <a name="empty"></a> Vector:: Empty (STL/CLR)
Testa se nenhum elemento está presente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool empty();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [Vector (STL/CLR)](../dotnet/vector-size-stl-clr.md)`() == 0`. Você pode usá-lo para testar se o vetor está vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_empty.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="end"></a> Vector:: end (STL/CLR)
Designa o fim da sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator end();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador de acesso aleatório que aponta logo após o fim da sequência controlada. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada, mas seu status pode alterar se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_end.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last two items   
    cliext::vector<wchar_t>::iterator it = c1.end();   
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

## <a name="erase"></a> Vector:: Erase (STL/CLR)
Remove os elementos em posições especificadas.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 primeiro  
 Início do intervalo a ser apagado.  
  
 last  
 Fim do intervalo a ser apagado.  
  
 onde  
 Elemento apagar.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada pelo `where`. Você pode usá-lo para remover um único elemento.  
  
 A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). Você pode usá-lo para remover a zero ou mais elementos contíguos.  
  
 Ambas as funções de membro retornam um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou [Vector:: end (STL/CLR)](../dotnet/vector-end-stl-clr.md) `()` se esse elemento não existe.  
  
 Ao apagar elementos, o número de cópias do elemento é linear no número de elementos entre o fim de apagamento e a extremidade mais próximo da sequência de. (Quando apagando um ou mais elementos em ambas as extremidades da sequência, nenhuma cópia do elemento ocorre).  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// cliext_vector_erase.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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
    cliext::vector<wchar_t>::iterator it = c1.end();   
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

## <a name="front"></a> Vector (STL/CLR)
Acessa o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference front();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma referência para o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_front.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

# <a name="front_item"></a> Vector::front_item (STL/CLR)
Acessa o primeiro elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
property value_type front_item;  
```  
  
### <a name="remarks"></a>Comentários  
 A propriedade acessa o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_front_item.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

# <a name="generic_container"></a> Vector::generic_container (STL/CLR)
O tipo da interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::  
    IVector<generic_value>  
    generic_container;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_generic_container.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::vector<wchar_t>::generic_container^ gc1 = %c1;   
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

## <a name="generic_iterator"></a> Vector::generic_iterator (STL/CLR)
O tipo de um iterador para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::Generic::  
    ContainerRandomAccessIterator<generic_value>  
    generic_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um iterador genérico que pode ser usado com a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_generic_iterator.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::vector<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    cliext::vector<wchar_t>::generic_iterator gcit = gc1->begin();   
    cliext::vector<wchar_t>::generic_value gcval = *gcit;   
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

# <a name="generic_reverse_iterator"></a> Vector::generic_reverse_iterator (STL/CLR)
O tipo de um iterador inverso para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::Generic::  
    ReverseRandomAccessIterator<generic_value> generic_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um iterador inverso genérico que pode ser usado com a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_generic_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::vector<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    cliext::vector<wchar_t>::generic_reverse_iterator gcit = gc1->rbegin();   
    cliext::vector<wchar_t>::generic_value gcval = *gcit;   
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

## <a name="generic_value"></a> Vector::generic_value (STL/CLR)
O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef GValue generic_value;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenados para uso com a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_generic_value.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    cliext::vector<wchar_t>::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    cliext::vector<wchar_t>::generic_iterator gcit = gc1->begin();   
    cliext::vector<wchar_t>::generic_value gcval = *gcit;   
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

## <a name="insert"></a> Vector:: Insert (STL/CLR)
Adiciona os elementos em uma posição especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator insert(iterator where, value_type val);  
void insert(iterator where, size_type count, value_type val);  
template<typename InIt>  
    void insert(iterator where, InIt first, InIt last);  
void insert(iterator where,  
    System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 count  
 Número de elementos a inserir.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Enumeração para inserir.  
  
 Val  
 Valor do elemento a ser inserido.  
  
 onde  
 Onde no contêiner para inserir antes.  
  
### <a name="remarks"></a>Comentários  
 Cada membro funções inserções, antes do elemento apontada pelo `where` na sequência controlada, uma sequência especificado pelo operandos restantes.  
  
 A primeira função de membro insere um elemento com o valor `val` e retorna um iterador que designa o elemento recentemente inserido. Você pode usá-lo para inserir um único elemento antes de um local designado por um iterador.  
  
 A segunda função membro insere uma repetição de elementos `count` de valor `val`. Você pode usá-lo para inserir zero ou mais elementos contíguos que são todas as cópias do mesmo valor.  
  
 Se `InIt` for um tipo inteiro, a terceira função membro se comportará da mesma forma que `insert(where, (size_type)first, (value_type)last)`. Caso contrário, ele insere a sequência [`first`, `last`). Você pode usá-lo para inserir zero ou mais elementos contíguos copiados de outra sequência.  
  
 A função de membro quarta insere a sequência designada pelo `right`. Você pode usá-lo para inserir uma sequência descrita por um enumerador.  
  
 Ao inserir um único elemento, o número de cópias do elemento é linear no número de elementos entre o ponto de inserção e a extremidade mais próximo da sequência. (Ao inserir um ou mais elementos em ambas as extremidades da sequência, nenhuma cópia do elemento ocorre). Se `InIt` é um iterador de entrada, a terceira função do membro efetivamente executa uma inserção única para cada elemento na sequência. Caso contrário, quando inserir `N` elementos, o número de cópias do elemento é linear em `N` mais o número de elementos entre o ponto de inserção e a extremidade mais próximo da sequência.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_insert.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value using iterator   
    cliext::vector<wchar_t>::iterator it = c1.begin();   
    System::Console::WriteLine("insert(begin()+1, L'x') = {0}",   
        *c1.insert(++it, L'x'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a repetition of values   
    cliext::vector<wchar_t> c2;   
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
  
## <a name="iterator"></a> Vector:: Iterator (STL/CLR)
O tipo de um iterador para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T1 iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T1` que pode servir como um iterador de acesso aleatório para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_iterator.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    cliext::vector<wchar_t>::iterator it = c1.begin();   
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

## <a name="op_as"></a> Vector:: Operator = (STL/CLR)
Substitui a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
vector<Value>% operator=(vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 O contêiner a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 As cópias de operador de membro `right` para o objeto, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada em `right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_as.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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

## <a name="op"></a> Vector::Operator(STL/CLR)
Acessa um elemento em uma posição especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference operator[](size_type pos);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 POS  
 Posição do elemento a acessar.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro retorna um referene para o elemento na posição `pos`. Você pode usá-lo para acessar um elemento cuja posição você sabe.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// cliext_vector_operator_sub.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" using subscripting   
    for (int i = 0; i < c1.size(); ++i)   
        System::Console::Write(" {0}", c1[i]);   
    System::Console::WriteLine();   
  
// change an entry and redisplay   
    c1[1] = L'x';   
    for (int i = 0; i < c1.size(); ++i)   
        System::Console::Write(" {0}", c1[i]);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
a x c  
```  

## <a name="pop_back"></a> Vector:: pop_back (STL/CLR)
Remove o último elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void pop_back();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro remove o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para encurtar o vetor por um elemento na parte traseira.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_pop_back.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="push_back"></a> Vector:: push_back (STL/CLR)
Adiciona um novo elemento de última.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void push_back(value_type val);  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro insere um elemento com o valor `val` no final da sequência controlada. Você pode usá-lo para anexar outro elemento de vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_push_back.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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
  
## <a name="rbegin"></a> Vector:: rbegin (STL/CLR)
Designa o início da sequência controlada invertida.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rbegin();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que designa o último elemento da sequência controlada ou logo após o início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` pode alterá-início da sequência controlada visto na ordem inversa, mas seu status se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_rbegin.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items in reversed sequence   
    cliext::vector<wchar_t>::reverse_iterator rit = c1.rbegin();   
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

## <a name="reference"></a> Vector:: Reference (STL/CLR)
O tipo de uma referência para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_reference.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    cliext::vector<wchar_t>::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        {   // get a reference to an element   
        cliext::vector<wchar_t>::reference ref = *it;   
        System::Console::Write(" {0}", ref);   
        }   
    System::Console::WriteLine();   
  
// modify contents " a b c"   
    for (it = c1.begin(); it != c1.end(); ++it)   
        {   // get a reference to an element   
        cliext::vector<wchar_t>::reference ref = *it;   
  
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

## <a name="rend"></a> Vector:: rend (STL/CLR)
Designa o fim da sequência controlada invertida.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rend();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que aponta logo após o início da sequência controlada. Portanto, ele designa o `end` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada visto na ordem inversa, mas seu status pode alterar se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_rend.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items   
    cliext::vector<wchar_t>::reverse_iterator rit = c1.rend();   
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

## <a name="reserve"></a> Vector:: Reserve (STL/CLR)
Garante a capacidade de crescimento mínimo para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void reserve(size_type count);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 count  
 Nova capacidade mínima do contêiner.  
  
### <a name="remarks"></a>Comentários  
 A função de membro garante que `capacity()` daqui em diante retorna pelo menos `count`. Você pode usá-lo para garantir que o contêiner não precisa realocar o armazenamento para a sequência controlada até que ele aumentou o tamanho especificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_reserve.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for (int i = 0; i < c1.size(); ++i)   
        System::Console::Write(" {0}", c1.at(i));   
    System::Console::WriteLine();   
  
// increase capacity   
    cliext::vector<wchar_t>::size_type cap = c1.capacity();   
    System::Console::WriteLine("capacity() = {0}, ok = {1}",   
        cap, c1.size() <= cap);   
    c1.reserve(cap + 5);   
    System::Console::WriteLine("capacity() = {0}, ok = {1}",   
        c1.capacity(), cap + 5 <= c1.capacity());   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
capacity() = 4, ok = True  
capacity() = 9, ok = True  
```  

## <a name="resize"></a> Vector:: Resize (STL/CLR)
Altera o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void resize(size_type new_size);  
void resize(size_type new_size, value_type val);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 new_size  
 Novo tamanho de sequência controlada.  
  
 Val  
 Valor do elemento de preenchimento.  
  
### <a name="remarks"></a>Comentários  
 As funções de membro ambos Certifique-se de que [Vector (STL/CLR)](../dotnet/vector-size-stl-clr.md) `()` daqui em diante retorna `new_size`. Se for necessário tornar a sequência controlada mais longa, a primeira função membro acrescentará elementos com valor `value_type()`, enquanto a segunda função membro acrescentará elementos com valor `val`. Para tornar a sequência controlada mais curto, ambas as funções de membro efetivamente apagar o último elemento [Vector (STL/CLR)](../dotnet/vector-size-stl-clr.md) `() -` `new_size` vezes. Você pode usá-lo para garantir que a sequência controlada tem tamanho `new_size`, cortar ou preenchimento atual sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_resize.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
// construct an empty container and pad with default values   
    cliext::vector<wchar_t> c1;   
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

## <a name="reverse_iterator"></a> Vector:: reverse_iterator (STL/CLR)
O tipo de um iterador inverso para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T3 reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T3` que pode servir como um iterador inverso para sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" reversed   
    cliext::vector<wchar_t>::reverse_iterator rit = c1.rbegin();   
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

## <a name="size"></a> Vector:: Size (STL/CLR)
Conta o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
size_type size();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada. Você pode usá-lo para determinar o número de elementos no momento na sequência controlada. Se você se preocupa se a sequência tem tamanho diferente de zero, consulte [Vector:: Empty (STL/CLR)](../dotnet/vector-empty-stl-clr.md)`()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_size.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="size_type"></a> Vector:: size_type (STL/CLR)
O tipo de uma distância com sinal entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef int size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elementos não-negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_size_type.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    cliext::vector<wchar_t>::size_type diff = c1.end() - c1.begin();   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
end()-begin() = 3  
```  
  
## <a name="swap"></a> Vector:: swap (STL/CLR)
Alterna o conteúdo de dois contêineres.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void swap(vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 Contêiner com o qual trocar conteúdos.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `*this` e `right`. Isso é feito no tempo constante e ele não lança exceções. Você pode usá-lo como uma maneira rápida de trocar o conteúdo de dois contêineres.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_swap.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct another container with repetition of values   
    cliext::vector<wchar_t> c2(5, L'x');   
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

## <a name="to_array"></a> Vector::to_array (STL/CLR)
Copia uma nova matriz sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
cli::array<Value>^ to_array();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma matriz que contém a sequência controlada. Você pode usá-lo para obter uma cópia da sequência controlada no formulário de matriz.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_to_array.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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

## <a name="value_type"></a> Vector:: value_type (STL/CLR)
O tipo de um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Value value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Value`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_value_type.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" using value_type   
    for (cliext::vector<wchar_t>::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        {   // store element in value_type object   
        cliext::vector<wchar_t>::value_type val = *it;   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  

## <a name="vector"></a> Vector:: Vector (STL/CLR)
Constrói um objeto contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
vector();  
vector(vector<Value>% right);  
vector(vector<Value>^ right);  
explicit vector(size_type count);  
vector(size_type count, value_type val);  
template<typename InIt>  
    vector(InIt first, InIt last);  
vector(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 count  
 Número de elementos a inserir.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Objeto ou intervalo a inserir.  
  
 Val  
 Valor do elemento a ser inserido.  
  
### <a name="remarks"></a>Comentários  
 O construtor:  
  
 `vector();`  
  
 inicializa a sequência controlada com nenhum elemento. Você pode usá-lo para especificar uma sequência vazia de controlado inicial.  
  
 O construtor:  
  
 `vector(vector<Value>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto vector `right`.  
  
 O construtor:  
  
 `vector(vector<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto vector cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit vector(size_type count);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `value_type()`. Você usá-lo para preencher o contêiner com elementos todos com o valor padrão.  
  
 O construtor:  
  
 `vector(size_type count, value_type val);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `val`. Você usá-lo para preencher o contêiner com elementos todos com o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `vector(InIt first, InIt last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`). Você pode usá-lo para fazer uma cópia de outra sequência de sequência controlada.  
  
 O construtor:  
  
 `vector(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador de sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_construct.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
// construct an empty container   
    cliext::vector<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::vector<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::vector<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::vector<wchar_t>::iterator it = c3.end();   
    cliext::vector<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::vector<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::vector<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::vector<wchar_t> c8(%c3);   
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

## <a name="op_neq"></a> operador! = (vector) (STL/CLR)
Vetor não igual a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Value>  
    bool operator!=(vector<Value>% left,  
        vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left == right)`. Você pode usá-lo para testar se `left` não for ordenado igual `right` quando os dois vetores são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_ne.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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

## <a name="op_lt"></a> operador&lt; (vector) (STL/CLR)
Vetor menor do que a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    bool operator<(vector<Value>% left,  
        vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 O operador função retornará true se, para a posição mais baixa `i` para o qual `!(right[i] < left[i])` é verdade que também `left[i] < right[i]`. Caso contrário, retornará `left->size() < right->size()` usá-lo para testar se `left` são ordenados antes `right` quando os dois vetores são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_lt.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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

## <a name="op_lteq"></a> operador&lt;= (vector) (STL/CLR)
Vetor menor ou igual comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    bool operator<=(vector<Value>% left,  
        vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(right < left)`. Você pode usá-lo para testar se `left` não for ordenado após `right` quando os dois vetores são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_le.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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

## <a name="op_eq"></a> operador = = (vector) (STL/CLR)
Comparação de igual de vetor.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    bool operator==(vector<Value>% left,  
        vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 A função de operador retorna true somente se as sequências controlados por `left` e `right` ter o mesmo comprimento e, para cada posição `i`, `left[i] ==` `right[i]`. Você pode usá-lo para testar se `left` é ordenado igual `right` quando os dois vetores são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_eq.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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

## <a name="op_gt"></a> operador&gt; (vector) (STL/CLR)
Vetor de maior que a comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    bool operator>(vector<Value>% left,  
        vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `right` `<` `left`. Você pode usá-lo para testar se `left` é solicitada após `right` quando os dois vetores são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_gt.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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

## <a name="op_gteq"></a> operador&gt;= (vector) (STL/CLR)
Vetor de maior que ou igual comparação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    bool operator>=(vector<Value>% left,  
        vector<Value>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Contêiner esquerdo a comparar.  
  
 direita  
 Contêiner direito a comparar.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left < right)`. Você pode usá-lo para testar se `left` não for ordenado antes `right` quando os dois vetores são comparado elemento pelo elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_vector_operator_ge.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::vector<wchar_t> c2;   
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
