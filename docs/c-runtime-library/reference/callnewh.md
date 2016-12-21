---
title: "_callnewh | Microsoft Docs"
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
  - "_callnewh"
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
  - "_callnewh"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_callnewh"
ms.assetid: 4dcb73e9-6384-4d12-a973-a8807d4de7a8
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _callnewh
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chama *o manipulador novo*atualmente instalado.  
  
## Sintaxe  
  
```cpp  
int _callnewh(  
   size_t size  
   )  
  
```  
  
#### Parâmetros  
 `size`  
 A quantidade de memória que [novo operador](../../cpp/new-operator-cpp.md) tentou atribuir.  
  
## Valor de Retorno  
  
|Valor|Descrição|  
|-----------|---------------|  
|0|Falha: Ou nenhum novo manipulador está instalado ou nenhum novo manipulador está ativa.|  
|1|Êxito: O novo manipulador é instalado e ativa.  A alocação de memória pode ser repetida.|  
  
## Exceções  
 Essa função gerará [bad\_alloc](../../standard-library/bad-alloc-class.md) se *o novo manipulador* não pode ser localizado.  
  
## Comentários  
 *O novo manipulador* é chamado se [novo operador](../../cpp/new-operator-cpp.md) não atribuir com êxito a memória.  O novo manipulador pode iniciar em qualquer ação apropriada, como liberar memória de forma que as alocações subsequentes sucedessem.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|\_callnewh|internal.h|  
  
## Consulte também  
 [\_set\_new\_handler](../Topic/_set_new_handler.md)   
 [\_set\_new\_mode](../../c-runtime-library/reference/set-new-mode.md)