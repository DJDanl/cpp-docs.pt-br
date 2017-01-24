---
title: "Compilador C4112 de aviso (n&#237;veis 1 e 4) | Microsoft Docs"
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
  - "C4112"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4112"
ms.assetid: aff64897-bb79-4a67-9b6f-902c6d44f3dc
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4112 de aviso (n&#237;veis 1 e 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\#line requer um número inteiro entre 1 e número  
  
 O [\#line](../Topic/%23line%20Directive%20\(C-C++\).md) diretiva especifica um parâmetro de número inteiro que está fora do intervalo permitido.  
  
 Se o parâmetro especificado é menor que 1, o contador de linha é redefinido para 1. Se o parâmetro especificado é maior que *número*, que é o limite definido pelo compilador, o contador de linha permanece inalterado. Este é um aviso de nível 1 em compatibilidade com ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\) e um aviso de nível 4 com extensões da Microsoft \([\/Ze](../../build/reference/za-ze-disable-language-extensions.md)\).  
  
 O exemplo a seguir gera C4112:  
  
```  
// C4112.cpp  
// compile with: /W4  
#line 0   // C4112, value must be between 1 and number  
  
int main() {  
}  
```