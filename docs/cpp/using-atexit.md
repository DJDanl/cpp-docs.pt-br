---
title: Usando atexit
ms.date: 11/04/2016
f1_keywords:
- atexit
helpviewer_keywords:
- atexit function
ms.assetid: d28fda17-c3d4-4af6-ba44-f44886bbb237
ms.openlocfilehash: 06baba59b5765f853f081b34d73be28a187730ba
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257992"
---
# <a name="using-atexit"></a>Usando atexit

Com o [atexit](../c-runtime-library/reference/atexit.md) função, você pode especificar uma função de processamento de saída que é executado antes do encerramento do programa. Nenhum objeto estático global inicializado antes da chamada para **atexit** são destruídos antes da execução da função de processamento de saída.

## <a name="see-also"></a>Consulte também

[Considerações de término adicionais](../cpp/additional-termination-considerations.md)