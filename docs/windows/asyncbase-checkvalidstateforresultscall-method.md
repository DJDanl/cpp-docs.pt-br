---
title: 'Método asyncbase:: Checkvalidstateforresultscall | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::CheckValidStateForResultsCall
dev_langs:
- C++
helpviewer_keywords:
- CheckValidStateForResultsCall method
ms.assetid: 87ca6805-bff1-4063-b855-6dd26132deff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 398f46d5f8eb15d961d80b9a7a20b758fffd09c3
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42584230"
---
# <a name="asyncbasecheckvalidstateforresultscall-method"></a>Método AsyncBase::CheckValidStateForResultsCall

Testa se os resultados de uma operação assíncrona que podem ser coletados no estado assíncrono atual.

## <a name="syntax"></a>Sintaxe

```cpp
inline HRESULT CheckValidStateForResultsCall();
```

## <a name="return-value"></a>Valor de retorno

S_OK se os resultados podem ser coletados; Caso contrário, E_ILLEGAL_METHOD_CALLE_ILLEGAL_METHOD_CALL.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)