---
title: Classe Platform::Collections::UnorderedMapView
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- collection/Platform::Collections::UnorderedMapView
ms.assetid: 545a3725-2efd-4cc1-b590-4a7cd2351f61
ms.openlocfilehash: acfc168959deb83244c98c5d361cf9e73c1388f2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213054"
---
# <a name="platformcollectionsunorderedmapview-class"></a>Classe Platform::Collections::UnorderedMapView

Representa uma exibição somente leitura em um *mapa*, que é uma coleção de pares chave-valor.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename K,
   typename V,
   typename C = ::std::equal_to<K>>
ref class UnorderedMapView sealed;
```

#### <a name="parameters"></a>parâmetros

*C*<br/>
O tipo de chave em pares chave-valor.

*L*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar a igualdade de dois valores de chave. Por padrão, [std:: equal_to \<K> ](../standard-library/equal-to-struct.md)

### <a name="remarks"></a>Comentários

UnorderedMapView é uma implementação concreta de C++ da interface [Windows:: Foundation:: Collections:: \<K,V> IMapView](/uwp/api/windows.foundation.collections.imapview-2) que é passada pela Abi (interface binária de aplicativo). Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[UnorderedMapView::UnorderedMapView](#ctor)|Inicializa uma nova instância da classe UnorderedMapView.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[UnorderedMapView:: primeiro](#first)|Retorna um iterador que é inicializado para o primeiro elemento na exibição do mapa.|
|[UnorderedMapView::HasKey](#haskey)|Determina se o UnorderedMapView atual contém a chave especificada.|
|[UnorderedMapView:: Lookup](#lookup)|Recupera o elemento na chave especificada no objeto UnorderedMapView atual.|
|[UnorderedMapView:: tamanho](#size)|Retorna o número de elementos no objeto UnorderedMapView atual.|
|[UnorderedMapView:: Split](#split)|Divide um objeto UnorderedMapView original em dois objetos UnorderedMapView.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`UnorderedMapView`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="unorderedmapviewfirst-method"></a><a name="first"></a>Método UnorderedMapView:: First

Retorna um iterador que especifica o primeiro elemento [Windows:: Foundation:: Collections: \<K,V> : IKeyValuePair](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no mapa não ordenado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
    Windows::Foundation::Collections::IKeyValuePair<K, V>^>^
    First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento na exibição do mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado pelo primeiro () é atribuir o valor de retorno a uma variável que é declarada com a **`auto`** palavra-chave de dedução de tipo. Por exemplo, `auto x = myMapView->First();`.

## <a name="unorderedmapviewhaskey-method"></a><a name="haskey"></a>Método UnorderedMapView:: HasKey

Determina se o UnorderedMap atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(K key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave usada para localizar o elemento. O tipo de `key` é TypeName *K*.

### <a name="return-value"></a>Valor retornado

**`true`** se a chave for encontrada; caso contrário, **`false`** .

## <a name="unorderedmapviewlookup-method"></a><a name="lookup"></a>Método UnorderedMapView:: Lookup

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(K key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave usada para localizar um elemento em UnorderedMapView. O tipo de `key` é TypeName *K*.

### <a name="return-value"></a>Valor retornado

O valor que é emparelhado com `key`. O tipo do valor de retorno é TypeName *V*.

## <a name="unorderedmapviewsize-method"></a><a name="size"></a>Método UnorderedMapView:: Size

Retorna o número de elementos [Windows:: Foundation:: Collections:: \<K,V> IKeyValuePair](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no UnorderedMapView.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no MapView não ordenado.

## <a name="unorderedmapviewsplit-method"></a><a name="split"></a>Método UnorderedMapView:: Split

Divide o objeto UnorderedMapView atual em dois objetos UnorderedMapView. Este método é não operacional.

### <a name="syntax"></a>Sintaxe

```cpp
void Split(
   Windows::Foundation::Collections::IMapView<
                         K,V>^ * firstPartition,
   Windows::Foundation::Collections::IMapView<
                         K,V>^ * secondPartition);
```

### <a name="parameters"></a>parâmetros

*firstPartition*<br/>
A primeira parte do objeto UnorderedMapView original.

*secondPartition*<br/>
A segunda parte do objeto UnorderedMapView original.

### <a name="remarks"></a>Comentários

Este método não está operacional; ele não faz nada.

## <a name="unorderedmapviewunorderedmapview-constructor"></a><a name="ctor"></a>Construtor UnorderedMapView:: UnorderedMapView

Inicializa uma nova instância da classe UnorderedMapView.

### <a name="syntax"></a>Sintaxe

```cpp
UnorderedMapView();
explicit UnorderedMapView(size_t n);
UnorderedMapView(size_t n, const H& h);
UnorderedMapView(size_t n, const H& h, const P& p);

explicit UnorderedMapView(
    const std::unordered_map<K, V, H, P>& m);
explicit UnorderedMapView(
    std::unordered_map<K, V, H, P>&& m);

template <typename InIt> UnorderedMapView(InIt first, InIt last );
template <typename InIt> UnorderedMapView(InIt first, InIt last, size_t n );

template <typename InIt> UnorderedMapView(
    InIt first,
    InIt last,
    size_t n,
    const H& h );

template <typename InIt> UnorderedMapView(
    InIt first,
    InIt last,
    size_t n,
    const H& h,
    const P& p );

UnorderedMapView(std::initializer_list<std::pair<const K, V>);

UnorderedMapView(std::initializer_list< std::pair<const K, V>> il, size_t n

UnorderedMapView(
    std::initializer_list< std::pair<const K, V>> il,
    size_t n,
    const H& h);

UnorderedMapView(
    std::initializer_list< std::pair<const K, V>> il,
    size_t n,
    const H& h,
    const P& p );
```

### <a name="parameters"></a>parâmetros

*n*<br/>
O número de elementos para os quais pré-alocar espaço.

*Iniciar*<br/>
O typename de UnorderedMapView.

*T*<br/>
Um objeto de função que gera um valor de hash para uma chave. O padrão é o [std:: \<K> hash](../standard-library/hash-class.md) para os tipos `std::hash` aos quais o oferece suporte.

*P*<br/>
Um tipo que fornece um objeto de função que pode comparar duas chaves para determinar sua igualdade. O padrão é o [std:: \<K> equal_to](../standard-library/equal-to-struct.md).

*d*<br/>
Uma referência ou [lvalues e rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std:: unordered_map](../standard-library/unordered-map-class.md) que é usado para inicializar o UnorderedMapView.

*first*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar UnorderedMapView.

*last*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar UnorderedMapView.

## <a name="see-also"></a>Confira também

[Namespace da plataforma:: Collections](../cppcx/platform-collections-namespace.md)<br/>
[Windows::Foundation::IMapView](/uwp/api/windows.foundation.collections.imapview-2)
