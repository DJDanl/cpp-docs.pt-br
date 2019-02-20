---
title: Tipo int
ms.date: 11/04/2016
helpviewer_keywords:
- int data type
- type int
- portability [C++], type int
- signed integers
ms.assetid: 0067ce9a-281e-491a-ae63-632952981e13
ms.openlocfilehash: 848c9799e7ab5cfdfd2b25cc84e55de02c673f3e
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56150006"
---
# <a name="type-int"></a>Tipo int

O tamanho de um item `int` com ou sem sinal é o tamanho padrão de um inteiro em um computador específico. Por exemplo, em sistemas operacionais de 16 bits, o tipo `int` geralmente é 16 bits, ou 2 bytes. Em sistemas operacionais de 32 bits, o tipo `int` geralmente é 32 bits, ou 4 bytes. Assim, o tipo `int` é equivalente ao tipo `short int` ou **long int** e o tipo `unsigned int` é equivalente ao tipo **unsigned short** ou `unsigned long`, dependendo do ambiente de destino. Todos os tipos `int` representam os valores com sinal, a menos que indicado em contrário.

Os especificadores de tipo `int` e `unsigned int` (ou simplesmente `unsigned`) definem determinados recursos da linguagem C (por exemplo, o tipo `enum`). Nesses casos, as definições de `int` e o inteiro sem sinal para uma implementação específica determinam o armazenamento real.

**Seção específica da Microsoft**

Os inteiros com sinal são representados no formato de dois complementos. O bit mais significativo contém o sinal: 1 para negativo, 0 para positivo e zero. O intervalo de valores é determinado em [Limites de Inteiros do C++](../c-language/cpp-integer-limits.md), que é obtido do arquivo de cabeçalho LIMITS.H.

**Fim da seção específica da Microsoft**

> [!NOTE]
>  Os especificadores de tipo int e unsigned int são amplamente usados em programas C porque permitem que um computador específico administre valores inteiros da maneira mais eficiente. No entanto, como os tamanhos dos tipos int e unsigned int variam, os programas que dependem de um int de determinado tamanho não podem ser portáteis para outros computadores. Para tornar os programas mais portáteis, você pode usar expressões com o operador sizeof (como descrito em [O operador sizeof](../c-language/sizeof-operator-c.md)) em vez de tamanhos de dados embutidos em código.

## <a name="see-also"></a>Consulte também

[Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)
