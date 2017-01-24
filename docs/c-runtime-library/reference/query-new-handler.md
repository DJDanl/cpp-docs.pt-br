---
title: "_query_new_handler | Microsoft Docs"
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
  - "_query_new_handler"
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
  - "_query_new_handler"
  - "query_new_handler"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _query_new_handler"
  - "tratamento de erros"
  - "rotinas de manipulador"
  - "Função query_new_handler"
ms.assetid: 9a84b5c3-fe33-4c01-83a0-be87dc3ec518
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _query_new_handler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o endereço da nova rotina atual do manipulador.  
  
## Sintaxe  
  
```  
  
      _PNH _query_new_handler(  
   void   
);  
```  
  
## Valor de retorno  
 Retorna o endereço da nova rotina atual do manipulador conforme definido por `_set_new_handler`.  
  
## Comentários  
 A função C\+\+ `_query_new_handler` retorna o endereço do conjunto atual da função manipulação de exceções gerais pela função C\+\+ [\_set\_new\_handler](../Topic/_set_new_handler.md) .  `_set_new_handler` é usado para especificar uma função manipulação de exceções gerais que é garantir o controle se o operador de **new** não aloca memória.  Para obter mais informações, consulte auditorias das funções de [operador novo](../../misc/operator-new-function.md) e de [a exclusão do operador](../Topic/operator%20delete%20Function.md)*na referência de linguagem C\+\+*.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_query_new_handler`|\<new.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [free](../../c-runtime-library/reference/free.md)