---
title: "ML Fatal Error A1010 | Microsoft Docs"
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
  - "A1010"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A1010"
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Fatal Error A1010
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**aninhamento de bloco incomparável:**  
  
 Início de um bloco não tinha um end correspondente ou o final do bloco não tinha um início correspondente.  Uma das opções a seguir pode ser envolvida:  
  
-   Uma diretiva de alto nível, como  [.IF](../Topic/.IF.md), [.Repetir](../../assembler/masm/dot-repeat.md), ou  [.ENQUANTO](../../assembler/masm/dot-while.md).  
  
-   Uma diretiva condicional os assemblies, como  [Se](../../assembler/masm/if-masm.md),  [REPITA](../../assembler/masm/repeat.md), ou  **ENQUANTO**.  
  
-   Uma definição de estrutura ou união.  
  
-   Uma definição de procedimento.  
  
-   Definição de um segmento.  
  
-   A  [POPCONTEXT](../../assembler/masm/popcontext.md) diretiva.  
  
-   Um assembly de condicional diretriz, como um  [ELSE](../Topic/ELSE%20\(MASM\).md),  [ELSEIF](../../assembler/masm/elseif-masm.md), ou  **ENDIF**  sem uma  [se](../../assembler/masm/if-masm.md).  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)