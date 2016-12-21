---
title: "_execlp, _wexeclp | Microsoft Docs"
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
  - "_wexeclp"
  - "_execlp"
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
  - "_wexeclp"
  - "wexeclp"
  - "_execlp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _execlp"
  - "Função _wexeclp"
  - "Função execlp"
  - "Função wexeclp"
ms.assetid: 7b179163-4bcd-4d6a-8baf-68f886791928
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _execlp, _wexeclp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Carrega e executa novos processos filho.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
intptr_t _execlp(   
   const char *cmdname,  
   const char *arg0,  
   ... const char *argn,  
   NULL   
);  
intptr_t _wexeclp(   
   const wchar_t *cmdname,  
   const wchar_t *arg0,  
   ... const wchar_t *argn,  
   NULL   
);  
```  
  
#### Parâmetros  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `arg0`, `...``argn`  
 Lista dos ponteiros dos parâmetros.  
  
## Valor de retorno  
 Se bem\-sucedidas, essas funções não retornarão ao processo de chamada.  Um valor de retorno de –1 indica um erro, caso em que a variável global `errno` é definida.  
  
|Valor `errno`|Descrição|  
|-------------------|---------------|  
|`E2BIG`|O espaço necessário para os argumentos e as configurações de ambiente excedem 32 KB.|  
|`EACCES`|O arquivo especificado tem uma violação de bloqueio ou compartilhamento.|  
|`EINVAL`|Parâmetro inválido.|  
|`EMFILE`|Muitos arquivos abertos \(o arquivo especificado deve ser aberto para determinar se ele é executável.\)|  
|`ENOENT`|Arquivo ou caminho não encontrado.|  
|`ENOEXEC`|O arquivo especificado não é executável ou tem um formato de arquivo executável inválido.|  
|`ENOMEM`|Não há memória suficiente disponível para executar o novo processo; a memória disponível foi corrompida; ou existe um bloco inválido, indicando que o processo de chamada não foi alocado adequadamente.|  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções carrega e executa um novo processo, passando cada argumento de linha de comando como um parâmetro separado usando a variável de ambiente `PATH` para localizar o arquivo a ser executado.  
  
 As funções de `_execlp` validam seus parâmetros.  Se `cmdname` ou `arg0` for um ponteiro nulo ou uma cadeia de caracteres vazia, essas funções chamarão o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão \-1.  Nenhum novo processo é iniciado.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_execlp`|\<process.h\>|\<errno.h\>|  
|`_wexeclp`|\<process.h\> ou \<wchar.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Consulte o exemplo em [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md).  
  
## Equivalência do .NET Framework  
  
-   [Classe System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx)  
  
-   [Classe System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_onexit, \_onexit\_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [system, \_wsystem](../../c-runtime-library/reference/system-wsystem.md)