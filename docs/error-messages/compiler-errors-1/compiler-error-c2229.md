---
title: "Erro do Compilador C2229 | Microsoft Docs"
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
  - "C2229"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2229"
ms.assetid: 933c7cf2-a463-4e74-b0b4-59dedad987fb
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2229
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o tipo “identificador” tem uma matriz zero feita dimensionar ilegal  
  
 Um membro de um campo da estrutura ou de bit contém uma matriz zero pequeno medida que não é o último membro.  
  
 Como é possível ter um valor nulo feitas dimensionar a matriz como o último membro da estrutura, você deve especificar seu tamanho quando você atribui o struct.  
  
 Se o valor for null feitas dimensionar a matriz não é o último membro da estrutura, o compilador não pode calcular o deslocamento para os campos restantes.  
  
 O seguinte exemplo gera C2229:  
  
```  
// C2229.cpp  
struct S {  
   int a[0];  // C2229  zero-sized array  
   int b[1];  
};  
  
struct S2 {  
   int a;  
   int b[0];  
};  
  
int main() {  
   // allocate 7 elements for b field  
   S2* s2 = (S2*)new int[sizeof(S2) + 7*sizeof(int)];  
   s2->b[6] = 100;  
}  
```