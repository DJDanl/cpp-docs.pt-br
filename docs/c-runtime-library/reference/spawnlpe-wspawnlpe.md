---
title: _spawnlpe, _wspawnlpe | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _spawnlpe
- _wspawnlpe
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
- spawnlpe
- _wspawnlpe
- _spawnlpe
- wspawnlpe
dev_langs:
- C++
helpviewer_keywords:
- _wspawnlpe function
- wspawnlpe function
- processes, creating
- spawnlpe function
- _spawnlpe function
- processes, executing new
- process creation
ms.assetid: e171ebfa-70e7-4c44-8331-2a291fc17bd6
caps.latest.revision: 18
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 9831f7056ef91f64bba54740fbf7a372beb8f335
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="spawnlpe-wspawnlpe"></a>_spawnlpe, _wspawnlpe
Cria e executa um novo processo.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _spawnlpe(  
   int mode,  
   const char *cmdname,  
   const char *arg0,  
   const char *arg1,  
   ... const char *argn,  
   NULL,  
   const char *const *envp   
);  
intptr_t _wspawnlpe(  
   int mode,  
   const wchar_t *cmdname,  
   const wchar_t *arg0,  
   const wchar_t *arg1,  
   ... const wchar_t *argn,  
   NULL,  
   const wchar_t *const *envp   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `mode`  
 Modo de execução do processo de chamada.  
  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `arg0, arg1, ... argn`  
 Lista de ponteiros para os argumentos. O argumento `arg0` costuma ser um ponteiro para `cmdname`. Os argumentos de `arg1` a `argn` são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. Após `argn`, deve haver um ponteiro `NULL` para marcar o fim da lista de argumentos.  
  
 `envp`  
 Matriz de ponteiros para as configurações de ambiente.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado de uma `_spawnlpe` ou `_wspawnlpe` síncrona (`_P_WAIT` especificado para `mode`) é o status de saída do novo processo. O valor retornado de uma `_spawnlpe` ou `_wspawnlpe` assíncrona (`_P_NOWAIT` ou `_P_NOWAITO` especificado para `mode`) é o identificador do processo. O status de saída é 0 se o processo foi encerrado normalmente. Você poderá definir o status de saída para um valor diferente de zero se o processo gerado usar especificamente um argumento diferente de zero para chamar a rotina `exit`. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal causada por uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Nesse caso, o parâmetro `errno` é definido com um dos valores a seguir.  
  
 `E2BIG`  
 A lista de argumentos ultrapassa 1.024 bytes.  
  
 `EINVAL`  
O argumento  `mode` é inválido.  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 `ENOEXEC`  
 O arquivo especificado não é executável ou tem um formato inválido do arquivo executável.  
  
 `ENOMEM`  
 Não há memória suficiente disponível para executar o novo processo.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções cria e executa um novo processo e passa cada argumento de linha de comando como um parâmetro separado e passa uma matriz de ponteiros para as configurações de ambiente. Essas funções usam a variável de ambiente `PATH` para localizar o arquivo a ser executado.  
  
 Essas funções validam seus parâmetros. Se `cmdname` ou `arg0` for uma cadeia de caracteres ou um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1. Nenhum processo novo é gerado.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_spawnlpe`|\<process.h>|  
|`_wspawnlpe`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo em [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_flushall](../../c-runtime-library/reference/flushall.md)   
 [_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [_onexit, _onexit_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [system, _wsystem](../../c-runtime-library/reference/system-wsystem.md)
