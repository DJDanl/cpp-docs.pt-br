---
title: Tokens (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- tokens [C++]
- parsing, C++ tokens
- translation units
- white space, in C++ tokens
ms.assetid: aa812fd0-6d47-4f3f-aee0-db002ee4d8b9
ms.openlocfilehash: 1606df56191ec00ffea543dedd3fd4eda98d01c2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50597295"
---
# <a name="tokens-c"></a>Tokens (C++)

Um token é o menor elemento de um programa em C/C++ que é significativo para o compilador. O analisador C++ reconhece os seguintes tipos de tokens: identificadores, palavra-chave, literais, operadores, pontuadores e outros separadores. Um fluxo desses tokens compõe uma unidade de tradução.

Geralmente, os tokens são separados por *espaço em branco*. O espaço em branco pode ser um ou vários:

- Espaços em branco

- Tabulações horizontais ou verticais

- Novas linhas

- Avanços de página

- Comentários

O analisador reconhece pontuadores, identificadores, literais, operadores e palavras-chave. Para obter informações sobre tipos específicos de token, consulte [palavras-chave](../cpp/keywords-cpp.md), [identificadores](../cpp/identifiers-cpp.md), [numérico, booliano e literais de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md), [cadeia de caracteres e literais de caracteres ](../cpp/string-and-character-literals-cpp.md), [Literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md), [operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md), e [pontuadores](../cpp/punctuators-cpp.md). Espaço em branco é ignorado, exceto conforme necessário separar os tokens.

Tokens de pré-processamento é usado nas fases do pré-processamento para gerar o fluxo do token passado para o compilador. As categorias de token de pré-processamento são nomes de cabeçalho, identificadores, números de pré-processamento, literais de caracteres, literais de cadeia de caracteres, operadores de pré-processamento e pontuadores e caracteres de espaço em branco não únicos que não correspondem a uma das outras categorias. Literais de caracteres e cadeia de caracteres podem ser literais definidos pelo usuário. Tokens de pré-processamento podem ser separados por espaço em branco ou comentários.

O analisador separa os tokens do fluxo de entrada criando o maior token possível usando os caracteres de entrada em uma verificação da esquerda para a direita. Considere este fragmento de código:

```cpp
a = i+++j;
```

Talvez o programador que criou o código tenha desejado criar uma destas duas instruções:

```cpp
a = i + (++j)

a = (i++) + j
```

Como o analisador cria o maior token possível a partir do fluxo de entrada, ele seleciona a segunda interpretação, criando os tokens `i++`, `+` e `j`.

## <a name="see-also"></a>Consulte também

[Convenções lexicais](../cpp/lexical-conventions.md)