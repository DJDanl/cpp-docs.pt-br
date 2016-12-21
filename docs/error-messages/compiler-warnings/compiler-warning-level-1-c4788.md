---
title: "Compilador C4788 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4788"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4788"
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4788 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: o identificador foi truncado “para numerar caracteres”  
  
 O compilador limita o comprimento máximo permitido um nome de função.  Quando o compilador gerenciar funclets para o código de EH\/SHE forma, o nome de funclet acrescentando ao nome da função com qualquer texto, por exemplo “\_\_catch”, “\_\_unwind”, ou outra cadeia de caracteres.  
  
 O nome de funclet resultante pode ser muito longo, e o compilador truncar\-o\-&z e gerencie\-lo\-á C4788.  
  
 Para resolver esse aviso, encurte o nome da função original.  Se a função é uma função ou método do modelo criando c, use um typedef para a parte do nome.  Por exemplo:  
  
```  
C1<x, y, z<T>>::C2<a,b,c>::f  
```  
  
 pode ser substituído por:  
  
```  
typedef C1<x, y, z<T>>::C2<a,b,c> new_class ;  
new_class::f  
```  
  
 Esse aviso ocorre apenas no compilador de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] .