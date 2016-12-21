---
title: "_CrtGetReportHook | Microsoft Docs"
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
  - "_CrtGetReportHook"
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
  - "CrtGetReportHook"
  - "_CrtGetReportHook"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função CrtGetReportHook"
  - "Função _CrtGetReportHook"
ms.assetid: 922758ed-7edd-4359-9c92-0535192dc11a
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtGetReportHook
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a função definida pelo cliente de relatório para enganchá\-la em tempo de execução C para o processo de relatório de depuração \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
_CRT_REPORT_HOOK _CrtGetReportHook( void );  
```  
  
## Valor de retorno  
 Retorna a função definida pelo cliente atual do relatório.  
  
## Comentários  
 `_CrtGetReportHook` permite que um aplicativo recupere a função atual do processo de relatório da biblioteca de depuração de tempo de execução C.  
  
 Para obter mais informações sobre como usar outras funções gancho\- capazes de tempo de execução e de escrever suas próprias funções definidas pelo cliente de gancho, consulte [Gravação da função de gancho de depuração](../Topic/Debug%20Hook%20Function%20Writing.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtGetReportHook`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Exemplo  
 Para obter um exemplo de como usar `_CrtSetReportHook`, consulte [relatório](http://msdn.microsoft.com/pt-br/f6e08c30-6bd9-459a-830a-56deec0d2051).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_CrtSetReportHook](../../c-runtime-library/reference/crtsetreporthook.md)