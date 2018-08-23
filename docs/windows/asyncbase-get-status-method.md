---
title: 'Método asyncbase:: Get_status | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::get_Status
dev_langs:
- C++
helpviewer_keywords:
- get_Status method
ms.assetid: 9823ecb9-212e-471d-b76f-7b8f21208905
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 31b333c14af6d57fb098d6aff0d0938092477de0
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613118"
---
# <a name="asyncbasegetstatus-method"></a>Método AsyncBase::get_Status

Recupera um valor que indica o status da operação assíncrona.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(
   get_Status
)(AsyncStatus *status) override;
```

### <a name="parameters"></a>Parâmetros

*status*  
O local em que o status deve ser armazenado. Para obter mais informações, consulte `Windows::Foundation::AsyncStatus` enumeração.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Status`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)