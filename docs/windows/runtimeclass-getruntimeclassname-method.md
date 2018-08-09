---
title: 'Método runtimeclass:: Getruntimeclassname | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::GetRuntimeClassName
dev_langs:
- C++
helpviewer_keywords:
- GetRuntimeClassName method
ms.assetid: f6388163-fe65-4948-a4bc-ae6826f480e7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 126133c5e542414f1fb38635e1cb14314bc55d52
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020389"
---
# <a name="runtimeclassgetruntimeclassname-method"></a>Método RuntimeClass::GetRuntimeClassName

Obtém o nome de classe de tempo de execução do atual **RuntimeClass** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

### <a name="parameters"></a>Parâmetros
*runtimeName*  
Quando essa operação for concluída, o nome de classe de tempo de execução.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Um erro de asserção é emitido se `__WRL_STRICT__` ou `__WRL_FORCE_INSPECTABLE_CLASS_MACRO__` não está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
 [Classe RuntimeClass](../windows/runtimeclass-class.md)