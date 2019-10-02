---
title: Classe Platform::Collections::Vector
ms.date: 10/01/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::Vector::Vector
- COLLECTION/Platform::Collections::Vector::Append
- COLLECTION/Platform::Collections::Vector::Clear
- COLLECTION/Platform::Collections::Vector::First
- COLLECTION/Platform::Collections::Vector::GetAt
- COLLECTION/Platform::Collections::Vector::GetMany
- COLLECTION/Platform::Collections::Vector::GetView
- COLLECTION/Platform::Collections::Vector::IndexOf
- COLLECTION/Platform::Collections::Vector::InsertAt
- COLLECTION/Platform::Collections::Vector::ReplaceAll
- COLLECTION/Platform::Collections::Vector::RemoveAt
- COLLECTION/Platform::Collections::Vector::RemoveAtEnd
- COLLECTION/Platform::Collections::Vector::SetAt
- COLLECTION/Platform::Collections::Vector::Size
- COLLECTION/Platform::Collections::Vector::VectorChanged
helpviewer_keywords:
- Vector Class (C++/Cx)
ms.assetid: aee8c076-9700-47c3-99b6-799fd3edb0ca
ms.openlocfilehash: a70856be04a63cad1c700cb3cc52711dde410265
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816573"
---
# <a name="platformcollectionsvector-class"></a>Classe Platform::Collections::Vector

Representa uma coleção sequencial de objetos que podem ser acessados separadamente por índice. Implementa [Windows:: Foundation:: Collections:: IObservableVector](/uwp/api/Windows.Foundation.Collections.IObservableVector_T_) para ajudar com a [vinculação de dados](/windows/uwp/data-binding/data-binding-in-depth)XAML.

## <a name="syntax"></a>Sintaxe

```
template <typename T, typename E>
   ref class Vector sealed;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo dos elementos contidos no objeto Vector.

*E*<br/>
Especifica um predicado binário para testar a igualdade com valores do tipo *T*. O valor padrão é `std::equal_to<T>`.

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

1. números inteiros

1. classe de interface ^

1. classe ref pública^

1. estrutura de valor

1. classe de enum pública

A classe **vector** é a C++ implementação concreta da interface [Windows:: Foundation:: Collections:: IVector](/uwp/api/Windows.Foundation.Collections.IVector_T_) .

Se você tentar usar um tipo de **vetor** em um valor de retorno público ou parâmetro, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do parâmetro ou do valor de retorno para [Windows::Foundation::Collections::IVector](/uwp/api/Windows.Foundation.Collections.IVector_T_). Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Vector::Vector](#ctor)|Inicializa uma nova instância da classe Vector.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Vetor:: Append](#append)|Insere o item especificado após o último item no Vector atual.|
|[Vetor:: Clear](#clear)|Exclui todos os elementos no Vector atual.|
|[Vector::First](#first)|Retorna um iterador que especifica o primeiro elemento em Vector.|
|[Vector::GetAt](#getat)|Recupera o elemento de Vector atual que é identificado pelo índice especificado.|
|[Vector::GetMany](#getmany)|Recupera uma sequência de itens de Vector atual, começando no índice especificado.|
|[Vector::GetView](#getview)|Retorna uma exibição somente leitura de um Vector; isto é, um [Platform::Collections::VectorView](../cppcx/platform-collections-vectorview-class.md).|
|[Vector::IndexOf](#indexof)|Procura o item especificado no vetor atual, e se encontrado, retorna o índice do item.|
|[Vector::InsertAt](#insertat)|Insere o item especificado no Vector atual após o elemento identificado pelo índice especificado.|
|[Vector::ReplaceAll](#replaceall)|Exclui os elementos no Vector atual e insere os elementos da matriz especificada.|
|[Vector::RemoveAt](#removeat)|Exclui o elemento identificado pelo índice especificado do Vector atual.|
|[Vector::RemoveAtEnd](#removeatend)|Exclui o elemento no final do Vector atual.|
|[Vector::SetAt](#setat)|Atribui o valor especificado ao elemento no Vector atual que é identificado pelo índice especificado.|
|[Vetor:: Size](#size)|Retorna o número de elementos no objeto Vector atual.|

### <a name="events"></a>Events

|||
|-|-|
|Nome|Descrição|
|evento [Windows:: Foundation:: Collection:: VectorChangedEventHandler @ no__t-1T > ^ vectorchanged](/uwp/api/windows.foundation.collections.vectorchangedeventhandler)|Ocorre quando o Vector é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Vector`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="append"></a>Método Vector:: Append

Insere o item especificado após o último item no Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Append(T item);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
O item a ser inserido no Vector. O tipo de *Item* é definido pelo TypeName de *T* .

## <a name="clear"></a>Método Vector:: Clear

Exclui todos os elementos no Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="first"></a>Método Vector:: First

Retorna um iterador que aponta para o primeiro elemento em Vector.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator <T>^ First();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que aponta para o primeiro elemento em Vector.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado pelo primeiro () é atribuir o valor de retorno a uma variável declarada com a palavra-chave de dedução de tipo **automático** . Por exemplo: `auto x = myVector->First();`. Este iterador conhece a duração da coleta.

Quando você precisar de um par de iteradores para passar para uma função STL, use as funções gratuitas [Windows:: Foundation:: coleções:: Begin](../cppcx/begin-function.md) e [Windows:: Foundation:: Collections:: End](../cppcx/end-function.md)

## <a name="getat"></a>Método Vector:: GetAt

Recupera o elemento de Vector atual que é identificado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual T GetAt(unsigned int index);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

### <a name="return-value"></a>Valor de retorno

O elemento especificado pelo parâmetro de *índice* . O tipo de elemento é definido pelo TypeName de *T* .

## <a name="getmany"></a>Método Vector:: getmany

Recupera uma sequência de itens de Vector atual, começando a partir do índice especificado e os copia na matriz alocada pelo chamador.

### <a name="syntax"></a>Sintaxe

```cpp
virtual unsigned int GetMany(
    unsigned int startIndex,
    Platform::WriteOnlyArray<T>^ dest);
```

### <a name="parameters"></a>Parâmetros

*startIndex*<br/>
O índice com base zero do início dos itens a serem recuperados.

*dest*<br/>
Uma matriz de itens alocada pelo chamador que começa no elemento especificado por *startIndex* e termina no último elemento no vetor.

### <a name="return-value"></a>Valor de retorno

O número de itens recuperados.

### <a name="remarks"></a>Comentários

Esta função não se destina a ser usada diretamente pelo código do cliente. Ele é usado internamente na [função to_vector](../cppcx/to-vector-function.md) para habilitar a conversão eficiente de Platform:: vector instâncias para instâncias std:: vector.

## <a name="getview"></a>Método Vector:: GetView

Retorna uma exibição somente leitura de um Vector; isto é, um IVectorView.

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IVectorView<T>^ GetView();
```

### <a name="return-value"></a>Valor de retorno

Um objeto IVectorView.

## <a name="indexof"></a>Método Vector:: IndexOf

Procura o item especificado no vetor atual, e se encontrado, retorna o índice do item.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool IndexOf(T value, unsigned int* index);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
O item a ser localizado.

*index*<br/>
O índice de base zero do item se o *valor* do parâmetro for encontrado; caso contrário, 0.

O parâmetro de *índice* será 0 se o item for o primeiro elemento do vetor ou o item não for encontrado. Se o valor de retorno for **true**, o item foi encontrado e será o primeiro elemento; caso contrário, o item não foi encontrado.

### <a name="return-value"></a>Valor de retorno

**true** se o item especificado for encontrado; caso contrário, **false**.

### <a name="remarks"></a>Comentários

O IndexOf usa o std::find_if para encontrar o item. Tipos de elementos personalizados deverão, portanto, sobrecarregar os operadores == e != para habilitar as comparações de igualdade exigidas por find_if.

##  <a name="insertat"></a>Método Vector:: InsertAt

Insere o item especificado no Vector atual após o elemento identificado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void InsertAt(unsigned int index, T item)
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

*item*<br/>
Um item a ser inserido no vetor após o elemento especificado pelo *índice*. O tipo de *Item* é definido pelo TypeName de *T* .

## <a name="removeat"></a>Método Vector:: RemoveAt

Exclui o elemento identificado pelo índice especificado do Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void RemoveAt(unsigned int index);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

## <a name="removeatend"></a>Método Vector:: RemoveAtEnd

Exclui o elemento no final do Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void RemoveAtEnd();
```

## <a name="replaceall"></a>Método Vector:: ReplaceAll

Exclui os elementos no Vector atual e insere os elementos da matriz especificada.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void ReplaceAll(const ::Platform::Array<T>^ arr);
```

### <a name="parameters"></a>Parâmetros

*arr*<br/>
Uma matriz de objetos cujo tipo é definido pelo TypeName de *T* .

## <a name="setat"></a>Método Vector:: SetAt

Atribui o valor especificado ao elemento no Vector atual que é identificado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void SetAt(unsigned int index, T item);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

*item*<br/>
O valor a ser atribuído ao elemento especificado. O tipo de *Item* é definido pelo TypeName de *T* .

## <a name="size"></a>Método Vector:: Size

Retorna o número de elementos no objeto Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos no Vector atual.

## <a name="ctor"></a>Construtor vector:: vector

Inicializa uma nova instância da classe Vector.

### <a name="syntax"></a>Sintaxe

```cpp
Vector();

explicit Vector(unsigned int size);
Vector( unsigned int size, T value);
template <typename U> explicit Vector( const ::std::vector<U>& v);
template <typename U> explicit Vector( std::vector<U>&& v);

Vector( const T * ptr, unsigned int size);
template <size_t N> explicit Vector(const T(&arr)[N]);
template <size_t N> explicit Vector(const std::array<T, N>& a);
explicit Vector(const Array<T>^ arr);

template <typename InIt> Vector(InIt first, InIt last);
Vector(std::initializer_list<T> il);
```

### <a name="parameters"></a>Parâmetros

*a*<br/>
Um [std:: array](../standard-library/array-class-stl.md) que será usado para inicializar o vetor.

*arr*<br/>
Uma [plataforma:: matriz](../cppcx/platform-array-class.md) que será usada para inicializar o vetor.

*InIt*<br/>
O tipo de uma coleção de objetos que é usada para inicializar o Vector atual.

*il*<br/>
Um [std:: initializer_list](../standard-library/initializer-list-class.md) de objetos do tipo *T* que será usado para inicializar o vetor.

*N*<br/>
O número de elementos em uma coleção de objetos que é usada para inicializar o Vector atual.

*size*<br/>
O número de elementos no Vector.

*value*<br/>
Um valor que é usado para inicializar cada elemento no Vector atual.

*v*<br/>
Um [lvalue e um rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std:: vector](../standard-library/vector-class.md) que é usado para inicializar o vetor atual.

*ptr*<br/>
Ponteiro para um `std::vector` que é usado para inicializar o Vector atual.

*first*<br/>
O primeiro elemento em uma sequência de objetos que é usado para inicializar o Vector atual. O tipo de *primeiro* é passado por meio de *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

*last*<br/>
O último elemento em uma sequência de objetos que é usado para inicializar o Vector atual. O tipo de *último* é passado por meio de *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="see-also"></a>Consulte também

[Coleções (C++/CX)](collections-c-cx.md)<br/>
[Namespace da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes de Windows Runtime noC++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
