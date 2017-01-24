---
title: "Erro CXX0064 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0064"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0064"
  - "CXX0064"
ms.assetid: aa509e71-0616-41ca-a94e-6c376b041e57
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0064 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível definir o ponto de interrupção na função de membro virtual associado  
  
 Um ponto de interrupção foi definido em uma função de membro virtual por um ponteiro para um objeto, como:  
  
```  
pClass->vfunc( int );  
```  
  
 Um ponto de interrupção pode ser definido em uma função virtual inserindo a classe, como:  
  
```  
Class::vfunc( int );  
```  
  
 Esse erro é idêntico a CAN0064.