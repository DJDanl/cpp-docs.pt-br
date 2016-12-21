---
title: "__dllonexit | Microsoft Docs"
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
  - "__dllonexit"
apilocation: 
  - "msvcrt.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
  - "msvcr80.dll"
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcr120_clr0400.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__dllonexit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__dllonexit"
ms.assetid: 708f2ceb-f95c-46b0-a58d-d68b3fa36f12
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __dllonexit
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Registra uma rotina a ser chamada no momento da saída.  
  
## Sintaxe  
  
```  
_onexit_t __dllonexit(  
   _onexit_t func,  
   _PVFV **  pbegin,   
   _PVFV **  pend   
   )  
```  
  
#### Parâmetros  
 `func`  
 Ponteiro para uma função a ser executada na saída.  
  
 `pbegin`  
 O ponteiro para uma variável que aponta para o início de uma lista de funções para realizar desanexar.  
  
 `pend`  
 O ponteiro para a variável que aponta para a fim de uma lista de funções para realizar desanexar.  
  
## Valor de Retorno  
 Se tiver êxito, um ponteiro para a função do usuário.  Caso contrário, um ponteiro NULL.  
  
## Comentários  
 A função de `__dllonexit` é análoga à função de [\_onexit](../c-runtime-library/reference/onexit-onexit-m.md) exceto que as variáveis globais usados por essa função não são visíveis a esta rotina.  Em vez de variáveis globais, essa função usa os parâmetros de `pbegin` e de `pend` .  
  
 As funções de `_onexit` e de `atexit` em uma DLL vinculado com MSVCRT.LIB devem manter sua própria lista de atexit\/\_onexit.  Esta rotina é o trabalhador que obtém chamado por tais DLL.  
  
 O tipo de `_PVFV` é definido como `typedef void (__cdecl *_PVFV)(void)`.  
  
## Requisitos  
  
|Rotina|Arquivo necessário|  
|------------|------------------------|  
|\_\_dllonexit|onexit.c|  
  
## Consulte também  
 [\_onexit, \_onexit\_m](../c-runtime-library/reference/onexit-onexit-m.md)