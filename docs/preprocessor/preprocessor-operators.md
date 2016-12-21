---
title: "Operadores de pr&#233;-processador | Microsoft Docs"
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
  - "operadores [C++], pré-processador"
  - "operadores de pré-processador"
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Operadores de pr&#233;-processador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quatro operadores específicos de pré\-processadores são usados no contexto da política de `#define` \(consulte a lista a seguir para obter um resumo de cada um.\)  Os operadores stringizing, charizing e token\-pasting são discutidos nas três seções seguintes.  Para obter informações sobre o operador **definido**, consulte [As políticas \#if, \#elif, \#else e \#endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).  
  
|Operador|Ação|  
|--------------|----------|  
|[Operador stringizing \(\#\)](../preprocessor/stringizing-operator-hash.md)|Faz com que o argumento correspondente real seja incluído entre aspas duplas|  
|[Operador charizing \(\#@\)](../preprocessor/charizing-operator-hash-at.md)|Faz com que o argumento correspondente seja incluído entre aspas simples e tratado como um caractere \(específico da Microsoft\)|  
|[Operador token\-pasting \(\#\#\)](../preprocessor/token-pasting-operator-hash-hash.md)|Permite que os tokens utilizados como argumentos reais sejam concatenados para formar outros tokens|  
|[operador definido](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|Simplifica a gravação de expressões compostas em determinadas políticas de macro|  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)   
 [Macros predefinidas](../preprocessor/predefined-macros.md)   
 [Referência de pré\-processador C\/C\+\+](../preprocessor/c-cpp-preprocessor-reference.md)