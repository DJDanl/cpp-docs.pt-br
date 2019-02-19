---
title: Constantes de caractere C
ms.date: 11/04/2016
helpviewer_keywords:
- characters, constants
- (') single quotation mark
- constants, character
- single quotation mark
ms.assetid: 388ae7d7-2c3a-44d6-a507-63f541ecd2da
ms.openlocfilehash: 5d87b57726f741cc96f2180de33cae01403786ec
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152762"
---
# <a name="c-character-constants"></a>Constantes de caractere C

Uma “constante de caractere” é formada colocando um único caractere do conjunto de caracteres representável entre aspas simples (**' '**). As constantes de caractere são usadas para representar caracteres no [conjunto de caracteres de execução](../c-language/execution-character-set.md).

## <a name="syntax"></a>Sintaxe

*character-constant*: **'** *c-char-sequence* **'**

**L'** *c-char-sequence* **'**

*c-char-sequence*: *c-char*

*c-char-sequence c-char*

*c-char*: Qualquer membro do conjunto de caracteres de origem, exceto a marca de aspas simples (**'**), a barra invertida (**\\**) ou o caractere de nova linha

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
