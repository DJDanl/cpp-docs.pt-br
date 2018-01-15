---
title: _execvp, _wexecvp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _execvp
- _wexecvp
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
- _execvp
- wexecvp
- _wexecvp
dev_langs: C++
helpviewer_keywords:
- _execvp function
- _wexecvp function
- wexecvp function
- execvp function
ms.assetid: a4db15df-b204-4987-be7c-de84c3414380
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 38ab921dc120fc82e05845c62dcc355167ad09c1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="execvp-wexecvp"></a>_execvp, _wexecvp
Carrega e executa novos processos filho.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _execvp(   
   const char *cmdname,  
   const char *const *argv   
);  
intptr_t _wexecvp(   
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
 Cada uma dessas funções carrega e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando e usando a variável de ambiente `PATH` para localizar o arquivo a ser executado.  
  
 As funções `_execvp` validam seus parâmetros. Se `cmdname` é um ponteiro nulo ou se `argv` é um ponteiro nulo, ponteiro para uma matriz vazia ou se a matriz contém uma cadeia de caracteres vazia como o primeiro argumento, as funções invocam o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1. Nenhum processo é inicializado.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|--------------|---------------------|---------------------|  
|`_execvp`|\<process.h>|\<errno.h>|  
|`_wexecvp`|\<process.h> ou \<wchar.h>|\<errno.h>|  
  
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