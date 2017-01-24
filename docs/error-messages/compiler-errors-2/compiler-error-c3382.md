---
title: "C3382 de erro do compilador | Microsoft Docs"
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
  - "C3382"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3382"
ms.assetid: a7603abd-ac4e-4ae6-a02b-3bdc6d1908a6
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3382 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'sizeof' não é compatível com \/CLR: safe  
  
 O arquivo de saída de um **\/clr:safe** compilação é um arquivo que é comprovadamente fortemente tipado e sizeof não tem suporte porque o valor de retorno do operador sizeof é size\_t, cujo tamanho varia dependendo do sistema operacional.  
  
 Para obter mais informações, consulte,  
  
-   [Operador sizeof](../../cpp/sizeof-operator.md)  
  
-   [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Problemas de migração de 64 bits do Visual C\+\+comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)  
  
## Exemplo  
 O exemplo a seguir gera C3382.  
  
```  
// C3382.cpp // compile with: /clr:safe int main() { sizeof( char );   // C3382 }  
```