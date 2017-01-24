---
title: "_spawnve, _wspawnve | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_spawnve"
  - "_wspawnve"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-process-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "wspawnve"
  - "_spawnve"
  - "_wspawnve"
  - "spawnve"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _spawnve"
  - "Função _wspawnve"
  - "criação de processo"
  - "processos, criando"
  - "processos, executando novo"
  - "Função spawnve"
  - "Função wspawnve"
ms.assetid: 26d1713d-b551-4f21-a07b-e9891a2ae6cf
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _spawnve, _wspawnve
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria e executa um novo processo.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
intptr_t _spawnve(  
   int mode,  
   const char *cmdname,  
   const char *const *argv,  
   const char *const *envp   
);  
intptr_t _wspawnve(  
   int mode,  
   const wchar_t *cmdname,  
   const wchar_t *const *argv,  
   const wchar_t *const *envp   
);  
```  
  
#### Parâmetros  
 `mode`  
 Modo de execução para um processo de chamada.  
  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `argv`  
 Matriz de ponteiros para argumentos.  O argumento `argv`\[0\] é geralmente um ponteiro para um caminho no modo real ou para o nome do programa no modo protegido, e `argv`\[1\] em `argv`\[`n`\] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos.  O argumento `argv`\[`n` \+1\] deve ser um ponteiro `NULL` para marcar o fim da lista de argumentos.  
  
 `envp`  
 Matriz de ponteiros para configurações de ambiente.  
  
## Valor de retorno  
 O valor de retorno de um `_spawnve` síncrono ou `_wspawnve` \(`_P_WAIT` especificado para `mode`\) é o status de saída do novo processo.  O valor de retorno de um `_spawnve` assíncrono ou `_wspawnve` \(`_P_NOWAIT` ou `_P_NOWAITO` especificado para `mode`\) é o identificador de processo.  O status de saída será 0 se o processo foi encerrado normalmente.  Você poderá definir o status de saída para um valor diferente de zero se o processo gerado chamar especificamente a rotina `exit` com um argumento diferente de zero.  Se o novo processo não definiu explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção.  Um valor de retorno de – 1 indica um erro \(o novo processo não é iniciado\).  Nesse caso, `errno` é definido para um dos valores a seguir.  
  
 `E2BIG`  
 A lista de argumento excede 1024 bytes.  
  
 `EINVAL`  
 O argumento `mode` é inválido.  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 `ENOEXEC`  
 O arquivo especificado não é executável ou tem um formato de arquivo executável inválido.  
  
 `ENOMEM`  
 Memória insuficiente disponível para executar o novo processo.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções cria e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando e uma matriz de ponteiros para configurações de ambiente.  
  
 Essas funções validam seus parâmetros.  Se `cmdname` ou `argv` for um ponteiro nulo, ou se `argv` apontar para o ponteiro nulo, ou se `argv[0]` for uma cadeia de caracteres vazia, o manipulador de parâmetro inválido será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão \-1.  Nenhum novo processo é gerado.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_spawnve`|\<stdio.h\> ou \<process.h\>|  
|`_wspawnve`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Consulte o exemplo em [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md).  
  
## Equivalência do .NET Framework  
  
-   [Classe System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx)  
  
-   [Classe System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_flushall](../../c-runtime-library/reference/flushall.md)   
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [\_onexit, \_onexit\_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [\_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [system, \_wsystem](../../c-runtime-library/reference/system-wsystem.md)