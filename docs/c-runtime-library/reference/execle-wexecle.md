---
title: "_execle, _wexecle | Microsoft Docs"
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
  - "_execle"
  - "_wexecle"
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
  - "wexecle"
  - "_execle"
  - "_wexecle"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _execle"
  - "Função _wexecle"
  - "Função execle"
  - "Função wexecle"
ms.assetid: 75efa9c5-96b7-4e23-acab-06258901f63a
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _execle, _wexecle
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Carrega e executa o novo processo filho.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
intptr_t _execle(   
   const char *cmdname,  
   const char *arg0,  
   ... const char *argn,  
   NULL,  
   const char *const *envp   
);  
intptr_t _wexecle(   
   const wchar_t *cmdname,  
   const wchar_t *arg0,  
   ... const wchar_t *argn,  
   NULL,  
   const char *const *envp   
);  
```  
  
#### Parâmetros  
 `cmdname`  
 Caminho do arquivo a ser executado.  
  
 `arg0`, `...``argn`  
 Lista de ponteiros para os parâmetros.  
  
 `envp`  
 Matriz de ponteiros para as configurações de ambiente.  
  
## Valor de retorno  
 Se for bem\-sucedido, essas funções não retornam ao processo de chamada.  Um valor de retorno de\-1 indica um erro, caso em que o `errno` variável global é definido.  
  
|Valor `errno`|Descrição|  
|-------------------|---------------|  
|`E2BIG`|O espaço necessário para os argumentos e as configurações de ambiente excede 32 KB.|  
|`EACCES`|O arquivo especificado tem uma violação de compartilhamento ou de bloqueio.|  
|`EINVAL`|Parâmetro inválido.|  
|`EMFILE`|Muitos arquivos estão abertos.  \(O arquivo especificado deve ser aberto para determinar se é executável.\)|  
|`ENOENT`|O arquivo ou caminho não foi encontrado.|  
|`ENOEXEC`|O arquivo especificado não é executável ou tem um formato inválido do arquivo executável.|  
|`ENOMEM`|Não há memória suficiente está disponível para executar o novo processo. a memória disponível corrompida; ou um bloco inválido, que indica que o processo de chamada não foi alocado corretamente.|  
  
 Para obter mais informações sobre esses códigos de retorno, consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções carrega e executa um novo processo e passa cada argumento de linha de comando como um parâmetro separado e passa uma matriz de ponteiros para as configurações de ambiente.  
  
 As funções `_execle` validam seus parâmetros.  Se `cmdname` ou `arg0` é um ponteiro nulo ou uma cadeia de caracteres vazia, essas funções para invocar o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão \-1.  Nenhum novo processo é iniciado.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_execle`|\<process.h\>|\<errno.h\>|  
|`_wexecle`|\< process.h \> ou \< WCHAR. h \>|\<errno.h\>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Veja o exemplo [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md).  
  
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