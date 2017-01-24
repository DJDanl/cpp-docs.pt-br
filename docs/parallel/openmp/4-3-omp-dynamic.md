---
title: "4.3 OMP_DYNAMIC | Microsoft Docs"
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
ms.assetid: a15edefb-1f85-4f06-a427-beb3cfc4434f
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 4.3 OMP_DYNAMIC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **OMP\_DYNAMIC** variável de ambiente habilita ou desabilita o ajuste dinâmico do número de threads disponíveis para a execução de regiões paralelas, a menos que o ajuste dinâmico explicitamente habilitada ou desabilitada, chamando o  **omp\_set\_dynamic** a rotina de biblioteca.  Seu valor deve ser  **TRUE** ou  **FALSE**.  
  
 Se definido como  **TRUE**, o número de segmentos que são usados para a execução paralelas regiões pode ser ajustado pelo ambiente de tempo de execução para melhor utilizar os recursos do sistema.  Se definido como  **FALSE**, ajuste dinâmico está desabilitado.  A condição de padrão é definido para implementação.  
  
 Exemplo:  
  
```  
setenv OMP_DYNAMIC TRUE  
```  
  
## Entre as referências:  
  
-   Para obter mais informações sobre regiões paralelas, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8.  
  
-   **omp\_set\_dynamic** funcionam, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.