---
title: "OpenMP Clauses | Microsoft Docs"
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
ms.assetid: 806e7d8f-b204-4e4c-a12c-273ab540a7ca
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OpenMP Clauses
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece links para as cláusulas usadas na API OpenMP.  
  
 Visual C\+\+ oferece suporte aos seguintes cláusulas OpenMP:  
  
|Cláusula|Descrição|  
|--------------|---------------|  
|[copyin](../Topic/copyin.md)|Permite que segmentos acessar o valor do mestre do segmento, para um [threadprivate](../Topic/threadprivate.md) variável.|  
|[copyprivate](../Topic/copyprivate.md)|Especifica que uma ou mais variáveis devem ser compartilhadas entre todos os threads.|  
|[default](../../../parallel/openmp/reference/default-openmp.md)|Especifica o comportamento de variáveis unscoped em uma região paralela.|  
|[firstprivate](../Topic/firstprivate.md)|Especifica que cada segmento deve ter sua própria instância de uma variável e que a variável deve ser inicializada com o valor da variável, porque ele existe antes da construção parallel.|  
|[if](../../../parallel/openmp/reference/if-openmp.md)|Especifica se deve ser executado um loop em paralelo ou serial.|  
|[lastprivate](../../../parallel/openmp/reference/lastprivate.md)|Especifica a versão do contexto delimitador da variável é definida igual à versão particular de qualquer segmento executa a iteração final \(construção for loop\) ou a última seção \(\# pragma seções\).|  
|[nowait](../../../parallel/openmp/reference/nowait.md)|Substitui a barreira implícita em uma diretiva.|  
|[num\_threads](../../../parallel/openmp/reference/num-threads.md)|Define o número de segmentos em uma equipe de thread.|  
|[ordered](../Topic/ordered%20\(OpenMP%20Clauses\).md)|Necessário em paralelo [for](../Topic/for%20\(OpenMP\).md) instrução se um [ordered](../../../parallel/openmp/reference/ordered-openmp-directives.md) diretiva deverá ser usada no loop.|  
|[private](../../../parallel/openmp/reference/private-openmp.md)|Especifica que cada segmento deve ter sua própria instância de uma variável.|  
|[reduction](../../../parallel/openmp/reference/reduction.md)|Especifica que uma ou mais variáveis que são exclusivos para cada segmento são o assunto de uma operação de redução no final da região paralela.|  
|[schedule](../../../parallel/openmp/reference/schedule.md)|Aplica\-se para o [for](../Topic/for%20\(OpenMP\).md) diretiva.|  
|[shared](../../../parallel/openmp/reference/shared-openmp.md)|Especifica que uma ou mais variáveis devem ser compartilhadas entre todos os threads.|  
  
## Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Directives](../../../parallel/openmp/reference/openmp-directives.md)