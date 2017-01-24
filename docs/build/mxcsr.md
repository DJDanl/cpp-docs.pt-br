---
title: "MxCsr | Microsoft Docs"
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
ms.assetid: 4f3c229d-0862-4733-acc7-9ed7a0b870ce
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# MxCsr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O estado do registro também inclui MxCsr.  A convenção de chamada divide esse registro em uma parte temporária e uma parte permanente.  A parte temporária consiste nos sinalizadores de status 6, MXCSR \[\] 0:5, quando o restante do registro, MXCSR \[\] 6:15, é considerado permanente.  
  
 A parte permanente é definida para os seguintes valores padrão no início da execução do programa:  
  
```  
MXCSR[6]         : Denormals are zeros - 0  
MXCSR[7:12]      : Exception masks all 1's (all exceptions masked)  
MXCSR[13:14]   : Rounding  control - 0 (round to nearest)  
MXCSR[15]      : Flush to zero for masked underflow - 0 (off)  
```  
  
 Um receptor que modifique alguns dos campos permanentes dentro de MXCSR deve restaurar\-lo antes de retornar ao chamador.  Além disso, um chamador que altere qualquer um dos campos deve restaurar\-los para seus valores padrão antes de chamar um receptor a menos que acordo pelo receptor esperar os valores alterados.  
  
 Há duas exceções as regras em relação ao não volatilidade dos sinalizadores de controle:  
  
-   Funções onde o objetivo documentada de função determinada é alterar os sinalizadores permanentes de MxCsr.  
  
-   Quando provavelmente está correto que a violação dessas regras resulta em programas que se comporta\/significa\-se o mesmo que um programa onde essas regras não sejam violadas, por exemplo, com a análise de inteiro\- programa.  
  
 Nenhuma suposição pode ser feita sobre o estado da parte temporária de MXCSR através de um limite de função, a menos que especificamente descrito na documentação de uma função.  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)