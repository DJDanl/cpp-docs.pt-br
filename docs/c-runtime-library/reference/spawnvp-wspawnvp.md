---
title: _spawnvp, _wspawnvp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wspawnvp
- _spawnvp
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
- _wspawnvp
- _spawnvp
- wspawnvp
dev_langs: C++
helpviewer_keywords:
- wspawnvp function
- processes, creating
- _wspawnvp function
- processes, executing new
- spawnvp function
- process creation
- _spawnvp function
ms.assetid: 8d8774ec-6ad4-4680-a5aa-440cde1e0249
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 49e51ca52f92d5df73d4ea5b5259cebbbf2c5380
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="spawnvp-wspawnvp"></a>_spawnvp, _wspawnvp
Cria e executa um processo.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _spawnvp(  
   int mode,  
   const char *cmdname,  
   const char *const *argv   
);  
intptr_t _wspawnvp(  
   int mode,  
   const wchar_t *cmdname,  
   const wchar_t *const *argv   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `mode`  
 Modo de execução para chamar o processo.  
  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `argv`  
 Matriz de ponteiros para os argumentos. O argumento `argv`[0] é geralmente um ponteiro para um caminho em modo real ou o nome do programa no modo protegido, enquanto `argv`[1] a `argv`[`n`] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. O argumento `argv`[`n` +1] deve ser um ponteiro `NULL` para marcar o fim da lista de argumentos.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado de uma `_spawnvp` ou `_wspawnvp` síncrona (`_P_WAIT` especificado para `mode`) é o status de saída do novo processo. O valor retornado de uma `_spawnvp` ou `_wspawnvp` assíncrona (`_P_NOWAIT` ou `_P_NOWAITO` especificado para `mode`) é o identificador do processo. O status de saída é 0 se o processo foi encerrado normalmente. Você poderá definir o status de saída para um valor diferente de zero se o processo gerado usar especificamente um argumento diferente de zero para chamar a rotina `exit`. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Nesse caso, o parâmetro `errno` é definido com um dos valores a seguir:  
  
 `E2BIG`  
 A lista de argumentos ultrapassa 1.024 bytes.  
  
 `EINVAL`  
 O argumento `mode` é inválido.  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 `ENOEXEC`  
 O arquivo especificado não é executável ou tem um formato de arquivo executável inválido.  
  
 `ENOMEM`  
 Não há memória suficiente disponível para executar o novo processo.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções cria e executa um novo processo, passa uma matriz de ponteiros para argumentos de linha de comando e usa a variável de ambiente `PATH` para localizar o arquivo a ser executado.  
  
 Essas funções validam seus parâmetros. Se `cmdname` ou `argv` for um ponteiro nulo ou se `argv` apontar para um ponteiro nulo ou se `argv[0]` for uma cadeia de caracteres inválida, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1. Nenhum processo novo é gerado.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_spawnvp`|\<stdio.h> ou \<process.h>|  
|`_wspawnvp`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
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