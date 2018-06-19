---
title: Tipo double | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- mantissas, floating-point variables
- type double
- portability [C++], type double
- double data type
ms.assetid: 17c85b24-1475-4d41-a03c-ddf2d6561d34
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f0eb8fb3952b1825bff730d5d22222b56cdb4ecf
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32387337"
---
# <a name="type-double"></a>Tipo duplo
Os valores de precisão double com tipo double têm 8 bytes. O formato é semelhante ao formato de float, exceto que tem um expoente excess-1023 de 11 bits e uma mantissa de 52 bits, mais 1 bit implícito de ordem alta. Esse formato fornece um intervalo de aproximadamente 1.7E-308 a 1.7E+308 para o tipo double.  
  
 **Seção específica da Microsoft**  
  
 O tipo double contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa. O intervalo é +/-1.7E308 com pelo menos 15 dígitos de precisão.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)