---
title: Rebaixamento de inteiros | Microsoft Docs
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
- demoting integers
ms.assetid: 51fb3654-60b0-4de7-80eb-bd910086c18a
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
ms.openlocfilehash: 468b88ccb64c06e64e9b234188295b3fcc148b1f
ms.lasthandoff: 04/01/2017

---
# <a name="demotion-of-integers"></a>Rebaixamentos de inteiros
**ANSI 3.2.1.2** O resultado da conversão de um inteiro para um número inteiro com sinal mais curto ou o resultado da conversão de um número inteiro sem sinal para um número inteiro com sinal de mesmo comprimento, se o valor não puder ser representado  
  
 Quando um inteiro **long** é convertido em **short** ou **short** é convertido em `char`, os bytes menos significativos são retidos.  
  
 Por exemplo, esta linha  
  
```  
short x = (short)0x12345678L;  
```  
  
 atribui o valor 0x5678 a `x`, e esta linha  
  
```  
char y = (char)0x1234;  
```  
  
 atribui o valor 0x34 a `y`.  
  
 Quando variáveis com sinal são convertidas em sem sinal e vice-versa, os padrões de bits permanecem os mesmos. Por exemplo, converter -2 (0xFE) em um valor sem sinal gera 254 (também 0xFE).  
  
## <a name="see-also"></a>Consulte também  
 [Inteiros](../c-language/integers.md)
