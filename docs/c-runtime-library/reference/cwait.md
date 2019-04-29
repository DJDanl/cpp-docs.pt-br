---
title: _cwait
ms.date: 11/04/2016
apiname:
- _cwait
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
- api-ms-win-crt-process-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _cwait
helpviewer_keywords:
- cwait function
- _cwait function
ms.assetid: d9b596b5-45f4-4e03-9896-3f383cb922b8
ms.openlocfilehash: f7a49497ac71ec15261e1215bd2bbed2e49f42ab
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62288778"
---
# <a name="cwait"></a>_cwait

Aguarda até outro processo terminar.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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
Ponteiro para um buffer em que o código de resultado do processo especificado será armazenado, ou **nulo**.

*procHandle*<br/>
O identificador para o processo para aguardar (ou seja, o processo que precisa terminar antes **cwait** pode retornar).

*action*<br/>
NULL: Ignorado por aplicativos de sistema operacional Windows; para outros aplicativos: código de ação para executar em *procHandle*.

## <a name="return-value"></a>Valor de retorno

Quando o processo especificado for concluída com êxito, retorna o identificador do processo especificado e define *termstat* para o código de resultado é retornado pelo processo especificado. Caso contrário, retornará -1 e definirá **errno** da seguinte maneira.

|Valor|Descrição|
|-----------|-----------------|
|**ECHILD**|Nenhum processo especificado existe, *procHandle* é inválido ou a chamada para o [GetExitCodeProcess](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) ou [WaitForSingleObject](/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) API falhou.|
|**EINVAL**|*ação* é inválido.|

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **cwait** função aguarda o encerramento de ID do processo especificado que é fornecida pelo *procHandle*. O valor de *procHandle* que é passado para **cwait** deve ser o valor retornado pela chamada para o [spawn](../../c-runtime-library/spawn-wspawn-functions.md) função que criou o processo especificado. Se a ID do processo terminar antes **cwait** é chamado, **cwait** retorna imediatamente. **cwait** pode ser usado por qualquer processo para aguardar qualquer outro processo conhecido para o qual um identificador válido (*procHandle*) existe.

*termstat* aponta para um buffer em que o código de retorno do processo especificado será armazenado. O valor de *termstat* indica se o processo especificado terminou normalmente chamando o Windows [ExitProcess](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) API. **ExitProcess** é chamado internamente se o processo especificado chamar **sair** ou **exit**, retorna da **principal**, ou atinge o final de **principal** . Para obter mais informações sobre o valor que é passado por meio *termstat*, consulte [GetExitCodeProcess](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess). Se **cwait** é chamado usando uma **nulo** valor para *termstat*, o código de retorno do processo especificado não é armazenado.

O *ação* parâmetro é ignorado pelo sistema operacional Windows, porque as relações pai-filho não são implementadas nesses ambientes.

A menos que *procHandle* é -1 ou -2 (identificadores para o processo atual ou thread), o identificador será fechado. Portanto, nessa situação, não use o identificador retornado.

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

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
