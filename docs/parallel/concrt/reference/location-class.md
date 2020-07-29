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
ms.openlocfilehash: 848be3131e23ff53f2dec16364b132ee7c218195
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182688"
---
# <a name="location-class"></a>Classe location

Uma abstração de um local físico no hardware.

## <a name="syntax"></a>Sintaxe

```cpp
class location;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[local](#ctor)|Sobrecarregado. Constrói um objeto `location`.|
|[~ Destruidor de local](#dtor)|Destrói um objeto `location`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[atualizados](#current)|Retorna um `location` objeto que representa o local mais específico que o thread de chamada está executando.|
|[from_numa_node](#from_numa_node)|Retorna um `location` objeto que representa um determinado nó numa.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador! =](#operator_neq)|Determina se dois `location` objetos representam local diferente.|
|[operador =](#operator_eq)|Atribui o conteúdo de um `location` objeto diferente a este.|
|[operador = =](#operator_eq_eq)|Determina se dois `location` objetos representam o mesmo local.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`location`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="location"></a><a name="dtor"></a>~ local

Destrói um objeto `location`.

```cpp
~location();
```

## <a name="current"></a><a name="current"></a>atualizados

Retorna um `location` objeto que representa o local mais específico que o thread de chamada está executando.

```cpp
static location __cdecl current();
```

### <a name="return-value"></a>Valor retornado

Um local que representa o lugar mais específico que o thread de chamada está executando.

## <a name="from_numa_node"></a><a name="from_numa_node"></a>from_numa_node

Retorna um `location` objeto que representa um determinado nó numa.

```cpp
static location __cdecl from_numa_node(unsigned short _NumaNodeNumber);
```

### <a name="parameters"></a>parâmetros

*_NumaNodeNumber*<br/>
O número do nó NUMA para o qual construir um local.

### <a name="return-value"></a>Valor retornado

Um local que representa o nó NUMA especificado pelo `_NumaNodeNumber` parâmetro.

## <a name="location"></a><a name="ctor"></a>local

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

### <a name="parameters"></a>parâmetros

*_Src*<br/>

*_LocationType*<br/>

*_Id*<br/>

*_BindingId*<br/>

*_PBinding*<br/>
Adicional Ponteiro de associação.

### <a name="remarks"></a>Comentários

Um local construído padrão representa o sistema como um todo.

## <a name="operator"></a><a name="operator_neq"></a>operador! =

Determina se dois `location` objetos representam local diferente.

```cpp
bool operator!= (const location& _Rhs) const;
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
Operando `location` .

### <a name="return-value"></a>Valor retornado

**`true`** Se os dois locais forem diferentes, **`false`** caso contrário.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Atribui o conteúdo de um `location` objeto diferente a este.

```cpp
location& operator= (const location& _Rhs);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O objeto `location` de origem.

### <a name="return-value"></a>Valor retornado

## <a name="operator"></a><a name="operator_eq_eq"></a>operador = =

Determina se dois `location` objetos representam o mesmo local.

```cpp
bool operator== (const location& _Rhs) const;
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
Operando `location` .

### <a name="return-value"></a>Valor retornado

**`true`** Se os dois locais forem idênticos e, **`false`** caso contrário,.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
