---
title: "2.6.3 barrier Directive | Microsoft Docs"
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
ms.assetid: 4485a3d7-533f-4fec-8128-a131bec7fa16
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.6.3 barrier Directive
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **barreira** diretiva sincroniza todos os threads em uma equipe.  Quando encontrado, cada thread na equipe aguarda até que todos os outros tiverem chegado neste ponto.  A sintaxe do  **barreira** diretiva é o seguinte:  
  
```  
#pragma omp barrier new-line  
```  
  
 Depois que todos os threads na equipe tiveram a barreira, cada thread na equipe começa a executar as instruções após a diretiva de barreira em paralelo.  Observe que, como o  **barreira** diretiva não tem uma instrução de linguagem c como parte de sua sintaxe, há algumas restrições em sua colocação dentro de um programa.  Consulte  [Apêndice C](../Topic/C.%20OpenMP%20C%20and%20C++%20Grammar.md) da gramática formal.  O exemplo a seguir ilustra essas restrições.  
  
```  
/* ERROR - The barrier directive cannot be the immediate  
*          substatement of an if statement  
*/  
if (x!=0)  
   #pragma omp barrier  
...  
  
/* OK - The barrier directive is enclosed in a  
*      compound statement.  
*/  
if (x!=0) {  
   #pragma omp barrier  
}  
```