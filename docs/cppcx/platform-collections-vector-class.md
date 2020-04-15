---
title: Classe Platform::Collections::Vector
ms.date: 12/04/2019
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
ms.openlocfilehash: b2d08461b4ab57ed8479549c18c35c872d0eb9f1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354381"
---
# <a name="platformcollectionsvector-class"></a>Classe Platform::Collections::Vector

Representa uma coleção sequencial de objetos que podem ser acessados separadamente por índice. Implementa [o Windows::Foundation::Collections:IObservávelpara](/uwp/api/Windows.Foundation.Collections.IObservableVector_T_) ajudar com a [vinculação de dados](/windows/uwp/data-binding/data-binding-in-depth)XAML .

## <a name="syntax"></a>Sintaxe

```
template <typename T, typename E>
   ref class Vector sealed;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo dos elementos contidos no objeto Vector.

*E*<br/>
Especifica um predicado binário para testar a igualdade com valores do tipo *T*. O valor `std::equal_to<T>`padrão é .

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

1. números inteiros

1. classe de interface^

1. classe ref pública^

1. estrutura de valor

1. classe de enum pública

A classe **Vector** é a implementação de concreto C++ do [Windows::Foundation::Collections:IVector](/uwp/api/Windows.Foundation.Collections.IVector_T_) interface.

Se você tentar usar um tipo **vetorial** em um valor de retorno público ou parâmetro, o erro do compilador C3986 será aumentado. Você pode corrigir o erro alterando o tipo do parâmetro ou do valor de retorno para [Windows::Foundation::Collections::IVector](/uwp/api/Windows.Foundation.Collections.IVector_T_). Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Vetor::Vetor](#ctor)|Inicializa uma nova instância da classe Vector.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Vector::Append](#append)|Insere o item especificado após o último item no Vector atual.|
|[Vetor::Limpar](#clear)|Exclui todos os elementos no Vector atual.|
|[Vetor::Primeiro](#first)|Retorna um iterador que especifica o primeiro elemento em Vector.|
|[Vetor::Getat](#getat)|Recupera o elemento de Vector atual que é identificado pelo índice especificado.|
|[Vetor::GetMany](#getmany)|Recupera uma sequência de itens de Vector atual, começando no índice especificado.|
|[Vetor::GetView](#getview)|Retorna uma exibição somente leitura de um Vector; isto é, um [Platform::Collections::VectorView](../cppcx/platform-collections-vectorview-class.md).|
|[Vetor::Indexof](#indexof)|Procura o item especificado no vetor atual, e se encontrado, retorna o índice do item.|
|[Vector::InsertAt](#insertat)|Insere o item especificado no Vetor atual no elemento identificado pelo índice especificado.|
|[Vector::ReplaceAll](#replaceall)|Exclui os elementos no Vector atual e insere os elementos da matriz especificada.|
|[Vector::RemoveAt](#removeat)|Exclui o elemento identificado pelo índice especificado do Vector atual.|
|[Vector::RemoveAtEnd](#removeatend)|Exclui o elemento no final do Vector atual.|
|[Vector::SetAt](#setat)|Atribui o valor especificado ao elemento no Vector atual que é identificado pelo índice especificado.|
|[Vetor::Tamanho](#size)|Retorna o número de elementos no objeto Vector atual.|

### <a name="events"></a>Eventos

|||
|-|-|
|Nome|Descrição|
|[evento Windows::Foundation::Collection:VectorChangedEventHandler\<T>^ VectorChanged](/uwp/api/windows.foundation.collections.vectorchangedeventhandler)|Ocorre quando o Vector é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Vector`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="vectorappend-method"></a><a name="append"></a>Vetor::Método de apêndice

Insere o item especificado após o último item no Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Append(T item);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
O item a ser inserido no Vector. O tipo de *item* é definido pelo nome do tipo *T.*

## <a name="vectorclear-method"></a><a name="clear"></a>Vetor::Método claro

Exclui todos os elementos no Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="vectorfirst-method"></a><a name="first"></a>Vetor::Primeiro método

Retorna um iterador que aponta para o primeiro elemento em Vector.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator <T>^ First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o primeiro elemento em Vector.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de segurar o iterator devolvido pelo First() é atribuir o valor de retorno a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.** Por exemplo, `auto x = myVector->First();`. Este iterador conhece a duração da coleta.

Quando você precisar de um par de iterizadores para passar para uma função STL, use as funções gratuitas [Windows::Foundation::Collections::begin](../cppcx/begin-function.md) e [Windows:Foundation::Collections::end](../cppcx/end-function.md)

## <a name="vectorgetat-method"></a><a name="getat"></a>Vector::GetAt Method

Recupera o elemento de Vector atual que é identificado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual T GetAt(unsigned int index);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo parâmetro de *índice.* O tipo de elemento é definido pelo nome do tipo *T.*

## <a name="vectorgetmany-method"></a><a name="getmany"></a>Vetor::ObtermétodoMany

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
Uma matriz de itens alocados pelo chamador que começam no elemento especificado pelo *startIndex* e terminam no último elemento no Vetor.

### <a name="return-value"></a>Valor retornado

O número de itens recuperados.

### <a name="remarks"></a>Comentários

Esta função não se destina a ser usada diretamente pelo código do cliente. Ele é usado internamente na [função to_vector](../cppcx/to-vector-function.md) para permitir a conversão eficiente de plataforma::intâncias vetoriais para instâncias de std::vetor.

## <a name="vectorgetview-method"></a><a name="getview"></a>Vector::Método GetView

Retorna uma exibição somente leitura de um Vector; isto é, um IVectorView.

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IVectorView<T>^ GetView();
```

### <a name="return-value"></a>Valor retornado

Um objeto IVectorView.

## <a name="vectorindexof-method"></a><a name="indexof"></a>Vetor::IndexOf Method

Procura o item especificado no vetor atual, e se encontrado, retorna o índice do item.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool IndexOf(T value, unsigned int* index);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
O item a ser localizado.

*Índice*<br/>
O índice baseado em zero do item se for encontrado o *valor* do parâmetro; caso contrário, 0.

O parâmetro *de índice* é 0 se o item for o primeiro elemento do Vetor ou o item não foi encontrado. Se o valor de devolução for **verdadeiro,** o item foi encontrado e é o primeiro elemento; caso contrário, o item não foi encontrado.

### <a name="return-value"></a>Valor retornado

**verdade** se o item especificado for encontrado; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

O IndexOf usa o std::find_if para encontrar o item. Tipos de elementos personalizados deverão, portanto, sobrecarregar os operadores == e != para habilitar as comparações de igualdade exigidas por find_if.

## <a name="vectorinsertat-method"></a><a name="insertat"></a>Vetor::InsertAt Método

Insere o item especificado no Vetor atual no elemento identificado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void InsertAt(unsigned int index, T item)
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

*item*<br/>
Um item para inserir no Vetor no elemento especificado pelo *índice*. O tipo de *item* é definido pelo nome do tipo *T.*

## <a name="vectorremoveat-method"></a><a name="removeat"></a>Vetor::Removeat Método

Exclui o elemento identificado pelo índice especificado do Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void RemoveAt(unsigned int index);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

## <a name="vectorremoveatend-method"></a><a name="removeatend"></a>Vetor::Removeatend Method

Exclui o elemento no final do Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void RemoveAtEnd();
```

## <a name="vectorreplaceall-method"></a><a name="replaceall"></a>Vetor::Substituirtodos os métodos

Exclui os elementos no Vector atual e insere os elementos da matriz especificada.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void ReplaceAll(const ::Platform::Array<T>^ arr);
```

### <a name="parameters"></a>Parâmetros

*Arr*<br/>
Uma matriz de objetos cujo tipo é definido pelo nome do tipo *T.*

## <a name="vectorsetat-method"></a><a name="setat"></a>Vetor::Método setat

Atribui o valor especificado ao elemento no Vector atual que é identificado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void SetAt(unsigned int index, T item);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um inteiro não assinado com base zero que especifica um determinado elemento no objeto Vector.

*item*<br/>
O valor a ser atribuído ao elemento especificado. O tipo de *item* é definido pelo nome do tipo *T.*

## <a name="vectorsize-method"></a><a name="size"></a>Vetor::Método de tamanho

Retorna o número de elementos no objeto Vector atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no Vector atual.

## <a name="vectorvector-constructor"></a><a name="ctor"></a>Vetor::Construtor vetorial

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

*Um*<br/>
Um [conjunto std::que](../standard-library/array-class-stl.md) será usado para inicializar o Vetor.

*Arr*<br/>
Uma [plataforma::Array](../cppcx/platform-array-class.md) que será usado para inicializar o Vetor.

*Init*<br/>
O tipo de uma coleção de objetos que é usada para inicializar o Vector atual.

*Il*<br/>
Um [std::initializer_list](../standard-library/initializer-list-class.md) de objetos do tipo *T* que serão usados para inicializar o Vetor.

*N*<br/>
O número de elementos em uma coleção de objetos que é usada para inicializar o Vector atual.

*Tamanho*<br/>
O número de elementos no Vector.

*value*<br/>
Um valor que é usado para inicializar cada elemento no Vector atual.

*V*<br/>
Um [Valores de Valor escoado e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std::vetor](../standard-library/vector-class.md) que é usado para inicializar o Vetor atual.

*Ptr*<br/>
Ponteiro para um `std::vector` que é usado para inicializar o Vector atual.

*Primeiro*<br/>
O primeiro elemento em uma sequência de objetos que é usado para inicializar o Vector atual. O tipo de *primeiro* é passado por meio de *um encaminhamento perfeito.* Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

*Última*<br/>
O último elemento em uma sequência de objetos que é usado para inicializar o Vector atual. O tipo de *último* é passado por meio de *um encaminhamento perfeito.* Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="see-also"></a>Confira também

[Coleções (C++/CX)](collections-c-cx.md)<br/>
[Espaço de nome da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
