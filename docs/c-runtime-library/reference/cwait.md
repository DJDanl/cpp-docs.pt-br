---
title: _cwait
description: Referência de API para a função de tempo de execução do Microsoft Visual C `_cwait()` .
ms.date: 10/23/2020
api_name:
- _cwait
- _o__cwait
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
- api-ms-win-crt-process-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _cwait
helpviewer_keywords:
- cwait function
- _cwait function
ms.assetid: d9b596b5-45f4-4e03-9896-3f383cb922b8
ms.openlocfilehash: 5b4c4db3c40645b947583b722d345c2e80dcaa8e
ms.sourcegitcommit: faecabcdd12ff53eb79dc0df193fc3567f2f037c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/27/2020
ms.locfileid: "92639101"
---
# <a name="_cwait"></a>_cwait

Aguarda até outro processo terminar.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _cwait(
   int *termstat,
   intptr_t procHandle,
   int action
);
```

### <a name="parameters"></a>parâmetros

*`termstat`*\
Ponteiro para um buffer em que o código de resultado do processo especificado será armazenado ou **`NULL`** .

*`procHandle`*\
O identificador para o processo aguardar (ou seja, o processo que deve ser encerrado antes que **_cwait** possa retornar).

*`action`*\
**`NULL`** : Ignorado por aplicativos do sistema operacional Windows; para outros aplicativos: o código de ação a ser executado em *`procHandle`* .

## <a name="return-value"></a>Valor de retorno

Quando o processo especificado foi concluído com êxito, retorna o identificador do processo especificado e define *`termstat`* para o código de resultado retornado pelo processo especificado. Caso contrário, retorna-1 e define **`errno`** da seguinte maneira.

|Valor|Descrição|
|-----------|-----------------|
|**`ECHILD`**|Nenhum processo especificado existe, *`procHandle`* é inválido ou houve falha na chamada para [`GetExitCodeProcess`](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) a [`WaitForSingleObject`](/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) API ou.|
|**`EINVAL`**|*`action`* é inválido.|

Para obter mais informações sobre esses e outros códigos de retorno, consulte [`errno, _doserrno, _sys_errlist, and _sys_nerr`](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) .

## <a name="remarks"></a>Comentários

A **`_cwait`** função aguarda o encerramento da ID de processo do processo especificado que é fornecido pelo *`procHandle`* . O valor de *`procHandle`* que é passado para **`_cwait`** deve ser o valor retornado pela chamada para a [`_spawn`](../../c-runtime-library/spawn-wspawn-functions.md) função que criou o processo especificado. Se a ID do processo for encerrada antes de **`_cwait`** ser chamada, **`_cwait`** retorna imediatamente. **`_cwait`** pode ser usado por qualquer processo para aguardar qualquer outro processo conhecido para o qual exista um identificador válido ( *`procHandle`* ).

*`termstat`* aponta para um buffer em que o código de retorno do processo especificado será armazenado. O valor de *`termstat`* indica se o processo especificado foi encerrado normalmente chamando a [`ExitProcess`](/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess) API do Windows. **`ExitProcess`** é chamado internamente se o processo especificado chama **`exit`** ou **`_exit`** , retorna de **`main`** ou atinge o final de **`main`** . Para obter mais informações sobre o valor que é passado de volta *`termstat`* , consulte [GetExitCodeProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess). Se **`_cwait`** for chamado usando um **`NULL`** valor para *`termstat`* , o código de retorno do processo especificado não será armazenado.

O *`action`* parâmetro é ignorado pelo sistema operacional Windows porque as relações pai-filho não são implementadas nesses ambientes.

A menos que *`procHandle`* seja-1 ou-2 (trate para o processo ou thread atual), o identificador será fechado. Nessa situação, não use o identificador retornado.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**`_cwait`**|\<process.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_cwait.c
// compile with: /c
// This program launches several processes and waits
// for a specified process to finish.

#define _CRT_RAND_S

#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Macro to get a random integer within a specified range
#define getrandom( min, max ) (( (rand_s (&number), number) % (int)((( max ) + 1 ) - ( min ))) + ( min ))

struct PROCESS
{
    intptr_t hProcess;
    char    name[40];
} process[4] = { { 0, "Ann" }, { 0, "Beth" }, { 0, "Carl" }, { 0, "Dave" } };

int main(int argc, char* argv[])
{
    int termstat, c;
    unsigned int number;

    srand((unsigned)time(NULL));    // Seed randomizer

    // If no arguments, this is the calling process
    if (argc == 1)
    {
        // Spawn processes in numeric order
        for (c = 0; c < 4; c++) {
            _flushall();
            process[c].hProcess = _spawnl(_P_NOWAIT, argv[0], argv[0],
                process[c].name, NULL);
        }

        // Wait for randomly specified process, and respond when done
        c = getrandom(0, 3);
        printf("Come here, %s.\n", process[c].name);
        _cwait(&termstat, process[c].hProcess, _WAIT_CHILD);
        printf("Thank you, %s.\n", process[c].name);

    }
    // If there are arguments, this must be a spawned process
    else
    {
        // Delay for a period that's determined by process number
        Sleep((argv[1][0] - 'A' + 1) * 1000L);
        printf("Hi, Dad. It's %s.\n", argv[1]);
    }
}
```

A ordem da saída varia de Run para Run.

```Output
Hi, Dad. It's Ann.
Come here, Ann.
Thank you, Ann.
Hi, Dad. It's Beth.
Hi, Dad. It's Carl.
Hi, Dad. It's Dave.
```

## <a name="see-also"></a>Veja também

[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)\
[_spawn, _wspawn funções](../../c-runtime-library/spawn-wspawn-functions.md)
