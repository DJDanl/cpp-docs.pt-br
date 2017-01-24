---
title: "C3052 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3052"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3052"
ms.assetid: 87480c42-1ceb-4775-8d20-88c54a7bb6a6
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3052 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': variável não aparece em uma cláusula de compartilhamento de dados em uma cláusula default \(none\)  
  
 Se [Default \(none\)](../../parallel/openmp/reference/default-openmp.md) é usada, qualquer variável usado no bloco estruturado deve ser especificado explicitamente como [compartilhado](../../parallel/openmp/reference/shared-openmp.md) ou [particular](../../parallel/openmp/reference/private-openmp.md).  
  
 O exemplo a seguir gera C3052:  
  
```  
// C3052.cpp // compile with: /openmp /c int main() { int n1 = 1; #pragma omp parallel default(none) // shared(n1) private(n1) { n1 = 0;   // C3052 use either a shared or private clause } }  
```