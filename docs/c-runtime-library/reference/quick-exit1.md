---
title: quick_exit1
ms.date: 11/04/2016
api_name:
- quick_exit
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- quick_exit
- process/quick_exit
- stdlib/quick_exit
helpviewer_keywords:
- quick_exit function
ms.assetid: ecfbdae6-01c4-45fa-aaeb-b368e1de2a9c
ms.openlocfilehash: 86246ed7a32dcd2f12b38aa4148570fc5fb3b7a6
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949681"
---
# <a name="quick_exit"></a>quick_exit

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

A função **quick_exit** não pode retornar ao chamador.

## <a name="remarks"></a>Comentários

A função **quick_exit** causa o encerramento normal do programa. Ele não chama nenhuma função registrada pelos manipuladores **atexit**, **_onexit** ou Signal registrados pela função **Signal** . O comportamento será indefinido se **quick_exit** for chamado mais de uma vez ou se a função **Exit** também for chamada.

As chamadas de função **quick_exit** , na ordem UEPS (último a entrar, primeiro a sair), as funções registradas por **at_quick_exit**, exceto para essas funções já chamadas quando a função foi registrada.  O comportamento será indefinido se uma chamada [longjmp](longjmp.md) for realizada durante uma chamada para uma função registrada que terminaria a chamada para a função.

Depois que as funções registradas tiverem sido chamadas, **quick_exit** invocará **_Exit** usando o valor de *status* para retornar o controle ao ambiente de host.

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
