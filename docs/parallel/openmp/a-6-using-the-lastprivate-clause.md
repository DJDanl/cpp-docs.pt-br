---
title: "A.6   Using the lastprivate Clause | Microsoft Docs"
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
ms.assetid: cf3bf0cc-aa46-4e44-9433-e2969e3be2c1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.6   Using the lastprivate Clause
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Às vezes, a execução correta depende do valor que a última iteração de um loop atribui a uma variável.  Tais programas devem listar todas as variáveis como argumentos para uma `lastprivate` cláusula \([seção 2.7.2.3](../Topic/2.7.2.3%20lastprivate.md) na página 27\) para que os valores das variáveis são os mesmos quando o loop é executado em seqüência.  
  
```  
#pragma omp parallel  
{  
   #pragma omp for lastprivate(i)  
      for (i=0; i<n-1; i++)  
         a[i] = b[i] + b[i+1];  
}  
a[i]=b[i];  
```  
  
 No exemplo anterior, o valor de `i` será igual ao final da região paralela `n–1`, como no caso seqüencial.