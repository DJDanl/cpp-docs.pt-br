---
title: Gramática de pré-processador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 1871d1b8281f4dd74733133ede70ed80430246b3
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42538567"
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador
**#define**  *identifier* *token-string*opt  
  
*#* **definir***identificador*[**(** *identificador*aceitar **,** *...*  **,** *identificador*aceitar **)**] *cadeia de caracteres de token*otimizado    
  
**defined(**  *identifier* **)**  
  
**defined**  *identifier*  
  
`#include` **"***path-spec***"**  
  
`#include` **\<***especificação de caminho***>**  
  
**#line**  *digit-sequence*  **"** *filename* **"** opt  
  
*#* **undef***identificador*   
  
**#error**  *token-string*  
  
**#pragma**  *token-string*  
  
*condicional* :  
*Se-part elif-partes*opt*parte else*aceitar*Part&lt;3}{4&gt;opt&lt;4}{5&gt;endif-line&lt;5*  
  
*Se parte* :  
*if-linetext*  
  
*if-line* :  
**#if**  *constant-expression*  
  
**#ifdef**  *identifier*  
  
**#ifndef**  *identifier*  
  
*elif partes* :  
*texto de linha elif*  
  
*texto de linha elif partes elif*  
  
*linha elif* :  
**#elif**  *constant-expression*  
  
*outra parte* :  
*else-linetext*  
  
*outra linha* :  
`#else`  
  
*linha endif* :  
`#endif`  
  
*sequência de dígitos* :  
*digit*  
  
*digit-sequence digit*  
  
*Dígito* : um dos  
**0 1 2 3 4 5 6 7 8 9**  
  
*cadeia de caracteres de token* :  
Cadeia de caracteres de tokens  
  
*token* :  
*keyword*  
  
*identifier*  
  
*constant*  
  
*operator*  
  
`punctuator`  
  
*nome do arquivo* :  
Nome de arquivo válido do sistema operacional  
  
*especificação de caminho* :  
Caminho de arquivo válido  
  
*texto* :  
Qualquer sequência de texto  
  
> [!NOTE]
> Os seguintes não terminais são expandidos na [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência da linguagem C++*: `constant`, `constant` - *expressão* , *identificador*, *palavra-chave*, `operator`, e `punctuator`.  
  
## <a name="see-also"></a>Consulte também  
 
[Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)