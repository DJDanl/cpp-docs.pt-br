---
title: "Erro do Compilador C2601 | Microsoft Docs"
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
  - "C2601"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2601"
ms.assetid: 88275582-5f37-45d7-807d-05f06ba00965
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2601
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: as definições de função são locais ilegais  
  
 O código tentar definir uma função dentro de uma função.  
  
 Ou, pode haver uma chave adicional em seu código\-fonte antes do local do erro C2601.  
  
 O seguinte exemplo gera C2601:  
  
```  
// C2601.cpp  
int main() {  
   int i = 0;  
  
   void funcname(int j) {   // C2601  
      j++;  
   }  
}  
```