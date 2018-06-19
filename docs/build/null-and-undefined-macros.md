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
ms.openlocfilehash: 494a084ee5ba1da29c132aa632b647b37f305855
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368464"
---
# <a name="null-and-undefined-macros"></a>Macros nulas e indefinidas
Macros nulas e indefinidas expanda em cadeias de caracteres nulas, mas uma macro definida como uma cadeia de caracteres nula é considerada definido em expressões de pré-processamento. Para definir uma macro como uma cadeia de caracteres nula, especificar nenhum caractere, exceto espaços ou guias após o sinal de igual (=) em uma linha de comando ou arquivo de comando e coloque a cadeia de caracteres nula ou definição de aspas duplas (""). Para remover-uma macro, use **! UNDEF.** Para obter mais informações, consulte [diretivas de pré-processamento de Makefile](../build/makefile-preprocessing-directives.md).  
  
## <a name="see-also"></a>Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)