---
title: Especificador de classe de armazenamento externa
ms.date: 07/10/2018
helpviewer_keywords:
- extern keyword [C]
- storage class specifiers, extern
- extern keyword [C], storage class specifier
- external linkage, storage-class specifiers
- external linkage, extern modifier
ms.assetid: 6e16d927-291f-49e4-986c-9d91a482a441
ms.openlocfilehash: e3242f86e30dcf3227586400b83266ad366ec7e8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217097"
---
# <a name="extern-storage-class-specifier"></a>Especificador de classe de armazenamento externa

Uma variável declarada com o **`extern`** especificador de classe de armazenamento é uma referência a uma variável com o mesmo nome definido em outro arquivo de origem. Ela é usada para tornar visível a definição da variável de nível externo. Uma variável declarada como **`extern`** não tem armazenamento alocado para si mesma; é apenas um nome.

## <a name="example"></a>Exemplo

Este exemplo ilustra declarações de nível interno e externo:

```c

// Source1.c

int i = 1;

// Source2. c

#include <stdio.h>

// Refers to the i that is defined in Source1.c:
extern int i;

void func(void);

int main()
{
    // Prints 1:
    printf_s("%d\n", i);
    func();
    return;
}

void func(void)
{
    // Address of global i assigned to pointer variable:
    static int *external_i = &i;

    // This definition of i hides the global i in Source.c:
    int i = 16;

    // Prints 16, 1:
    printf_s("%d\n%d\n", i, *external_i);
}
```

Neste exemplo, a variável `i` é definida em Source1.c com um valor inicial de 1. Uma **`extern`** declaração em origem2. c torna ' i ' visível nesse arquivo.

Na `func` função, o endereço da variável global `i` é usado para inicializar a variável de **`static`** ponteiro `external_i` . Isso funciona porque a variável global tem **`static`** tempo de vida, o que significa que seu endereço não é alterado durante a execução do programa. Em seguida, uma variável `i` é definida dentro do escopo de `func` como uma variável local com o valor inicial 16. Essa definição não afeta o valor da variável `i` de nível externo, que é ocultada pelo uso do respectivo nome para a variável local. O valor de `i` global agora está acessível apenas através do ponteiro `external_i`.

## <a name="see-also"></a>Confira também

[Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)
