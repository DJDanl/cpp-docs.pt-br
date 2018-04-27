---
title: Testando erros de extração | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- extraction errors
ms.assetid: 6a681028-adba-4557-8f7b-f137932905f8
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9394f387546f9b9dccf72f532148aa2b9161ce15
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="testing-for-extraction-errors"></a>Testando erros de extração

Gere as funções de processamento de erro, abordadas em [Funções de processamento de erro](../standard-library/output-file-stream-member-functions.md), aplicadas a fluxos de entrada. É importante testar erros durante a extração. Considere esta instrução:

```cpp
cin>> n;
```

Se `n` for um inteiro com sinal, um valor maior que 32.767 (o valor máximo permitido ou MAX_INT) definirá o bit `fail` do fluxo e o objeto `cin` se tornará inutilizável. Todas as extrações posteriores resultam em um retorno imediato sem valor armazenado.

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)<br/>
