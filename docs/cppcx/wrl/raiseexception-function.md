---
title: Função RaiseException
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RaiseException
helpviewer_keywords:
- RaiseException function
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
ms.openlocfilehash: 3270057bf5b1b27a98bef1ab236291eab15d27ab
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213623"
---
# <a name="raiseexception-function"></a>Função RaiseException

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline void __declspec(noreturn)   RaiseException(
      HRESULT hr,
      DWORD dwExceptionFlags = EXCEPTION_NONCONTINUABLE);
```

### <a name="parameters"></a>parâmetros

*Human*<br/>
O código de exceção da exceção que está sendo gerada; ou seja, o HRESULT de uma operação com falha.

*dwExceptionFlags*<br/>
Um sinalizador que indica uma exceção continuável (o valor do sinalizador é zero), ou a exceção não continuável (o valor do sinalizador é zero). Por padrão, a exceção é não continuável.

## <a name="remarks"></a>Comentários

Gera uma exceção no thread de chamada.

Para obter mais informações, consulte a função `RaiseException` do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Internal. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
