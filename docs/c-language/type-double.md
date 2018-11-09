---
title: Tipo duplo
ms.date: 11/04/2016
helpviewer_keywords:
- mantissas, floating-point variables
- type double
- portability [C++], type double
- double data type
ms.assetid: 17c85b24-1475-4d41-a03c-ddf2d6561d34
ms.openlocfilehash: 42f8ed943fd9d034d5cae8cb057e094363b27d8e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532256"
---
# <a name="type-double"></a>Tipo duplo

Os valores de precisão double com tipo double têm 8 bytes. O formato é semelhante ao formato de float, exceto que tem um expoente excess-1023 de 11 bits e uma mantissa de 52 bits, mais 1 bit implícito de ordem alta. Esse formato fornece um intervalo de aproximadamente 1.7E-308 a 1.7E+308 para o tipo double.

**Seção específica da Microsoft**

O tipo double contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa. O intervalo é +/-1.7E308 com pelo menos 15 dígitos de precisão.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)