---
title: "A.5   Using the critical Directive | Microsoft Docs"
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
ms.assetid: 14423018-25b9-4f98-92f2-34c9b0ac0ce0
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.5   Using the critical Directive
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O exemplo a seguir inclui vários `critical` diretivas \([seção 2.6.2](../../parallel/openmp/2-6-2-critical-construct.md) na página 18\).  O exemplo ilustra um modelo de enfileiramento de mensagens em que uma tarefa é desenfileirada e trabalhada.  Para proteção contra vários threads desenfileiramento a mesma tarefa, a operação de dequeuing deve estar em um `critical` seção.  Como as duas filas neste exemplo são independentes, elas são protegidas por `critical` diretivas com nomes diferentes,  *xaxis* e  *yaxis*.  
  
```  
#pragma omp parallel shared(x, y) private(x_next, y_next)  
{  
    #pragma omp critical ( xaxis )  
        x_next = dequeue(x);  
    work(x_next);  
    #pragma omp critical ( yaxis )  
        y_next = dequeue(y);  
    work(y_next);  
}  
```