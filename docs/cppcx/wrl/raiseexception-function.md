---
title: Função RaiseException
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RaiseException
helpviewer_keywords:
- RaiseException function
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
ms.openlocfilehash: 08305c5d59d7e272aac87ad9aa183c8e82588632
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59029953"
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