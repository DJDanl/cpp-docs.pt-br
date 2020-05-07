---
title: Sequências de escape
ms.date: 11/04/2016
helpviewer_keywords:
- "\r escape sequence"
- double backslash
- horizontal-tab 	 escape sequence
- (') single quotation mark
- "bell character \a escape sequence"
- escape sequences
- hexadecimal escape sequence
- carriage returns
- tab 	 escape sequence
- "\f escape sequence"
- quotation marks, single
- "form feed \f escape sequence"
- "\v escape sequence"
- control character escape sequences
- " symbol in escape sequences"
- octal escape sequence
- escape characters
- "newline character \n escape sequence"
- nongraphic control characters
- question mark, literal
- "\n escape sequence"
- "vertical tab \v escape sequence"
- "\a escape sequence"
- '? symbol'
- '? symbol, escape sequence character'
- "	 escape sequence"
- backspace escape sequence
ms.assetid: 5aef377f-a76c-4d5c-aa04-8308758ad6a8
ms.openlocfilehash: 5de0b5f1a73fcfb6ea0325bea3247ebe4c85d411
ms.sourcegitcommit: 878a164fe6d550ca81ab87d8425c8d3cd52fe384
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/22/2019
ms.locfileid: "68375828"
---
# <a name="escape-sequences"></a>Sequências de escape

As combinações de caracteres que consistem em uma**\\**barra invertida () seguida por uma letra ou por uma combinação de dígitos são chamadas de "sequências de escape". Para representar um caractere de nova linha, aspas simples ou alguns outros caracteres em uma constante de caractere, você deve usar sequências de escape. Uma sequência de escape é considerada um único caractere e, portanto, é válida como uma constante de caractere.

Geralmente, as sequências de escape são usadas para especificar ações como retornos de carro e movimentos de tabulação em terminais e impressoras. Também são usadas para fornecer representações literais de caracteres não imprimíveis e de caracteres que normalmente têm significados especiais, como as aspas duplas (**"**). A tabela a seguir lista as sequências de escape ANSI e o que elas representam.

Observe que o ponto de interrogação precedido por uma barra invertida (**\\?**) especifica um ponto de interrogação literal em casos em que a sequência de caracteres seria interpretada erroneamente como um trigraph. Consulte [Trígrafos](../c-language/trigraphs.md) para obter mais informações.

### <a name="escape-sequences"></a>Sequências de escape

|Sequência de escape|Representa|
|---------------------|----------------|
|**\a**|Campainha (alerta)|
|**\b**|Backspace|
|**\f**|Avanço de formulário|
|**\n**|Nova linha|
|**\r**|Retorno de carro|
|**\**|Guia horizontal|
|**\v**|Guia vertical|
|**\\'**|Aspas simples|
|**\\"**|Aspas duplas|
|**\\\\**|Barra invertida|
|**\\?**|Ponto de interrogação literal|
|**\\***OOO*|Caractere ASCII em notação octal|
|**\x** *hh*|Caractere ASCII em notação hexadecimal|
|**\X** *HHHH*|Caractere Unicode em notação hexadecimal, se esta sequência de escape é usada em uma constante de caractere largo ou uma literal de cadeia de caracteres Unicode.<br /><br /> Por exemplo, `WCHAR f = L'\x4e00'` ou `WCHAR b[] = L"The Chinese character for one is \x4e00"`.|

**Específico da Microsoft**

Se uma barra invertida precede um caractere que não consta da tabela, o compilador trata o caractere indefinido como o próprio caractere. Por exemplo, `\c` é tratado como um `c`.

**FINAL específico da Microsoft**

As sequências de escape permitem que você envie caracteres de controle não gráficos a um dispositivo de exibição. Por exemplo, o caractere de ESC (**\033**) costuma ser usado como o primeiro caractere de um comando de controle para um terminal ou uma impressora. Algumas sequências de escape são específicas ao dispositivo. Por exemplo, as sequências de escape de tabulação vertical e de avanço de página (**\v** e **\f**) não afetam a saída da tela, mas executam operações de impressora apropriadas.

Você também pode usar a barra invertida**\\**() como um caractere de continuação. Quando um caractere de nova linha (equivalente a pressionar a tecla RETURN) vem logo após a barra invertida, o compilador ignora a barra invertida e o caractere de nova linha e trata a próxima linha como parte da linha anterior. Isso é útil principalmente para definições de pré-processador que ocupam mais do que uma única linha. Por exemplo:

```
#define assert(exp) \
( (exp) ? (void) 0:_assert( #exp, __FILE__, __LINE__ ) )
```

## <a name="see-also"></a>Confira também

[Constantes de caractere C](../c-language/c-character-constants.md)
