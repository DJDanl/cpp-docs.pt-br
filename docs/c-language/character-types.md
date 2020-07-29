---
title: Tipos de caractere
ms.date: 11/04/2016
helpviewer_keywords:
- character data types [C]
- types [C], character
ms.assetid: d3ca8cda-c0d7-43af-9472-697e8ef015ce
ms.openlocfilehash: 5b1306c70cdab423c8758bf3e6c9ac4e9d6507da
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226484"
---
# <a name="character-types"></a>Tipos de caractere

Uma constante de caractere inteiro não precedida pela letra **L** tem o tipo **`int`** . O valor de uma constante de caractere inteiro que contém um único caractere é o valor numérico do caractere interpretado como um inteiro. Por exemplo, o valor numérico do caractere `a` é 97 em decimal e 61 em hexadecimal.

Sintaticamente, uma "constante de caractere largo" é uma constante de caractere prefixada pela letra **L**. Uma constante de caractere largo tem tipo **`wchar_t`** , um tipo inteiro definido no stddef. Arquivo de cabeçalho H. Por exemplo:

```
char    schar =  'x';   /* A character constant          */
wchar_t wchar = L'x';   /* A wide-character constant for
                            the same character           */
```

As constantes de caractere largo têm 16 bits de largura e especificam membros do conjunto estendido de caracteres de execução. Eles permitem que você expresse caracteres em alfabetos que são muito grandes para serem representados por tipo **`char`** . Consulte [Multibyte e caracteres largos](../c-language/multibyte-and-wide-characters.md) para obter mais informações sobre os caracteres largos.

## <a name="see-also"></a>Confira também

[Constantes de caractere C](../c-language/c-character-constants.md)
