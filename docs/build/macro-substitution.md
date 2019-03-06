---
title: Substituição de macro
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, macro substitution
- macros, NMAKE
- substitution macros in NMAKE
ms.assetid: 47465cfe-fd92-49db-aebe-7c2d7ecceb73
ms.openlocfilehash: d82aed5a34b7cafad0e40146470972dc6ff02424
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414675"
---
# <a name="macro-substitution"></a>Substituição de macro

Quando *macroname* será invocado, cada ocorrência do *string1* em sua definição cadeia de caracteres é substituída por *string2*.

## <a name="syntax"></a>Sintaxe

```
$(macroname:string1=string2)
```

## <a name="remarks"></a>Comentários

Substituição de macro diferencia maiusculas de minúsculas e é literal; *string1* e *string2* não é possível invocar as macros. Substituição não modifica a definição original. Você pode substituir o texto em qualquer macro predefinida, exceto [ $$@ ](../build/filename-macros.md).

Não há espaços ou tabulações precedem os dois-pontos; qualquer após os dois-pontos são interpretados como literal. Se *string2* for null, todas as ocorrências de *string1* são excluídas da cadeia de caracteres de definição da macro.

## <a name="see-also"></a>Consulte também

[Usando uma macro NMAKE](../build/using-an-nmake-macro.md)
