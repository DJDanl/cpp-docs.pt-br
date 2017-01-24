---
title: "A.11   Specifying a Fixed Number of Threads | Microsoft Docs"
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
ms.assetid: 1d06b142-4c35-44b8-994b-20f2aed5462b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.11   Specifying a Fixed Number of Threads
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Alguns programas contam com um número fixo, pré\-especificados de segmentos seja executado corretamente.  Como a configuração padrão para o ajuste dinâmico do número de threads é definidos na implementação, esses programas podem optar por desativar o recurso dinâmico de threads e definir o número de segmentos explicitamente para garantir a portabilidade.  O exemplo a seguir mostra como fazer isso usando `omp_set_dynamic` \([seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39\), e `omp_set_num_threads` \([seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36\):  
  
```  
omp_set_dynamic(0);  
omp_set_num_threads(16);  
#pragma omp parallel shared(x, npoints) private(iam, ipoints)  
{  
    if (omp_get_num_threads() != 16)   
      abort();  
    iam = omp_get_thread_num();  
    ipoints = npoints/16;  
    do_by_16(x, iam, ipoints);  
}  
```  
  
 Neste exemplo, o programa executa corretamente apenas se ele é executado pelo 16 segmentos.  Se a implementação não é capaz de suportar 16 segmentos, o comportamento deste exemplo é definidos na implementação.  
  
 Observe que o número de threads em execução de uma região paralela permanece constante durante uma região paralela, independentemente dos threads dinâmicos definindo.  O mecanismo de threads dinâmica determina o número de segmentos usados no início da região paralela e mantém constante para a duração da região.