---
title: Classe Platform::Collections::VectorView
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::VectorView::VectorView
- COLLECTION/Platform::Collections::VectorView::First
- COLLECTION/Platform::Collections::VectorView::GetAt
- COLLECTION/Platform::Collections::VectorView::GetMany
- COLLECTION/Platform::Collections::VectorView::IndexOf
- COLLECTION/Platform::Collections::VectorView::Size
helpviewer_keywords:
- VectorView Class
ms.assetid: 05cd461d-dce7-49d3-b0e7-2e5c78ed8192
ms.openlocfilehash: 207f5d517eaae475af1c65a284a3d1ebe50621af
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218384"
---
# <a name="platformcollectionsvectorview-class"></a>Classe Platform::Collections::VectorView

Representa uma exibição somente leitura de uma coleção sequencial de objetos que podem ser acessados separadamente por índice. O tipo de cada objeto na coleção é especificado pelo parâmetro de modelo.

## <a name="syntax"></a>Sintaxe

```
template <typename T, typename E>
   ref class VectorView sealed;
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo dos elementos contidos no objeto `VectorView` .

*Oriental*<br/>
Especifica um predicado binário para testar a igualdade com valores do tipo `T`. O valor padrão é `std::equal_to<T>`.

### <a name="remarks"></a>Comentários

A `VectorView` classe implementa a interface [Windows:: Foundation:: Collections:: \<T> IVectorView](/uwp/api/windows.foundation.collections.ivectorview-1) e o suporte para os iteradores da biblioteca de modelos padrão.

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[VectorView::VectorView](#ctor)|Inicializa uma nova instância da classe VectorView.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[VectorView:: primeiro](#first)|Retorna um iterador que especifica o primeiro elemento em VectorView.|
|[VectorView::GetAt](#getat)|Recupera o elemento de VectorView atual que é indicado pelo índice especificado.|
|[VectorView:: getmuitos](#getmany)|Recupera uma sequência de itens de VectorView atual, começando no índice especificado.|
|[VectorView:: IndexOf](#indexof)|Procura o item especificado no VectorView atual e, se encontrado, retorna o índice do item.|
|[VectorView::Size](#size)|Retorna o número de elementos no objeto VectorView atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VectorView`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="vectorviewfirst-method"></a><a name="first"></a>Método VectorView:: First

Retorna um iterador que especifica o primeiro elemento em VectorView.

### <a name="syntax"></a>Sintaxe

```

virtual Windows::Foundation::Collections::IIterator<T>^
   First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento em VectorView.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado pelo primeiro () é atribuir o valor de retorno a uma variável que é declarada com a **`auto`** palavra-chave de dedução de tipo. Por exemplo, `auto x = myVectorView->First();`.

## <a name="vectorviewgetat-method"></a><a name="getat"></a>Método VectorView:: GetAt

Recupera o elemento de VectorView atual que é indicado pelo índice especificado.

### <a name="syntax"></a>Sintaxe

```

T GetAt(
   UInt32 index
);
```

### <a name="parameters"></a>parâmetros

*index*<br/>
Um inteiro sem sinal de base zero que especifica um determinado elemento no objeto VectorView.

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo parâmetro `index`. O tipo de elemento é especificado pelo parâmetro de modelo VectorView, *T*.

## <a name="vectorviewgetmany-method"></a><a name="getmany"></a>Método VectorView:: getmany

Recupera uma sequência de itens de VectorView atual, começando no índice especificado.

### <a name="syntax"></a>Sintaxe

```

virtual unsigned int GetMany(
   unsigned int startIndex,
   ::Platform::WriteOnlyArray<T>^ dest
);
```

### <a name="parameters"></a>parâmetros

*startIndex*<br/>
O índice com base zero do início dos itens a serem recuperados.

*dest*<br/>
Quando essa operação for concluída, uma matriz de itens que começam com o elemento especificado por `startIndex` e que terminam no último elemento no VectorView.

### <a name="return-value"></a>Valor retornado

O número de itens recuperados.

## <a name="vectorviewindexof-method"></a><a name="indexof"></a>Método VectorView:: IndexOf

Procura o item especificado no VectorView atual e, se encontrado, retorna o índice do item.

### <a name="syntax"></a>Sintaxe

```

virtual bool IndexOf(
   T value,
   unsigned int* index
);
```

### <a name="parameters"></a>parâmetros

*value*<br/>
O item a ser localizado.

*index*<br/>
O índice com base zero do item se o parâmetro `value` for encontrado; caso contrário, 0.

O parâmetro de *índice* será 0 se o item for o primeiro elemento do `VectorView` ou o item não for encontrado. Se o valor de retorno for **`true`** , o item foi encontrado e será o primeiro elemento; caso contrário, o item não foi encontrado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o item especificado for encontrado; caso contrário, **`false`** .

## <a name="vectorviewsize-method"></a><a name="size"></a>Método VectorView:: Size

Retorna o número de elementos no objeto VectorView atual.

### <a name="syntax"></a>Sintaxe

```

virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no VectorView atual.

## <a name="vectorviewvectorview-constructor"></a><a name="ctor"></a>Construtor VectorView:: VectorView

Inicializa uma nova instância da classe VectorView.

### <a name="syntax"></a>Sintaxe

```
VectorView();
explicit VectorView(
   UInt32 size
);
VectorView(
   UInt32 size,
   T value
);
explicit VectorView(
   const ::std::vector<T>& v
);
explicit VectorView(
   ::std::vector<T>&& v
);
VectorView(
   const T * ptr,
   UInt32 size
);

template <
   size_t N
>
explicit VectorView(
   const T (&arr)[N]
);

template <
   size_t N
>
explicit VectorView(
   const ::std::array<T,
   N>& a
);

explicit VectorView(
   const ::Platform::Array<T>^ arr
);

template <
   typename InIt
>
VectorView(
   InItfirst,
   InItlast
);

VectorView(
   std::initializer_list<T> il
);
```

### <a name="parameters"></a>parâmetros

*Iniciar*<br/>
O tipo de uma coleção de objetos que é usada para inicializar o VectorView atual.

*Il*<br/>
Um [std:: initializer_list](../standard-library/initializer-list-class.md) cujos elementos serão usados para inicializar o VectorView.

*N*<br/>
O número de elementos em uma coleção de objetos que é usada para inicializar o VectorView atual.

*size*<br/>
O número de elementos no VectorView.

*value*<br/>
Um valor que é usado para inicializar cada elemento no VectorView atual.

*l*<br/>
Um [lvalue e um rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std:: vector](../standard-library/vector-class.md) que é usado para inicializar o VectorView atual.

*ptr*<br/>
Ponteiro para um `std::vector` que é usado para inicializar o VectorView atual.

*arr*<br/>
Um objeto [Platform:: array](../cppcx/platform-array-class.md) que é usado para inicializar o VectorView atual.

*um*<br/>
Um objeto [std:: array](../standard-library/array-class-stl.md) que é usado para inicializar o VectorView atual.

*first*<br/>
O primeiro elemento em uma sequência de objetos que é usado para inicializar o VectorView atual. O tipo de `first` é passado por meio de *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

*last*<br/>
O último elemento em uma sequência de objetos que é usado para inicializar o VectorView atual. O tipo de `last` é passado por meio de *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
