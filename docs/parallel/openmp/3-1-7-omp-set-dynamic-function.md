---
title: "3.1.7 omp_set_dynamic Function | Microsoft Docs"
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
ms.assetid: 1fba961b-b82c-4a1e-ab0f-e4be826e50ab
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.7 omp_set_dynamic Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **omp\_set\_dynamic** função ativa ou desativa o ajuste dinâmico do número de threads disponíveis para a execução de regiões paralelas.  O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_dynamic(int dynamic_threads);  
```  
  
 Se  *dynamic\_threads* for avaliada como um valor diferente de zero, o número de segmentos que são usados para a execução de regiões paralelas subseqüentes pode ser ajustado automaticamente pelo ambiente de tempo de execução para melhor utilizar os recursos do sistema.  Como conseqüência, o número de segmentos especificado pelo usuário é a contagem máxima de segmentos.  O número de threads na equipe de execução de uma região paralela permanece fixo para a duração da região paralela e for reportado pela  **omp\_get\_num\_threads** função.  
  
 Se  *dynamic\_threads* for avaliada como 0, o ajuste dinâmico está desabilitado.  
  
 Esta função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o  **omp\_in\_parallel** função retorna zero.  Se ela é chamada a partir de uma parte do programa em que o  **omp\_in\_parallel** função retorna um valor diferente de zero, o comportamento desta função é indefinido.  
  
 Uma chamada para  **omp\_set\_dynamic** tem precedência sobre o  **OMP\_DYNAMIC** variável de ambiente.  
  
 O padrão para o ajuste dinâmico de segmentos é definidos na implementação.  Como resultado, os códigos de usuário que dependem de um número específico de threads para execução correta devem explicitamente desativar threads dinâmicos.  Implementações não são necessárias para fornecer a capacidade de ajustar dinamicamente o número de segmentos, mas eles são necessários para fornecer a interface para oferecer suporte a portabilidade em todas as plataformas.  
  
## Entre as referências:  
  
-   **omp\_get\_num\_threads** funcionam, consulte  [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.  
  
-   **OMP\_DYNAMIC** consulte variável, do ambiente  [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.  
  
-   **omp\_in\_parallel** funcionam, consulte  [seção 3.1.6](../../parallel/openmp/3-1-6-omp-in-parallel-function.md) na página 38.