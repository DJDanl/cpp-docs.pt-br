---
title: "Aviso do compilador C4484 | Microsoft Docs"
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
  - "C4484"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4484"
ms.assetid: 3d30e5b3-2297-45b7-a37a-1360056fdd0e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4484
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“override\_function”: as correspondências baseiam o método “base\_class\_function” da classe de referência, mas não são “virtuais”, “novos marcados como” ou “substituição”; “novo” \(e não “virtual "\) será assumido  
  
 Ao criar com **\/clr**, o compilador não substituirá implicitamente uma função da classe base, que significa a função obterá um novo local em vtable.  Para resolver, especifique explicitamente se uma função é uma substituição.  
  
 Para obter mais informações, consulte:  
  
-   [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [override](../../windows/override-cpp-component-extensions.md)  
  
-   [new \(new slot in vtable\)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md)  
  
 C4484 é emitido sempre como um erro.  Use o pragma de [warning](../../preprocessor/warning.md) para suprimir C4484.  
  
## Exemplo  
 O exemplo a seguir produz C4484.  
  
```  
// C4484.cpp  
// compile with: /clr  
ref struct A {  
   virtual void Test() {}  
};  
  
ref struct B : A {  
   void Test() {}   // C4484  
};  
  
// OK  
ref struct C {  
   virtual void Test() {}  
   virtual void Test2() {}  
};  
  
ref struct D : C {  
   virtual void Test() new {}  
   virtual void Test2() override {}  
};  
```