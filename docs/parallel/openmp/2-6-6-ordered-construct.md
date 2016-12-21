---
title: "2.6.6 ordered Construct | Microsoft Docs"
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
ms.assetid: 5b3c1ba5-cfb8-4b05-865b-f446ae1c9f7c
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.6.6 ordered Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O seguinte bloco estruturado um  **ordenada** diretiva é executada na ordem em que as iterações seriam executadas em um loop seqüencial.  A sintaxe da  **ordenada** diretiva é o seguinte:  
  
```  
#pragma omp ordered new-line  
   structured-block  
```  
  
 Um  **ordenados** diretiva deve estar entre a extensão dinâmica de um  **para** ou  **paralela para** construir.  O  **para** ou  **paralela para** diretriz para o qual o  **ordenada** ligações de construção devem ter um  **ordenados** cláusula especificada conforme descrito em  [seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página 11.  Na execução de um  **para** ou  **paralela para** construir com um  **ordenados** cláusula,  **ordenados** construções são executadas estritamente na ordem em que eles seriam executados em uma execução seqüencial do loop.  
  
 Restrições para o  **ordenada** diretiva são os seguintes:  
  
-   Uma iteração de um loop com uma  **para** construção não deve executar a mesma diretiva ordenada mais de uma vez e não devem executar mais de um  **ordenada** diretiva.