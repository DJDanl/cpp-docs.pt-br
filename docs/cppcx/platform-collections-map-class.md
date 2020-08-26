---
title: Classe Platform::Collections::Map
ms.date: 10/01/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::Map::Map
- COLLECTION/Platform::Collections::Map::Clear
- COLLECTION/Platform::Collections::Map::First
- COLLECTION/Platform::Collections::Map::GetView
- COLLECTION/Platform::Collections::Map::HasKey
- COLLECTION/Platform::Collections::Map::Insert
- COLLECTION/Platform::Collections::Map::Lookup
- COLLECTION/Platform::Collections::Map::Remove
- COLLECTION/Platform::Collections::Map::Size
helpviewer_keywords:
- Map Class (C++/Cx)
ms.assetid: 2b8cf968-1167-4898-a149-1195b32c1785
ms.openlocfilehash: 40b7d653b21cdc2b0fab4c852c9809ab1db46a12
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839134"
---
# <a name="platformcollectionsmap-class"></a>Classe Platform::Collections::Map

Representa um *mapa*, que é uma coleção de pares chave-valor. Implementa [Windows:: Foundation:: Collections:: IObservableMap](/uwp/api/windows.foundation.collections.iobservablemap-2) para ajudar com a [vinculação de dados](/windows/uwp/data-binding/data-binding-in-depth)XAML.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename K,
   typename V,
   typename C = std::less<K>>
ref class Map sealed;
```

### <a name="parameters"></a>parâmetros

*C*<br/>
O tipo de chave em pares chave-valor.

*L*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, [std:: less \<K> ](../standard-library/less-struct.md).

*__is_valid_winrt_type ()* Uma função gerada pelo compilador que valida o tipo de *K* e *V* e fornece uma mensagem de erro amigável se o tipo não puder ser armazenado no mapa.

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- integers

- classe de interface ^

- classe ref pública^

- estrutura de valor

- classe de enum pública

O mapa é basicamente um wrapper para [std::map](../standard-library/map-class.md). É uma implementação concreta do C++ dos tipos [Windows:: Foundation:: Collections:: IMap \<Windows::Foundation::Collections::IKeyValuePair\<K,V> > ](/uwp/api/windows.foundation.collections.imap-2) e [IObservableMap](/uwp/api/windows.foundation.collections.iobservablemap-2) que são transmitidos entre as interfaces de Windows Runtime pública. Se você tentar usar um tipo `Platform::Collections::Map` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do parâmetro ou valor de retorno para [Windows:: Foundation:: Collections:: IMap \<K,V> ](/uwp/api/windows.foundation.collections.imap-2).

Para obter mais informações, consulte [coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Mapa:: map](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Mapa:: limpar](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[Mapa:: primeiro](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[MAP:: GetView](#getview)|Retorna uma exibição somente leitura do Mapa atual; isto é, um [Platform::Collections::MapView Class](../cppcx/platform-collections-mapview-class.md).|
|[MAP:: HasKey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[Mapa:: inserir](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[Mapa:: Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[Map::Remove](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[Mapa:: tamanho](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Eventos

| Nome | Descrição |
|--|--|
| Evento [map:: MapChanged](#mapchanged) | Ocorre quando o Map é alterado. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Map`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="mapclear-method"></a><a name="clear"></a> Método map:: Clear

Remove todos os pares chave-valor do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="mapfirst-method"></a><a name="first"></a> MAP:: primeiro método

Retorna um iterador que especifica o primeiro elemento no mapa ou **`nullptr`** se o mapa está vazio.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado pelo primeiro () é atribuir o valor de retorno a uma variável que é declarada com a **`auto`** palavra-chave de dedução de tipo. Por exemplo, `auto x = myMap->First();`.

## <a name="mapgetview-method"></a><a name="getview"></a> Método map:: GetView

Retorna uma exibição somente leitura do mapa atual; ou seja, uma [classe Platform:: Collections:: MapView](../cppcx/platform-collections-mapview-class.md), que implementa a interface [Windows:: Foundation:: Collections:: \<K,V> IMapView](/uwp/api/windows.foundation.collections.imapview-2) .

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor retornado

Um objeto `MapView`.

## <a name="maphaskey-method"></a><a name="haskey"></a> Método map:: HasKey

Determina se o Map atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(K key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave usada para localizar o elemento Map. O tipo de *chave* é TypeName *K*.

### <a name="return-value"></a>Valor Retornado

**`true`** se a chave for encontrada; caso contrário, **`false`** .

## <a name="mapinsert-method"></a><a name="insert"></a> Método map:: Insert

Adiciona os pares chave-valor especificados ao objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(K key, V value);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é TypeName *K*.

*value*<br/>
A porção de valor do par chave-valor. O tipo de *valor* é TypeName *V*.

### <a name="return-value"></a>Valor Retornado

**`true`** se a chave de um elemento existente no mapa atual corresponder à *chave* e a parte de valor desse elemento for definida como *valor*. **`false`** Se nenhum elemento existente no mapa atual corresponder à *chave* , os parâmetros de *chave* e *valor* serão feitos em um par chave-valor e, em seguida, adicionados ao mapa atual.

## <a name="maplookup-method"></a><a name="lookup"></a> Método map:: Lookup

Recupera o valor do tipo V que está associado à chave especificada do tipo K, se a chave existir.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(K key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave usada para localizar um elemento em Map. O tipo de *chave* é TypeName *K*.

### <a name="return-value"></a>Valor Retornado

O valor que é emparelhado com a *chave*. O tipo do valor de retorno é TypeName *V*.

### <a name="remarks"></a>Comentários

Se a chave não existir, uma [plataforma:: OutOfBoundsException](../cppcx/platform-outofboundsexception-class.md) será lançada.

## <a name="mapmap-constructor"></a><a name="ctor"></a> Construtor map:: map

Inicializa uma nova instância da classe Map.

### <a name="syntax"></a>Sintaxe

```cpp
explicit Map(const C& comp = C());
explicit Map(const StdMap& m);
explicit Map(StdMap&& m ;
template <typename InIt>
Map(
   InItfirst,
   InItlast,
   const C& comp = C());
```

### <a name="parameters"></a>parâmetros

*Iniciar*<br/>
O typename do Map atual.

*comp*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map.

*d*<br/>
Uma referência ou um [rvalue](../cpp/lvalues-and-rvalues-visual-cpp.md) para um `map Class` que é usado para inicializar o mapa atual.

*first*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o Map atual.

*last*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o Map atual.

## <a name="mapmapchanged-event"></a><a name="mapchanged"></a> Evento MAP:: MapChanged

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Um [MapChangedEventHandler \<K,V> ](/uwp/api/windows.foundation.collections.mapchangedeventhandler-2) que contém informações sobre o objeto que disparou o evento e o tipo de alteração ocorrida. Consulte também [enumeração \<K> IMapChangedEventArgs](/uwp/api/windows.foundation.collections.imapchangedeventargs-1) e [CollectionChange](/uwp/api/windows.foundation.collections.collectionchange).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Windows Runtime aplicativos que usam C# ou Visual Basic projeto IMap \<K,V> como IDictionary \<K,V> .

## <a name="mapremove-method"></a><a name="remove"></a> Método map:: Remove

Exclui os pares chave-valor especificados do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(K key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é TypeName *K*.

## <a name="mapsize-method"></a><a name="size"></a> Método map:: Size

Retorna o número de elementos [Windows:: Foundation:: Collections:: \<K,V> IKeyValuePair](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) no mapa.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos em Map.

## <a name="see-also"></a>Confira também

[Coleções (C++/CX)](collections-c-cx.md)<br/>
[Namespace da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
