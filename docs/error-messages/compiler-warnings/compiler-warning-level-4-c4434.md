---
title: "Compilador C4434 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4434"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4434"
ms.assetid: 24b8785e-353a-4c37-8bed-ed61001a871d
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4434 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

um construtor de classe deve ter a facilidade de uso particular; alterar o acesso privado  
  
 C4434 indica que o compilador alterou a acessibilidade de um construtor estático.  Os construtores estáticos devem ter a facilidade de uso particular, como eles devem ser chamados por Common Language Runtime.  Para obter mais informações, consulte [Construtores estáticos](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Static_constructors).  
  
## Exemplo  
 O exemplo a seguir produz C4434.  
  
```  
// C4434.cpp  
// compile with: /W4 /c /clr  
public ref struct R {  
   static R(){}   // C4434  
};  
```