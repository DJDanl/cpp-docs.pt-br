---
title: 2.7.2.7 copyin
ms.date: 11/04/2016
ms.assetid: 76cfb9f8-bf65-4585-adbf-fd933f5606b4
ms.openlocfilehash: 65bb8faba085e5582e779fa0e9d5bf1a91a39f0e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50545438"
---
# <a name="2727-copyin"></a>2.7.2.7 copyin

O **copyin** cláusula fornece um mecanismo para atribuir o mesmo valor para **threadprivate** variáveis para cada thread em que a equipe a região paralela em execução. Para cada variável especificada em uma **copyin** cláusula, o valor da variável no thread principal da equipe é copiada, como se por atribuição às cópias privadas de thread no início da região paralela. A sintaxe do **copyin** cláusula é da seguinte maneira:

```

copyin(
variable-list
)

```

As restrições para o **copyin** cláusula são da seguinte maneira:

- Uma variável que é especificada na **copyin** cláusula deve ter um operador de atribuição de cópia acessível inequívoca.

- Uma variável que é especificada na **copyin** cláusula deve ser um **threadprivate** variável.