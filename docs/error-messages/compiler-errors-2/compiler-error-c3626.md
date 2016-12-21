---
title: "Erro do Compilador C3626 | Microsoft Docs"
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
  - "C3626"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3626"
ms.assetid: 43926e2b-1ba9-4a43-9343-c58449cbb336
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3626
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“palavra\-chave”: a palavra\-chave “\_\_event” pode ser usado somente em interfaces, funções de membro e os membros de dados de COM que são ponteiros para os representantes  
  
 Uma palavra\-chave foi usado incorretamente.  
  
 O seguinte exemplo gera C3626:  
  
```  
// C3626.cpp  
// compile with: /c  
struct A {  
   __event int i;   // C3626  
// try the following line instead  
// __event int i();  
};  
```