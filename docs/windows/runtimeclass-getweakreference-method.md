---
title: 'Método runtimeclass:: Getweakreference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::GetWeakReference
dev_langs:
- C++
helpviewer_keywords:
- GetWeakReference method
ms.assetid: 26656ace-7f20-4364-87c9-4a75dd30912e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cc4d2e542afcd72426cb3b0aba57b7d7cbabad06
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42583638"
---
# <a name="runtimeclassgetweakreference-method"></a>Método RuntimeClass::GetWeakReference

Obtém um ponteiro para o objeto de referência fraca para a atual **RuntimeClass** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(
   GetWeakReference
)(_Deref_out_ IWeakReference **weakReference);
```

### <a name="parameters"></a>Parâmetros

*weakReference*  
Quando essa operação for concluída, um ponteiro para um objeto de referência fraca.

## <a name="return-value"></a>Valor de retorno

Sempre S_OK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)