---
title: "Erro do Compilador C3797 | Microsoft Docs"
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
  - "C3797"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3797"
ms.assetid: ab27ff34-8c1d-4297-b004-9e39bd3a4f25
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3797
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“substituição”: a declaração de evento pode não ter o especificador de substituição \(devem ser colocados no evento adicionar\/remover\/métodos de aumento no lugar\)  
  
 Você não pode substituir um evento \(trivial um evento sem definidos explicitamente métodos de acessador\) com outro evento trivial.  O evento substituindo deve definir seu comportamento com funções do acessador.  
  
 Para obter mais informações, consulte [event](../../windows/event-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3797.  
  
```  
// C3797.cpp  
// compile with: /clr /c  
delegate void MyDel();  
  
ref class Class1 {  
public:  
   virtual event MyDel ^ E;  
};  
  
ref class Class2 : public Class1 {  
public:  
   virtual event MyDel ^ E override;   // C3797  
};  
  
// OK  
ref class Class3 : public Class1 {  
public:  
   virtual event MyDel ^ E {  
      void add(MyDel ^ d) override {}  
      void remove(MyDel ^ d) override {}  
   }  
};  
```