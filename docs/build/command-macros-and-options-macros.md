---
title: Macros de comando e opções
ms.date: 11/04/2016
helpviewer_keywords:
- options macros
- command macros in NMAKE
- macros, options macros
- macros, command macros
ms.assetid: 50dff03c-0dc3-4a8a-9a17-57e0e4ea9bac
ms.openlocfilehash: f18cfd6ada235485a5fe47bdc94b49631b9abbbe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50601299"
---
# <a name="command-macros-and-options-macros"></a>Macros de comando e opções

Macros de comando são predefinidas para produtos da Microsoft. Macros de opções representam as opções para esses produtos e não são definidas por padrão. Ambos são usados nas regras de inferência de tipos predefinidos e podem ser usados em blocos de descrição ou regras de inferência de tipos definidos pelo usuário. Macros de comando podem ser redefinidas para representar a parte ou toda uma linha de comando, incluindo as opções. Macros de opções geram uma cadeia de caracteres nula se deixado indefinido.

|Produto da Microsoft|Macro de comando|Definido como|Macro de opções|
|-----------------------|-------------------|----------------|-------------------|
|Macro Assembler|**ASSIM COMO ACONTECE**|ml|**AFLAGS**|
|Compilador básico|**CONTINUIDADE DE NEGÓCIOS**|continuidade de negócios|**BFLAGS**|
|Compilador C|**CC**|Cl|**CFLAGS**|
|Compilador C++|**CPP**|Cl|**CPPFLAGS**|
|Compilador C++|**CXX**|Cl|**CXXFLAGS**|
|Compilador de Recurso|**RC**|RC|**RFLAGS**|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](../build/special-nmake-macros.md)