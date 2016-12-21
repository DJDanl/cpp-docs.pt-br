---
title: "Erro do Compilador C2470 | Microsoft Docs"
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
  - "C2470"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2470"
ms.assetid: e17d2cb8-b84c-447c-976a-625f0c96f3fe
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2470
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: é semelhante a uma definição de função, mas não há nenhuma lista de parâmetros; corpo aparente de salto  
  
 Uma definição de função está faltando a lista de argumentos.  
  
 O seguinte exemplo gera C2470:  
  
```  
// C2470.cpp  
int MyFunc {};  // C2470  
void MyFunc2() {};  //OK  
  
int main(){  
   MyFunc();  
   MyFunc2();  
}  
```