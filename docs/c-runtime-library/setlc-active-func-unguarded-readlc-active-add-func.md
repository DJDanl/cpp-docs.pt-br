---
title: "___setlc_active_func, ___unguarded_readlc_active_add_func | Microsoft Docs"
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
  - "___setlc_active_func"
  - "___unguarded_readlc_active_add_func"
apilocation: 
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
  - "msvcrt.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
f1_keywords: 
  - "___unguarded_readlc_active_add_func"
  - "___setlc_active_func"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "___setlc_active_func"
  - "___unguarded_readlc_active_add_func"
ms.assetid: 605ec4e3-81e5-4ece-935a-f434768cc702
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ___setlc_active_func, ___unguarded_readlc_active_add_func
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

OBSOLETO.  O CRT exporta essas funções internas somente para preservar a compatibilidade binária.  
  
## Sintaxe  
  
```cpp  
int ___setlc_active_func(void); int * ___unguarded_readlc_active_add_func(void);  
```  
  
## Valor de retorno  
 O valor retornado não é significativo.  
  
## Comentários  
 Embora as funções CRT internas `___setlc_active_func` e `___unguarded_readlc_active_add_func` sejam obsoletas e não sejam mais utilizadas, elas são exportadas pela biblioteca do CRT para preservar a compatibilidade binária.  O propósito original de `___setlc_active_func` era retornar o número de chamadas ativas no momento para a função `setlocale`.  O propósito original de `___unguarded_readlc_active_add_func` era retornar o número de funções que faziam referência ao código de idioma sem bloqueá\-lo.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`___setlc_active_func`, `___unguarded_readlc_active_add_func`|nenhum|  
  
## Consulte também  
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)