---
title: "C3772 de erro do compilador | Microsoft Docs"
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
  - "C3772"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3772"
ms.assetid: 63e938d4-088d-41cc-a562-5881a05b5710
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3772 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

"nome": declaração de modelo friend inválido  
  
 Não é válido para declarar um amigo uma especialização de modelo de classe. Você não pode declarar uma especialização explícita ou parcial de um modelo de classe e na mesma instrução declare um amigo que especialização. O *nome* espaço reservado identifica declaração inválida.  
  
### Para corrigir este erro  
  
-   Não declare um amigo uma especialização de modelo de classe.  
  
-   Se for apropriado para seu aplicativo, declare um amigo do modelo de classe ou declarar um amigo uma especialização parcial ou explícita específica.  
  
## Exemplo  
 O exemplo de código a seguir falha porque ele declara um amigo de uma especialização parcial de um modelo de classe.  
  
```  
// c3772.cpp // compile with: /c // A class template. template<class T> class A {}; // A partial specialization of the class template. template<class T> class A<T*> {}; // An explicit specialization. template<> class A<char>; class X { // Invalid declaration of a friend of a partial specialization. template<class T> friend class A<T*>; // C3772 // Instead, if it is appropriate for your application, declare a // friend of the class template. Consequently, all specializations // of the class template are friends: //    template<class T> friend class A; // Or declare a friend of a particular partial specialization: //    friend class A<int*>; // Or declare a friend of a particular explicit specialization: //    friend class A<char>; };  
```  
  
## Consulte também  
 [Especificações de modelo](../Topic/Template%20Specifications.md)   
 [Especialização parcial de modelos de classe](../../cpp/template-specialization-cpp.md)   
 [Especialização explícita de modelos de classe](../Topic/Explicit%20Specialization%20of%20Class%20Templates.md)