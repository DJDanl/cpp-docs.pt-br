---
title: '{1&gt;classe Platform::Collections::Map&lt;1} | Microsoft Docs'
ms.custom: ''
ms.date: 01/18/2018
ms.technology: cpp-windows
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
dev_langs:
- C++
helpviewer_keywords:
- Map Class (C++/Cx)
ms.assetid: 2b8cf968-1167-4898-a149-1195b32c1785
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a2192786a9ebb14061e31655fd63e0f7c67b5100
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43218417"
---
# <a name="platformcollectionsmap-class"></a>Classe Platform::Collections::Map

Representa um *mapa*, que é uma coleção de pares chave-valor.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename K,
   typename V,
   typename C = std::less<K>>
ref class Map sealed;
```

### <a name="parameters"></a>Parâmetros

*K*  
 O tipo de chave em pares chave-valor.

*V*  
O tipo de valor em pares chave-valor.

*C*  
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map. Por padrão, [std:: Less\<K >](../standard-library/less-struct.md).

*__is_valid_winrt_type()*  
Uma função gerada pelo compilador que valida o tipo de *K* e *V* e fornece uma mensagem de erro amigável caso o tipo não pode ser armazenado no mapa.

### <a name="remarks"></a>Comentários

Os tipos permitidos são:

- números inteiros

- classe de interface ^

- classe ref pública^

- estrutura de valor

- classe de enum pública

O mapa é basicamente um wrapper para [std::map](../standard-library/map-class.md). É uma implementação concreta de C++ do [IMAP < ikeyvaluepair\<K, V >>](http://go.microsoft.com/fwlink/p/?LinkId=262408) e [IObservableMap](/uwp/api/Windows.Foundation.Collections.IObservableMap_K_V_) interfaces de tempo de execução do Windows de tipos que são transmitidos pelas público. Se você tentar usar um tipo `Platform::Collections::Map` em um parâmetro ou valor de retorno público, o erro do compilador C3986 será gerado. Você pode corrigir o erro alterando o tipo do valor de parâmetro ou retornado para [IMAP\<K, V >](http://go.microsoft.com/fwlink/p/?LinkId=262408).

Para obter mais informações, consulte [coleções](../cppcx/collections-c-cx.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Map::Map](#ctor)|Inicializa uma nova instância da classe Map.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Map:: Clear](#clear)|Remove todos os pares chave-valor do objeto Map atual.|
|[Map::First](#first)|Retorna um iterador que especifica o primeiro elemento no mapa.|
|[Map::GetView](#getview)|Retorna uma exibição somente leitura do Mapa atual; isto é, um [Platform::Collections::MapView Class](../cppcx/platform-collections-mapview-class.md).|
|[Map::HasKey](#haskey)|Determina se o Map atual contém a chave especificada.|
|[Map::Insert](#insert)|Adiciona os pares chave-valor especificados ao objeto Map atual.|
|[Map:: Lookup](#lookup)|Recupera o elemento na chave especificada no objeto Map atual.|
|[Map::Remove](#remove)|Exclui os pares chave-valor especificados do objeto Map atual.|
|[Map:: Size](#size)|Retorna o número de elementos no objeto Map atual.|

### <a name="events"></a>Eventos

|||
|-|-|
|Nome|Descrição|
|[Map:: mapchanged](#mapchanged-event.md) `event`|Ocorre quando o Map é alterado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Map`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="clear"></a>  Método Map:: Clear

Remove todos os pares chave-valor do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Clear();
```

## <a name="first"></a>  Método Map:: First

Retorna um iterador que especifica o primeiro elemento no mapa, ou `nullptr` se o mapa estiver vazio.

### <a name="syntax"></a>Sintaxe

```cpp
virtual Windows::Foundation::Collections::IIterator<
Windows::Foundation::Collections::IKeyValuePair<K, V>^>^ First();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que especifica o primeiro elemento no mapa.

### <a name="remarks"></a>Comentários

Uma maneira conveniente de manter o iterador retornado por First () é atribuir o valor de retorno a uma variável que é declarada com o **automática** palavra-chave de dedução de tipo. Por exemplo, `auto x = myMap->First();`.

## <a name="getview"></a>  Método Map:: GetView

Retorna uma exibição somente leitura do Map atual; ou seja, uma [Platform::Collections::mapview&lt;3](../cppcx/platform-collections-mapview-class.md), que implementa o [3&gt;{4&gt;Windows::Foundation::Collections::imapview&lt;4}&lt;3}\<K, V >] / uwp/api/Windows.Foundation.Collections.IMapView_K_V_) interface.

### <a name="syntax"></a>Sintaxe

```cpp
Windows::Foundation::Collections::IMapView<K, V>^ GetView();
```

### <a name="return-value"></a>Valor de retorno

Um objeto `MapView`.

## <a name="haskey"></a>  Método Map:: haskey

Determina se o Map atual contém a chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
bool HasKey(K key);
```

### <a name="parameters"></a>Parâmetros

*key*  
A chave usada para localizar o elemento Map. O tipo de *chave* é o typename *K*.

### <a name="return-value"></a>Valor de retorno

`true` se a chave for encontrada; caso contrário, `false`.

## <a name="insert"></a>  Método Map:: Insert

Adiciona os pares chave-valor especificados ao objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual bool Insert(K key, V value);
```

### <a name="parameters"></a>Parâmetros

*key*  
A porção de chave do par chave-valor. O tipo de *chave* é o typename *K*.

*value*  
A porção de valor do par chave-valor. O tipo de *valor* é o typename *V*.

### <a name="return-value"></a>Valor de retorno

`true` Se a chave de um elemento existente no Map atual corresponder *chave* e a parte do valor desse elemento é definida como *valor*. `false` Se nenhum elemento existente no Map atual corresponder *chave* e o *chave* e *valor* parâmetros são colocados em um par chave-valor e, em seguida, adicionados ao Map atual.

## <a name="lookup"></a>  Método Map:: Lookup

Recupera o valor do tipo V que está associado à chave especificada do tipo K, se a chave existir.

### <a name="syntax"></a>Sintaxe

```cpp
V Lookup(K key);
```

### <a name="parameters"></a>Parâmetros

*key*  
A chave usada para localizar um elemento em Map. O tipo de *chave* é o typename *K*.

### <a name="return-value"></a>Valor de retorno

O valor que é emparelhado com o *chave*. O tipo do valor de retorno é typename *V*.

### <a name="remarks"></a>Comentários

Se a chave não existir, em seguida, um [Platform:: outofboundsexception](../cppcx/platform-outofboundsexception-class.md) é gerada.

## <a name="ctor"></a>  Construtor Map:: Map

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

*InIt*  
O typename do Map atual.

*comp*  
Um tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no Map.

*m*  
Uma referência ou [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um `map Class` que é usado para inicializar o Map atual.

*first*  
O iterador de entrada do primeiro elemento em um intervalo de elementos usados para inicializar o Map atual.

*last*  
O iterador de entrada do primeiro elemento após um intervalo de elementos usados para inicializar o Map atual.

## <a name="mapchanged"></a>  Evento Map:: mapchanged

Gerado quando um item é inserido no mapa ou removido dele.

### <a name="syntax"></a>Sintaxe

```cpp
event Windows::Foundation::Collections::MapChangedEventHandler<K,V>^ MapChanged;
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

Um [MapChangedEventHandler\<K, V >](/uwp/api/windows.foundation.collections.mapchangedeventhandler) que contém informações sobre o objeto que gerou o evento e o tipo de alteração que ocorreu. Consulte também [IMapChangedEventArgs\<K >](https://msdn.microsoft.com/library/windows/apps/br226034.aspx) e [CollectionChange Enumeration](https://msdn.microsoft.com/library/windows/apps/windows.foundation.collections.collectionchange.aspx).

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

Projeto de aplicativos de tempo de execução do Windows que usam c# ou Visual Basic IMap\<K, V > como IDictionary\<K, V >.

## <a name="remove"></a>  Método Map:: remove

Exclui os pares chave-valor especificados do objeto Map atual.

### <a name="syntax"></a>Sintaxe

```cpp
virtual void Remove(K key);
```

### <a name="parameters"></a>Parâmetros

*key*  
A porção de chave do par chave-valor. O tipo de *chave* é o typename *K*.

## <a name="size"></a>  Método Map:: Size

Retorna o número de [ikeyvaluepair\<K, V >](https://msdn.microsoft.com/library/windows/apps/br226031.aspx) elementos no mapa.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property unsigned int Size;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos em Map.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)  
[Criando componentes de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)  
