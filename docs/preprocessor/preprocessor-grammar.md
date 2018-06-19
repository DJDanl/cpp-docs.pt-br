---
title: Gramática do pré-processador | Microsoft Docs
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
ms.openlocfilehash: d14a3e00e18a2d3ac69dd472ac4056a379ada224
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33843360"
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador
**#define**  *identifier* *token-string*opt  
  
 *#* **definir***identificador*[**(** *identificador*aceitação **,** *...*  **,** *identificador*aceitação **)**] *cadeia de caracteres de token*aceitar    
  
 **defined(**  *identifier* **)**  
  
 **defined**  *identifier*  
  
 `#include` **"***path-spec***"**  
  
 `#include` **\<***especificação de caminho***>**  
  
 **#line**  *digit-sequence*  **"** *filename* **"** opt  
  
 *#* **undef***identificador*   
  
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
  
 *nome de arquivo* :  
 Nome de arquivo válido do sistema operacional  
  
 *especificação de caminho* :  
 Caminho de arquivo válido  
  
 *texto* :  
 Qualquer sequência de texto  
  
> [!NOTE]
>  Sem os terminais seguintes são expandidas no [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência de linguagem C++*: `constant`, `constant` - *expressão* , *identificador*, *palavra-chave*, `operator`, e `punctuator`.  
  
## <a name="see-also"></a>Consulte também  
 [Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)