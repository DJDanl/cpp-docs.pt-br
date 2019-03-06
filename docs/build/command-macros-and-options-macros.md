---
title: Macros de comando e opções
ms.date: 11/04/2016
helpviewer_keywords:
- options macros
- command macros in NMAKE
- macros, options macros
- macros, command macros
ms.assetid: 50dff03c-0dc3-4a8a-9a17-57e0e4ea9bac
ms.openlocfilehash: daf8c243f95f7cc12a3d3b1c5cf16f5a384c9671
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57418291"
---
# <a name="command-macros-and-options-macros"></a>Macros de comando e opções

Macros de comando são predefinidas para produtos da Microsoft. Macros de opções representam as opções para esses produtos e não são definidas por padrão. Ambos são usados nas regras de inferência de tipos predefinidos e podem ser usados em blocos de descrição ou regras de inferência de tipos definidos pelo usuário. Macros de comando podem ser redefinidas para representar a parte ou toda uma linha de comando, incluindo as opções. Macros de opções geram uma cadeia de caracteres nula se deixado indefinido.

|Produto da Microsoft|Macro de comando|Definido como|Macro de opções|
|-----------------------|-------------------|----------------|-------------------|
|Macro Assembler|**AS**|ml|**AFLAGS**|
|Compilador básico|**BC**|bc|**BFLAGS**|
|Compilador C|**CC**|cl|**CFLAGS**|
|Compilador C++|**CPP**|cl|**CPPFLAGS**|
|Compilador C++|**CXX**|cl|**CXXFLAGS**|
|Compilador de Recurso|**RC**|rc|**RFLAGS**|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](../build/special-nmake-macros.md)
