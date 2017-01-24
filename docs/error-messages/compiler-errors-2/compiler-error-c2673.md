---
title: "Erro do Compilador C2673 | Microsoft Docs"
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
  - "C2673"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2673"
ms.assetid: 780230c0-619b-4a78-b01d-ff5886306741
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2673
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: as funções globais não têm “esse” ponteiros  
  
 Uma função global tentar acessar `this`.  
  
 O seguinte exemplo gera C2673:  
  
```  
// C2673.cpp  
int main() {  
   this = 0;   // C2673  
}  
```