---
title: Identificadores em expressões primárias
ms.date: 11/04/2016
helpviewer_keywords:
- identifiers, designating objects
ms.assetid: d4602fe6-e7e6-40cc-9823-3b1ebf5d3d38
ms.openlocfilehash: 053720bcdf635a7e09363712259b558d93a2972c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233080"
---
# <a name="identifiers-in-primary-expressions"></a>Identificadores em expressões primárias

Os identificadores podem ter o **float**tipo integral `enum`, `struct`float,,, **Union**, array, pointer ou Function. Um identificador é uma expressão primária contanto que tenha sido declarada como a designação de um objeto (nesse caso, um l-value) ou como uma função (nesse caso, um designador de função). Para obter uma definição de l-value, consulte [Expressões de L-Value e R-Value](../c-language/l-value-and-r-value-expressions.md).

O valor do ponteiro representado por um identificador de matriz não é uma variável, portanto, um identificador de matriz não pode formar o operando esquerdo de uma operação de atribuição e, em virtude disso, não é um l-value modificável.

Um identificador declarado como uma função representa um ponteiro cujo valor é o endereço da função. O ponteiro aborda uma função que retorna um valor de um tipo especificado. Portanto, os identificadores da função também não podem ser l-values em operações de atribuição. Para obter mais informações, consulte [Identificadores](../c-language/c-identifiers.md).

## <a name="see-also"></a>Confira também

[Expressões primárias C](../c-language/c-primary-expressions.md)
