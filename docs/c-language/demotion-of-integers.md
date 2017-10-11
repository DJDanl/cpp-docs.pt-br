---
title: Rebaixamento de inteiros | Microsoft Docs
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
- demoting integers
ms.assetid: 51fb3654-60b0-4de7-80eb-bd910086c18a
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: e09a81ca21f6e00777322178dcdf1c09ef22dd5b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
