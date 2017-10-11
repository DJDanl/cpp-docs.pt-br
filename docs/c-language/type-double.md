---
title: Tipo double | Microsoft Docs
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
- mantissas, floating-point variables
- type double
- portability [C++], type double
- double data type
ms.assetid: 17c85b24-1475-4d41-a03c-ddf2d6561d34
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: aa4e81164a02774f7f9aa034f2c1a5492233600d
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="type-double"></a>Tipo duplo
Os valores de precisão double com tipo double têm 8 bytes. O formato é semelhante ao formato de float, exceto que tem um expoente excess-1023 de 11 bits e uma mantissa de 52 bits, mais 1 bit implícito de ordem alta. Esse formato fornece um intervalo de aproximadamente 1.7E-308 a 1.7E+308 para o tipo double.  
  
 **Seção específica da Microsoft**  
  
 O tipo double contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa. O intervalo é +/-1.7E308 com pelo menos 15 dígitos de precisão.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)
