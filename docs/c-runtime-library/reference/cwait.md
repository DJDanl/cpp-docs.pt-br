---
title: _cwait
ms.date: 4/2/2020
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
ms.openlocfilehash: 9e2e23acb041004b9e96d1c6558ae195ed522155
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82914791"
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

### <a name="parameters"></a>Parâmetros

*termstat*<br/>
Ponteiro para um buffer em que o código de resultado do processo especificado será armazenado ou **nulo**.

*procHandle*<br/>
O identificador para o processo aguardar (ou seja, o processo que deve ser encerrado antes que **_cwait** possa retornar).

*action*<br/>
NULL: ignorado por aplicativos do sistema operacional Windows; para outros aplicativos: código de ação a ser executado em *procHandle*.

## <a name="return-value"></a>Valor retornado

Quando o processo especificado tiver sido concluído com êxito, retornará o identificador do processo especificado e definirá *termstat* para o código de resultado retornado pelo processo especificado. Caso contrário, retorna-1 e define **errno** da seguinte maneira.

|Valor|Descrição|
|-----------|-----------------|
|**ECHILD**|Não existe um processo especificado, *procHandle* é inválido ou a chamada para a API [GetExitCodeProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) ou [WaitForSingleObject](/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) falhou.|
|**EINVAL**|*ação* inválida.|

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_cwait** aguarda o encerramento da ID de processo do processo especificado que é fornecido pelo *procHandle*. O valor de *procHandle* que é passado para **_cwait** deve ser o valor retornado pela chamada para a função [_spawn](../../c-runtime-library/spawn-wspawn-functions.md) que criou o processo especificado. Se a ID do processo for encerrada antes de **_cwait** ser chamada, **_cwait** retornará imediatamente. **_cwait** pode ser usado por qualquer processo para aguardar qualquer outro processo conhecido para o qual exista um identificador válido (*procHandle*).

*termstat* aponta para um buffer em que o código de retorno do processo especificado será armazenado. O valor de *termstat* indica se o processo especificado terminou normalmente chamando a API [ExitProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess) do Windows. **ExitProcess** é chamado internamente se o processo especificado chama **Exit** ou **_exit**, retorna de **Main**ou atinge o final de **Main**. Para obter mais informações sobre o valor que é passado de volta por meio de *termstat*, consulte [GetExitCodeProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess). Se **_cwait** for chamado usando um valor **nulo** para *termstat*, o código de retorno do processo especificado não será armazenado.

O parâmetro *Action* é ignorado pelo sistema operacional Windows porque as relações pai-filho não são implementadas nesses ambientes.

A menos que *procHandle* seja-1 ou-2 (identificadores para o processo ou thread atual), o identificador será fechado. Portanto, nessa situação, não use o identificador retornado.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_cwait**|\<process.h>|\<errno.h>|

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
   int     nPid;
   char    name[40];
} process[4] = { { 0, "Ann" }, { 0, "Beth" }, { 0, "Carl" }, { 0, "Dave" } };

int main( int argc, char *argv[] )
{
   int termstat, c;
   unsigned int number;

   srand( (unsigned)time( NULL ) );    // Seed randomizer

   // If no arguments, this is the calling process
   if ( argc == 1 )
   {
      // Spawn processes in numeric order
      for ( c = 0; c < 4; c++ ) {
         _flushall();
         process[c].nPid = _spawnl( _P_NOWAIT, argv[0], argv[0],
                                    process[c].name, NULL );
      }

      // Wait for randomly specified process, and respond when done
      c = getrandom( 0, 3 );
      printf( "Come here, %s.\n", process[c].name );
      _cwait( &termstat, process[c].nPid, _WAIT_CHILD );
      printf( "Thank you, %s.\n", process[c].name );

   }
   // If there are arguments, this must be a spawned process
   else
   {
      // Delay for a period that's determined by process number
      Sleep( (argv[1][0] - 'A' + 1) * 1000L );
      printf( "Hi, Dad. It's %s.\n", argv[1] );
   }
}
```

```Output
Hi, Dad. It's Ann.
Come here, Ann.
Thank you, Ann.
Hi, Dad. It's Beth.
Hi, Dad. It's Carl.
Hi, Dad. It's Dave.
```

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
