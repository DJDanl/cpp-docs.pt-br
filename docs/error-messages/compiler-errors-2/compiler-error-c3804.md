---
title: "Erro do Compilador C3804 | Microsoft Docs"
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
  - "C3804"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3804"
ms.assetid: 7c4cda28-ec96-4d04-937b-36dbd9944722
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3804
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“property\_accessor”: os métodos de acessador para uma propriedade devem ser todos estáticos ou qualquer não estático  
  
 Ao definir uma propriedade não trivial, as funções do acessador podem ser estáticos ou, mas não ambos.  
  
 Consulte [property](../../windows/property-cpp-component-extensions.md) para maiores informações.  
  
## Exemplo  
 O exemplo a seguir produz C3804.  
  
```  
// C3804.cpp  
// compile with: /c /clr  
ref struct A {  
  
   property int i {  
      static int get() {}  
      void set(int i) {}  
   }   // C3804 error  
  
   // OK  
   property int j {  
      int get() { return 0; }  
      void set(int i) {}  
   }  
  
   property int k {  
      static int get() { return 0; }  
      static void set(int i) {}  
   }  
};  
```