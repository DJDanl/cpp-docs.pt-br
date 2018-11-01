---
title: Função GetModuleBase
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::GetModuleBase
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
ms.openlocfilehash: 40289903eba2ce7ac35d4d0b208c3b609efb09f2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50650808"
---
# <a name="getmodulebase-function"></a>Função GetModuleBase
Recupera uma [ModuleBase](../windows/modulebase-class.md) ponteiro que permite para incrementar e diminuir a contagem de referência de um [RuntimeClass](../windows/runtimeclass-class.md) objeto.

## <a name="syntax"></a>Sintaxe

```cpp
inline Details::ModuleBase* GetModuleBase() throw()
```

## <a name="return-value"></a>Valor de retorno

Um ponteiro para um `ModuleBase` objeto.

## <a name="remarks"></a>Comentários

Essa função é usada internamente para incrementar e diminuir contagens de referência de objeto.

Você pode usar essa função para controlar as contagens de referência chamando [modulebase:: Incrementobjectcount](../windows/modulebase-incrementobjectcount-method.md) e [modulebase:: Decrementobjectcount](../windows/modulebase-decrementobjectcount-method.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)