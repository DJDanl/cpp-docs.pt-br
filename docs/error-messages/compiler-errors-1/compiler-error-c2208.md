---
title: "Erro do Compilador C2208 | Microsoft Docs"
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
  - "C2208"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2208"
ms.assetid: 9ae704bc-bf70-45f1-8e47-0470f21edd4e
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2208
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: nenhum membro definidas usando esse tipo  
  
 Um identificador que resolve um nome de tipo está em uma declaração de agregação, mas o compilador não pode declarar um membro.  
  
 O seguinte exemplo gera C2208:  
  
```  
// C2208.cpp  
class C {  
   C;   // C2208  
   C(){}   // OK  
};  
```