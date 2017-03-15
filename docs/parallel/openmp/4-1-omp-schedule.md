---
title: "4.1 OMP_SCHEDULE | Microsoft Docs"
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
ms.assetid: d0dce411-2351-4ee9-a1cc-c0322a58b65c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 4.1 OMP_SCHEDULE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**OMP\_SCHEDULE** se aplica somente ao  **para** e  **paralela para** diretivas que têm o tipo de agendamento  **em tempo de execução**.  O tamanho de bloco e de tipo de agenda para todos os loops pode ser definido em tempo de execução, definindo a variável de ambiente para qualquer um dos tipos de agendamento reconhecido e um recurso opcional  *chunk\_size*.  
  
 Para  **para** e  **paralela para** diretivas que têm um tipo de agendamento diferente de  **em tempo de execução**,  **OMP\_SCHEDULE** será ignorado.  O valor padrão para essa variável de ambiente é definidos na implementação.  Se o opcional  *chunk\_size* for definido, o valor deve ser positivo.  Se  *chunk\_size* não estiver definida, será adotado o valor 1, exceto no caso de um  **estático** agendamento.  Para um  **estático** agendamento, o tamanho de bloco padrão é definido no espaço de iteração do loop dividido pelo número de segmentos aplicado para o loop.  
  
 Exemplo:  
  
```  
setenv OMP_SCHEDULE "guided,4"  
setenv OMP_SCHEDULE "dynamic"  
```  
  
## Entre as referências:  
  
-   **para** diretiva, consulte  [seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página 11.  
  
-   **paralela para** diretiva, consulte  [seção 2.5.1](../Topic/2.5.1%20parallel%20for%20Construct.md) na página 16.