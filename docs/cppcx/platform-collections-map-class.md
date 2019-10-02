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
ms.openlocfilehash: 81721d719a424250beed89f4a5656b3f2fc27922
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816308"
---
# <a name="platformcollectionsmap-class"></a>Classe Platform::Collections::Map

Representa um *mapa*, que é uma coleção de pares chave-valor. Implementa [Windows:: Foundation:: Collections:: IObservableMap](/uwp/api/windows.foundation.collections.iobservablemap_k_v_) para ajudar com a [vinculação de dados](/windows/uwp/data-binding/data-binding-in-depth)XAML.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename K,
   typename V,
   typename C = std::less<K>>
ref class Map sealed;
```

### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de chave em pares chave-valor.

*V*<br/>
O tipo de valor em pares chave-valor.

*C*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, o [std:: less @ no__t-1k >](../standard-library/less-struct.md).

*__is_valid_winrt_type ()* Uma função gerada pelo compilador que valida o tipo de *K* e *V* e fornece uma mensagem de erro amigável se o tipo não puder ser armazenado no mapa.

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- números inteiros

- classe de interface ^

- classe ref pública^

- estrutura de valor

- classe de enum pública

O mapa é basicamente um wrapper para [std::map](../standard-library/map-class.md). É uma C++ implementação concreta dos tipos [Windows:: Foundation:: Collections:: IMap < janelas:: Foundation:: Collections:: IKeyValuePair @ no__t-2k, V > >](/uwp/api/Windows.Foundation.Collections.IMap_K_V_) e [IObservableMap](/uwp/api/Windows.Foundation.Collections.IObservableMap_K_V_) que são transmitidas entre as janelas públicas Interfaces de tempo de execução. Se você tentar usar um tipo `Platform::Collections::Map` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do parâmetro ou valor de retorno para [Windows:: Foundation:: Collections:: IMap @ no__t-1K, V >](/uwp/api/Windows.Foundation.Collections.IMap_K_V_).

Para obter mais informações, consulte [coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Map::Map](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Map::Clear](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[Map::First](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[Map::GetView](#getview)|Retorna uma exibição somente leitura do Mapa atual; isto é, um [Platform::Collections::MapView Class](../cppcx/platform-collections-mapview-class.md).|
|[Map::HasKey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[Map::Insert](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[Mapa:: Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[Map::Remove](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[Mapa:: tamanho](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Events

|||
|-|-|
|Nome|Descrição|
|Evento [map:: MapChanged](#mapchanged)|Ocorre quando o Map é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Map`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="clear"></a>Método map:: Clear

Remove todos os pares chave-valor do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="first"></a>MAP:: primeiro método

Retorna um iterador que especifica o primeiro elemento no mapa, ou `nullptr` se o mapa estiver vazio.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ First();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado pelo primeiro () é atribuir o valor de retorno a uma variável declarada com a palavra-chave de dedução de tipo **automático** . Por exemplo: `auto x = myMap->First();`.

## <a name="getview"></a>Método map:: GetView

Retorna uma exibição somente leitura do mapa atual; ou seja, uma [classe Platform:: Collections:: MapView](../cppcx/platform-collections-mapview-class.md), que implementa a interface [Windows:: Foundation:: Collections:: IMapView @ No__t-1K, V >]/UWP/API/Windows.Foundation.Collections.IMapView_K_V_).

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor de retorno

Um objeto `MapView`.

## <a name="haskey"></a>Método map:: HasKey

Determina se o Map atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(K key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave usada para localizar o elemento Map. O tipo de *chave* é TypeName *K*.

### <a name="return-value"></a>Valor de retorno

**true** se a chave for encontrada; caso contrário, **false**.

## <a name="insert"></a>Método map:: Insert

Adiciona os pares chave-valor especificados ao objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(K key, V value);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é TypeName *K*.

*value*<br/>
A porção de valor do par chave-valor. O tipo de *valor* é TypeName *V*.

### <a name="return-value"></a>Valor de retorno

**true** se a chave de um elemento existente no mapa atual corresponder à *chave* e a parte de valor desse elemento for definida como *valor*. **false** se nenhum elemento existente no mapa atual corresponder à *chave* e os parâmetros de *chave* e *valor* forem feitos em um par chave-valor e, em seguida, adicionados ao mapa atual.

## <a name="lookup"></a>Método map:: Lookup

Recupera o valor do tipo V que está associado à chave especificada do tipo K, se a chave existir.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(K key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave usada para localizar um elemento em Map. O tipo de *chave* é TypeName *K*.

### <a name="return-value"></a>Valor de retorno

O valor que é emparelhado com a *chave*. O tipo do valor de retorno é TypeName *V*.

### <a name="remarks"></a>Comentários

Se a chave não existir, uma [plataforma:: OutOfBoundsException](../cppcx/platform-outofboundsexception-class.md) será lançada.

## <a name="ctor"></a>Construtor map:: map

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

### <a name="parameters"></a>Parâmetros

*InIt*<br/>
O typename do Map atual.

*comp*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map.

*m*<br/>
Uma referência ou um [rvalue](../cpp/lvalues-and-rvalues-visual-cpp.md) para um `map Class` que é usado para inicializar o mapa atual.

*first*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o Map atual.

*last*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o Map atual.

## <a name="mapchanged"></a>Evento MAP:: MapChanged

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

Um [> MapChangedEventHandler @ no__t-1K, V](/uwp/api/windows.foundation.collections.mapchangedeventhandler) que contém informações sobre o objeto que disparou o evento e o tipo de alteração ocorrida. Consulte também [IMapChangedEventArgs @ no__t-1k >](/uwp/api/Windows.Foundation.Collections.IMapChangedEventArgs_K_) e [Enumeração CollectionChange](/uwp/api/windows.foundation.collections.collectionchange).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Windows Runtime aplicativos que usam C# ou Visual Basic projeto IMap @ No__t-1K, v > como IDictionary @ No__t-2K, v >.

## <a name="remove"></a>Método map:: Remove

Exclui os pares chave-valor especificados do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(K key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é TypeName *K*.

## <a name="size"></a>Método map:: Size

Retorna o número de elementos [Windows:: Foundation:: Collections:: IKeyValuePair @ no__t-1K, V >](/uwp/api/Windows.Foundation.Collections.IKeyValuePair_K_V_) no mapa.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos em Map.

## <a name="see-also"></a>Consulte também

[Coleções (C++/CX)](collections-c-cx.md)<br/>
[Namespace da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes de Windows Runtime noC++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
