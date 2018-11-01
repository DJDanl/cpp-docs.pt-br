---
title: Definindo uma macro NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- macros, NMAKE
- defining NMAKE macros
- NMAKE macros, defining
ms.assetid: 45aae451-9d33-4a3d-8799-2e0cae17070d
ms.openlocfilehash: 860a5766e0d766f7426cb6c1a7eaf5db02686aa4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498964"
---
# <a name="defining-an-nmake-macro"></a>Definindo uma macro NMAKE

## <a name="syntax"></a>Sintaxe

```

macroname=string
```

## <a name="remarks"></a>Comentários

O *macroname* é uma combinação de letras, dígitos e sublinhados (_) até 1.024 caracteres, e é o caso confidenciais. O *macroname* pode conter uma macro invocada. Se *macroname* consiste inteiramente de uma macro invocada, a macro que está sendo invocada não pode ser nulo ou indefinido.

O `string` pode ser qualquer sequência de zero ou mais caracteres. Uma cadeia de caracteres nula contém zero caracteres ou apenas espaços ou tabulações. O `string` pode conter uma invocação de macro.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Caracteres especiais em macros](../build/special-characters-in-macros.md)

[Macros nulas e indefinidas](../build/null-and-undefined-macros.md)

[Onde definir macros](../build/where-to-define-macros.md)

[Precedência em definições de macro](../build/precedence-in-macro-definitions.md)

## <a name="see-also"></a>Consulte também

[Macros e NMAKE](../build/macros-and-nmake.md)