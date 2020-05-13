---
title: Classe Platform::Collections::UnorderedMapView
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- collection/Platform::Collections::UnorderedMapView
ms.assetid: 545a3725-2efd-4cc1-b590-4a7cd2351f61
ms.openlocfilehash: f0096982ad5d11b9ea394c9f02ba748a52e4216b
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82031479"
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

#### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de chave em pares chave-valor.

*V*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar a igualdade de dois valores de chave. Por padrão, [\<std::equal_to K>](../standard-library/equal-to-struct.md)

### <a name="remarks"></a>Comentários

UnorderedMapView é uma implementação C++ concreta do [Windows::Foundation::Collections:IMapView\<K,V>](/uwp/api/windows.foundation.collections.imapview-2) interface que é passada através da interface binária do aplicativo (ABI). Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Desordenado'''''''''''''''''''''''''''''''''''](#ctor)|Inicializa uma nova instância da classe UnorderedMapView.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Desordenado'MapView::Primeiro](#first)|Retorna um iterador que é inicializado para o primeiro elemento na exibição do mapa.|
|[Desordenado'' ''''''''''''''''''''''''](#haskey)|Determina se o UnorderedMapView atual contém a chave especificada.|
|[Desordenado'MapView::Lookup](#lookup)|Recupera o elemento na chave especificada no objeto UnorderedMapView atual.|
|[Desordenado'MapView::Tamanho](#size)|Retorna o número de elementos no objeto UnorderedMapView atual.|
|[Desordenado'MapEie::Split](#split)|Divide um objeto UnorderedMapView original em dois objetos UnorderedMapView.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`UnorderedMapView`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="unorderedmapviewfirst-method"></a><a name="first"></a>Desordenado'MapEieI::Primeiro método

Retorna um iterator que especifica o primeiro [elemento Windows::Foundation::Collections::IKeyValuePair\<K,V>](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no mapa desordenado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
    Windows::Foundation::Collections::IKeyValuePair<K, V>^>^
    First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento na exibição do mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de segurar o iterator devolvido pelo First() é atribuir o valor de retorno a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.** Por exemplo, `auto x = myMapView->First();`.

## <a name="unorderedmapviewhaskey-method"></a><a name="haskey"></a>Desordenado'MapEie::HasKey Method

Determina se o UnorderedMap atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar o elemento. O tipo `key` de é o nome tipo *K*.

### <a name="return-value"></a>Valor retornado

**verdade** se a chave for encontrada; caso contrário, **falso**.

## <a name="unorderedmapviewlookup-method"></a><a name="lookup"></a>Desordenado'MapView::Método de procurar

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar um elemento em UnorderedMapView. O tipo `key` de é o nome tipo *K*.

### <a name="return-value"></a>Valor retornado

O valor que é emparelhado com `key`. O tipo de valor de retorno é o nome de digite *V*.

## <a name="unorderedmapviewsize-method"></a><a name="size"></a>Desordenado''''''''''''''''''''''''''

Retorna o número do [Windows::Foundation::Coleções::IKeyValuePair\<K,V>](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) elementos no UnorderedMapView.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no MapView não ordenado.

## <a name="unorderedmapviewsplit-method"></a><a name="split"></a>Desordenado''''''''''''''''''''''''''

Divide o objeto UnorderedMapView atual em dois objetos UnorderedMapView. Este método é não operacional.

### <a name="syntax"></a>Sintaxe

```cpp
void Split(
   Windows::Foundation::Collections::IMapView<
                         K,V>^ * firstPartition,
   Windows::Foundation::Collections::IMapView<
                         K,V>^ * secondPartition);
```

### <a name="parameters"></a>Parâmetros

*primeirapartição*<br/>
A primeira parte do objeto UnorderedMapView original.

*segundapartição*<br/>
A segunda parte do objeto UnorderedMapView original.

### <a name="remarks"></a>Comentários

Este método não está operacional; ele não faz nada.

## <a name="unorderedmapviewunorderedmapview-constructor"></a><a name="ctor"></a>Desordenado'MapEie:Desordenado', 'Desordenado'', 'Desordenado', 'Desordenado', 'Desordenado', '''''

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

### <a name="parameters"></a>Parâmetros

*n*<br/>
O número de elementos para os quais pré-alocar espaço.

*Init*<br/>
O typename de UnorderedMapView.

*H*<br/>
Um objeto de função que gera um valor de hash para uma chave. Os padrões de [std::hash\<K>](../standard-library/hash-class.md) para os tipos que `std::hash` suportam.

*P*<br/>
Um tipo que fornece um objeto de função que pode comparar duas chaves para determinar sua igualdade. Padrão para [\<std::equal_to K>](../standard-library/equal-to-struct.md).

*M*<br/>
Uma referência ou [Valores e Valores](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std::unordered_map](../standard-library/unordered-map-class.md) que é usado para inicializar o UnorderedMapView.

*Primeiro*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar UnorderedMapView.

*Última*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar UnorderedMapView.

## <a name="see-also"></a>Confira também

[Namespace Platform::Collections](../cppcx/platform-collections-namespace.md)<br/>
[Windows::Foundation::IMapView](/uwp/api/windows.foundation.collections.imapview-2)
