---
title: Tokens (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- tokens [C++]
- parsing, C++ tokens
- translation units
- white space, in C++ tokens
ms.assetid: aa812fd0-6d47-4f3f-aee0-db002ee4d8b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ba2e1a6cc36e4e5f2f785c1e5dff03c6fb5e392d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="tokens-c"></a>Tokens (C++)
Um token é o menor elemento de um programa em C/C++ que é significativo para o compilador. O analisador C++ reconhece os seguintes tipos de tokens: identificadores, palavra-chave, literais, operadores, pontuadores e outros separadores. Um fluxo desses tokens compõe uma unidade de tradução.  
  
 Tokens geralmente são separados por *espaço em branco*. O espaço em branco pode ser um ou vários:  
  
-   Espaços em branco  
  
-   Tabulações horizontais ou verticais  
  
-   Novas linhas  
  
-   Avanços de página  
  
-   Comentários  
  
 O analisador reconhece as palavras-chave, identificadores, literais, operadores e sinais de pontuação. Para obter informações sobre tipos específicos de token, consulte [palavras-chave](../cpp/keywords-cpp.md), [identificadores](../cpp/identifiers-cpp.md), [numérico, booleano e literais de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md), [cadeia de caracteres e literais de caracteres ](../cpp/string-and-character-literals-cpp.md), [Literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md), [operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md), e [sinais de pontuação](../cpp/punctuators-cpp.md). Espaço em branco é ignorado, exceto conforme necessário separar os tokens.  
  
 Símbolos de pré-processamento são usados nas fases de pré-processamento para gerar o fluxo do token passado para o compilador. As categorias de token de pré-processamento são nomes de cabeçalho, identificadores, números de pré-processamento, literais de caracteres, literais de cadeia de caracteres, operadores de pré-processamento e sinais de pontuação e caracteres de espaço em branco não único que não correspondem a uma das categorias de. Literais de caracteres e cadeia de caracteres podem ser literais definidos pelo usuário. Símbolos de pré-processamento pode ser separado por espaços em branco ou comentários.  
  
 O analisador separa os tokens do fluxo de entrada criando o maior token possível usando os caracteres de entrada em uma verificação da esquerda para a direita. Considere este fragmento de código:  
  
```  
a = i+++j;  
```  
  
 Talvez o programador que criou o código tenha desejado criar uma destas duas instruções:  
  
```  
a = i + (++j)  
  
a = (i++) + j  
```  
  
 Como o analisador cria o maior token possível a partir do fluxo de entrada, ele seleciona a segunda interpretação, criando os tokens `i++`, `+` e `j`.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)