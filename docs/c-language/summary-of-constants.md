---
title: Resumo de constantes
ms.date: 11/04/2016
helpviewer_keywords:
- constants, C
ms.assetid: 4158234c-e189-4e25-970f-52a04bc6380a
ms.openlocfilehash: f927d977d818bed28c5fd7392f7933cd1a63ced3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157730"
---
# <a name="summary-of-constants"></a>Resumo de constantes

*constante*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*constante de ponto flutuante*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inteiro-constante*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Enumeração-constante*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*constante de caractere*

*floating-point-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*fractional-constant* *exponent-part*<sub>opt</sub> *floating-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *exponent-part* *floating-suffix*<sub>opt</sub>

*fractional-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*aceitar sequência de dígitos*<sub>opt</sub> **.** *digit-sequence*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de dígitos*  **.**

*exponent-part*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de dígitos de* *sinal* **e** <sub>aceitação</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Sequência de dígitos de* *sinal* **E** <sub>aceitação</sub>

*sign*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**+ -**

*sequência de dígitos*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*dígito*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *digit*

*floating-suffix*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**f l F L**

*integer-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*decimal-constant* *integer-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*binary-constant* *integer-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*octal-constant* *integer-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*hexadecimal-constant* *integer-suffix*<sub>opt</sub>

*decimal-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*dígito diferente de zero*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*decimal-constant* *digit*

*binary-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0b** *binary-digit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0B** *-dígito binário*

*octal-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*octal-constant* *octal-digit*

*hexadecimal-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;dígito **0x***hexadecimal*  <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0X**  *hexadecimal-digit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*hexadecimal-constant* *hexadecimal-digit*

*nonzero-digit*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**1 2 3 4 5 6 7 8 9**

*octal-digit*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7**

*hexadecimal-digit*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**a b c d e f**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**A B C D E F**

*unsigned-suffix*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**u U**

*long-suffix*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**l L**

*character-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**'** *c-Char-Sequence* **'**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**L '** *c-Char-Sequence* **'**

*integer-suffix*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unsigned-suffix* *long-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*long-suffix* *unsigned-suffix*<sub>opt</sub>

*c-char-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*c-Char*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*c-char-sequence* *c-char*

*c-Char*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Qualquer membro do conjunto de caracteres de origem, exceto a aspa simples (**'**), barra invertida (**\\**) ou sequência de escape de caractere de nova linha

*escape-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de escape simples*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*octal-sequência de escape*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de escape hexadecimal*

*simple-escape-sequence*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\a \b \f \n \r \t \v**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\\' \\" \\\ \\?**

*octal-sequência de escape*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\\***dígito octal*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\\***octal-digit* *dígito octal octal-* dígito<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\\**dígito octal *-dígito octal* *octal-digit* *-dígito*

*hexadecimal-escape-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\x** *hexadecimal-digit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*hexadecimal-escape-sequence* *hexadecimal-digit*

## <a name="see-also"></a>Confira também

[Gramática lexical](../c-language/lexical-grammar.md)<br/>
