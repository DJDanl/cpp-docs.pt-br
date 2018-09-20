---
title: Função GetModuleBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::GetModuleBase
dev_langs:
- C++
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4d460b006d2d17df308a62c0433621aac7008f4d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46411399"
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