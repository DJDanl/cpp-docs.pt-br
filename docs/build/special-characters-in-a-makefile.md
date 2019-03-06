---
title: Caracteres especiais em um makefile
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, special characters
- makefiles, special characters
- special characters, in NMAKE macros
- macros, special characters
ms.assetid: 92c34ab5-ca6b-4fc0-bcf4-3172eaeda9f0
ms.openlocfilehash: e2703adbbdba392b1a317e2656c6f3dba30a36b6
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57420746"
---
# <a name="special-characters-in-a-makefile"></a>Caracteres especiais em um makefile

Para usar um caractere especial de NMAKE como um caractere literal, coloque um acento circunflexo (^) na frente dele. NMAKE ignora acentos circunflexos que precedem outros caracteres. Os caracteres especiais são:

`:  ;  #  (  )  $  ^  \  {  }  !  @  —`

Um acento circunflexo (^) dentro de uma cadeia de caracteres entre aspas é tratado como um caractere de acento circunflexo literal. Um cursor no final de uma linha insere um caractere de nova linha literal em uma cadeia de caracteres ou uma macro.

Em macros, uma barra invertida (\\) seguido por uma nova linha será substituído por um espaço.

Nos comandos, um símbolo de porcentagem (%) é um especificador de arquivo. Para representar % literalmente em um comando, especifique dois sinais de porcentagem (%) no lugar de uma única. Em outras situações, NMAKE interpreta um único % literalmente, mas ele sempre interpreta um duplo % % como um único %. Portanto, para representar um literal % %, especificar qualquer um dos sinais de três por cento, % % %, ou sinais de porcentagem de quatro, % % %.

Para usar o símbolo de cifrão ($) como um caractere literal em um comando, especifique duas cifrão ($$). Esse método também pode ser usado em outras situações onde ^ $ funciona.

## <a name="see-also"></a>Consulte também

[Conteúdo de um makefile](../build/contents-of-a-makefile.md)
