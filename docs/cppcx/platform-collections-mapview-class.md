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
ms.openlocfilehash: 1e38865f1d43edac4fc895052f1ea1b5a54a34ab
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62161700"
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
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa em MapView. Por padrão, [std:: Less\<K >](../standard-library/less-struct.md).

### <a name="remarks"></a>Comentários

MapView é uma implementação concreta de C++ do [3&gt;{4&gt;Windows::Foundation::Collections::imapview&lt;4}&lt;3} \<K, V >](/uwp/api/Windows.Foundation.Collections.IMapView_K_V_) interface que é transmitida pela interface binária de aplicativo (ABI). Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Mapview:: Mapview](#ctor)|Inicializa uma nova instância da classe MapView.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[MapView::First](#first)|Retorna um iterador que é inicializado para o primeiro elemento na exibição do mapa.|
|[MapView::HasKey](#haskey)|Determina se o MapView atual contém a chave especificada.|
|[Mapview:: Lookup](#lookup)|Recupera o elemento na chave especificada no objeto MapView atual.|
|[Mapview:: Size](#size)|Retorna o número de elementos no objeto MapView atual.|
|[MapView::Split](#split)|Divide um objeto MapView original em dois objetos MapView.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MapView`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="first"></a> Método mapview:: First

Retorna um iterador que especifica o primeiro elemento na exibição de mapa.

### <a name="syntax"></a>Sintaxe

```
virtual Windows::Foundation::Collections::IIterator<
   Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ First();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que especifica o primeiro elemento na exibição do mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado por First () é atribuir o valor de retorno a uma variável que é declarada com o **automática** palavra-chave de dedução de tipo. Por exemplo, `auto x = myMapView->First();`.

## <a name="haskey"></a>  Método mapview:: Haskey

Determina se o MapView atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```

bool HasKey(K key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave usada para localizar o elemento MapView. O tipo de *chave* é o typename *K*.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a chave for encontrada; caso contrário, **falso**.

##  <a name="lookup"></a> Método mapview:: Lookup

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```
V Lookup(K key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave usada para localizar um elemento em MapView. O tipo de `key` é o typename *K*.

### <a name="return-value"></a>Valor de retorno

O valor que é emparelhado com `key`. O tipo do valor de retorno é typename *V*.

##  <a name="ctor"></a> Construtor mapview:: Mapview

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

*InIt*<br/>
O typename de MapView atual.

*comp*<br/>
Um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa em MapView.

*m*<br/>
Uma referência ou [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um `map Class` que é usado para inicializar o MapView atual.

*first*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o MapView atual.

*last*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o MapView atual.

*il*<br/>
Um [std:: initializer_list < std:: Pair\<K, V >>](../standard-library/initializer-list-class.md) cujos elementos serão inseridos em MapView.

##  <a name="size"></a> Método mapview:: Size

Retorna o número de elementos no objeto MapView atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos no MapView atual.

##  <a name="split"></a> Método mapview:: Split

Divide o objeto MapView atual em dois objetos MapView. Este método é não operacional.

### <a name="syntax"></a>Sintaxe

```
void Split(
   Windows::Foundation::Collections::IMapView<
                         K, V>^ * firstPartition,
   Windows::Foundation::Collections::IMapView<
                         K, V>^ * secondPartition);
```

### <a name="parameters"></a>Parâmetros

*firstPartition*<br/>
A primeira parte do objeto MapView original.

*secondPartition*<br/>
A segunda parte do objeto MapView original.

### <a name="remarks"></a>Comentários

Este método não está operacional; ele não faz nada.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)
