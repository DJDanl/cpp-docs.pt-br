---
title: "Aviso do compilador C4485 | Microsoft Docs"
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
  - "C4485"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4485"
ms.assetid: a6f2b437-ca93-4dcd-b9cb-df415e10df86
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4485
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“override\_function”: as correspondências baseiam o método “base\_class\_function” da classe de referência, mas não são “novos marcado” ou “substituição”; “novo” e “\(virtual "\) será assumido  
  
 Um acessador substituir, com ou sem a palavra\-chave de `virtual` , uma função do acessador tipado da classe base, mas o especificador de `override` ou de `new` não fazia parte da assinatura substituindo da função.  Adicionar o especificador de `new` ou de `override` para resolver esse aviso.  
  
 Consulte [override](../../windows/override-cpp-component-extensions.md) e [new \(new slot in vtable\)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md) para obter mais informações.  
  
 C4485 é emitido sempre como um erro.  Use o pragma de [warning](../../preprocessor/warning.md) para suprimir C4485.  
  
## Exemplo  
 O exemplo C4485 gerencia  
  
```  
// C4485.cpp  
// compile with: /clr  
delegate void Del();  
  
ref struct A {  
   virtual event Del ^E;  
};  
  
ref struct B : A {  
   virtual event Del ^E;   // C4485  
};  
  
ref struct C : B {  
   virtual event Del ^E {  
      void raise() override {}  
      void add(Del ^) override {}  
      void remove(Del^) override {}  
   }  
};  
```