---
title: "__RTDynamicCast | Microsoft Docs"
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
  - "__RTDynamicCast"
apilocation: 
  - "msvcr90.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
  - "msvcrt.dll"
  - "msvcr100.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__RTDynamicCast"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__RTDynamicCast"
ms.assetid: 56aa2d7a-aa47-46ef-830d-e37175611239
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __RTDynamicCast
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Implementação de tempo de execução do operador de [dynamic\_cast](../cpp/dynamic-cast-operator.md) .  
  
## Sintaxe  
  
```cpp  
PVOID __RTDynamicCast (  
   PVOID inptr,   
   LONG VfDelta,  
   PVOID SrcType,  
   PVOID TargetType,   
   BOOL isReference  
   ) throw(...)  
```  
  
#### Parâmetros  
 `inptr`  
 Ponteiro para um objeto polimórfica.  
  
 `VfDelta`  
 Deslocamento do ponteiro virtual da função no objeto.  
  
 `SrcType`  
 Tipo estático de objeto apontado pelo parâmetro de `inptr` .  
  
 `TargetType`  
 Resultado pretendido de conversão.  
  
 `isReference`  
 `true` se a entrada for uma referência; `false` se a entrada é um ponteiro.  
  
## Valor de Retorno  
 Ponteiro para o subobjeto apropriado, se bem\-sucedido; caso contrário, NULL.  
  
## Exceções  
 `bad_cast()` se a entrada a `dynamic_cast<>` é uma referência e a conversão falha.  
  
## Comentários  
 Converte `inptr` a um objeto do tipo `TargetType`.  O tipo de `inptr` deve ser um ponteiro se `TargetType` é um ponteiro, ou um valor l\- se `TargetType` é uma referência.  `TargetType` deve ser um ponteiro ou uma referência a um tipo previamente definido da classe, ou a um ponteiro nulo.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|\_\_RTDynamicCast|rtti.h|