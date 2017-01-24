---
title: "Aviso do compilador (n&#237;vel 1) C4526 | Microsoft Docs"
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
  - "C4526"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4526"
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4526
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: a função de membro estático não pode substituir function'override virtual da função virtual 'ignorado, função virtual será oculta  
  
 A função de membro estático atende aos critérios para substituir a função virtual, o que torna a função de membro virtual e estático.  
  
 O seguinte código gerenciado C4526:  
  
```  
// C4526.cpp  
// compile with: /W1 /c  
// C4526 expected  
struct myStruct1 {  
   virtual void __stdcall func( int ) = 0;  
};  
  
struct myStruct2: public myStruct1 {  
   static void __stdcall func( int );  
};  
```  
  
 Os seguintes são correções possíveis:  
  
-   Se a função foi projetada substituir a função virtual da classe base, remova o especificador estático.  
  
-   Se a função foi projetada ser uma função de membro estático, renomeá\-la e não entra em conflito com a função virtual da classe base.