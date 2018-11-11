---
title: literais String C
ms.date: 08/31/2018
helpviewer_keywords:
- string literals, syntax
- strings [C++], string literals
- literal strings, C
ms.assetid: 4b05523e-49a2-4900-b21a-754350af3328
ms.openlocfilehash: bd8b49645e34224cbea7e801f197bfbcbc012915
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50635580"
---
# <a name="c-string-literals"></a>literais String C

Um “literal de cadeia de caracteres” é uma sequência de caracteres do conjunto de caracteres de origem entre aspas duplas (**" "**). Os literais de cadeia de caracteres são usados para representar uma sequência de caracteres que, juntos, formam uma cadeia de caracteres terminada em nulo. Você sempre deve prefixar literais de cadeia de caracteres largos com a letra **L**.

## <a name="syntax"></a>Sintaxe

*string-literal*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**"** *s-char-sequence*<sub>opt</sub> **"**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**L"** *s-char-sequence*<sub>opt</sub> **"**

*s-char-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*s-char*

&nbsp;&nbsp;&nbsp;&nbsp;*s-char-sequence* *s-char*

*s-char*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;qualquer membro do conjunto de caracteres de origem, exceto a marca de aspas duplas ("), a barra invertida (\\) ou o caractere de nova linha<br/>

&nbsp;&nbsp;&nbsp;&nbsp;*escape-sequence*

## <a name="remarks"></a>Comentários

O exemplo abaixo é um literal de cadeia de caracteres simples:

```C
char *amessage = "This is a string literal.";
```

Todos os códigos de escape listados na tabela [Sequências de escape](../c-language/escape-sequences.md) são válidos em literais de cadeia de caracteres. Para representar uma marca de aspas duplas em um literal de cadeia de caracteres, use a sequência de escape **\\"**. As aspas simples (**'**) podem ser representadas sem uma sequência de escape. A barra invertida (**\\**) deve ser seguida por uma segunda barra invertida (**\\\\**) quando aparecer em uma cadeia de caracteres. Quando uma barra invertida aparece no fim de uma linha, é sempre interpretada como um caractere de continuação de linha.

## <a name="see-also"></a>Consulte também

[Elementos de C](../c-language/elements-of-c.md)
