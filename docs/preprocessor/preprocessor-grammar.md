---
title: Gramática do pré-processador
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor
- grammar, preprocessor
- preprocessor, grammar
ms.assetid: 6cd33fad-0b08-4592-9be8-7359c43e24e9
ms.openlocfilehash: f0916e3cc9bbdb398db693286dacc4517df03557
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222266"
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador

*linha de controle*: \
&nbsp;&nbsp;&nbsp;&nbsp; **#define** *identificador* do *cadeia de caracteres de token* <sub>aceitar</sub>\
&nbsp;&nbsp;&nbsp;&nbsp; **#define** *identificador* do **(** &#x2800;&#x200B;<sub>aceitar</sub> identificador **,** ... **,** *identificador* do &#x200B; <sub></sub>aceitar&#x2800; **)** <sub>aceitar</sub> *cadeia de caracteres de token*\
&nbsp;&nbsp;&nbsp;&nbsp; **#include** **"** _caminho-especificação_ **"** \
&nbsp;&nbsp;&nbsp;&nbsp; **#include** _caminho-especificação_ **\<** **>** \
&nbsp;&nbsp;&nbsp;&nbsp; **#line** *sequência de dígitos* **"** _nome do arquivo_ **"** &#x200B; <sub>aceitar</sub>  \
&nbsp;&nbsp;&nbsp;&nbsp; **#undef** *identificador* do\
&nbsp;&nbsp;&nbsp;&nbsp; **#error** *cadeia de caracteres de token*\
&nbsp;&nbsp;&nbsp;&nbsp; **#pragma** *token-string*

*expressão de constante*: \
&nbsp;&nbsp;&nbsp;&nbsp;**definido (** &#x2800;*identificador*&#x2800; **)** \
&nbsp;&nbsp;&nbsp;&nbsp;**definido** *identificador* do\
&nbsp;&nbsp;&nbsp;&nbsp;qualquer outra expressão constante

*condicional*: \
&nbsp;&nbsp;&nbsp;&nbsp;*If-Part* *elif-partes* <sub>aceitar</sub> *parte else* <sub>aceitar</sub> *endif-linha*

*If-Part*: \
&nbsp;&nbsp;&nbsp;&nbsp;*if-line* *text*

*If-line*: \
&nbsp;&nbsp;&nbsp;&nbsp; **#if** *expressão de constante*\
&nbsp;&nbsp;&nbsp;&nbsp; **#ifdef** *identificador* do\
&nbsp;&nbsp;&nbsp;&nbsp; **#ifndef** *identifier*

*elif-partes*: \
&nbsp;&nbsp;&nbsp;&nbsp;*elif-linha* *texto* de\
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
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *digit*

*dígito*: um de \
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**

*cadeia de caracteres de token*: \
&nbsp;&nbsp;&nbsp;&nbsp;Cadeia de caracteres de tokens

*token*: \
&nbsp;&nbsp;&nbsp;&nbsp;*chaves*\
&nbsp;&nbsp;&nbsp;&nbsp;*ID*\
&nbsp;&nbsp;&nbsp;&nbsp;*amortiza*\
&nbsp;&nbsp;&nbsp;&nbsp;*operador*\
&nbsp;&nbsp;&nbsp;&nbsp;*punctuator*

*nome do arquivo*: \
&nbsp;&nbsp;&nbsp;&nbsp;Nome de arquivo do sistema operacional legal

*caminho-especificação*: \
&nbsp;&nbsp;&nbsp;&nbsp;Caminho de arquivo válido

*texto*: \
&nbsp;&nbsp;&nbsp;&nbsp;Qualquer sequência de texto

> [!NOTE]
> Os seguintes não terminais são expandidos na seção [convenções lexicais](../cpp/lexical-conventions.md) da referência de  *C++ linguagem*: *constante*, *expressão constante*, *identificador*, *palavra-chave*, *operador*e  *pontuador*.

## <a name="see-also"></a>Consulte também

[Resumo da gramática (CC++/)](../preprocessor/grammar-summary-c-cpp.md)
