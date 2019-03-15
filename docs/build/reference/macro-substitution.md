---
title: Substituição de macro
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, macro substitution
- macros, NMAKE
- substitution macros in NMAKE
ms.assetid: 47465cfe-fd92-49db-aebe-7c2d7ecceb73
ms.openlocfilehash: 43dc9133c53b1c436c0df8c3db66ae8f18604222
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824560"
---
# <a name="macro-substitution"></a>Substituição de macro

Quando *macroname* será invocado, cada ocorrência do *string1* em sua definição cadeia de caracteres é substituída por *string2*.

## <a name="syntax"></a>Sintaxe

```
$(macroname:string1=string2)
```

## <a name="remarks"></a>Comentários

Substituição de macro diferencia maiusculas de minúsculas e é literal; *string1* e *string2* não é possível invocar as macros. Substituição não modifica a definição original. Você pode substituir o texto em qualquer macro predefinida, exceto [ $$@ ](filename-macros.md).

Não há espaços ou tabulações precedem os dois-pontos; qualquer após os dois-pontos são interpretados como literal. Se *string2* for null, todas as ocorrências de *string1* são excluídas da cadeia de caracteres de definição da macro.

## <a name="see-also"></a>Consulte também

[Usando uma macro NMAKE](using-an-nmake-macro.md)
