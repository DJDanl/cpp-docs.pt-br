---
title: "Erro do Compilador C3740 | Microsoft Docs"
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
  - "C3740"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3740"
ms.assetid: edb17a90-2307-4df6-943d-580460d26d2b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3740
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

os modelos não podem origem ou para receber eventos  
  
 Uma classe ou uma estrutura templated não podem conter [eventos](../../cpp/event-handling.md).  
  
 O seguinte exemplo gera C3740:  
  
```  
// C3740.cpp  
template <typename T>   // Delete the template specification  
struct E {  
   __event void f();   // C3740  
};  
  
int main() {  
}  
```