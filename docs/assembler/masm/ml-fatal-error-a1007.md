---
title: "ML Fatal Error A1007 | Microsoft Docs"
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
  - "A1007"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A1007"
ms.assetid: bcf9c826-beb3-4e93-91fe-1ffd34995fbf
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Fatal Error A1007
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**nível de aninhamento muito profundo**  
  
 O montador atingiu o limite de aninhamento.  O limite é de 20 níveis, exceto onde indicado o contrário.  
  
 Um dos procedimentos a seguir foi profundamente aninhado:  
  
-   Uma diretiva de alto nível, como  [.IF](../Topic/.IF.md), [.Repetir](../../assembler/masm/dot-repeat.md), ou  [.ENQUANTO](../../assembler/masm/dot-while.md).  
  
-   Uma definição de estrutura.  
  
-   Uma diretiva de assembly de condicional.  
  
-   Uma definição de procedimento.  
  
-   A  [PUSHCONTEXT](../../assembler/masm/pushcontext.md) diretiva \(o limite é de 10\).  
  
-   Definição de um segmento.  
  
-   Um arquivo de inclusão.  
  
-   Uma macro.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)