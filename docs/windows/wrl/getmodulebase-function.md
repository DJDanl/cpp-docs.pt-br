---
title: Função GetModuleBase
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::GetModuleBase
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
ms.openlocfilehash: 4d8c8467b7aeb9c21bf5f4ee19c60e6e60880688
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335495"
---
# <a name="getmodulebase-function"></a>Função GetModuleBase

Recupera uma [ModuleBase](modulebase-class.md) ponteiro que permite para incrementar e diminuir a contagem de referência de um [RuntimeClass](runtimeclass-class.md) objeto.

## <a name="syntax"></a>Sintaxe

```cpp
inline Details::ModuleBase* GetModuleBase() throw()
```

## <a name="return-value"></a>Valor retornado

Um ponteiro para um `ModuleBase` objeto.

## <a name="remarks"></a>Comentários

Essa função é usada internamente para incrementar e diminuir contagens de referência de objeto.

Você pode usar essa função para controlar as contagens de referência chamando [modulebase:: Incrementobjectcount](modulebase-class.md#incrementobjectcount) e [modulebase:: Decrementobjectcount](modulebase-class.md#decrementobjectcount).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)