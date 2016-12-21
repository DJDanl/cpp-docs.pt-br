---
title: "Erro do Compilador C2733 | Microsoft Docs"
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
  - "C2733"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2733"
ms.assetid: 67f83561-c633-407c-a2ee-f9fd16e165bf
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2733
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

segundo vínculo de C da função sobrecarregada “function” não permitida  
  
 Mais de uma função sobrecarregada é declarada com esse tipo de C.  Ao usar o vínculo de C, somente um formulário de uma função especificada pode ser armazenada.  Como as funções sobrecarregadas têm o mesmo nome undecorated, não podem ser usadas com programas de 2.0 c.  
  
 O seguinte exemplo gera C2733:  
  
```  
// C2733.cpp  
extern "C" {  
   void F1(int);  
}  
  
extern "C" {  
   void F1();   // C2733  
   // try the following line instead  
   // void F2();  
}  
```