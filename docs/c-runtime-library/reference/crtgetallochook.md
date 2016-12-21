---
title: "_CrtGetAllocHook | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CrtGetAllocHook"
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
apitype: "DLLExport"
f1_keywords: 
  - "CrtGetAllocHook"
  - "_CrtGetAllocHook"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtGetAllocHook"
  - "Função CrtGetAllocHook"
ms.assetid: 036acf7c-547a-4b3f-a636-80451070d7ed
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtGetAllocHook
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a função de alocação definida pelo cliente atual para conectar no processo de alocação de memória de depuração de tempo de execução C \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
_CRT_ALLOC_HOOK _CrtGetAllocHook( void );  
```  
  
## Valor de retorno  
 Retorna a função definida no momento de gancho de alocação.  
  
## Comentários  
 `_CrtGetAllocHook` recupera a função definida pelo cliente atual de gancho de aplicativo para o processo de alocação de memória da biblioteca de depuração de tempo de execução C.  
  
 Para obter mais informações sobre como usar outras funções gancho\- capazes de tempo de execução e de escrever suas próprias funções definidas pelo cliente de gancho, consulte [Gravação da função de gancho de depuração](../Topic/Debug%20Hook%20Function%20Writing.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtGetAllocHook`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_CrtSetAllocHook](../Topic/_CrtSetAllocHook.md)