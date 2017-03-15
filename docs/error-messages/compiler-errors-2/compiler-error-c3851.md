---
title: C3851 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 630198992aaf227c422d9f71b2c93f2f01f7bd84
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3851"></a>C3851 de erro do compilador
'char': nome universal-caracteres não é possível designar um caractere no conjunto de caracteres básicas  
  
 No código compilado c++, você não pode usar um nome universal de caracteres que representa um caractere no conjunto de caracteres de origem básico fora de uma cadeia de caracteres ou literal de caractere. Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets2.md). No código compilado como C, você não pode usar um nome universal de caracteres para caracteres no intervalo 0x20-0x7f, inclusive, exceto 0x24 ('$'), 0x40 (' @'), ou 0x60 (' ').  
  
 Os exemplos a seguir geram C3851 e mostram como corrigi-lo:  
  
```cpp  
// C3851.cpp  
int main()  
{  
   int test1_\u0041 = 0;   // C3851, \u0041 = 'A' in basic character set  
   int test2_A = 0;        // OK  
}  
```
