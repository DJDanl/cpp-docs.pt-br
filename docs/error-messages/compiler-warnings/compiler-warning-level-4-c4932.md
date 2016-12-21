---
title: "Compilador C4932 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4932"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4932"
ms.assetid: 0b8d88cc-21f6-45cb-a9f5-1795b7db0dfa
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4932 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\_\_identifier\(Identifier\) e \_\_identifier\(identifier\) não podem ser diferenciados  
  
 O compilador é capaz de distinguir entre **\_finally** e `__finally` ou `__try` e **\_try** como um parâmetro passado para [identifier](../../windows/identifier-cpp-cli.md). Você não deve tentar usar ambos como identificadores no mesmo programa, pois resultará em uma [C2374](../../error-messages/compiler-errors-1/compiler-error-c2374.md) erro.  
  
 O exemplo a seguir gera C4932:  
  
```  
// C4932.cpp // compile with: /clr /W4 /WX int main() { int __identifier(_finally) = 245;   // C4932 int __identifier(__finally) = 25;   // C4932 }  
```