---
title: "Preced&#234;ncia em regras de infer&#234;ncia | Microsoft Docs"
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
helpviewer_keywords: 
  - "regras de inferência em NMAKE"
  - "precedência, regra de inferência"
  - "regras, inferência"
ms.assetid: 69e3dc02-0815-4c3a-b02b-1cb85fceaf24
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Preced&#234;ncia em regras de infer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se uma regra de inferência é definido, multiplicar NMAKE usa a definição de alta prioridade.  A lista a seguir mostra a ordem de precedência do mais alto ao mais baixo:  
  
1.  Uma regra de inferência definida em um makefile; as definições posteriores têm precedência.  
  
2.  Uma regra de inferência definida em Tools.ini; as definições posteriores têm precedência.  
  
3.  Uma regra de inferência predefinida.  
  
## Consulte também  
 [Regras de inferência](../build/inference-rules.md)