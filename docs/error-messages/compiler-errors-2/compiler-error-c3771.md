---
title: "C3771 de erro do compilador | Microsoft Docs"
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
  - "C3771"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3771"
ms.assetid: 68c23b25-7f21-4eaa-8f7e-38fda1130a69
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3771 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

"identificador": declaração friend não pode ser encontrada no escopo de namespace mais próximo  
  
 Declaração de modelo de classe para o modelo especificado *identificador* não pode ser encontrado no namespace atual.  
  
### Para corrigir este erro  
  
-   Certifique\-se de que a declaração de modelo de classe para o identificador do modelo é definida no namespace atual ou o identificador do modelo é um nome totalmente qualificado.  
  
## Exemplo  
 O exemplo de código a seguir declara um modelo de classe e uma função no namespace `NA`, mas tentar declarar um modelo de função friend no namespace `NB`.  
  
```  
// C3771.cpp // compile with: /c namespace NA { template<class T> class A { void aFunction(T t) {}; }; } // using namespace NA; namespace NB { class X { template<class T> friend void A<T>::aFunction(T); // C3771 // try the following line instead //      template<class T> friend void NA::A<T>::aFunction(T); // or try "using namespace NA;" instead. }; }  
```  
  
## Consulte também  
 [Especificações de modelo](../Topic/Template%20Specifications.md)