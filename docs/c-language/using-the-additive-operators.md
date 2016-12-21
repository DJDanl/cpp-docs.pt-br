---
title: "Usando os operadores Additive | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "operadores aditivos"
  - "operadores [C++], adição"
ms.assetid: 7d54841e-436d-4ae8-9865-1ac1829e6f22
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando os operadores Additive
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os exemplos a seguir, que ilustram os operadores de adição e subtração, usam estas declarações:  
  
```  
int i = 4, j;  
float x[10];  
float *px;  
```  
  
 Estas instruções são equivalentes:  
  
```  
px = &x[4 + i];  
px = &x[4] + i;    
```  
  
 O valor de `i` é multiplicado pelo comprimento de um **float** e adicionado a `&x[4]`.  O valor de ponteiro resultante é o endereço de `x[8]`.  
  
```  
j = &x[i] - &x[i-2];  
```  
  
 Nesse exemplo, o endereço do terceiro elemento de `x` \(determinado por `x[i–2]`\) é subtraído do endereço do quinto elemento de `x` \(determinado por `x[i]`\).  A diferença é dividida pelo comprimento de um **float**; o resultado é o valor inteiro 2.  
  
## Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)