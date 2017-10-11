---
title: Valores | Microsoft Docs
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
ms.assetid: 24003f89-220f-4f93-be7a-b650c26157d7
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 13f497358ae320263fd7043787abb943f760809b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="values"></a>Valores
**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de números de ponto flutuante  
  
 O tipo **float** contém 32 bits: 1 para o sinal, 8 para o exponente e 23 para a mantissa. O intervalo é +/- 3.4E38 com pelo menos 7 dígitos de precisão.  
  
 O tipo **double** contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa. O intervalo é +/- 1.7E308 com pelo menos 15 dígitos de precisão.  
  
 O tipo **long double** contém 80 bits: 1 para o sinal, 15 para o expoente e 64 para a mantissa. O intervalo é +/- 1.2E4932 com pelo menos 19 dígitos de precisão. Observe que, com o compilador Microsoft C, a representação do tipo **long double** é idêntico à do tipo **double**.  
  
## <a name="see-also"></a>Consulte também  
 [Matemática de ponto flutuante](../c-language/floating-point-math.md)
