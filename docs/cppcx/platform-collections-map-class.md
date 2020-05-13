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
ms.openlocfilehash: ff27f6c543a2326dd4318f66aae51b89092b28e2
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032441"
---
# <a name="platformcollectionsmap-class"></a>Classe Platform::Collections::Map

Representa um *mapa*, que é uma coleção de pares chave-valor. Implementa [o Windows::Foundation::Collections::IObservávelMap](/uwp/api/windows.foundation.collections.iobservablemap-2) para ajudar com a [vinculação de dados](/windows/uwp/data-binding/data-binding-in-depth)XAML .

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
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, [\<std::menos>K ](../standard-library/less-struct.md).

*__is_valid_winrt_type* Uma função gerada por compilador que valida o tipo de *K* e *V* e fornece uma mensagem de erro amigável se o tipo não puder ser armazenado no Mapa.

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- números inteiros

- classe de interface^

- classe ref pública^

- estrutura de valor

- classe de enum pública

O mapa é basicamente um wrapper para [std::map](../standard-library/map-class.md). É uma implementação de concreto C++ dos tipos [Windows::Foundation::Collections:IMap<Windows::Foundation::Collections:IKeyValuePair\<K,V>>](/uwp/api/windows.foundation.collections.imap-2) e [IObwatchbleMap](/uwp/api/windows.foundation.collections.iobservablemap-2) que são passados através de interfaces públicas do Windows Runtime. Se você tentar usar um tipo `Platform::Collections::Map` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do parâmetro ou do valor de retorno para [o Windows::Foundation::Collections:IMap\<K,V>](/uwp/api/windows.foundation.collections.imap-2).

Para obter mais informações, consulte [Coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Mapa::Mapa](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Mapa::Claro](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[Mapa::Primeiro](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[Mapa::GetView](#getview)|Retorna uma exibição somente leitura do Mapa atual; isto é, um [Platform::Collections::MapView Class](../cppcx/platform-collections-mapview-class.md).|
|[Mapa::Haskey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[Mapa::Inserir](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[Mapa::Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[Map::Remove](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[Mapa::Tamanho](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Eventos

|||
|-|-|
|Nome|Descrição|
|[Mapa::MapAlterou](#mapchanged) evento|Ocorre quando o Map é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Map`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="mapclear-method"></a><a name="clear"></a>Mapa::Método claro

Remove todos os pares chave-valor do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="mapfirst-method"></a><a name="first"></a>Mapa::Primeiro método

Retorna um iterador que especifica o primeiro elemento no mapa, ou `nullptr` se o mapa estiver vazio.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ First();
```

### <a name="return-value"></a>Valor retornado

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de segurar o iterator devolvido pelo First() é atribuir o valor de retorno a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.** Por exemplo, `auto x = myMap->First();`.

## <a name="mapgetview-method"></a><a name="getview"></a>Mapa::Método getview

Retorna uma exibição somente leitura do Mapa atual; ou seja, uma [plataforma::Coleções:MapView Class](../cppcx/platform-collections-mapview-class.md), que implementa o [Windows::Foundation::Collections:IMapView\<K,V>](/uwp/api/windows.foundation.collections.imapview-2) interface.

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor retornado

Um objeto `MapView` .

## <a name="maphaskey-method"></a><a name="haskey"></a>mapa::Método haskey

Determina se o Map atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar o elemento Map. O tipo de *chave* é o nome de digite *K*.

### <a name="return-value"></a>Valor retornado

**verdade** se a chave for encontrada; caso contrário, **falso**.

## <a name="mapinsert-method"></a><a name="insert"></a>Mapa::Método de inserção

Adiciona os pares chave-valor especificados ao objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(K key, V value);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é o nome de digite *K*.

*value*<br/>
A porção de valor do par chave-valor. O tipo de *valor* é o nome de digite *V*.

### <a name="return-value"></a>Valor retornado

**verdade** se a chave de um elemento existente no Mapa atual corresponder à *tecla* e a parte de valor desse elemento for definida como *valor*. **falso** se nenhum elemento existente no Mapa atual corresponder *à tecla* e os parâmetros *de chave* e *valor* são transformados em um par de valor-chave e, em seguida, adicionados ao Mapa atual.

## <a name="maplookup-method"></a><a name="lookup"></a>Mapa::Método de análise

Recupera o valor do tipo V que está associado à chave especificada do tipo K, se a chave existir.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave usada para localizar um elemento em Map. O tipo de *chave* é o nome de digite *K*.

### <a name="return-value"></a>Valor retornado

O valor que é emparelhado com a *chave*. O tipo de valor de retorno é o nome de digite *V*.

### <a name="remarks"></a>Comentários

Se a chave não existir, uma [plataforma::OutOfBoundsException](../cppcx/platform-outofboundsexception-class.md) será lançada.

## <a name="mapmap-constructor"></a><a name="ctor"></a>Mapa::Construtor de mapas

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

*Init*<br/>
O typename do Map atual.

*Comp*<br/>
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map.

*M*<br/>
Uma referência [rvalue](../cpp/lvalues-and-rvalues-visual-cpp.md) ou valor `map Class` para um que é usado para inicializar o Mapa atual.

*Primeiro*<br/>
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o Map atual.

*Última*<br/>
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o Map atual.

## <a name="mapmapchanged-event"></a><a name="mapchanged"></a>Mapa::Evento alterado no mapa

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Um [MapChangedEventHandler\<K,V>](/uwp/api/windows.foundation.collections.mapchangedeventhandler-2) que contém informações sobre o objeto que levantou o evento e o tipo de alteração que ocorreu. Veja também [\<iMapChangedEventArgs K>](/uwp/api/windows.foundation.collections.imapchangedeventargs-1) e [CollectionChange Enumeration](/uwp/api/windows.foundation.collections.collectionchange).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Os aplicativos Windows Runtime que usam C# ou visual basic projeto IMap\<K,V> como IDictionary\<K,V>.

## <a name="mapremove-method"></a><a name="remove"></a>Mapa::Remover método

Exclui os pares chave-valor especificados do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(K key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A porção de chave do par chave-valor. O tipo de *chave* é o nome de digite *K*.

## <a name="mapsize-method"></a><a name="size"></a>Mapa::Método de tamanho

Retorna o número do [Windows::Foundation::Coleções::IKeyValuePair\<K,V>](/uwp/api/windows.foundation.collections.ikeyvaluepair-2) elementos no Mapa.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor retornado

O número de elementos em Map.

## <a name="see-also"></a>Confira também

[Coleções (C++/CX)](collections-c-cx.md)<br/>
[Espaço de nome da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
