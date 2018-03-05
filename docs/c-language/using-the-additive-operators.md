---
title: Usando os operadores Additive | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], addition
- additive operators
ms.assetid: 7d54841e-436d-4ae8-9865-1ac1829e6f22
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 94e2a63412e4fecd5f358659cc4bf02f90df57ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-the-additive-operators"></a>Usando os operadores Additive
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
  
 O valor de `i` é multiplicado pelo comprimento de um **float** e adicionado a `&x[4]`. O valor de ponteiro resultante é o endereço de `x[8]`.  
  
```  
j = &x[i] - &x[i-2];  
```  
  
 Nesse exemplo, o endereço do terceiro elemento de `x` (determinado por `x[i-2]`) é subtraído do endereço do quinto elemento de `x` (determinado por `x[i]`). A diferença é dividida pelo comprimento de um **float**; o resultado é o valor inteiro 2.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)