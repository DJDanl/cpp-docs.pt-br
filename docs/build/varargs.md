---
title: Varargs | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: aac0c54b-0a2d-4a22-b1de-ee41381a3eb1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8305eaddf87a2e67b797bedff1944dbcbbbdbd41
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713635"
---
# <a name="varargs"></a>Varargs

Se os parâmetros são passados por meio de varargs (por exemplo, argumentos de reticências), essencialmente, o parâmetro normal passando aplica incluindo despejar os argumentos subsequentes e quintas. Novamente é responsabilidade do computador chamado argumentos de despejo que ter seus endereços obtidos. Para valores de ponto flutuante somente, o inteiro e o registro de ponto flutuante conterá o valor de float, caso o receptor espera que o valor em registros de inteiros.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)