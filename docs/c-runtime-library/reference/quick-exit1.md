---
title: "quick_exit | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "quick_exit"
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
  - "quick_exit"
  - "process/quick_exit"
  - "stdlib/quick_exit"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função quick_exit"
ms.assetid: ecfbdae6-01c4-45fa-aaeb-b368e1de2a9c
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# quick_exit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Causa o encerramento de programa normal ocorra.  
  
## Sintaxe  
  
```  
__declspec(noreturn) void quick_exit(  
    int status  
);  
```  
  
#### Parâmetros  
 status  
 O código de status para retornar para o ambiente de host.  
  
## Valor de retorno  
 O `quick_exit` função não pode retornar a seu chamador.  
  
## Comentários  
 O `quick_exit` função causa o encerramento de programa normal. Ele chama nenhuma função registradas por `atexit`, `_onexit` ou sinalizar manipuladores registrados pelo `signal` função. Comportamento é indefinido se `quick_exit` é chamado mais de depois, ou se o `exit` também é chamada de função.  
  
 O `quick_exit` chamadas de função, no último a entrar, primeiro a sair \(UEPS\) ordem, as funções registradas pelo `at_quick_exit`, exceto para essas funções já chamadas quando a função foi registrada.  Comportamento é indefinido se um [longjmp](../../c-runtime-library/reference/longjmp.md) chamada é feita durante uma chamada para uma função registrada que encerra a chamada para a função.  
  
 Depois de tem sido chamadas as funções registradas, `quick_exit` invoca `_Exit` usando o `status` valor para retornar o controle para o ambiente de host.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`quick_exit`|\< process.h \> ou \< stdlib. h \>|  
  
 Para obter mais informações sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_onexit, \_onexit\_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [system, \_wsystem](../../c-runtime-library/reference/system-wsystem.md)