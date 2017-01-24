---
title: "Erro do Compilador C2776 | Microsoft Docs"
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
  - "C2776"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2776"
ms.assetid: 9d80addc-62c7-40fc-a2cc-60303abb87df
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2776
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

somente um “” obtém o método pode ser especificado pela propriedade  
  
 Você só pode especificar uma função de `get` no atributo [propriedade](../../cpp/property-cpp.md) estendido.  Esse erro ocorre quando várias funções de `get` são especificadas.  
  
 O seguinte exemplo gera C2776:  
  
```  
// C2776.cpp  
struct A {  
   __declspec(property(get=GetProp,get=GetPropToo))  
   // try the following line instead  
   // __declspec(property(get=GetProp))  
      int prop;   // C2776  
   int GetProp(void);  
   int GetPropToo(void);  
};  
```