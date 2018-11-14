---
title: 2.7.2.7 copyin
ms.date: 11/04/2016
ms.assetid: 76cfb9f8-bf65-4585-adbf-fd933f5606b4
ms.openlocfilehash: 20db32530ee60967245497cdfb12a0fce103f7b7
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51519523"
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