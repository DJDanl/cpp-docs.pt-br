---
title: Armazenamento de uniões
ms.date: 11/04/2016
helpviewer_keywords:
- storage, union
- union keyword [C], storage
- union keyword [C]
ms.assetid: b33d246a-8d20-41c4-89b2-ab05f1428792
ms.openlocfilehash: 49b99dc17fd7bdddd8a47e3bfd5913a70a7631a7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157912"
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

Os membros da união `x` são, por ordem de declaração, um ponteiro para um valor `char`, um valor `char` e uma matriz de valores **float**. O armazenamento alocado para `x` é o armazenamento necessário para a matriz `f`de 20 elementos, pois `f` é o membro mais longo da união. Como nenhuma marca é associada à união, seu tipo é sem nome ou “anônimo”.

## <a name="see-also"></a>Confira também

[Declarações de união](../c-language/union-declarations.md)
