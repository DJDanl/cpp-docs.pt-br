---
title: Resumo da gramática do pré-processador (C/C++)
description: Define e descreve a sintaxe de gramáticaC++ do pré-processador do Microsoft C/Compiler (MSVC).
ms.date: 08/29/2019
helpviewer_keywords:
- grammar
- preprocessor, grammar
ms.assetid: 0acb6e9b-364c-4ef8-ace4-7be980521121
ms.openlocfilehash: 99e7e8218a80e28d67767392cadfb5c4918a3bfe
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302179"
---
# <a name="preprocessor-grammar-summary-cc"></a>Resumo da gramática do pré-processador (C/C++)

Este artigo descreve a gramática formal do C e C++ do pré-processador. Ele aborda a sintaxe de diretivas e operadores de pré-processamento. Para obter mais informações, consulte Diretivas de [pré-processador](../preprocessor/preprocessor.md) e [pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md).

## <a name="definitions"></a>Definições para o resumo da gramática

Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.

Os não terminais são espaços reservados na sintaxe. A maioria é definida em outra parte deste resumo da sintaxe. As definições podem ser recursivas. Os seguintes não terminais são definidos na seção [convenções lexicais](../cpp/lexical-conventions.md) da  *C++ referência de linguagem*:

*constante*, *expressão constante*, *identificador*, *palavra-chave*, *operador*, *pontuador*

Um componente opcional é indicado pelo <sub>opt</sub> subscrito. Por exemplo, a sintaxe a seguir indica uma expressão opcional entre chaves:

**{** *expressão*<sub>opt</sub> **}**

## <a name="conventions"></a>Convenções de documento

As convenções usam atributos diferentes de fonte para componentes diferentes de sintaxe. Os símbolos e as fontes são os seguintes:

| Atributo | Descrição |
|---------------|-----------------|
| *nonterminal* | O tipo em itálico indica não terminais. |
| **#include** | Os terminais de tipo em negrito são palavras reservadas a literais e símbolos que devem ser inseridos como mostrado. Os caracteres nesse contexto sempre diferenciam maiúsculas de minúsculas. |
| <sub>opt</sub> | Não terminais seguidos por <sub>opt</sub> são sempre opcionais.|
| default typeface | Os caracteres no conjunto descrito ou listados nesta face de tipos podem ser usados como terminais em instruções. |

Um sinal de dois pontos ( **:** ) depois de um não terminal introduz sua definição. As definições alternativas são listadas em linhas separadas.

Nos blocos de sintaxe de código, esses símbolos no tipo padrão têm um significado especial:

| Símbolo | Descrição |
|---|---|
| \[] | Colchetes circundam um elemento opcional. |
| {\|} | As chaves envolvem elementos alternativos, separados por barras verticais. |
| ... | Indica que o padrão de elemento anterior pode ser repetido. |

Nos blocos de sintaxe de código, vírgulas (`,`), pontos (`.`), ponto-e-vírgula (`;`), dois-pontos (`:`), parênteses (`( )`), aspas duplas (`"`) e aspas simples (`'`) são literais.

## <a name="grammar"></a>Gramática do pré-processador

*linha de controle*: \
&nbsp;<sub></sub> &nbsp;&nbsp;&nbsp;*identificador* *de token-cadeia de caracteres* **#define**
&nbsp;&nbsp;&nbsp;&nbsp; *identificador* **de #define (** <sub>aceitar</sub> identificador **,** ... **,** *identificador*<sub>opcional</sub> **)** *token-cadeia de caracteres*<sub>\</sub>
&nbsp;&nbsp;&nbsp;&nbsp; **#include** **"** _caminho-especificação_ **"** \
&nbsp;&nbsp;&nbsp;&nbsp; **#include** **\<** _caminho-spec_ **>** \
&nbsp;&nbsp;&nbsp;&nbsp; **#line** *sequência de dígitos de seqüência* **"** _nome do arquivo_ **"** <sub>\</sub>
&nbsp;&nbsp;&nbsp;&nbsp; **#undef** *identificador*\
&nbsp;&nbsp;&nbsp;&nbsp; **#error** *cadeia de caracteres de token*\
&nbsp;&nbsp;&nbsp;&nbsp; **#pragma** *token-string*

*expressão de constante*: \
&nbsp;&nbsp;&nbsp;&nbsp;**definido (** *identificador* **)** \
&nbsp;&nbsp;&nbsp;&nbsp; *identificador* definido\
&nbsp;&nbsp;&nbsp;&nbsp;qualquer outra expressão constante

*condicional*: \
&nbsp;&nbsp;&nbsp;&nbsp;*If-Part* *elif-* Parts<sub>aceitar</sub> *else de parte, peça*<sub></sub> *endif – linha*

*If-Part*: \
&nbsp;&nbsp;&nbsp;&nbsp;*if-line* *text*

*If-line*: \
&nbsp;&nbsp;&nbsp;&nbsp; **#if** *expressão constante*\
&nbsp;&nbsp;&nbsp;&nbsp; **#ifdef** *identificador*\
&nbsp;&nbsp;&nbsp;&nbsp; **#ifndef** *identifier*

*elif-partes*: \
&nbsp;&nbsp;&nbsp;&nbsp;*texto* *de linha de elif*\
&nbsp;&nbsp;&nbsp;&nbsp;*elif-parts* *elif-line* *text*

*elif-linha*: \
&nbsp;&nbsp;&nbsp;&nbsp; **#elif** *constant-expression*

*else-parte*: \
&nbsp;&nbsp;&nbsp;&nbsp;*else-line* *text*

*else-linha*: \
&nbsp;&nbsp;&nbsp;&nbsp; **#else**

*endif-linha*: \
&nbsp;&nbsp;&nbsp;&nbsp; **#endif**

*sequência de dígitos*: \
&nbsp;&nbsp;&nbsp;&nbsp;*dígito*\
&nbsp;&nbsp;&nbsp;dígito *de sequência de dígitos* &nbsp;

*dígito*: um de \
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**

*cadeia de caracteres de token*: \
&nbsp;&nbsp;&nbsp;&nbsp;cadeia de tokens

*token*: \
&nbsp;&nbsp;&nbsp;&nbsp;*palavra-chave*\
&nbsp;&nbsp;&nbsp;*identificador* de &nbsp;\
&nbsp;&nbsp;&nbsp;&nbsp;*constante*\
*operador* &nbsp;&nbsp;&nbsp;&nbsp;\
&nbsp;&nbsp;&nbsp;&nbsp;*punctuator*

*nome do arquivo*: \
&nbsp;&nbsp;&nbsp;&nbsp;nome de arquivo do sistema operacional legal

*caminho-especificação*: \
&nbsp;&nbsp;&nbsp;&nbsp;Caminho de arquivo válido

*texto*: \
&nbsp;&nbsp;&nbsp;&nbsp;qualquer sequência de texto

> [!NOTE]
> Os seguintes não terminais são expandidos na seção [convenções lexicais](../cpp/lexical-conventions.md) da referência de  *C++ linguagem*: *constante*, *expressão constante*, *identificador*, *palavra-chave*, *operador*e *pontuador*.


## <a name="see-also"></a>Veja também

[Referência deC++ C/pré-processador](../preprocessor/c-cpp-preprocessor-reference.md)
