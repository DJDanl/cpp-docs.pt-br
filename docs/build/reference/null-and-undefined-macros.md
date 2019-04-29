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
ms.openlocfilehash: 0f4905473dd6914547ad6ac129d34e438992c2af
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320494"
---
# <a name="null-and-undefined-macros"></a>Macros nulas e indefinidas

Macros nulas e indefinidas expandir para cadeias de caracteres nulas, mas uma macro definida como uma cadeia de caracteres nula é considerada definido em expressões de pré-processamento. Para definir uma macro como uma cadeia de caracteres nula, especificar nenhum caractere, exceto o tabulações ou espaços depois do sinal de igual (=) em uma linha de comando ou arquivo de comando e coloque a cadeia de caracteres nula ou a definição entre aspas duplas (""). Para excluir uma macro, use **! UNDEF.** Para obter mais informações, consulte [diretivas de pré-processamento de Makefile](makefile-preprocessing-directives.md).

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](defining-an-nmake-macro.md)
