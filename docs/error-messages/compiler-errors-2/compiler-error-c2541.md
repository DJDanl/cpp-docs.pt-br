---
title: "Erro do Compilador C2541 | Microsoft Docs"
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
  - "C2541"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2541"
ms.assetid: ed95180f-00df-4e62-a8e9-1b6dab8281bf
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2541
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“excluir”: exclusão: não pode excluir objetos que não são ponteiros  
  
 O operador de [excluir](../../cpp/delete-operator-cpp.md) foi usado em um objeto que não seja um ponteiro.  
  
 O seguinte exemplo gera C2541:  
  
```  
// C2541.cpp  
int main() {  
   int i;  
   delete i;   // C2541 i not a pointer  
  
   // OK  
   int *ip = new int;  
   delete ip;  
}  
```