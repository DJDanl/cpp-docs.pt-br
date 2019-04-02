---
title: Função RaiseException
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RaiseException
helpviewer_keywords:
- RaiseException function
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
ms.openlocfilehash: 0a1c661378c4b71378456f2813159b7415cf3fad
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783922"
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

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)