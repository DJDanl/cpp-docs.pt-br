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
ms.openlocfilehash: 4cbd3f367bc57c2eedf672422a458b67b1908fc0
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335498"
---
# <a name="runtimeclassflags-structure"></a>Estrutura RuntimeClassFlags

Contém o tipo para uma instância de um [RuntimeClass](runtimeclass-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <unsigned int flags>
struct RuntimeClassFlags;
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Um [enumeração RuntimeClassType](runtimeclasstype-enumeration.md) valor.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante RuntimeClassFlags::value](#value-constant)|Contém uma [enumeração RuntimeClassType](runtimeclasstype-enumeration.md) valor.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RuntimeClassFlags`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="value-constant"></a>Constante runtimeclassflags:: Value

Um campo que contém um [enumeração RuntimeClassType](runtimeclasstype-enumeration.md) valor.

```cpp
static const unsigned int value = flags;
```
