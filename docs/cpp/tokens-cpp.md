---
title: TokensC++()
ms.date: 11/04/2016
helpviewer_keywords:
- tokens [C++]
- parsing, C++ tokens
- translation units
- white space, in C++ tokens
ms.assetid: aa812fd0-6d47-4f3f-aee0-db002ee4d8b9
ms.openlocfilehash: cd104b7308716ca182374bbff2df61731c84d574
ms.sourcegitcommit: 878a164fe6d550ca81ab87d8425c8d3cd52fe384
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/22/2019
ms.locfileid: "68376260"
---
# <a name="tokens-c"></a>TokensC++()

Um token é o menor elemento de um programa em C/C++ que é significativo para o compilador. O analisador C++ reconhece os seguintes tipos de tokens: identificadores, palavra-chave, literais, operadores, pontuadores e outros separadores. Um fluxo desses tokens compõe uma unidade de tradução.

Os tokens são geralmente separados por *espaço em branco*. O espaço em branco pode ser um ou vários:

- Espaços em branco

- Tabulações horizontais ou verticais

- Novas linhas

- Feeds de formulário

- Comentários

O analisador reconhece palavras-chave, identificadores, literais, operadores e pontuadores. Para obter informações sobre tipos de token específicos, consulte [palavras-chave](../cpp/keywords-cpp.md), [identificadores](../cpp/identifiers-cpp.md), [números numéricos, booleanos e de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md), literais [de cadeia de caracteres e caracteres](../cpp/string-and-character-literals-cpp.md), [literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md), [ C++ operadores internos, Precedência e Associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)e [pontuadores](../cpp/punctuators-cpp.md). O espaço em branco é ignorado, exceto conforme necessário para separar os tokens.

Os tokens de pré-processamento são usados nas fases de pré-processamento para gerar o fluxo de token passado para o compilador. As categorias de token de pré-processamento são nomes de cabeçalho, identificadores, números de pré-processamento, literais de caracteres, literais de cadeia de caracteres, operadores de pré-processamento e pontuadores e caracteres de espaço não-branco únicos que não correspondem a uma das outras categorias. Literais de caracteres e de cadeia de caracteres podem ser literais definidos pelo usuário. Os tokens de pré-processamento podem ser separados por espaços em branco ou comentários.

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