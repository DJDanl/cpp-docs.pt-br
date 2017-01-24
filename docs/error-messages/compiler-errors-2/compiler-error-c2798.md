---
title: "Erro do Compilador C2798 | Microsoft Docs"
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
  - "C2798"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2798"
ms.assetid: fb0cd861-b228-4f81-8090-e28344a727e0
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2798
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o “super::member” é ambíguo  
  
 As estruturas herdadas vários contém o membro que você referenciou com [super](../../cpp/super.md).  Você pode corrigir o erro por um dos seguintes:  
  
-   Removendo B1 ou B2 da lista de herança de D.  
  
-   Alterando o nome do membro de dados no ou no B1 B2.  
  
 O seguinte exemplo gera C2798:  
  
```  
// C2798.cpp  
struct B1 {  
   int i;  
};  
  
struct B2 {  
   int i;  
};  
  
struct D : B1, B2 {  
   void g() {  
      __super::i = 4; // C2798  
   }  
};  
```