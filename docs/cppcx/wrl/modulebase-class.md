---
title: Classe ModuleBase
ms.date: 09/21/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ModuleBase
- implements/Microsoft::WRL::Details::ModuleBase::DecrementObjectCount
- implements/Microsoft::WRL::Details::ModuleBase::IncrementObjectCount
- implements/Microsoft::WRL::Details::ModuleBase::ModuleBase
- implements/Microsoft::WRL::Details::ModuleBase::~ModuleBase
helpviewer_keywords:
- ModuleBase class
- Microsoft::WRL::Details::ModuleBase::DecrementObjectCount method
- Microsoft::WRL::Details::ModuleBase::IncrementObjectCount method
- Microsoft::WRL::Details::ModuleBase::ModuleBase, constructor
- Microsoft::WRL::Details::ModuleBase::~ModuleBase, destructor
ms.assetid: edce7591-6893-46f7-94a7-382827775548
ms.openlocfilehash: 13a8ceef3133e9946524e1fcd02e96535eccd7fc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371265"
---
# <a name="modulebase-class"></a>Classe ModuleBase

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class ModuleBase;
```

## <a name="remarks"></a>Comentários

Representa a classe base das classes [de Módulo.](module-class.md)

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                         | Descrição
-------------------------------------------- | ---------------------------------------------------------
[Base do módulo::Base do módulo](#modulebase)        | Inicializa uma instância da classe `Module`.
[Base do módulo::~Base do módulo](#tilde-modulebase) | Desinicializa a instância `Module` atual da classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                      | Descrição
--------------------------------------------------------- | -------------------------------------------------------------------------
[ModuleBase::DecrementObjectCount](#decrementobjectcount) | Quando implementado, diminui o número de objetos rastreados pelo módulo.
[Base do módulo::IncrementObjectCount](#incrementobjectcount) | Quando implementado, aumenta o número de objetos rastreados pelo módulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="modulebasemodulebase"></a><a name="tilde-modulebase"></a>Base do módulo::~Base do módulo

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual ~ModuleBase();
```

### <a name="remarks"></a>Comentários

Desinicializa a instância `ModuleBase` atual da classe.

## <a name="modulebasedecrementobjectcount"></a><a name="decrementobjectcount"></a>ModuleBase::DecrementObjectCount

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual long DecrementObjectCount() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem antes da operação de decrésia.

### <a name="remarks"></a>Comentários

Quando implementado, diminui o número de objetos rastreados pelo módulo.

## <a name="modulebaseincrementobjectcount"></a><a name="incrementobjectcount"></a>Base do módulo::IncrementObjectCount

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual long IncrementObjectCount() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem antes da operação de incremento.

### <a name="remarks"></a>Comentários

Quando implementado, aumenta o número de objetos rastreados pelo módulo.

## <a name="modulebasemodulebase"></a><a name="modulebase"></a>Base do módulo::Base do módulo

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ModuleBase();
```

### <a name="remarks"></a>Comentários

Inicializa uma instância da classe `Module`.
