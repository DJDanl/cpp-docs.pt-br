---
title: "typeof vai at&#233; T::typeid | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __typeof"
  - "palavra-chave typeid [C++]"
  - "Operador typeid"
ms.assetid: 6a0d35a7-7a1a-4070-b187-cff37cfdc205
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# typeof vai at&#233; T::typeid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador de `typeof` usado em extensões gerenciadas para C\+\+ foi substituído pela palavra\-chave de `typeid` em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Em extensões gerenciadas, o operador de `__typeof()` retorna o objeto associado de `Type*` quando é passada o nome de um tipo gerenciado.  Por exemplo:  
  
```  
// Creates and initializes a new Array instance.  
Array* myIntArray =   
   Array::CreateInstance( __typeof(Int32), 5 );  
```  
  
 Na nova sintaxe, `__typeof` foi substituído por um formulário adicional de `typeid` que retorna `Type^` quando um tipo gerenciado é especificado.  
  
```  
// Creates and initializes a new Array instance.  
Array^ myIntArray =   
   Array::CreateInstance( Int32::typeid, 5 );  
```  
  
## Consulte também  
 [Alteração geral em linguagens](../Topic/General%20Language%20Changes%20\(C++-CLI\).md)   
 [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md)