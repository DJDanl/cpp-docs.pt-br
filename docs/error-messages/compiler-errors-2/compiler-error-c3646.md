---
title: "Erro do Compilador C3646 | Microsoft Docs"
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
  - "C3646"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3646"
ms.assetid: 4391ead2-9637-4ca3-aeda-5a991b18d66d
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3646
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“especificador”: especificador desconhecido de substituição  
  
 O compilador encontrou um token na posição onde esperava encontrar um especificador de substituição, mas o token não foi reconhecido pelo compilador.  
  
 Para obter mais informações, consulte [Especificadores de Substituição](../../windows/override-specifiers-cpp-component-extensions.md).  
  
 O seguinte exemplo gera C3646:  
  
```  
// C3646.cpp  
// compile with: /clr /c  
ref class C {  
   void f() unknown;   // C3646  
   // try the following line instead  
   // virtual void f() abstract;  
};  
```