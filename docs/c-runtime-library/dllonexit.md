---
title: __dllonexit
ms.date: 11/04/2016
api_name:
- __dllonexit
api_location:
- msvcrt.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr80.dll
- msvcr120.dll
- msvcr90.dll
- msvcr120_clr0400.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __dllonexit
helpviewer_keywords:
- __dllonexit
ms.assetid: 708f2ceb-f95c-46b0-a58d-d68b3fa36f12
ms.openlocfilehash: 61d63c751dd755bf8a7680c674681e114945814b
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70940439"
---
# <a name="__dllonexit"></a>__dllonexit

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

## <a name="return-value"></a>Valor de retorno

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
