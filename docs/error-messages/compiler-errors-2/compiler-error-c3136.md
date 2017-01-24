---
title: "Erro do Compilador C3136 | Microsoft Docs"
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
  - "C3136"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3136"
ms.assetid: c77103cd-00f7-408e-b74b-4f8562039d31
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3136
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

contadores de “interface”: uma interface COM só pode herdar de outra interface COM, “interface” não é uma interface COM  
  
 Uma interface para que você aplicou [atributo de interface](../../windows/interface-attributes.md) herda de uma interface que não é uma interface COM.  Uma interface COM herda por fim de `IUnknown`.  Qualquer interface precedida por um atributo de interface é uma interface COM.  
  
 O exemplo a seguir gerenciar C3136:  
  
```  
// C3136.cpp  
#include "unknwn.h"  
  
__interface A   // C3136  
// try the following line instead  
// _interface A : IUnknown  
{  
   int a();  
};  
  
[object]  
__interface B : A  
{  
   int aa();  
};  
```