---
title: "Erro do Compilador C2870 | Microsoft Docs"
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
  - "C2870"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2870"
ms.assetid: 80523ee9-1fd3-4dc4-8a77-5083deb99066
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2870
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“name”: uma definição de namespace deve aparecer no escopo do arquivo ou imediatamente em outra definição de namespace  
  
 Você definiu o namespace `name` incorretamente.  Os namespaces devem ser definidas no escopo do arquivo \(fora de todos os blocos e classes\) ou imediatamente em outra namespace.  
  
 O seguinte exemplo gera C2870:  
  
```  
// C2870.cpp  
// compile with: /c  
int main() {  
   namespace A { int i; };   // C2870  
}  
```