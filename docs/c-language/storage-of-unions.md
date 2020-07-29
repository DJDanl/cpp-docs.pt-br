---
title: Armazenamento de uniões
ms.date: 11/04/2016
helpviewer_keywords:
- storage, union
- union keyword [C], storage
- union keyword [C]
ms.assetid: b33d246a-8d20-41c4-89b2-ab05f1428792
ms.openlocfilehash: 64e8b5184eeccd4de6d196e40ec464807bec93e7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211652"
---
# <a name="storage-of-unions"></a>Armazenamento de uniões

O armazenamento associado a uma variável de união é o armazenamento necessário para o maior membro da união. Quando um membro menor é armazenado, a variável de união pode conter espaço de memória não utilizado. Todos os membros são armazenados no mesmo espaço de memória e começam no mesmo endereço. O valor armazenado é substituído sempre que um valor é atribuído a um membro diferente. Por exemplo:

```
union         /* Defines a union named x */
{
    char *a, b;
    float f[20];
} x;
```

Os membros da `x` União são, em ordem de sua declaração, um ponteiro para um **`char`** valor, um **`char`** valor e uma matriz de **`float`** valores. O armazenamento alocado para `x` é o armazenamento necessário para a matriz `f`de 20 elementos, pois `f` é o membro mais longo da união. Como nenhuma marca é associada à união, seu tipo é sem nome ou “anônimo”.

## <a name="see-also"></a>Confira também

[Declarações Union](../c-language/union-declarations.md)
