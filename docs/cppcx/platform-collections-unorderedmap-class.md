---
title: Classe Platform::Collections::UnorderedMap
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- collection/Platform::Collections::UnorderedMap
ms.assetid: dc84f261-b13c-4c0a-9b57-30dcb9e3065e
ms.openlocfilehash: 80b46cb95f2fdb83922ca22e8aa06a89aca4bfde
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82031492"
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

#### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de chave em pares chave-valor.

*V*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, [\<std::equal_to K>](../standard-library/equal-to-struct.md).

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- números inteiros

- classe de interface^

- classe ref pública^

- estrutura de valor

- classe de enum pública

**UnorderedMap** é basicamente um invólucro para [std::unordered_map](../standard-library/unordered-map-class.md) que suporta o armazenamento de tipos de tempo de execução do Windows. É uma implementação concreta dos tipos [Windows::Foundation::Collections::IMap](/uwp/api/windows.foundation.collections.imap-2) e [IObserbleMap](/uwp/api/windows.foundation.collections.iobservablemap-2) que são passados através de interfaces públicas do Windows Runtime. Se você tentar usar um tipo `Platform::Collections::UnorderedMap` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do parâmetro ou do valor retornado para [Windows::Foundation::Collections::IMap](/uwp/api/windows.foundation.collections.imap-2).

Para obter mais informações, consulte [Coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Desordenado':Desordenado', 'Desordenado'',](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Mapa desordenado::Limpar](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[Mapa desordenado::Primeiro](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[Mapa desordenado::GetView](#getview)|Retorna uma exibição somente leitura do Map atual; isto é, uma classe Platform::Collections::UnorderedMapView.|
|[Mapa desordenado::HasKey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[Mapa desordenado::Inserir](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[Mapa desordenado::Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[Mapa desordenado::Remover](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[Mapa desordenado::Tamanho](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Eventos

|||
|-|-|
|Nome|Descrição|
|[Mapa::MapAlterou](#mapchanged) evento|Ocorre quando o Map é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`UnorderedMap`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="unorderedmapclear-method"></a><a name="clear"></a>Mapa desordenado::Método de limpar

Remove todos os pares chave-valor do objeto UnorderedMap atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="unorderedmapfirst-method"></a><a name="first"></a>Mapa desordenado::Primeiro método

Retorna um iterator que especifica o primeiro [elemento Windows::Foundation::Collections::IKeyValuePair\<K,V>](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no mapa desordenado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
   Windows::Foundation::Collections::IKeyValuePair<K, V>^>^
   First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de segurar o iterator devolvido pelo First() é atribuir o valor de retorno a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.** Por exemplo, `auto x = myUnorderedMap->First();`.

## <a name="unorderedmapgetview-method"></a><a name="getview"></a>DesordenadoMap::Método GetView

Retorna uma exibição somente leitura do Mapa Não ordenado atual; ou seja, uma [plataforma::Coleções::UnorderedMapView Class](../cppcx/platform-collections-unorderedmapview-class.md) que implementa o [Windows::Foundation::Collections:IMapView::IMapView](/uwp/api/windows.foundation.collections.imapview-2) interface.

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor retornado

Um objeto `UnorderedMapView`.

## <a name="unorderedmaphaskey-method"></a><a name="haskey"></a>Mapa desordenado::Método HasKey

Determina se o UnorderedMap atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(
   K key
);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar o elemento UnorderedMap. O tipo de *chave* é o nome de digite *K*.

### <a name="return-value"></a>Valor retornado

**verdade** se a chave for encontrada; caso contrário, **falso**.

## <a name="unorderedmapinsert-method"></a><a name="insert"></a>Mapa desordenado::Método de inserção

Adiciona o par chave-valor especificado ao objeto UnorderedMap atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(
   K key,
   V value
);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é o nome de digite *K*.

*value*<br/>
A porção de valor do par chave-valor. O tipo de *valor* é o nome de digite *V*.

### <a name="return-value"></a>Valor retornado

**verdade** se a chave de um elemento existente no Mapa atual corresponder à *tecla* e a parte de valor desse elemento for definida como *valor*. **falso** se nenhum elemento existente no Mapa atual corresponder *à chave* e os parâmetros *de chave* e *valor* são transformados em um par de valor-chave e, em seguida, adicionados ao Mapa Não ordenado atual.

## <a name="unorderedmaplookup-method"></a><a name="lookup"></a>Mapa desordenado::Método de procurar

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(
   K key
);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar um elemento em UnorderedMap. O tipo de *chave* é o nome de digite *K*.

### <a name="return-value"></a>Valor retornado

O valor que é emparelhado com a *chave*. O tipo de valor de retorno é o nome de digite *V*.

## <a name="unorderedmapmapchanged"></a><a name="mapchanged"></a>Mapa desordenado::Mapaalterado

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Um [MapChangedEventHandler\<K,V>](/uwp/api/windows.foundation.collections.mapchangedeventhandler-2) que contém informações sobre o objeto que levantou o evento e o tipo de alteração que ocorreu. Veja também [\<iMapChangedEventArgs K>](/uwp/api/windows.foundation.collections.imapchangedeventargs-1) e [CollectionChange Enumeration](/uwp/api/windows.foundation.collections.collectionchange).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Os aplicativos Windows Runtime que nos C# ou Visual Basic project IMap\<K,V> como IDictionary\<K,V>.

## <a name="unorderedmapremove-method"></a><a name="remove"></a>DesordenadoMap::Método de remover

Exclui os pares de chave-valor especificados do objeto UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(
   K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é o nome de digite *K*.

## <a name="unorderedmapsize-method"></a><a name="size"></a>Mapa desordenado::Método de tamanho

Retorna o número do [Windows::Foundation::Coleções::IKeyValuePair\<K,V>](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) elementos no UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no mapa não ordenado.

## <a name="unorderedmapunorderedmap-constructor"></a><a name="ctor"></a>DesordenadoMap::Construtor demapado não ordenado

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

### <a name="parameters"></a>Parâmetros

*Init*<br/>
O typename da UnorderedMap atual.

*P*<br/>
Um objeto de função que pode comparar duas chaves para determinar se são iguais. Este parâmetro é padrão para [\<std::equal_to K>](../standard-library/equal-to-struct.md).

*H*<br/>
Um objeto de função que gera um valor de hash para uma chave. Este parâmetro é padrão para [hash Classe 1](../standard-library/hash-class.md) para os tipos-chave que a classe suporta.

*M*<br/>
Uma referência ou [Valores e Valores](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std::unordered_map](../standard-library/unordered-map-class.md) que é usado para inicializar o Mapa Não ordenado atual.

*Il*<br/>
Um [std::initializer_list](../standard-library/initializer-list-class.md) de objetos [std::pair](../standard-library/pair-structure.md) que é usado para inicializar o mapa.

*Primeiro*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o UnorderedMap atual.

*Última*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o UnorderedMap atual.

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)<br/>
[Namespace Platform::Collections](../cppcx/platform-collections-namespace.md)<br/>
[classe Platform::Collections::Map](../cppcx/platform-collections-map-class.md)<br/>
[Classe Platform::Collections::UnorderedMapView](../cppcx/platform-collections-unorderedmapview-class.md)<br/>
[Coleções](../cppcx/collections-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
