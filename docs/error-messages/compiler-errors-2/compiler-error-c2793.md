---
title: "Erro do Compilador C2793 | Microsoft Docs"
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
  - "C2793"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2793"
ms.assetid: ce35f4e8-c357-40ca-95c4-15ff001ad69d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2793
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“token”: “:: a seguir” do token inesperado, o identificador ou palavra\-chave “operador” esperado  
  
 Os únicos tokens que podem seguir `__super::` é um identificador ou a palavra\-chave `operator`.  
  
 O exemplo C2793 gerencia  
  
```  
// C2793.cpp  
struct B {  
   void mf();  
};  
  
struct D : B {  
   void mf() {  
      __super::(); // C2793  
   }  
};  
```