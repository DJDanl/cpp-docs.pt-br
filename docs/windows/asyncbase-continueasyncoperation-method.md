---
title: 'Método asyncbase:: Continueasyncoperation | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::ContinueAsyncOperation
dev_langs:
- C++
helpviewer_keywords:
- ContinueAsyncOperation method
ms.assetid: ce38181d-2fc3-4579-b0ce-237a3c7648bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b83d7a0bb5eadede42d2572d5ebc5a02a0fe9a0e
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42607179"
---
# <a name="asyncbasecontinueasyncoperation-method"></a>Método AsyncBase::ContinueAsyncOperation

Determina se a operação assíncrona devam continuar o processamento ou deve parar.

## <a name="syntax"></a>Sintaxe

```cpp
inline bool ContinueAsyncOperation();
```

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o estado atual da operação assíncrona for *iniciado*, que significa que a operação deve continuar. Caso contrário, **falsos**, que significa que a operação deve parar.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)