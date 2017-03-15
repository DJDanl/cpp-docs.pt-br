---
title: Valores | Microsoft Docs
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
ms.assetid: 24003f89-220f-4f93-be7a-b650c26157d7
caps.latest.revision: 9
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 94884482c75b7944735e0f4bd7c36669ced490c1
ms.lasthandoff: 02/25/2017

---
# <a name="values"></a>Valores
**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de números de ponto flutuante  
  
 O tipo **float** contém 32 bits: 1 para o sinal, 8 para o exponente e 23 para a mantissa. O intervalo é +/– 3.4E38 com pelo menos 7 dígitos de precisão.  
  
 O tipo **double** contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa. O intervalo é +/– 1.7E308 com pelo menos 15 dígitos de precisão.  
  
 O tipo **long double** contém 80 bits: 1 para o sinal, 15 para o expoente e 64 para a mantissa. O intervalo é +/– 1.2E4932 com pelo menos 19 dígitos de precisão. Observe que, com o compilador Microsoft C, a representação do tipo **long double** é idêntico à do tipo **double**.  
  
## <a name="see-also"></a>Consulte também  
 [Matemática de ponto flutuante](../c-language/floating-point-math.md)
