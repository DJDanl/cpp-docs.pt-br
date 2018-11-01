---
title: quick_exit1
ms.date: 11/04/2016
apiname:
- quick_exit
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- quick_exit
- process/quick_exit
- stdlib/quick_exit
helpviewer_keywords:
- quick_exit function
ms.assetid: ecfbdae6-01c4-45fa-aaeb-b368e1de2a9c
ms.openlocfilehash: 50f1ee72cce04c2bebc8f7396a2b6fad98301dd7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50429009"
---
# <a name="quickexit"></a>quick_exit

Causa o término normal do programa.

## <a name="syntax"></a>Sintaxe

```C
__declspec(noreturn) void quick_exit(
    int status
);
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O código de status para retornar para o ambiente de host.

## <a name="return-value"></a>Valor de retorno

O **quick_exit** função não pode retornar a seu chamador.

## <a name="remarks"></a>Comentários

O **quick_exit** função causa o término normal do programa. Ele chama nenhuma função registrada por **atexit**, **OnExit** ou manipuladores de sinal registrados pela **sinal** função. Comportamento será indefinido se **quick_exit** é chamado mais de quando ou se o **sair** também é chamada de função.

O **quick_exit** chamadas de função, no último a entrar, primeiro a sair (UEPS) ordem, as funções registradas por **at_quick_exit**, exceto para aquelas funções já chamadas quando a função foi registrada.  O comportamento será indefinido se uma chamada [longjmp](longjmp.md) for realizada durante uma chamada para uma função registrada que terminaria a chamada para a função.

Depois que as funções registradas foram chamadas, **quick_exit** invoca **exit** usando o *status* valor para retornar o controle para o ambiente de host.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**quick_exit**|\<process.h> ou \<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
