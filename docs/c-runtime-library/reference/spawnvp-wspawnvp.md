---
title: "_spawnvp, _wspawnvp | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_wspawnvp"
  - "_spawnvp"
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
  - "_wspawnvp"
  - "_spawnvp"
  - "wspawnvp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _spawnvp"
  - "Função _wspawnvp"
  - "criação de processo"
  - "processos, criando"
  - "processos, executando novo"
  - "Função spawnvp"
  - "Função wspawnvp"
ms.assetid: 8d8774ec-6ad4-4680-a5aa-440cde1e0249
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _spawnvp, _wspawnvp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um processo e o executa.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `mode`  
 Modo de execução para o processo de chamada.  
  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `argv`  
 Matriz de ponteiros para os argumentos.  O argumento `argv`\[0\] é geralmente um ponteiro para um caminho em modo real ou o nome do programa no modo protegido, e `argv`\[1\] por meio de `argv`\[`n`\] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos.  O argumento `argv`\[`n` \+ 1\] deve ser um `NULL` ponteiro para marcar o final da lista de argumentos.  
  
## Valor de retorno  
 O valor de retorno de um síncrono `_spawnvp` ou `_wspawnvp` \(`_P_WAIT` especificado para `mode`\) é o status de saída do novo processo.  O valor de retorno de um assíncrono `_spawnvp` ou `_wspawnvp` \(`_P_NOWAIT` ou `_P_NOWAITO` especificado para `mode`\) é o identificador de processo.  O status de saída é 0 se o processo foi encerrado normalmente.  Você pode definir o status de saída para um valor diferente de zero se o processo gerado especificamente usa um argumento diferente de zero para chamar o `exit` rotina.  Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indica uma saída normal com uma anulação ou uma interrupção.  Um valor de retorno de\-1 indica um erro \(o novo processo não é iniciado\).  Nesse caso, `errno` é definido como um dos seguintes valores:  
  
 `E2BIG`  
 Lista de argumentos ultrapassa 1024 bytes.  
  
 `EINVAL`  
 `mode` argumento é inválido.  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 `ENOEXEC`  
 Arquivo especificado não é executável ou tem formato inválido do arquivo executável.  
  
 `ENOMEM`  
 Não há memória suficiente está disponível para executar o novo processo.  
  
 Para obter mais informações sobre esses e outros, códigos de retorno, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções cria um novo processo executa e passa uma matriz de ponteiros para argumentos de linha de comando e usa o `PATH` variável de ambiente para localizar o arquivo a ser executado.  
  
 Essas funções validam seus parâmetros.  Se `cmdname` ou `argv` é um ponteiro nulo, ou se `argv` aponta para um ponteiro nulo, ou `argv[0]` é uma seqüência vazia, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL`, e retornará \-1.  Nenhum processo novo é gerado.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_spawnvp`|\< stdio \> ou \< process.h \>|  
|`_wspawnvp`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Veja o exemplo [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md).  
  
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