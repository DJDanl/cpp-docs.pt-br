---
title: Definindo uma macro NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- macros, NMAKE
- defining NMAKE macros
- NMAKE macros, defining
ms.assetid: 45aae451-9d33-4a3d-8799-2e0cae17070d
ms.openlocfilehash: 6eb7c2f7759bda21f1424cef91b1dc814ba8d8ba
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57424100"
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
