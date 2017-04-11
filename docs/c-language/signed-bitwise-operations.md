---
title: "Operações bit a bit com sinal | Microsoft Docs"
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
- bitwise operations
- signed bitwise operations
ms.assetid: 1e5cf65b-ee32-41a0-a5c2-82c1854091f6
caps.latest.revision: 6
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
ms.openlocfilehash: e3e4eeb1c71752c7e682bc500afacb730162abca
ms.lasthandoff: 04/01/2017

---
# <a name="signed-bitwise-operations"></a>Operações bit a bit com sinal
**ANSI 3.3** Os resultados de operações bit a bit em inteiros com sinal  
  
 As operações bit a bit em inteiros com sinal funcionam da mesma forma que as operações bit a bit em inteiros sem sinal. Por exemplo, `-16 & 99` pode ser expresso em binário como  
  
```  
  11111111 11110000  
& 00000000 01100011  
  _________________  
  00000000 01100000  
```  
  
 O resultado do AND bit a bit é 96.  
  
## <a name="see-also"></a>Consulte também  
 [Inteiros](../c-language/integers.md)
