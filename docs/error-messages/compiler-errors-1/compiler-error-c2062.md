---
title: "Erro do Compilador C2062 | Microsoft Docs"
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
  - "C2062"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2062"
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2062
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

tipo “tipo” inesperado  
  
 O compilador não esperava um nome de tipo.  
  
 O seguinte exemplo gera C2062:  
  
```  
// C2062.cpp  
// compile with: /c  
struct A {  : int l; };   // C2062  
struct B { private: int l; };   // OK  
```  
  
 C2062 também pode ocorrer devido à maneira que os identificadores do compilador indefinidas na lista de parâmetros de um construtor.  Se o compilador encontrar digitado incorretamente \(?\) um tipo indefinido, suponha que o construtor é uma expressão, e emite C2062.  Para resolver, para usar apenas definidos em uma lista de parâmetros de construtor.