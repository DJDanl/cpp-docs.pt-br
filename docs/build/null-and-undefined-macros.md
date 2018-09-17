---
title: Macros nulas e indefinidas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, undefined macros
- Null macros in NMAKE
- macros, null and undefined
- undefined macros and NMAKE
- NMAKE program, null macros
ms.assetid: 1db4611a-1755-4328-b00f-d35365af8b6c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eee6e713715e4709af990878224261a41f5470e3
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45702631"
---
# <a name="null-and-undefined-macros"></a>Macros nulas e indefinidas

Macros nulas e indefinidas expandir para cadeias de caracteres nulas, mas uma macro definida como uma cadeia de caracteres nula é considerada definido em expressões de pré-processamento. Para definir uma macro como uma cadeia de caracteres nula, especificar nenhum caractere, exceto o tabulações ou espaços depois do sinal de igual (=) em uma linha de comando ou arquivo de comando e coloque a cadeia de caracteres nula ou a definição entre aspas duplas (""). Para excluir uma macro, use **! UNDEF.** Para obter mais informações, consulte [diretivas de pré-processamento de Makefile](../build/makefile-preprocessing-directives.md).

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)