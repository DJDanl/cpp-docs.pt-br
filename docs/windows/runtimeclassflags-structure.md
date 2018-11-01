---
title: Estrutura RuntimeClassFlags
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassFlags
- implements/Microsoft::WRL::RuntimeClassFlags::value
helpviewer_keywords:
- Microsoft::WRL::RuntimeClassFlags structure
- Microsoft::WRL::RuntimeClassFlags::value constant
ms.assetid: 7098d605-bd14-4d51-82f4-3def8296a938
ms.openlocfilehash: 74ae72dc87d45abba04d15303ed2ec92b18f8c28
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668527"
---
# <a name="runtimeclassflags-structure"></a>Estrutura RuntimeClassFlags

Contém o tipo para uma instância de um [RuntimeClass](../windows/runtimeclass-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <unsigned int flags>
struct RuntimeClassFlags;
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Um [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante RuntimeClassFlags::value](#value-constant)|Contém uma [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RuntimeClassFlags`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="value-constant"></a>Constante runtimeclassflags:: Value

Um campo que contém um [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.

```cpp
static const unsigned int value = flags;
```
