---
title: Classe Location | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- location
- CONCRT/concurrency::location
- CONCRT/concurrency::location::location
- CONCRT/concurrency::location::current
- CONCRT/concurrency::location::from_numa_node
dev_langs:
- C++
helpviewer_keywords:
- location class
ms.assetid: c3289f51-5bf1-4dff-a18d-d0dab8e5d9c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8c2352662de2d55be823064afd16354ff7f2c72e
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49163615"
---
# <a name="location-class"></a>Classe location

Uma abstração de um local físico em hardware.

## <a name="syntax"></a>Sintaxe

```
class location;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Local](#ctor)|Sobrecarregado. Constrói um objeto `location`.|
|[~ local destruidor](#dtor)|Destrói um objeto `location`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[current](#current)|Retorna um `location` objeto que representa o local mais específico, o thread de chamada está em execução.|
|[from_numa_node](#from_numa_node)|Retorna um `location` objeto que representa um nó NUMA.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)|Determina se dois `location` objetos representam um local diferente.|
|[operator=](#operator_eq)|Atribui o conteúdo de um outro `location` objeto para esse outro.|
|[operator==](#operator_eq_eq)|Determina se dois `location` objetos representam o mesmo local.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`location`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~ local

Destrói um objeto `location`.

```
~location();
```

##  <a name="current"></a> Atual

Retorna um `location` objeto que representa o local mais específico, o thread de chamada está em execução.

```
static location __cdecl current();
```

### <a name="return-value"></a>Valor de retorno

Um local que representa o local mais específico o thread de chamada está em execução.

##  <a name="from_numa_node"></a> from_numa_node

Retorna um `location` objeto que representa um nó NUMA.

```
static location __cdecl from_numa_node(unsigned short _NumaNodeNumber);
```

### <a name="parameters"></a>Parâmetros

*_NumaNodeNumber*<br/>
O número de nó para construir um local para.

### <a name="return-value"></a>Valor de retorno

Um local que representa o nó NUMA especificado pelo `_NumaNodeNumber` parâmetro.

##  <a name="ctor"></a> Local

Constrói um objeto `location`.

```
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

*ID*<br/>

*_BindingId*<br/>

*_PBinding*<br/>
(Opcional) Ponteiro de ligação.

### <a name="remarks"></a>Comentários

Um local padrão construído representa o sistema como um todo.

##  <a name="operator_neq"></a> operador! =

Determina se dois `location` objetos representam um local diferente.

```
bool operator!= (const location& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
Operando `location`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os dois locais forem diferentes, **falso** caso contrário.

##  <a name="operator_eq"></a> operador =

Atribui o conteúdo de um outro `location` objeto para esse outro.

```
location& operator= (const location& _Rhs);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A fonte `location` objeto.

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_eq_eq"></a> operador = =

Determina se dois `location` objetos representam o mesmo local.

```
bool operator== (const location& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
Operando `location`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os dois locais forem idênticos, e **falso** caso contrário.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
