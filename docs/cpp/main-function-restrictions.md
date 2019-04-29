---
title: Restrições da função main
ms.date: 11/04/2016
f1_keywords:
- Main
helpviewer_keywords:
- main function, restrictions on using
ms.assetid: 7b3df731-344b-44a8-850c-11cbcbfbfa83
ms.openlocfilehash: 9ccea987b05c7854e78ba1621fd6c0a065d73d5a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301832"
---
# <a name="main-function-restrictions"></a>Restrições da função main

Várias restrições se aplicam para o **principal** função que não se aplicam a quaisquer outras funções do C++. O **principal** função:

- Não pode ser sobrecarregado (consulte [sobrecarregamento de função](function-overloading.md)).

- Não pode ser declarado como **embutido**.

- Não pode ser declarado como **estático**.

- Não pode ter seu endereço removido.

- Não pode ser chamada.

## <a name="see-also"></a>Consulte também

[main: inicialização de programa](../cpp/main-program-startup.md)