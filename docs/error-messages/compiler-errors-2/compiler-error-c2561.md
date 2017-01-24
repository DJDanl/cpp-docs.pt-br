---
title: "Erro do Compilador C2561 | Microsoft Docs"
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
  - "C2561"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2561"
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2561
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: a função deve retornar um valor  
  
 A função foi declarado como retornar um valor, mas a definição de função não contém uma instrução de `return` .  
  
 Esse erro pode ser causado por um protótipo incorreto da função:  
  
1.  Se a função não retorna um valor, declarar a função com o tipo de retorno [nulo](../../cpp/void-cpp.md).  
  
2.  Verifique se todos os possíveis ramificações da função retorna um valor do tipo declarado no protótipo.  
  
3.  C\+\+ funções que contém as rotinas de assembly embutidos que armazenam o valor de retorno no registro de `AX` pode precisar de uma instrução de retorno.  Copie o valor em `AX` a uma variável temporária e retornar a variável da função.  
  
 O seguinte exemplo gera C2561:  
  
```  
// C2561.cpp  
int Test(int x) {  
   if (x) {  
      return;   // C2561  
      // try the following line instead  
      // return 1;  
   }  
   return 0;  
}  
  
int main() {  
   Test(1);  
}  
```