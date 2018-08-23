---
title: 'Método asyncbase:: Checkvalidstatefordelegatecall | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::CheckValidStateForDelegateCall
dev_langs:
- C++
helpviewer_keywords:
- CheckValidStateForDelegateCall method
ms.assetid: d997ebe7-2378-4e74-a379-f0f85e6922f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cd3629fcaf8507abd2baf6cded3c6a63bc6fd64f
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42611494"
---
# <a name="asyncbasecheckvalidstatefordelegatecall-method"></a>Método AsyncBase::CheckValidStateForDelegateCall

Testa se as propriedades de delegado podem ser modificadas no estado assíncrono atual.

## <a name="syntax"></a>Sintaxe

```cpp
inline HRESULT CheckValidStateForDelegateCall();
```

## <a name="return-value"></a>Valor de retorno

S_OK se propriedades de delegado podem ser modificadas; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)