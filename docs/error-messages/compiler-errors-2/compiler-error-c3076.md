---
title: "Erro do Compilador C3076 | Microsoft Docs"
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
  - "C3076"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3076"
ms.assetid: 8a87b3e4-2c17-4b87-9622-ef0962d6a34e
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3076
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

instância “”: você não pode inserir uma instância de um tipo de referência “, tipo”, em um tipo nativo  
  
 Um tipo nativo não pode conter uma instância de um tipo de CLR.  
  
 Para obter mais informações, consulte [Semântica da pilha do C\+\+ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
## Exemplo  
 O exemplo a seguir produz C3076.  
  
```  
// C3076.cpp  
// compile with: /clr /c  
ref struct U {};  
  
struct V {  
   U y;   // C3076  
};  
  
ref struct W {  
   U y;   // OK  
};  
```