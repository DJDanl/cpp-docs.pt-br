---
title: Classe Platform::Collections::UnorderedMap | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- collection/Platform::Collections::UnorderedMap
ms.assetid: dc84f261-b13c-4c0a-9b57-30dcb9e3065e
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fbc1905023f64c4983cf041eda244b28ce507abc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

*K*  
O tipo de chave em pares chave-valor.

*V*  
O tipo de valor em pares chave-valor.

*C*  
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, [std:: equal_to\<K >](../standard-library/equal-to-struct.md).

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- números inteiros

- classe de interface ^

- classe ref pública^

- estrutura de valor

- classe de enum pública

**UnorderedMap** é basicamente um wrapper para [std:: unordered_map](../standard-library/unordered-map-class.md) que dá suporte ao armazenamento de tipos de tempo de execução do Windows. É a implementação concreta do [Windows::Foundation::Collections::IMap](/uwp/api/Windows.Foundation.Collections.IMap_K_V_) e [IObservableMap](/uwp/api/Windows.Foundation.Collections.IObservableMap_K_V_) tipos que são transmitidos pelas público interfaces de tempo de execução do Windows. Se você tentar usar um tipo `Platform::Collections::UnorderedMap` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do valor do parâmetro ou retornado para [Windows::Foundation::Collections::IMap](/uwp/api/Windows.Foundation.Collections.IMap_K_V_).

Para obter mais informações, consulte [coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[UnorderedMap::UnorderedMap](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[UnorderedMap::Clear](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[UnorderedMap::First](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[UnorderedMap::GetView](#getview)|Retorna uma exibição somente leitura do Map atual; isto é, uma classe Platform::Collections::UnorderedMapView.|
|[UnorderedMap::HasKey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[UnorderedMap::Insert](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[UnorderedMap::Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[UnorderedMap::Remove](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[Unorderedmap](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Eventos

|||
|-|-|
|Nome|Descrição|
|[Map:: mapchanged](#mapchanged) evento|Ocorre quando o Map é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`UnorderedMap`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="clear"></a>  Método Unorderedmap:

Remove todos os pares chave-valor do objeto UnorderedMap atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="first"></a>  Método Unorderedmap:

Retorna um iterador que especifica o primeiro [Windows::Foundation::Collections::IKeyValuePair\<K, V >](http://msdn.microsoft.com/library/windows/apps/br226031.aspx) elemento no mapa não ordenado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
   Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ 
   First();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado por First () é atribuir o valor de retorno a uma variável que é declarada com o **automática** palavra-chave de dedução de tipo. Por exemplo, `auto x = myUnorderedMap->First();`.

## <a name="getview"></a>  Método Unorderedmap:

Retorna uma exibição somente leitura do UnorderedMap atual; ou seja, um [Platform::Collections::UnorderedMapView classe](../cppcx/platform-collections-unorderedmapview-class.md) que implementa o [Windows::Foundation::Collections::IMapView::IMapView](http://msdn.microsoft.com/library/windows/apps/br226037.aspx) interface.

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor de retorno

Um objeto `UnorderedMapView`.

## <a name="haskey"></a>  Método Unorderedmap:

Determina se o UnorderedMap atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(
   K key
);
```

### <a name="parameters"></a>Parâmetros

*key*  
A chave usada para localizar o elemento UnorderedMap. O tipo de *chave* é o typename *K*.

### <a name="return-value"></a>Valor de retorno

`true` se a chave for encontrada; caso contrário, `false`.

## <a name="insert"></a>  UnorderedMap::Insert Method

Adiciona o par chave-valor especificado ao objeto UnorderedMap atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(
   K key,
   V value
);
```

### <a name="parameters"></a>Parâmetros

*key*  
A porção de chave do par chave-valor. O tipo de *chave* é o typename *K*.

*value*  
A porção de valor do par chave-valor. O tipo de *valor* é o typename *V*.

### <a name="return-value"></a>Valor de retorno

`true` Se a chave de um elemento existente no Map atual corresponder *chave* e a parte de valor desse elemento é definida como *valor*. `false` Se nenhum elemento existente no Map atual corresponder *chave* e *chave* e *valor* parâmetros são colocados em um par chave-valor e, em seguida, adicionados ao UnorderedMap atual.

## <a name="lookup"></a>  Método Unorderedmap:

Recupera o valor do tipo V que está associado à chave especificada do tipo K.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(
   K key
);
```

### <a name="parameters"></a>Parâmetros

*key*  
A chave usada para localizar um elemento em UnorderedMap. O tipo de *chave* é o typename *K*.

### <a name="return-value"></a>Valor de retorno

O valor que é emparelhado com o *chave*. O tipo do valor de retorno é typename *V*.

## <a name="mapchanged"></a>  UnorderedMap::MapChanged

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

Um [MapChangedEventHandler\<K, V >](http://msdn.microsoft.com/library/windows/apps/br206644.aspx) que contém informações sobre o objeto que gerou o evento e o tipo de alteração que ocorreu. Consulte também [IMapChangedEventArgs\<K >](http://msdn.microsoft.com/library/windows/apps/br226034.aspx) e [CollectionChange Enumeration](http://msdn.microsoft.com/library/windows/apps/windows.foundation.collections.collectionchange.aspx).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Aplicativos de Windows Runtime que nós c# ou Visual Basic projeto IMap\<K, V > como IDictionary\<K, V >.

## <a name="remove"></a>  Método Unorderedmap::

Exclui os pares de chave-valor especificados do objeto UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(
   K key);
```

### <a name="parameters"></a>Parâmetros

*key*  
A porção de chave do par chave-valor. O tipo de *chave* é o typename *K*.

## <a name="size"></a>  Método Unorderedmap:

Retorna o número de [Windows::Foundation::Collections::IKeyValuePair\<K, V >](http://msdn.microsoft.com/library/windows/apps/br226031.aspx) elementos em UnorderedMap.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos no mapa não ordenado.

## <a name="ctor"></a>  Construtor UnorderedMap::UnorderedMap

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

*InIt*  
O typename da UnorderedMap atual.

*P*  
Um objeto de função que pode comparar duas chaves para determinar se são iguais. Padrão desse parâmetro é [std:: equal_to\<K >](../standard-library/equal-to-struct.md).

*H*  
Um objeto de função que gera um valor de hash para uma chave. Padrão desse parâmetro é [hash classe 1](../standard-library/hash-class.md) para os tipos de chave que classe oferece suporte.

*m*  
Uma referência ou [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std:: unordered_map](../standard-library/unordered-map-class.md) que é usado para inicializar o UnorderedMap atual.

*IL* um [std:: initializer_list](../standard-library/initializer-list-class.md) de [STD](../standard-library/pair-structure.md) objetos que é usado para inicializar o mapa.

*first*  
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o UnorderedMap atual.

*last*  
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o UnorderedMap atual.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)  
[Namespace Platform::Collections](../cppcx/platform-collections-namespace.md)  
[classe Platform::Collections::Map](../cppcx/platform-collections-map-class.md)  
[Classe Platform::Collections::UnorderedMapView](../cppcx/platform-collections-unorderedmapview-class.md)  
[Coleções](../cppcx/collections-c-cx.md)  
[Criando componentes de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)  
