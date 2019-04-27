---
title: Gramática do pré-processador
ms.date: 09/04/2018
helpviewer_keywords:
- preprocessor
- grammar, preprocessor
- preprocessor, grammar
ms.assetid: 6cd33fad-0b08-4592-9be8-7359c43e24e9
ms.openlocfilehash: 6177cf5fddba549e410842ef3f270edcc13d4782
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179874"
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador

*control-line*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#define** *identifier* *token-string*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#define** <em>identificador</em>**(** *identificador*<sub>aceitar</sub> **,** ... **,** *identificador*<sub>aceitar</sub> **)** *token de cadeia de caracteres*<sub>otimizado</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#include** **"** *path-spec* **"**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#include** **\<** *path-spec* **>**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#line** *digit-sequence*  **"** *filename* **"**<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#undef** *identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#error** *token-string*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#pragma** *token-string*

*constant-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**defined(** *identifier* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**defined** *identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;qualquer expressão de constante

*condicional* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*if-part* *elif-parts*<sub>opt</sub> *else-part*<sub>opt</sub> *endif-line*

*if-part* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*if-line* *text*

*if-line* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#if** *constant-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#ifdef** *identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#ifndef** *identifier*

*elif partes* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*elif-line* *text*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*elif-parts* *elif-line* *text*

*elif-line* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#elif** *constant-expression*

*else-part* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*else-line* *text*

*else-line* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#else**

*endif-line* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#endif**

*digit-sequence* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *digit*

*digit* : one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**

*token-string* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Cadeia de caracteres de tokens

*token* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*keyword*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*constant*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*operator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*punctuator*

*nome do arquivo* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Nome de arquivo válido do sistema operacional

*path-spec* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Caminho de arquivo válido

*text* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Qualquer sequência de texto

> [!NOTE]
> Os seguintes não terminais são expandidos na [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência da linguagem C++*: *constante*, *expressão constante* , *identificador*, *palavra-chave*, *operador*, e *punctuator*.

## <a name="see-also"></a>Consulte também

[Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)