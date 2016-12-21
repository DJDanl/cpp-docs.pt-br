---
title: "push_macro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc-pragma.push_macro"
  - "push_macro_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragmas, push_macro"
  - "push_macro (pragma)"
ms.assetid: ac89efc9-afd1-4dfe-bfd1-497229b3e81d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# push_macro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Salva o valor da macro *macro\_name* na parte superior da pilha dessa macro.  
  
## Sintaxe  
  
```  
  
#pragma push_macro("  
macro_name  
")  
  
```  
  
## Comentários  
 Você pode recuperar o valor de *macro\_name* com **pop\_macro**.  
  
 Consulte [pop\_macro](../Topic/pop_macro.md) para obter um exemplo.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)