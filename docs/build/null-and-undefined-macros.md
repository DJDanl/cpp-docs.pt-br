---
title: Macros nulas e indefinidas
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, undefined macros
- Null macros in NMAKE
- macros, null and undefined
- undefined macros and NMAKE
- NMAKE program, null macros
ms.assetid: 1db4611a-1755-4328-b00f-d35365af8b6c
ms.openlocfilehash: f6f294234f7244b65137742e1fe8abaa37a676a5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498911"
---
# <a name="null-and-undefined-macros"></a>Macros nulas e indefinidas

Macros nulas e indefinidas expandir para cadeias de caracteres nulas, mas uma macro definida como uma cadeia de caracteres nula é considerada definido em expressões de pré-processamento. Para definir uma macro como uma cadeia de caracteres nula, especificar nenhum caractere, exceto o tabulações ou espaços depois do sinal de igual (=) em uma linha de comando ou arquivo de comando e coloque a cadeia de caracteres nula ou a definição entre aspas duplas (""). Para excluir uma macro, use **! UNDEF.** Para obter mais informações, consulte [diretivas de pré-processamento de Makefile](../build/makefile-preprocessing-directives.md).

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)