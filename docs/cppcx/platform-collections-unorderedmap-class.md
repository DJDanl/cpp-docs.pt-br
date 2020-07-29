---
title: Classe Platform::Collections::UnorderedMap
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- collection/Platform::Collections::UnorderedMap
ms.assetid: dc84f261-b13c-4c0a-9b57-30dcb9e3065e
ms.openlocfilehash: 3c95f4a982e23d757b330ecadcae5cfbfd6fd531
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213067"
---
# <a name="platformcollectionsunorderedmap-class"></a>Classe Platform::Collections::UnorderedMap

Representa um *mapa*não ordenado, que é uma coleção de pares chave-valor.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename K,
   typename V,
   typename C = std::equal_to<K>
>
ref class Map sealed;
```

#### <a name="parameters"></a>parâmetros

*C*<br/>
O tipo de chave em pares chave-valor.

*L*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, [std:: equal_to \<K> ](../standard-library/equal-to-struct.md).

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- integers

- classe de interface ^

- classe ref pública^

- estrutura de valor

- classe de enum pública

**UnorderedMap** é basicamente um wrapper para [std:: unordered_map](../standard-library/unordered-map-class.md) que dá suporte ao armazenamento de tipos de Windows Runtime. É uma implementação concreta dos tipos [Windows:: Foundation:: Collections:: IMap](/uwp/api/windows.foundation.collections.imap-2) e [IObservableMap](/uwp/api/windows.foundation.collections.iobservablemap-2) que são transmitidos entre as interfaces de Windows Runtime pública. Se você tentar usar um tipo `Platform::Collections::UnorderedMap` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do parâmetro ou do valor retornado para [Windows::Foundation::Collections::IMap](/uwp/api/windows.foundation.collections.imap-2).

Para obter mais informações, consulte [coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[UnorderedMap::UnorderedMap](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[UnorderedMap:: Clear](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[UnorderedMap:: primeiro](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[UnorderedMap:: GetView](#getview)|Retorna uma exibição somente leitura do Map atual; isto é, uma classe Platform::Collections::UnorderedMapView.|
|[UnorderedMap::HasKey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[UnorderedMap:: Insert](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[UnorderedMap:: Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[UnorderedMap:: Remove](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[UnorderedMap:: tamanho](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Eventos

|||
|-|-|
|Nome|Descrição|
|Evento [map:: MapChanged](#mapchanged)|Ocorre quando o Map é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`UnorderedMap`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="unorderedmapclear-method"></a><a name="clear"></a>Método UnorderedMap:: Clear

Remove todos os pares chave-valor do objeto UnorderedMap atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="unorderedmapfirst-method"></a><a name="first"></a>Método UnorderedMap:: First

Retorna um iterador que especifica o primeiro elemento [Windows:: Foundation:: Collections: \<K,V> : IKeyValuePair](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no mapa não ordenado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
   Windows::Foundation::Collections::IKeyValuePair<K, V>^>^
   First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado pelo primeiro () é atribuir o valor de retorno a uma variável que é declarada com a **`auto`** palavra-chave de dedução de tipo. Por exemplo, `auto x = myUnorderedMap->First();`.

## <a name="unorderedmapgetview-method"></a><a name="getview"></a>Método UnorderedMap:: GetView

Retorna uma exibição somente leitura do UnorderedMap atual; ou seja, uma [classe Platform:: Collections:: UnorderedMapView](../cppcx/platform-collections-unorderedmapview-class.md) que implementa a interface [Windows:: Foundation:: Collections:: IMapView:: IMapView](/uwp/api/windows.foundation.collections.imapview-2) .

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor retornado

Um objeto `UnorderedMapView`.

## <a name="unorderedmaphaskey-method"></a><a name="haskey"></a>Método UnorderedMap:: HasKey

Determina se o UnorderedMap atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(
   K key
);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave usada para localizar o elemento UnorderedMap. O tipo de *chave* é TypeName *K*.

### <a name="return-value"></a>Valor retornado

**`true`** se a chave for encontrada; caso contrário, **`false`** .

## <a name="unorderedmapinsert-method"></a><a name="insert"></a>Método UnorderedMap:: Insert

Adiciona o par chave-valor especificado ao objeto UnorderedMap atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(
   K key,
   V value
);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é TypeName *K*.

*value*<br/>
A porção de valor do par chave-valor. O tipo de *valor* é TypeName *V*.

### <a name="return-value"></a>Valor retornado

**`true`** se a chave de um elemento existente no mapa atual corresponder à *chave* e a parte de valor desse elemento for definida como *valor*. **`false`** Se nenhum elemento existente no mapa atual corresponder à *chave* , os parâmetros de *chave* e *valor* serão feitos em um par chave-valor e, em seguida, adicionados ao UnorderedMap atual.

## <a name="unorderedmaplookup-method"></a><a name="lookup"></a>Método UnorderedMap:: Lookup

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(
   K key
);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave usada para localizar um elemento em UnorderedMap. O tipo de *chave* é TypeName *K*.

### <a name="return-value"></a>Valor retornado

O valor que é emparelhado com a *chave*. O tipo do valor de retorno é TypeName *V*.

## <a name="unorderedmapmapchanged"></a><a name="mapchanged"></a>UnorderedMap::MapChanged

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Um [MapChangedEventHandler \<K,V> ](/uwp/api/windows.foundation.collections.mapchangedeventhandler-2) que contém informações sobre o objeto que disparou o evento e o tipo de alteração ocorrida. Consulte também [enumeração \<K> IMapChangedEventArgs](/uwp/api/windows.foundation.collections.imapchangedeventargs-1) e [CollectionChange](/uwp/api/windows.foundation.collections.collectionchange).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Windows Runtime aplicativos nos quais C# ou Visual Basic projeto IMap \<K,V> como IDictionary \<K,V> .

## <a name="unorderedmapremove-method"></a><a name="remove"></a>Método UnorderedMap:: Remove

Exclui os pares de chave-valor especificados do objeto UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(
   K key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é TypeName *K*.

## <a name="unorderedmapsize-method"></a><a name="size"></a>Método UnorderedMap:: Size

Retorna o número de elementos [Windows:: Foundation:: Collections:: \<K,V> IKeyValuePair](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no mapa não ordenado.

## <a name="unorderedmapunorderedmap-constructor"></a><a name="ctor"></a>Construtor UnorderedMap:: UnorderedMap

Inicializa uma nova instância da classe UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
UnorderedMap();

explicit UnorderedMap(
    size_t n
    );

UnorderedMap(
    size_t n,
    const H& h
    );

UnorderedMap(
    size_t n,
    const H& h,
    const P& p
    );

explicit UnorderedMap(
    const std::unordered_map<K, V, H, P>& m
    );

explicit UnorderedMap(
    std::unordered_map<K, V, H, P>&& m
    );

template <typename InIt>
UnorderedMap(
    InIt first,
    InIt last
    );

template <typename InIt>
UnorderedMap(
    InIt first,
    InIt last,
    size_t n
    );

template <typename InIt>
UnorderedMap(
    InIt first,
    InIt last,
    size_t n,
    const H& h
    );

template <typename InIt>
UnorderedMap(
    InIt first,
    InIt last,
    size_t n,
    const H& h,
    const P& p
    );

UnorderedMap(
    std::initializer_list< std::pair<const K, V>> il
    );

UnorderedMap(
    std::initializer_list< std::pair<const K, V>> il,
    size_t n
    );

UnorderedMap(
    std::initializer_list< std::pair<const K, V>> il,
    size_t n,
    const H& h
    );

UnorderedMap(
    std::initializer_list< std::pair<const K, V>> il,
    size_t n,
    const H& h,
    const P& p
    );
```

### <a name="parameters"></a>parâmetros

*Iniciar*<br/>
O typename da UnorderedMap atual.

*P*<br/>
Um objeto de função que pode comparar duas chaves para determinar se são iguais. O padrão desse parâmetro é [std:: equal_to \<K> ](../standard-library/equal-to-struct.md).

*T*<br/>
Um objeto de função que gera um valor de hash para uma chave. Esse parâmetro assume como padrão a [classe 1 de hash](../standard-library/hash-class.md) para os tipos de chave aos quais a classe dá suporte.

*d*<br/>
Uma referência ou [lvalues e rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std:: unordered_map](../standard-library/unordered-map-class.md) que é usado para inicializar o UnorderedMap atual.

*Il*<br/>
Um [std:: initializer_list](../standard-library/initializer-list-class.md) de objetos [std::p Air](../standard-library/pair-structure.md) que é usado para inicializar o mapa.

*first*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o UnorderedMap atual.

*last*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o UnorderedMap atual.

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)<br/>
[Namespace da plataforma:: Collections](../cppcx/platform-collections-namespace.md)<br/>
[Classe Platform:: coleções:: map](../cppcx/platform-collections-map-class.md)<br/>
[Classe Platform:: Collections:: UnorderedMapView](../cppcx/platform-collections-unorderedmapview-class.md)<br/>
[Coleções](../cppcx/collections-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
