---
title: C3851 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
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
ms.workload:
- cplusplus
ms.openlocfilehash: 792d13ece8b864b3d8d7e251bf530f685a02ccf7
ms.sourcegitcommit: 770f6c4a57200aaa9e8ac6e08a3631a4b4bdca05
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/16/2018
---
# <a name="compiler-error-c3851"></a>C3851 de erro do compilador
'char': um-nome de caractere universal não pode designar um caractere no conjunto de caracteres básicas  
  
 No código compilado como C++, você não pode usar um nome de caractere universal que representa um caractere no conjunto de caracteres de origem básico fora de uma cadeia de caracteres ou literal de caractere. Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets.md). No código compilado como C, você não pode usar um nome de caractere universal para caracteres no intervalo 0x20-0x7f, inclusive, exceto 0x24 ('$'), 0x40 (' @'), ou 0x60 (' ').  
  
 Os exemplos a seguir geram C3851 e mostram como corrigi-lo:  
  
```cpp  
// C3851.cpp  
int main()  
{  
   int test1_\u0041 = 0;   // C3851, \u0041 = 'A' in basic character set  
   int test2_A = 0;        // OK  
}  
```