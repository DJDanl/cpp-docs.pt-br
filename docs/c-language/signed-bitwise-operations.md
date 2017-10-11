---
title: "Operações bit a bit com sinal | Microsoft Docs"
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
- bitwise operations
- signed bitwise operations
ms.assetid: 1e5cf65b-ee32-41a0-a5c2-82c1854091f6
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 9ffc5335bb28e619f166a524083937d17a59bb97
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
