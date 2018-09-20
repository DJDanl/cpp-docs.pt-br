---
title: Estrutura RuntimeClassFlags | Microsoft Docs
ms.custom: ''
ms.date: 09/07/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassFlags
- implements/Microsoft::WRL::RuntimeClassFlags::value
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::RuntimeClassFlags structure
- Microsoft::WRL::RuntimeClassFlags::value constant
ms.assetid: 7098d605-bd14-4d51-82f4-3def8296a938
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 39a7684337e7666613bcd824b29417ca5ba0b021
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438048"
---
# <a name="runtimeclassflags-structure"></a>Estrutura RuntimeClassFlags

Contém o tipo para uma instância de um [RuntimeClass](../windows/runtimeclass-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <
   unsigned int flags
>
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
