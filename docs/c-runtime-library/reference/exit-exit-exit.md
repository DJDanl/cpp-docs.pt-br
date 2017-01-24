---
title: "sair, Exit, Exit | Microsoft Docs"
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
  - "_exit"
  - "exit"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "Exit"
  - "_exit"
  - "process/exit"
  - "process/_Exit"
  - "stdlib/exit"
  - "stdlib/_Exit"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função exit"
  - "Função _exit"
  - "encerrando processos"
  - "chamadas de função, encerrando"
  - "finalização, do processo de chamada"
ms.assetid: b1501fa6-27c2-478c-9e93-cc4fd802a01f
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# sair, Exit, Exit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encerra o processo de chamada. O `exit` função termina após a limpeza; `_exit` e `_Exit` encerrá\-lo imediatamente.  
  
> [!NOTE]
>  Não use esse método para desligar um aplicativo Universal Windows Platform \(UWP\) ou um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, exceto em teste ou cenários de depuração. Formas de programação ou da interface do usuário para fechar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo não são permitidos. Para obter mais informações sobre aplicativos do Windows 8 e 8.1, consulte [ciclo de vida do aplicativo](http://go.microsoft.com/fwlink/?LinkId=262853). Para obter mais informações sobre aplicativos do Windows 10, consulte [guias de instruções para aplicativos do Windows 10](http://go.microsoft.com/fwlink/p/?linkid=619133).  
  
## Sintaxe  
  
```  
void exit(   
   int const status   
);  
void _Exit(   
   int const status   
);  
void _exit(   
   int const status   
);  
```  
  
#### Parâmetros  
 `status`  
 Código de status de saída.  
  
## Comentários  
 O `exit`, `_Exit` e `_exit` funções encerrar o processo de chamada. O `exit` função chama destruidores para objetos de thread local, em seguida, chama — na ordem do último a entrar, primeiro a sair \(UEPS\) — as funções que são registradas por `atexit` e `_onexit`, e, em seguida, libera todos os buffers de arquivo antes de ele encerra o processo. O `_Exit` e `_exit` funções terminar o processo sem destruir objetos de thread local ou processamento `atexit` ou `_onexit` funções e sem eliminação buffers de fluxo.  
  
 Embora o `exit`, `_Exit` e `_exit` chamadas não retornam um valor, o byte de ordem inferior de `status` é disponibilizada para o ambiente de host ou o processo de chamada em espera, se houver, depois que o processo é encerrado. Normalmente, os conjuntos de chamador de `status` valor como 0 para indicar uma saída normal ou para algum outro valor para indicar um erro. O `status` valor está disponível para o comando em lotes do sistema operacional `ERRORLEVEL` e é representado por uma das duas constantes: `EXIT_SUCCESS`, que representa um valor de 0, ou `EXIT_FAILURE`, que representa um valor de 1.  
  
 O `exit`, `_Exit`, `_exit`, `quick_exit`, `_cexit`, e `_c_exit` funções se comportam da seguinte maneira.  
  
|Função|Descrição|  
|------------|---------------|  
|`exit`|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`_Exit`|Executa os procedimentos de encerramento de biblioteca C mínimos, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`_exit`|Executa os procedimentos de encerramento de biblioteca C mínimos, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`quick_exit`|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`_cexit`|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|  
|`_c_exit`|Executa os procedimentos de encerramento de biblioteca C mínimo e retorna ao chamador. Não encerra o processo.|  
  
 Quando você chama o `exit`,  `_Exit` ou `_exit` função, os destruidores de quaisquer objetos temporários ou automáticos que existem no momento da chamada não sejam chamados. Um objeto automático é definido em uma função onde o objeto não é declarado como estático. Um objeto temporário é um objeto que é criado pelo compilador. Para destruir um objeto automática antes de chamar `exit`, `_Exit`, ou `_exit`, explicitamente chamar o destruidor do objeto, da seguinte maneira:  
  
```  
myObject.myClass::~myClass();  
```  
  
 Não use `DLL_PROCESS_ATTACH` chamar `exit` de `DllMain`. Se desejar sair do `DLLMain` funcionar, retorne `FALSE` de `DLL_PROCESS_ATTACH`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`exit`, `_Exit`, `_exit`|\< process.h \> ou \< stdlib. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_exit.c // This program returns an exit code of 1. The // error code could be tested in a batch file. #include <stdlib.h> int main( void ) { exit( 1 ); }  
```  
  
## Equivalência do .NET Framework  
 [System::Diagnostics::Process::kill](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.kill.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [\_cexit, \_c\_exit](../../c-runtime-library/reference/cexit-c-exit.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [\_onexit, \_onexit\_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [quick\_exit](../../c-runtime-library/reference/quick-exit1.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [system, \_wsystem](../../c-runtime-library/reference/system-wsystem.md)