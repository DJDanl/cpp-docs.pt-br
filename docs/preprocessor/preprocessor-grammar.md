---
title: "Gramática do pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- preprocessor
- grammar, preprocessor
- preprocessor, grammar
ms.assetid: 6cd33fad-0b08-4592-9be8-7359c43e24e9
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 02b3597b035e3ea4bfa1670aa405109f4c01a077
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador
**#define**  *identifier* *token-string*opt  
  
 *#* **define**  *identifier*[**(** *identifier*opt**,** *...* **,** *identifier*opt **)**] *token-string*opt  
  
 **defined(**  *identifier* **)**  
  
 **defined**  *identifier*  
  
 `#include` **"***path-spec***"**  
  
 `#include` **\<***path-spec***>**  
  
 **#line**  *digit-sequence*  **"** *filename* **"**opt  
  
 *#* **undef**  *identifier*  
  
 **#error**  *token-string*  
  
 **#pragma**  *token-string*  
  
 *condicional* :  
 *Se partes elif partes*aceitar*parte else*aceitar*linha endif*  
  
 *Se partes* :  
 *if-linetext*  
  
 *Se-linha* :  
 **#if**  *constant-expression*  
  
 **#ifdef**  *identifier*  
  
 **#ifndef**  *identifier*  
  
 *partes elif* :  
 *texto da linha de elif*  
  
 *texto da linha de elif partes elif*  
  
 *linha elif* :  
 **#elif**  *constant-expression*  
  
 *parte Else* :  
 *else-linetext*  
  
 *outra linha* :  
 `#else`  
  
 *linha endif* :  
 `#endif`  
  
 *digit-sequence* :  
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
  
 *nome de arquivo* :  
 Nome de arquivo válido do sistema operacional  
  
 *path-spec* :  
 Caminho de arquivo válido  
  
 *text* :  
 Qualquer sequência de texto  
  
> [!NOTE]
>  Sem os terminais seguintes são expandidas no [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência de linguagem C++*: `constant`, `constant` - *expressão* , *identificador*, *palavra-chave*, `operator`, e `punctuator`.  
  
## <a name="see-also"></a>Consulte também  
 [Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)