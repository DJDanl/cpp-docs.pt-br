---
title: "3.1.9 omp_set_nested Function | Microsoft Docs"
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
ms.assetid: e4afc3aa-bb96-4314-9849-fd5df5f437d9
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.9 omp_set_nested Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **omp\_set\_nested** função ativa ou desativa o paralelismo aninhado.  O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_nested(int nested);  
```  
  
 Se  *aninhadas* for avaliada como 0, aninhados paralelismo estiver desativado, o que é o padrão e regiões paralelas aninhados são serializados e executados pelo thread atual.  Se  *aninhados* for avaliada como um valor diferente de zero, paralelismo aninhado está ativado e regiões paralelas que estão aninhados podem implantar threads adicionais Times aninhados.  
  
 Esta função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o  **omp\_in\_parallel** função retorna zero.  Se ela é chamada a partir de uma parte do programa em que o  **omp\_in\_parallel** função retorna um valor diferente de zero, o comportamento desta função é indefinido.  
  
 Essa chamada tem precedência sobre o  **OMP\_NESTED** variável de ambiente.  
  
 Quando o paralelismo aninhado é ativado, o número de segmentos usados para executar a regiões paralelas aninhados é definidos na implementação.  Como resultado, compatível com OpenMP implementações podem serializar aninhados regiões paralelas, mesmo quando o paralelismo aninhado está ativado.  
  
## Entre as referências:  
  
-   **OMP\_NESTED** consulte variável, do ambiente  [seção 4.4](../Topic/4.4%20OMP_NESTED.md) na página 49.  
  
-   **omp\_in\_parallel** funcionam, consulte  [seção 3.1.6](../../parallel/openmp/3-1-6-omp-in-parallel-function.md) na página 38.