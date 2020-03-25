---
title: Função GetModuleBase
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::GetModuleBase
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
ms.openlocfilehash: 0d130fffa9fad9ae327d03eaa01d84742094cc67
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213961"
---
# <a name="getmodulebase-function"></a>Função GetModuleBase

Recupera um ponteiro [ModuleBase](modulebase-class.md) que permite incrementar e decrementar a contagem de referência de um objeto [RuntimeClass](runtimeclass-class.md) .

## <a name="syntax"></a>Sintaxe

```cpp
inline Details::ModuleBase* GetModuleBase() throw()
```

## <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `ModuleBase`.

## <a name="remarks"></a>Comentários

Essa função é usada internamente para incrementar e decrementar contagens de referência de objeto.

Você pode usar essa função para controlar as contagens de referência chamando [ModuleBase:: IncrementObjectCount](modulebase-class.md#incrementobjectcount) e [ModuleBase::D ecrementobjectcount](modulebase-class.md#decrementobjectcount).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
