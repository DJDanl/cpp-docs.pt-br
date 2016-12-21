---
title: "Erro do Compilador C2109 | Microsoft Docs"
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
  - "C2109"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2109"
ms.assetid: 2d1ac79d-a985-4904-a38b-b270578d664d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2109
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o subscrito requer a matriz ou o tipo de ponteiro  
  
 O subscrito foi usado em uma variável que não seja uma matriz.  
  
 O seguinte exemplo gera C2109:  
  
```  
// C2109.cpp  
int main() {  
   int a, b[10] = {0};  
   a[0] = 1;   // C2109  
   b[0] = 1;   // OK  
}  
```