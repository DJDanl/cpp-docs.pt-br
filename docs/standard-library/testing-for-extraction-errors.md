---
title: Testando erros de extração
ms.date: 11/04/2016
helpviewer_keywords:
- extraction errors
ms.assetid: 6a681028-adba-4557-8f7b-f137932905f8
ms.openlocfilehash: db551a21fd33665d83b11373f040be158406d492
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68453673"
---
# <a name="testing-for-extraction-errors"></a>Testando erros de extração

Gere as funções de processamento de erro, abordadas em [Funções de processamento de erro](../standard-library/output-file-stream-member-functions.md), aplicadas a fluxos de entrada. É importante testar erros durante a extração. Considere esta instrução:

```cpp
cin>> n;
```

Se `n` for um inteiro com sinal, um valor maior que 32.767 (o valor máximo permitido ou MAX_INT) definirá o bit `fail` do fluxo e o objeto `cin` se tornará inutilizável. Todas as extrações posteriores resultam em um retorno imediato sem valor armazenado.

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)
