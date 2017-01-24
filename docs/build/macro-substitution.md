---
title: "Substitui&#231;&#227;o de macro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macros , NMAKE"
  - "programa NMAKE, substituição de macro"
  - "macros de substituição em NMAKE"
ms.assetid: 47465cfe-fd92-49db-aebe-7c2d7ecceb73
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Substitui&#231;&#227;o de macro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando *o macroname* é chamado, cada ocorrência *de caracteres1* em sua cadeia de caracteres de definição é substituída *por string2*.  
  
## Sintaxe  
  
```  
$(macroname:string1=string2)  
```  
  
## Comentários  
 A substituição macro é com diferenciação de maiúsculas e minúsculas e é literal; *string1* e *string2* não podem chamar macros.  Reprovação não altera a definição original.  Você pode substituir o texto em qualquer macro predefinido exceto [$$@](../build/filename-macros.md).  
  
 Nenhum espaço ou tabulação precede o dois pontos; alguns após os dois\-pontos são interpretados como o literal.  *String2* se for nulo, todas as ocorrências *de caracteres1* serão excluídas de cadeia de caracteres de definição de macro.  
  
## Consulte também  
 [Usando uma macro NMAKE](../build/using-an-nmake-macro.md)