---
title: Restrições da função main
ms.date: 11/04/2016
f1_keywords:
- Main
helpviewer_keywords:
- main function, restrictions on using
ms.assetid: 7b3df731-344b-44a8-850c-11cbcbfbfa83
ms.openlocfilehash: 9ccea987b05c7854e78ba1621fd6c0a065d73d5a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50555721"
---
# <a name="main-function-restrictions"></a>Restrições da função main

Várias restrições se aplicam para o **principal** função que não se aplicam a quaisquer outras funções do C++. O **principal** função:

- Não pode ser sobrecarregado (consulte [sobrecarregamento de função](function-overloading.md)).

- Não pode ser declarado como **embutido**.

- Não pode ser declarado como **estático**.

- Não pode ter seu endereço removido.

- Não pode ser chamada.

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)