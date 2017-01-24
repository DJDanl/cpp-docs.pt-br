---
title: "A.12   Using the atomic Directive | Microsoft Docs"
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
ms.assetid: d3ba3c87-413d-4efa-8a45-8a7f28ab0164
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.12   Using the atomic Directive
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O exemplo a seguir evita condições de corrida \(atualizações simultâneas de um elemento do  *x* por vários threads\) usando o `atomic` diretiva \([seção 2.6.4](../../parallel/openmp/2-6-4-atomic-construct.md) na página 19\):  
  
```  
#pragma omp parallel for shared(x, y, index, n)  
    for (i=0; i<n; i++)   
    {  
        #pragma omp atomic  
            x[index[i]] += work1(i);  
        y[i] += work2(i);  
    }  
```  
  
 A vantagem de usar o `atomic` diretiva neste exemplo é que ele permite que as atualizações de dois elementos diferentes de x ocorram em paralelo.  Se um `critical` diretiva \([seção 2.6.2](../../parallel/openmp/2-6-2-critical-construct.md) na página 18\) foram usados em vez disso, e em seguida, todas as atualizações para elementos de  *x* seria executado em série \(embora não de qualquer garantia de ordem\).  
  
 Observe que o `atomic` diretiva se aplica apenas à instrução c ou C\+\+ imediatamente a seguir.  Como resultado, os elementos de  *y* não são atualizados atomicamente neste exemplo.