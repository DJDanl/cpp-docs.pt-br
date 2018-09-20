---
title: Função RaiseException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RaiseException
dev_langs:
- C++
helpviewer_keywords:
- RaiseException function
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 12032318f898b2986b64d5cd8a1e611a31d1fc8c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46372386"
---
# <a name="raiseexception-function"></a>Função RaiseException

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline void __declspec(noreturn)   RaiseException(
      HRESULT hr,
      DWORD dwExceptionFlags = EXCEPTION_NONCONTINUABLE);
```

### <a name="parameters"></a>Parâmetros

*hr*<br/>
O código de exceção da exceção que está sendo gerado; ou seja, o HRESULT de uma operação com falha.

*dwExceptionFlags*<br/>
Um sinalizador que indica uma exceção noncontinuable (o valor do sinalizador é diferente de zero) ou a exceção de continuidade (o valor do sinalizador é zero). Por padrão, a exceção é não continuável.

## <a name="remarks"></a>Comentários

Gera uma exceção no thread de chamada.

Para obter mais informações, consulte o Windows `RaiseException` função.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)