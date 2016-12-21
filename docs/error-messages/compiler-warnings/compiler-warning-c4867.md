---
title: "Aviso do compilador C4867 | Microsoft Docs"
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
  - "C4867"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4867"
ms.assetid: 8a257d70-c3a7-462d-b285-e57c952a8bf7
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4867
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: lista de argumento ausente da chamada de função; use “chamada” para criar um ponteiro para o membro  
  
 Um ponteiro para a função de membro foi inicializado incorretamente.  
  
 Esse aviso pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: conformidade do ponteiro\-à\- membro.  Codificar que compilado antes do Visual C\+\+ 2005 gerará agora C4867.  
  
 Esse aviso é emitido sempre como um erro.  Use o pragma de [warning](../../preprocessor/warning.md) para desabilitar esse aviso.  Para obter mais informações sobre como C4867 e de MFC\/ATL, consulte [\_ATL\_ENABLE\_PTM\_WARNING](../Topic/_ATL_ENABLE_PTM_WARNING.md).  
  
## Exemplo  
 O exemplo a seguir produz C4867.  
  
```  
// C4867.cpp  
// compile with: /c  
class A {  
public:  
   void f(int) {}  
  
   typedef void (A::*TAmtd)(int);  
  
   struct B {  
      TAmtd p;  
   };  
  
   void g() {  
      B b = {f};   // C4867  
      B b2 = {&A::f};   // OK  
   }  
};  
```