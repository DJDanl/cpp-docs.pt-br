---
title: _cwait | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
helpviewer_keywords:
- cwait function
- _cwait function
ms.assetid: d9b596b5-45f4-4e03-9896-3f383cb922b8
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 9f58035cc3e3159dc8bb54860e3c8e7454f35b51
ms.lasthandoff: 02/25/2017

---
# <a name="cwait"></a>_cwait
Aguarda até outro processo terminar.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _cwait(   
   int *termstat,  
   intptr_t procHandle,  
   int action   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `termstat`  
 Ponteiro para um buffer em que o código de resultado do processo especificado será armazenado ou NULL.  
  
 `procHandle`  
 O identificador para o processo a esperar (ou seja, o processo que precisa terminar antes de `_cwait` poder retornar).  
  
 `action`  
 NULL: Ignorado por aplicativos do sistema operacional Windows; para outros aplicativos: código de ação a realizar no `procHandle`.  
  
## <a name="return-value"></a>Valor de retorno  
 Quando o processo especificado é concluído com sucesso, retorna o identificador do processo especificado e define `termstat` para o código de resultado retornado pelo processo especificado. Caso contrário, retorna –1 e define `errno` da seguinte maneira.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`ECHILD`|Não há nenhum processo especificado existente, `procHandle` é inválido ou a chamada à API [GetExitCodeProcess](http://msdn.microsoft.com/library/windows/desktop/ms683189.aspx) ou [WaitForSingleObject](http://msdn.microsoft.com/library/windows/desktop/ms687032.aspx) falhou.|  
|`EINVAL`|`action` é inválido.|  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_cwait` espera o encerramento de ID do processo especificado fornecido por `procHandle`. O valor de `procHandle` passado para `_cwait` deve ser o valor retornado pela chamada à função [_spawn](../../c-runtime-library/spawn-wspawn-functions.md) que criou o processo especificado. Se a ID do processo terminar antes de `_cwait` ser chamada, `_cwait` retorna imediatamente. `_cwait` pode ser usado por qualquer processo para esperar qualquer outro processo conhecido para o qual exista um identificador válido (`procHandle`).  
  
 `termstat` aponta para um buffer em que o código de retorno do processo especificado será armazenado. O valor de `termstat` indica se o processo especificado foi encerrado normalmente com a chamada à API [ExitProcess](http://msdn.microsoft.com/library/windows/desktop/ms682658.aspx) do Windows. `ExitProcess` é chamado internamente se o processo especificado chamar `exit` ou `_exit`, retornar de `main` ou atingir o fim de `main`. Para obter mais informações sobre o valor passado de volta por meio de `termstat`, consulte [GetExitCodeProcess](http://msdn.microsoft.com/library/windows/desktop/ms683189.aspx). Se `_cwait` for chamado usando um valor NULL para `termstat`, o código de retorno para o processo especificado não é armazenado.  
  
 O parâmetro `action` é ignorado pelo sistema operacional Windows porque os relacionamentos entre pai e filho não são implementados nesses ambientes.  
  
 A menos que `procHandle` seja -1 ou -2 (identificadores para o processo ou thread atual), o identificador será fechado. Portanto, nessa situação, não use o identificador retornado.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_cwait`|\<process.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
  
      // crt_cwait.c  
// compile with: /c  
// This program launches several processes and waits  
// for a specified process to finish.  
//  
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
   if( argc == 1 )  
   {  
      // Spawn processes in numeric order  
      for( c = 0; c < 4; c++ ){  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::Diagnostics::Process::WaitForExit](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.waitforexit.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)
