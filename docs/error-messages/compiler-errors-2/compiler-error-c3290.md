---
title: "C3290 de erro do compilador | Microsoft Docs"
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
  - "C3290"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3290"
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3290 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': uma propriedade trivial não pode ter o tipo de referência  
  
 Uma propriedade foi declarada incorretamente. Quando você declarar uma propriedade trivial, o compilador cria uma variável que irá atualizar a propriedade e não é possível ter uma referência de rastreamento variável em uma classe.  
  
 Consulte [property](../../windows/property-cpp-component-extensions.md) e [Tracking Reference Operator](../../windows/tracking-reference-operator-cpp-component-extensions.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir gera C3290.  
  
```  
// C3290.cpp // compile with: /clr /c ref struct R {}; ref struct X { R^ mr; property R % y;   // C3290 property R ^ x;   // OK // OK property R% prop { R% get() { return *mr; } void set(R%) {} } }; int main() { X x; R% xp = x.prop; }  
```