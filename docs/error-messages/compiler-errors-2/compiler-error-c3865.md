---
title: "Erro do Compilador C3865 | Microsoft Docs"
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
  - "C3865"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3865"
ms.assetid: 9bc62bb0-4fb8-4856-a5cf-c7cb4029a596
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3865
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“calling\_convention”: pode ser usado somente em funções de membro nativos  
  
 Uma convenção de chamada foi usada em uma função que tenha uma função a um global ou em uma função de membro gerenciado.  A convenção de chamada só pode ser usada em uma função de membro nativo \(não gerenciado\).  
  
 Para obter mais informações, consulte [Convenções de chamada](../Topic/Calling%20Conventions.md).  
  
 O seguinte exemplo gera C3865:  
  
```  
// C3865.cpp  
// compile with: /clr  
// processor: x86  
void __thiscall Func(){}   // C3865  
  
// OK  
struct MyType {  
   void __thiscall Func(){}  
};  
```