---
title: "C3556 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3556"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3556"
ms.assetid: 9b002dcc-494e-414f-9587-20c2a0a39333
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3556 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'expression': argumento incorreto para 'decltype'  
  
 O compilador não pode deduzir o tipo da expressão que é o argumento para o `decltype(``expression``)` especificador de tipo. No exemplo de código a seguir, o compilador não é possível deduzir o tipo do `myFunction` argumento porque `myFunction` está sobrecarregado.  
  
```  
void myFunction(); void myFunction(int); decltype(myFunction); // C3556  
```