---
title: _execv, _wexecv | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _wexecv
- _execv
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
- _execv
- _wexecv
- wexecv
dev_langs:
- C++
helpviewer_keywords:
- _wexecv function
- _execv function
- wexecv function
- execv function
ms.assetid: 8dbaf7bc-9040-4316-a0c1-db7e866b52af
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a9520c8975d342b423bf61a1f5973a4bdabfcc37
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="execv-wexecv"></a>_execv, _wexecv
Carrega e executa novos processos filho.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _execv(   
   const char *cmdname,  
   const char *const *argv   
);  
intptr_t _wexecv(   
   const wchar_t *cmdname,  
   const wchar_t *const *argv   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `argv`  
 Matriz de ponteiros para os parâmetros.  
  
## <a name="return-value"></a>Valor de retorno  
 Se bem-sucedidas, essas funções não retornam ao processo de chamada. Um valor de retorno de -1 indica um erro, caso em que o `errno` variável global está definido.  
  
|Valor `errno`|Descrição|  
|-------------------|-----------------|  
|`E2BIG`|O espaço necessário para os argumentos e as configurações de ambiente excede 32 KB.|  
|`EACCES`|O arquivo especificado tem uma violação de compartilhamento ou de bloqueio.|  
|`EINVAL`|Parâmetro inválido.|  
|`EMFILE`|Muitos arquivos abertos (o arquivo especificado deve ser aberto para determinar se ele é executável).|  
|`ENOENT`|Arquivo ou caminho não encontrado.|  
|`ENOEXEC`|O arquivo especificado não é executável ou tem um formato inválido do arquivo executável.|  
|`ENOMEM`|Não há memória suficiente disponível para executar o novo processo. A memória disponível foi corrompida ou há um bloco inválido, indicando que o processo de chamada não foi alocado corretamente.|  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções carrega e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando.  
  
 As funções `_execv` validam seus parâmetros. Se `cmdname` é um ponteiro nulo ou se `argv` é um ponteiro nulo, ponteiro para uma matriz vazia ou se a matriz contém uma cadeia de caracteres vazia como o primeiro argumento, as funções `_execv` invocam o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1. Nenhum processo é inicializado.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|--------------|---------------------|---------------------|  
|`_execv`|\<process.h>|\<errno.h>|  
|`_wexecv`|\<process.h> ou \<wchar.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo nas [ funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_onexit, _onexit_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)   
 [system, _wsystem](../../c-runtime-library/reference/system-wsystem.md)