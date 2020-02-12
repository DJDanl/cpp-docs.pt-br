---
title: Classe location
ms.date: 11/04/2016
f1_keywords:
- location
- CONCRT/concurrency::location
- CONCRT/concurrency::location::location
- CONCRT/concurrency::location::current
- CONCRT/concurrency::location::from_numa_node
helpviewer_keywords:
- location class
ms.assetid: c3289f51-5bf1-4dff-a18d-d0dab8e5d9c7
ms.openlocfilehash: 7f45ff6d3092bd7c27e81adddca72c9411f752d1
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139821"
---
# <a name="location-class"></a>Classe location

Uma abstração de um local físico no hardware.

## <a name="syntax"></a>Sintaxe

```cpp
class location;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[local](#ctor)|Sobrecarregado. Constrói um objeto `location`.|
|[~ Destruidor de local](#dtor)|Destrói um objeto `location`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[atualizados](#current)|Retorna um objeto `location` que representa o local mais específico que o thread de chamada está executando.|
|[from_numa_node](#from_numa_node)|Retorna um objeto `location` que representa um determinado nó NUMA.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)|Determina se dois objetos de `location` representam local diferente.|
|[operator=](#operator_eq)|Atribui o conteúdo de um objeto `location` diferente a este.|
|[operator==](#operator_eq_eq)|Determina se dois objetos de `location` representam o mesmo local.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`location`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ local

Destrói um objeto `location`.

```cpp
~location();
```

## <a name="current"></a>atualizados

Retorna um objeto `location` que representa o local mais específico que o thread de chamada está executando.

```cpp
static location __cdecl current();
```

### <a name="return-value"></a>Valor retornado

Um local que representa o lugar mais específico que o thread de chamada está executando.

## <a name="from_numa_node"></a>from_numa_node

Retorna um objeto `location` que representa um determinado nó NUMA.

```cpp
static location __cdecl from_numa_node(unsigned short _NumaNodeNumber);
```

### <a name="parameters"></a>Parâmetros

*_NumaNodeNumber*<br/>
O número do nó NUMA para o qual construir um local.

### <a name="return-value"></a>Valor retornado

Um local que representa o nó NUMA especificado pelo parâmetro `_NumaNodeNumber`.

## <a name="ctor"></a>local

Constrói um objeto `location`.

```cpp
location();

location(
    const location& _Src);

location(
    T _LocationType,
    unsigned int _Id,
    unsigned int _BindingId = 0,
    _Inout_opt_ void* _PBinding = NULL);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>

*_LocationType*<br/>

*_Id*<br/>

*_BindingId*<br/>

*_PBinding*<br/>
Adicional Ponteiro de associação.

### <a name="remarks"></a>Comentários

Um local construído padrão representa o sistema como um todo.

## <a name="operator_neq"></a>operador! =

Determina se dois objetos de `location` representam local diferente.

```cpp
bool operator!= (const location& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
`location`de operando.

### <a name="return-value"></a>Valor retornado

**true** se os dois locais forem diferentes; caso contrário, **false** .

## <a name="operator_eq"></a>operador =

Atribui o conteúdo de um objeto `location` diferente a este.

```cpp
location& operator= (const location& _Rhs);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O objeto `location` de origem.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq_eq"></a>operador = =

Determina se dois objetos de `location` representam o mesmo local.

```cpp
bool operator== (const location& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
`location`de operando.

### <a name="return-value"></a>Valor retornado

**true** se os dois locais forem idênticos e **false** caso contrário.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
