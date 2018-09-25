---
title: Classe ModuleBase | Microsoft Docs
ms.custom: ''
ms.date: 09/21/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ModuleBase
- implements/Microsoft::WRL::Details::ModuleBase::DecrementObjectCount
- implements/Microsoft::WRL::Details::ModuleBase::IncrementObjectCount
- implements/Microsoft::WRL::Details::ModuleBase::ModuleBase
- implements/Microsoft::WRL::Details::ModuleBase::~ModuleBase
dev_langs:
- C++
helpviewer_keywords:
- ModuleBase class
- Microsoft::WRL::Details::ModuleBase::DecrementObjectCount method
- Microsoft::WRL::Details::ModuleBase::IncrementObjectCount method
- Microsoft::WRL::Details::ModuleBase::ModuleBase, constructor
- Microsoft::WRL::Details::ModuleBase::~ModuleBase, destructor
ms.assetid: edce7591-6893-46f7-94a7-382827775548
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a87b5d617663e87e8c69596e6b1eedca61996b80
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169548"
---
# <a name="modulebase-class"></a>Classe ModuleBase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class ModuleBase;
```

## <a name="remarks"></a>Comentários

Representa a classe base do [módulo](../windows/module-class.md) classes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                         | Descrição
-------------------------------------------- | ---------------------------------------------------------
[Modulebase:: Modulebase](#modulebase)        | Inicializa uma instância da classe `Module`.
[ModuleBase:: ~ ModuleBase](#tilde-modulebase) | A instância atual do realiza o desligamento de `Module` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                      | Descrição
--------------------------------------------------------- | -------------------------------------------------------------------------
[Modulebase:: Decrementobjectcount](#decrementobjectcount) | Quando implementado, diminui o número de objetos rastreados pelo módulo.
[Modulebase:: Incrementobjectcount](#incrementobjectcount) | Quando implementado, incrementa o número de objetos controlados pelo módulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="tilde-modulebase"></a>ModuleBase:: ~ ModuleBase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual ~ModuleBase();
```

### <a name="remarks"></a>Comentários

A instância atual do realiza o desligamento de `ModuleBase` classe.

## <a name="decrementobjectcount"></a>Modulebase:: Decrementobjectcount

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual long DecrementObjectCount() = 0;
```

### <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de decremento.

### <a name="remarks"></a>Comentários

Quando implementado, diminui o número de objetos rastreados pelo módulo.

## <a name="incrementobjectcount"></a>Modulebase:: Incrementobjectcount

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual long IncrementObjectCount() = 0;
```

### <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de incremento.

### <a name="remarks"></a>Comentários

Quando implementado, incrementa o número de objetos controlados pelo módulo.

## <a name="modulebase"></a>Modulebase:: Modulebase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
ModuleBase();
```

### <a name="remarks"></a>Comentários

Inicializa uma instância da classe `Module`.
