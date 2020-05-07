---
title: Tipos incompletos
ms.date: 11/04/2016
helpviewer_keywords:
- void keyword [C], incomplete
- types [C], incomplete
- incomplete types
- unions, incomplete
- arrays [C], incomplete types
- void keyword [C]
- structures, incomplete
ms.assetid: 01bc0cf6-9fa7-458c-9371-ecbe54ea6aee
ms.openlocfilehash: e7a5cd7624b55e7bce0fbd09451ab42426f5bc37
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232885"
---
# <a name="incomplete-types"></a>Tipos incompletos

Um *tipo incompleto* é um tipo que descreve um identificador, mas que não tem informações necessárias para determinar o tamanho do identificador. Um tipo incompleto pode ser:

- Um tipo de estrutura cujos membros você ainda não especificou.

- Um tipo de união cujos membros você ainda não especificou.

- Um tipo de matriz cuja dimensão você ainda não especificou.

O tipo **void** é um tipo incompleto que não pode ser concluído. Para concluir um tipo incompleto, especifique as informações ausentes. Os exemplos a seguir mostram como criar e concluir os tipos incompletos.

- Para criar um tipo incompleto de estrutura, declare um tipo de estrutura sem especificar seus membros. Neste exemplo, o ponteiro `ps` aponta para um tipo incompleto de estrutura chamado `student`.

    ```C
    struct student *ps;
    ```

- Para concluir um tipo incompleto de estrutura, declare o mesmo tipo de estrutura posteriormente no mesmo escopo com seus membros especificados, como em

    ```C
    struct student
    {
        int num;
    }                   /* student structure now completed */
    ```

- Para criar um tipo incompleto de matriz, declare um tipo de matriz sem especificar sua contagem de repetições. Por exemplo: 

    ```C
    char a[];  /* a has incomplete type */
    ```

- Para concluir um tipo incompleto de matriz, declare o mesmo nome posteriormente no mesmo escopo com sua contagem de repetições especificada, como em

    ```C
    char a[25]; /* a now has complete type */
    ```

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
