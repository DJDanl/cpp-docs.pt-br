---
title: "Defini&#231;&#245;es para o resumo de gram&#225;tica | Microsoft Docs"
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
  - "pré-processador"
  - "pré-processador, definições"
ms.assetid: cc752dc8-6f4e-4347-a556-e0d9ef4c46bd
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Defini&#231;&#245;es para o resumo de gram&#225;tica
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os terminais são pontos de extremidade em uma definição de sintaxe.  Nenhuma outra resolução é possível.  Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.  
  
 Os não terminais são espaços reservados na sintaxe.  A maioria é definida em outra parte deste resumo da sintaxe.  As definições podem ser recursivas.  Os seguintes não terminais são definidos em [Resumo da gramática](../misc/grammar-summary-cpp.md) da *Referência da linguagem C\+\+*:  
  
 `constant`, *expressão constante*, *identificador*, *palavra\-chave*, `operator`, `punctuator`  
  
 Um componente opcional é indicado pelo aceitação subscrita.  Por exemplo, o exemplo a seguir indica uma expressão opcional incluída em chaves:  
  
 **{** *expression*opt **}**  
  
## Consulte também  
 [Resumo de gramática](../preprocessor/grammar-summary-c-cpp.md)