---
title: _lock
ms.date: 11/04/2016
api_name:
- _lock
api_location:
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr100.dll
- msvcr90.dll
- msvcr80.dll
- msvcr110.dll
- msvcrt.dll
- msvcr120_clr0400.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- lock
- _lock
helpviewer_keywords:
- lock function
- _lock function
ms.assetid: 29f77c37-30de-4b3d-91b6-030216e645a6
ms.openlocfilehash: 9ab7cab2209dc2e02cacca6d540927aa39dc3965
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745376"
---
# <a name="_lock"></a>_lock

Adquire um bloqueio de vários threads.

> [!IMPORTANT]
> Essa função está obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.

## <a name="syntax"></a>Sintaxe

```cpp
void __cdecl _lock
   int locknum
);
```

#### <a name="parameters"></a>Parâmetros

*locknum*<br/>
[in] O identificador do bloqueio a ser adquirido.

## <a name="remarks"></a>Comentários

Se o bloqueio já tiver sido adquirido, este método adquire o bloqueio de qualquer forma e causa um erro interno do C Runtime (CRT). Se o método não conseguir adquirir um bloqueio, ele sairá com um erro fatal e definirá o código de erro para `_RT_LOCK`.

## <a name="requirements"></a>Requisitos

**Fonte:** mlock.c

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[_unlock](../c-runtime-library/unlock.md)
