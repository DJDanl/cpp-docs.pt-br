---
title: Estrutura RuntimeClassFlags | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassFlags
dev_langs:
- C++
helpviewer_keywords:
- RuntimeClassFlags structure
ms.assetid: 7098d605-bd14-4d51-82f4-3def8296a938
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f0a32fc373900af1a4322f4f2511c44417d2916a
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42594268"
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

*flags*  
Um [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante RuntimeClassFlags::value](../windows/runtimeclassflags-value-constant.md)|Contém uma [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RuntimeClassFlags`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)