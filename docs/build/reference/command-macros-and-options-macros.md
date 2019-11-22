---
title: Macros de comando e opções
description: Descreve as macros predefinidas do NMAKE para ferramentas de compilação e suas opções.
ms.date: 11/20/2019
helpviewer_keywords:
- options macros
- command macros in NMAKE
- macros, options macros
- macros, command macros
ms.assetid: 50dff03c-0dc3-4a8a-9a17-57e0e4ea9bac
no-loc:
- AS
- AFLAGS
- CC
- CFLAGS
- CPP
- CPPFLAGS
- CXX
- CXXFLAGS
- RC
- RFLAGS
- ias
- ml
- ml64
- cl
- rc
ms.openlocfilehash: d5c4477fd97e2a6c48dbac4d0ce83f7fd5f12ad6
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303169"
---
# <a name="command-macros-and-options-macros"></a>Macros de comando e opções

Macros de comando são predefinidas para produtos Microsoft. As macros de opções representam opções para esses produtos e são indefinidas por padrão. Ambos são usados em regras de inferência predefinidas e podem ser usados em blocos de descrição ou em regras de inferência definidas pelo usuário. Macros de comando podem ser redefinidas para representar parte ou toda uma linha de comando, incluindo opções. As macros de opções geram uma cadeia de caracteres nula se não forem definidas.

|Produto da Microsoft|Macro de comando|Definido como|Macro de opções|
|-----------------------|-------------------|----------------|-------------------|
|Macro Assembler|**AS**|ml, ias ou ml64|**AFLAGS**|
|Compilador C|**CC**|cl|**CFLAGS**|
|Compilador C++|**CPP**|cl|**CPPFLAGS**|
|Compilador C++|**CXX**|cl|**CXXFLAGS**|
|Compilador de Recurso|**RC**|rc|**RFLAGS**|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](special-nmake-macros.md)
