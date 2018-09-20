---
title: 'Método asyncbase:: Get_errorcode | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::get_ErrorCode
dev_langs:
- C++
helpviewer_keywords:
- get_ErrorCode method
ms.assetid: 50b4f8a2-9a21-4ea0-bb5d-7ff524d62aea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e7320831a5cbe6c950baf61abfb167f010a8ecb1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375701"
---
# <a name="asyncbasegeterrorcode-method"></a>Método AsyncBase::get_ErrorCode

Recupera o código de erro para a operação assíncrona atual.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(
   get_ErrorCode
)(HRESULT* errorCode) override;
```

### <a name="parameters"></a>Parâmetros

*código de erro*<br/>
O local em que o código de erro atual é armazenado.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL se a operação assíncrona atual está fechada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)