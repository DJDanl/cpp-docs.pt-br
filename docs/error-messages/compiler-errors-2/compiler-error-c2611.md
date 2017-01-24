---
title: "Erro do Compilador C2611 | Microsoft Docs"
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
  - "C2611"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2611"
ms.assetid: 3f2d5253-f24f-4724-83d0-6b2aa6a4e551
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2611
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“token”: seguintes ilegal “” esperado ~ \(identificador\)  
  
 O token não é um identificador.  
  
 O seguinte exemplo gera C2611:  
  
```  
// C2611.cpp  
// compile with: /c  
class C {  
   C::~operator int();   // C2611  
   ~C();   // OK  
};  
```