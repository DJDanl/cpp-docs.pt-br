---
title: "_get_terminate | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_get_terminate"
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
  - "get_terminate"
  - "_get_terminate"
  - "__get_terminate"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __get_terminate"
  - "Função _get_terminate"
  - "Função get_terminate"
ms.assetid: c8f168c4-0ad5-4832-a522-dd1ef383c208
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_terminate
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna a rotina de conclusão a ser chamada por `terminate`.  
  
## Sintaxe  
  
```  
terminate_function _get_terminate( void );  
```  
  
## Valor de retorno  
 Retorna um ponteiro para a função registrada por [set\_terminate](../../c-runtime-library/reference/set-terminate-crt.md).  Se nenhuma função tiver sido definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_terminate`|\<eh.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas do tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [set\_unexpected](../../c-runtime-library/reference/set-unexpected-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../Topic/unexpected%20\(CRT\).md)