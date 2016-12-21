---
title: "Operadores p&#243;s-fixados | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "operadores [C], sufixo"
  - "operadores de sufixo"
ms.assetid: 76260011-1624-484e-8bef-72ae7ab556cc
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores p&#243;s-fixados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores pós\-fixados tem a precedência mais alta \(a associação mais estreita\) na avaliação da expressão.  
  
## Sintaxe  
 *postfix\-expression*:  
 *primary\-expression*  
  
 *postfix\-expression*  **\[**  *expression*  **\]**  
  
 *postfix\-expression*  **\(**  *argument\-expression\-list*  opt **\)**  
  
 *postfix\-expression*  **.**  *identifier*  
  
 *postfix\-expression*  **–\>**  *identifier*  
  
 *postfix\-expression*  **\+\+**  
  
 *postfix\-expression*  **––**  
  
 Os operadores nesse nível de precedência são: subscritos de matriz, chamadas de função, membros de estrutura e união, e operadores de incremento e decremento pós\-fixados.  
  
## Consulte também  
 [Operadores C](../c-language/c-operators.md)