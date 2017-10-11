---
title: C3851 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3851
dev_langs:
- C++
helpviewer_keywords:
- C3851
ms.assetid: da30c21c-33aa-4439-8fb3-2f5021ea4985
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ed2a62b859e37455041171c81bb6830db372c697
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3851"></a>C3851 de erro do compilador
'char': um-nome de caractere universal não pode designar um caractere no conjunto de caracteres básicas  
  
 No código compilado como C++, você não pode usar um nome de caractere universal que representa um caractere no conjunto de caracteres de origem básico fora de uma cadeia de caracteres ou literal de caractere. Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets2.md). No código compilado como C, você não pode usar um nome de caractere universal para caracteres no intervalo 0x20-0x7f, inclusive, exceto 0x24 ('$'), 0x40 (' @'), ou 0x60 (' ').  
  
 Os exemplos a seguir geram C3851 e mostram como corrigi-lo:  
  
```cpp  
// C3851.cpp  
int main()  
{  
   int test1_\u0041 = 0;   // C3851, \u0041 = 'A' in basic character set  
   int test2_A = 0;        // OK  
}  
```
