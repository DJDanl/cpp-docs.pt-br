---
title: "Erro fatal C1026 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1026"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1026"
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1026
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o estouro de pilha do analisador, programa muito complexo  
  
 O espaço necessário analisar o programa gerou um estouro de pilha do compilador.  
  
 Reduzir a complexidade das expressões por:  
  
-   Diminuindo o aninhamento em `for` e instruções de `switch` .  Colocar instruções mais profundamente aninhadas em funções separadas.  
  
-   Dividindo as expressões longas que envolvem operadores ou chamadas de função de vírgula.