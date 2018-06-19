---
title: Operações bit a bit com sinal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- bitwise operations
- signed bitwise operations
ms.assetid: 1e5cf65b-ee32-41a0-a5c2-82c1854091f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c3ddd1c32beb5660fd1fa3c0160756734b4c1923
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32385251"
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