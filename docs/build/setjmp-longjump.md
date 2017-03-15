---
title: "setjmp/longjump | Microsoft Docs"
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
ms.assetid: b0e21902-095d-4198-8f9a-b6326525721a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# setjmp/longjump
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você incluir setjmpex.h ou setjmp.h, todas as chamadas a [setjmp](../c-runtime-library/reference/setjmp.md) ou a [longjmp](../c-runtime-library/reference/longjmp.md) resultarão em um desenrolamento que invoca destruidores e chamam finally.  Isso difere de x, onde incluindo resultados de setjmp.h finalmente nas cláusulas e os destruidores que não estão sendo chamado.  
  
 Uma chamada para `setjmp` preserva o ponteiro de pilha atual, registros permanentes, e os registros de MxCsr.  Chamadas para o retorno de `longjmp` para o site e a redefinições as mais recentes de chamada de `setjmp` o ponteiro de pilha, registros permanentes, e os registros de MxCsr, de volta para o estado como mantido por chamada mais recente de `setjmp` .  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)