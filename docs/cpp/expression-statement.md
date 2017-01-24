---
title: "Instru&#231;&#227;o de express&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instruções de expressão"
  - "instruções, expressão"
ms.assetid: 547d7f7a-58be-4ffc-a4b3-d64c7ae7538c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o de express&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Instruções de expressão fazem com as expressões sejam avaliadas.  Nenhuma transferência de controle ou iteração ocorre como resultado de uma instrução de expressão.  
  
 A sintaxe da instrução de expressão é simplesmente  
  
## Sintaxe  
  
```  
[expression ] ;  
```  
  
## Comentários  
 Todas as expressões em uma instrução de expressão são avaliadas e todos os efeitos colaterais são concluídos antes que a próxima instrução seja executada.  As instruções de expressão mais comuns são atribuições e chamadas de função.  Como a expressão é opcional, um sinal de ponto e vírgula sozinho é considerado uma instrução de expressão vazia, conhecida como instrução [nula](../Topic/Null%20Statement.md).  
  
## Consulte também  
 [Visão geral de instruções C\+\+](../cpp/overview-of-cpp-statements.md)