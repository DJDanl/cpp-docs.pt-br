---
title: Declaradores abstratos C
ms.date: 11/04/2016
helpviewer_keywords:
- declarators, abstract
- abstract declarations
ms.assetid: 6a556ad7-0555-421a-aa02-294d77cda8b5
ms.openlocfilehash: 540b938e2c4121f189216942bc06630fc61ee19c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220854"
---
# <a name="c-abstract-declarators"></a>Declaradores abstratos C

Um declarador abstrato é um declarador sem um identificador, consistindo em um ou mais modificadores de ponteiro, matriz ou função. O modificador de ponteiro ( <strong>\*</strong> ) sempre precede o identificador em um Declarador; a matriz (**[]**) e os modificadores de função ( **()** ) seguem o identificador. Sabendo disso, você pode determinar onde o identificador apareceria em um declarador abstrato e interpretar o declarador corretamente. Consulte [Interpretar declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md) para obter mais informações e exemplos de declaradores complexos. Geralmente, **`typedef`** pode ser usado para simplificar os declaradores. Consulte [Declarações de Typedef](../c-language/typedef-declarations.md).

Os declaradores abstratos podem ser complexos. Os parênteses em um declarador abstrato complexo especificam uma determinada interpretação, como fazem no caso dos declaradores complexos em declarações.

Estes exemplos ilustram declaradores abstratos:

```
int *         // The type name for a pointer to type int:

int *[3]      // An array of three pointers to int

int (*) [5]   // A pointer to an array of five int

int *()       // A function with no parameter specification
              // returning a pointer to int

// A pointer to a function taking no arguments and
// returning an int

int (*) ( void )

// An array of an unspecified number of constant pointers to
// functions each with one parameter that has type unsigned int
// and an unspecified number of other parameters returning an int

int (*const []) ( unsigned int, ... )
```

> [!NOTE]
> O declarador abstrato que consiste em um conjunto de parênteses vazios, **( )**, não é permitido porque é ambíguo. É impossível determinar se o lugar do identificador implícito é dentro dos parênteses (nesse caso, ele é um tipo não modificado) ou antes dos parênteses (nesse caso, ele é um tipo de função).

## <a name="see-also"></a>Confira também

[Declaradores e declarações de variáveis](../c-language/declarators-and-variable-declarations.md)
