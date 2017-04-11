---
title: Usando os operadores Additive | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], addition
- additive operators
ms.assetid: 7d54841e-436d-4ae8-9865-1ac1829e6f22
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 04e23f9694193a05d48b7fcdff717d06e448e877
ms.lasthandoff: 04/01/2017

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
