---
title: "Erro do Compilador C3062 | Microsoft Docs"
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
  - "C3062"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3062"
ms.assetid: 78632e6d-255f-42c3-b124-31a9194ff86d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3062
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

enum “”: o enumerador requer o valor desde que o tipo subjacente é “tipo”  
  
 Você pode especificar um tipo subjacente para uma enumeração.  No entanto, alguns tipos exigem que você atribuir valores a cada enumerador.  
  
 Para obter mais informações sobre enum, consulte [classe de enum](../../windows/enum-class-cpp-component-extensions.md).  
  
 O seguinte exemplo gera C3062:  
  
```  
// C3062.cpp  
// compile with: /clr  
  
enum class MyEnum : bool { a };   // C3062  
enum class MyEnum2 : bool { a = true};   // OK  
```