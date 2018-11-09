---
title: Constantes de caractere C
ms.date: 11/04/2016
helpviewer_keywords:
- characters, constants
- (') single quotation mark
- constants, character
- single quotation mark
ms.assetid: 388ae7d7-2c3a-44d6-a507-63f541ecd2da
ms.openlocfilehash: 684763b5ce3983b6efc44db9499c139c84f6e3aa
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50507179"
---
# <a name="c-character-constants"></a>Constantes de caractere C

Uma “constante de caractere” é formada colocando um único caractere do conjunto de caracteres representável entre aspas simples (**' '**). As constantes de caractere são usadas para representar caracteres no [conjunto de caracteres de execução](../c-language/execution-character-set.md).

## <a name="syntax"></a>Sintaxe

*character-constant*: **'** *c-char-sequence* **'**

**L'** *c-char-sequence* **'**

*c-char-sequence*: *c-char*

*c-char-sequence c-char*

*c-char*: Qualquer membro do conjunto de caracteres de origem, exceto aspas únicas (**'**), barra invertida (**\\**) ou caractere de nova linha

*escape-sequence*

*escape-sequence*: *simple-escape-sequence*

*octal-escape-sequence*

*hexadecimal-escape-sequence*

*simple-escape-sequence*: um dentre **\a \b \f \n \r \t \v**

**\\' \\" \\\ \\?**

*octal-escape-sequence*: **\\**  *octal-digit*

**\\**  *octal-digit octal-digit*

**\\**  *octal-digit octal-digit octal-digit*

*hexadecimal-escape-sequence*: **\x**  *hexadecimal-digit*

*hexadecimal-escape-sequence hexadecimal-digit*

## <a name="see-also"></a>Consulte também

[Constantes C](../c-language/c-constants.md)