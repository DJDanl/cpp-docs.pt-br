---
title: Gramática de pré-processador | Microsoft Docs
ms.custom: ''
ms.date: 09/04/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- preprocessor
- grammar, preprocessor
- preprocessor, grammar
ms.assetid: 6cd33fad-0b08-4592-9be8-7359c43e24e9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 56df4d0bfdaf87ace87a9f9dcbde85166929e642
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43766110"
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador

*linha do controle*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#define** *identificador* *cadeia de caracteres de token*<sub>otimizado</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#define** <em>identificador</em>**(** *identificador*<sub>aceitar</sub> **,** ... **,** *identificador*<sub>aceitar</sub> **)** *token de cadeia de caracteres*<sub>otimizado</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#include** **"** *caminho-spec* **"**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#include** **\<** *especificação de caminho* **>**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#line** *sequência de dígitos***"** *filename* **"**<sub>otimizado  </sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#undef** *identificador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#error** *cadeia de caracteres de token*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#pragma** *cadeia de caracteres de token*

*constant-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**definido (** *identificador* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**definido** *identificador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;qualquer expressão de constante

*condicional* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Se parte* *partes elif*<sub>aceitar</sub> *parte else*<sub>aceitar</sub> *Part&lt;3}{4&gt;opt&lt;4}{5&gt;endif-line&lt;5*

*Se parte* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*if-line* *texto*

*if-line* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#if** *expressão constante*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#ifdef** *identificador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#ifndef** *identificador*

*elif partes* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*linha elif* *texto*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*partes elif* *linha elif* *texto*

*linha elif* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#elif** *expressão constante*

*outra parte* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*linha Else* *texto*

*outra linha* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#else**

*linha endif* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#endif**

*sequência de dígitos* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Dígito*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de dígitos* *dígito*

*Dígito* : um dos<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**

*cadeia de caracteres de token* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Cadeia de caracteres de tokens

*token* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Palavra-chave*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Identificador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Constante*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*operador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*punctuator*

*nome do arquivo* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Nome de arquivo válido do sistema operacional

*especificação de caminho* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Caminho de arquivo válido

*texto* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Qualquer sequência de texto

> [!NOTE]
> Os seguintes não terminais são expandidos na [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência da linguagem C++*: *constante*, *expressão constante* , *identificador*, *palavra-chave*, *operador*, e *punctuator*.

## <a name="see-also"></a>Consulte também

[Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)