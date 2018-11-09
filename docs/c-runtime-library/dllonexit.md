---
title: __dllonexit
ms.date: 11/04/2016
apiname:
- __dllonexit
apilocation:
- msvcrt.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr80.dll
- msvcr120.dll
- msvcr90.dll
- msvcr120_clr0400.dll
apitype: DLLExport
f1_keywords:
- __dllonexit
helpviewer_keywords:
- __dllonexit
ms.assetid: 708f2ceb-f95c-46b0-a58d-d68b3fa36f12
ms.openlocfilehash: 70e69952e350f96179298e2d64ec6ddf7b9167bc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50625405"
---
# <a name="dllonexit"></a>__dllonexit

Registra uma rotina a ser chamada na hora de saída.

## <a name="syntax"></a>Sintaxe

```
_onexit_t __dllonexit(   _onexit_t func,
   _PVFV **  pbegin,
   _PVFV **  pend
   )
```

#### <a name="parameters"></a>Parâmetros

*func*<br/>
Ponteiro para uma função a ser executada ao sair.

*pbegin*<br/>
Ponteiro para uma variável que aponta para o início de uma lista de funções para executar ao desanexar.

*pend*<br/>
Ponteiro para uma variável que aponta para o fim de uma lista de funções para executar ao desanexar.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a função do usuário. Caso contrário, um ponteiro **NULL**.

## <a name="remarks"></a>Comentários

A função `__dllonexit` é semelhante à função [_onexit](../c-runtime-library/reference/onexit-onexit-m.md) exceto que as variáveis globais usadas por essa função não são visíveis para essa rotina. Em vez de variáveis globais, essa função usa os parâmetros `pbegin` e `pend`.

As funções `_onexit` e `atexit` em uma DLL vinculadas a MSVCRT.LIB devem manter sua própria lista de atexit/_onexit. Essa rotina é o trabalho que é chamado por essas DLLs.

O tipo `_PVFV` é definido como `typedef void (__cdecl *_PVFV)(void)`.

## <a name="requirements"></a>Requisitos

|Rotina|Arquivo necessário|
|-------------|-------------------|
|__dllonexit|onexit.c|

## <a name="see-also"></a>Consulte também

[_onexit, _onexit_m](../c-runtime-library/reference/onexit-onexit-m.md)