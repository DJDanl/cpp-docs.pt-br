---
title: "Aviso do compilador C4430 | Microsoft Docs"
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
  - "C4430"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4430"
ms.assetid: 12efbfff-aa58-4a86-a7d6-2c6a12d01dd3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4430
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

especificador ausente do tipo int \- assumido.Observação: C\+\+ não da suporte ao int  
  
 Esse erro pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: todas as declarações devem especificar explicitamente o tipo; int é assumido não.  
  
 C4430 é emitido sempre como um erro.  Você pode desativar esse aviso com `#pragma warning` ou **\/wd**; consulte [warning](../../preprocessor/warning.md) ou [\/w, \/W0, \/W1, \/W2, \/W3, \/W4, \/w1, \/w2, \/w3, \/w4, \/Wall, \/wd, \/, \/wo, \/Wv, \/WX \(nível de aviso\)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir produz C4430.  
  
```  
// C4430.cpp  
// compile with: /c  
struct CMyClass {  
   CUndeclared m_myClass;  // C4430  
   int m_myClass;  // OK  
};  
  
typedef struct {  
   POINT();   // C4430  
   // try the following line instead  
   // int POINT();  
   unsigned x;  
   unsigned y;  
} POINT;  
```