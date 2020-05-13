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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326294"
---
# <a name="c-character-constants"></a>Constantes de caractere C

Uma “constante de caractere” é formada colocando um único caractere do conjunto de caracteres representável entre aspas simples (**' '**). As constantes de caractere são usadas para representar caracteres no [conjunto de caracteres de execução](../c-language/execution-character-set.md).

## <a name="syntax"></a>Sintaxe

*caractere-constante*: **'** *c-Char-Sequence* **'**

**L '** *c-Char-Sequence* **'**

*c-Char-Sequence*: *c-Char*

*c-char-sequence c-char*

*c-char*: Qualquer membro do conjunto de caracteres de origem, exceto aspas únicas (**'**), barra invertida (**\\**) ou caractere de nova linha

*sequência de escape*

*escape-sequence*: *simple-escape-sequence*

*octal-escape-sequence*

*sequência de escape hexadecimal*

*simple-escape-sequence*: um dentre **\a \b \f \n \r \t \v**

**\\' \\" \\\ \\?**

*octal-escape-sequência*: **\\** *octal-dígito*  

**\\**  *dígito octal octal-dígito*

**\\**  *dígito octal-dígito octal-dígito*

*hexadecimal-escape-sequence*: **\x**  *hexadecimal-digit*

*hexadecimal-escape-sequence hexadecimal-digit*

## <a name="see-also"></a>Confira também

[Constantes C](../c-language/c-constants.md)
