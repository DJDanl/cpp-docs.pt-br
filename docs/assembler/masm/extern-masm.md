---
title: "EXTERN (MASM) | Microsoft Docs"
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
  - "extern"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "EXTERN directive"
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# EXTERN (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um ou mais variáveis externas, rótulos ou símbolos chamados  *nome* cujo tipo é `type`.  
  
## Sintaxe  
  
```  
  
   EXTERN [[langtype]] name [[(altid)]] :  
type [[, [[langtype]] name [[(altid)]] :type]]...  
```  
  
## Comentários  
 O `type` pode ser  [ABS](../../assembler/masm/operator-abs.md), que importa  *nome* como uma constante.  Mesmo que  [EXTRN](../../assembler/masm/extrn.md).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)