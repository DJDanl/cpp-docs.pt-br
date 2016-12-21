---
title: "Erro do Compilador C2147 | Microsoft Docs"
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
  - "C2147"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2147"
ms.assetid: d1adb3bf-7ece-4815-922c-ad7492fb6670
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2147
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

erro de sintaxe: o identificador “” é uma nova palavra\-chave  
  
 Um identificador que foi usado agora é uma palavra\-chave reservada no idioma.  
  
 O seguinte exemplo gera C2147:  
  
```  
// C2147.cpp  
// compile with: /clr  
int main() {  
   int gcnew = 0;   // C2147  
   int i = 0;   // OK  
}  
```