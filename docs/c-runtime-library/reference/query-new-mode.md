---
title: "_query_new_mode | Microsoft Docs"
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
  - "_query_new_mode"
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
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "query_new_mode"
  - "_query_new_mode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _query_new_mode"
  - "modos de manipulador"
  - "Função query_new_mode"
ms.assetid: e185c5f9-b73b-4257-8eff-b47648374768
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _query_new_mode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um inteiro que indica o novo modo de manipulador definido por `_set_new_mode` para `malloc`.  
  
## Sintaxe  
  
```  
  
      int _query_new_mode(  
   void   
);  
```  
  
## Valor de retorno  
 Retorna o novo modo atual do manipulador, ou 0 ou 1, para `malloc`.  Um valor de retorno 1 indica que, falha alocar memória, `malloc` chama a nova rotina do manipulador; um valor de retorno 0 indica que não.  
  
## Comentários  
 A função C\+\+ `_query_new_mode` retorna um inteiro que indica o novo modo de manipulador que é definido pela função C\+\+ [\_set\_new\_mode](../../c-runtime-library/reference/set-new-mode.md) para [malloc](../../c-runtime-library/reference/malloc.md).  O novo modo de manipulador indica se, a falha alocar memória, `malloc` é chamar a nova rotina do manipulador conforme definido por [\_set\_new\_handler](../Topic/_set_new_handler.md).  Por padrão, `malloc` não chama a nova rotina do manipulador de falha.  Você pode usar `_set_new_mode` para substituir esse comportamento de modo que a falha `malloc` chama a nova rotina do manipulador da mesma forma que o operador de **new** faz quando não aloca memória.  Para obter mais informações, consulte as funções de [a exclusão do operador](../Topic/operator%20delete%20Function.md) e de [operador novo](../../misc/operator-new-function.md)*na referência de linguagem C\+\+*.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_query_new_mode`|\<new.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_query\_new\_handler](../../c-runtime-library/reference/query-new-handler.md)