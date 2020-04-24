---
title: Classe Platform::Collections::MapView
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::MapView::MapView
- COLLECTION/Platform::Collections::MapView::First
- COLLECTION/Platform::Collections::MapView::HasKey
- COLLECTION/Platform::Collections::MapView::Lookup
- COLLECTION/Platform::Collections::MapView::Size
- COLLECTION/Platform::Collections::MapView::Split
helpviewer_keywords:
- MapView Class
ms.assetid: 9577dde7-f599-43c6-b1e4-7d653706fd62
ms.openlocfilehash: 98c146cec2febefee9c16528bee8f6be83f2a026
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032428"
---
# <a name="platformcollectionsmapview-class"></a>Classe Platform::Collections::MapView

Representa uma exibição somente leitura em um *mapa*, que é uma coleção de pares chave-valor.

## <a name="syntax"></a>Sintaxe

```
template <
   typename K,
   typename V,
   typename C = ::std::less<K>>
ref class MapView sealed;
```

#### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de chave em pares chave-valor.

*V*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa em MapView. Por padrão, [\<std::menos>K ](../standard-library/less-struct.md).

### <a name="remarks"></a>Comentários

MapView é uma implementação c++ concreta do [Windows::Foundation::Collections::IMapView \<K,V>](/uwp/api/windows.foundation.collections.imapview-2) interface que é passada através da interface binária do aplicativo (ABI). Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[MapView::MapView](#ctor)|Inicializa uma nova instância da classe MapView.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[MapView::Primeiro](#first)|Retorna um iterador que é inicializado para o primeiro elemento na exibição do mapa.|
|[mapview::Haskey](#haskey)|Determina se o MapView atual contém a chave especificada.|
|[MapView::Lookup](#lookup)|Recupera o elemento na chave especificada no objeto MapView atual.|
|[MapView::Size](#size)|Retorna o número de elementos no objeto MapView atual.|
|[MapView::Split](#split)|Divide um objeto MapView original em dois objetos MapView.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MapView`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="mapviewfirst-method"></a><a name="first"></a>MapView::Primeiro método

Retorna um iterador que especifica o primeiro elemento na exibição de mapa.

### <a name="syntax"></a>Sintaxe

```
virtual Windows::Foundation::Collections::IIterator<
   Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento na exibição do mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de segurar o iterator devolvido pelo First() é atribuir o valor de retorno a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.** Por exemplo, `auto x = myMapView->First();`.

## <a name="mapviewhaskey-method"></a><a name="haskey"></a>MapView::HasKey Method

Determina se o MapView atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```

bool HasKey(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar o elemento MapView. O tipo de *chave* é o nome de digite *K*.

### <a name="return-value"></a>Valor retornado

**verdade** se a chave for encontrada; caso contrário, **falso**.

## <a name="mapviewlookup-method"></a><a name="lookup"></a>MapView::Método de revisão

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```
V Lookup(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar um elemento em MapView. O tipo `key` de é o nome tipo *K*.

### <a name="return-value"></a>Valor retornado

O valor que é emparelhado com `key`. O tipo de valor de retorno é o nome de digite *V*.

## <a name="mapviewmapview-constructor"></a><a name="ctor"></a>MapView::MapView Constructor

Inicializa uma nova instância da classe MapView.

### <a name="syntax"></a>Sintaxe

```cpp
explicit MapView(const C& comp = C());

explicit MapView(const ::std::map<K, V, C>& m);

explicit MapView(std::map<K, V, C>&& m);

template <typename InIt> MapView(
    InIt first,
    InIt last,
    const C& comp = C());

MapView(
    ::std::initializer_list<std::pair<const K, V>> il,
    const C& comp = C());
```

### <a name="parameters"></a>Parâmetros

*Init*<br/>
O typename de MapView atual.

*Comp*<br/>
Um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa em MapView.

*M*<br/>
Uma referência ou [Valores e Valores](../cpp/lvalues-and-rvalues-visual-cpp.md) para um `map Class` que é usado para inicializar o MapView atual.

*Primeiro*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o MapView atual.

*Última*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o MapView atual.

*Il*<br/>
Um [std::initializer_list<std::pair\<K,V>>](../standard-library/initializer-list-class.md) cujos elementos serão inseridos no MapView.

## <a name="mapviewsize-method"></a><a name="size"></a>MapView::Método de tamanho

Retorna o número de elementos no objeto MapView atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no MapView atual.

## <a name="mapviewsplit-method"></a><a name="split"></a>MapView::Método de divisão

Divide o objeto MapView atual em dois objetos MapView. Este método é não operacional.

### <a name="syntax"></a>Sintaxe

```cpp
void Split(
   Windows::Foundation::Collections::IMapView<
                         K, V>^ * firstPartition,
   Windows::Foundation::Collections::IMapView<
                         K, V>^ * secondPartition);
```

### <a name="parameters"></a>Parâmetros

*primeirapartição*<br/>
A primeira parte do objeto MapView original.

*segundapartição*<br/>
A segunda parte do objeto MapView original.

### <a name="remarks"></a>Comentários

Este método não está operacional; ele não faz nada.

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)
