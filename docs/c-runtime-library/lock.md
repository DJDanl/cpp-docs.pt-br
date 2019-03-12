---
title: _lock
ms.date: 11/04/2016
apiname:
- _lock
apilocation:
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr100.dll
- msvcr90.dll
- msvcr80.dll
- msvcr110.dll
- msvcrt.dll
- msvcr120_clr0400.dll
apitype: DLLExport
f1_keywords:
- lock
- _lock
helpviewer_keywords:
- lock function
- _lock function
ms.assetid: 29f77c37-30de-4b3d-91b6-030216e645a6
ms.openlocfilehash: d29488c6dec15fb58eef24f50c1bfafefb8e85c6
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57741151"
---
# <a name="lock"></a>_lock

Adquire um bloqueio de vários threads.

> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.

## <a name="syntax"></a>Sintaxe

```
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

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[_unlock](../c-runtime-library/unlock.md)
