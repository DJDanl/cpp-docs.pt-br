---
title: "Gramática do pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- preprocessor
- grammar, preprocessor
- preprocessor, grammar
ms.assetid: 6cd33fad-0b08-4592-9be8-7359c43e24e9
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 797d4bf4274a92ca4f265d01579698c0f9c6a4a3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="preprocessor-grammar"></a>Gramática do pré-processador
**#define***identificador* *cadeia de caracteres de token*aceitar    
  
 *#***definir***identificador*[**(** *identificador*aceitação**,** *...*  **,** *identificador*aceitação **)**] *cadeia de caracteres de token*aceitar    
  
 **definido (***identificador* **)**   
  
 **definido***identificador*   
  
 `#include`**"***especificação de caminho***"**  
  
 `#include` **\<**  *especificação de caminho***>**  
  
 **#line***sequência de dígitos***"** *filename* **"**aceitar      
  
 *#***undef***identificador*   
  
 **#error***cadeia de caracteres de token*   
  
 **#pragma***cadeia de caracteres de token*   
  
 *condicional* :  
 *Se partes elif partes*aceitar*parte else*aceitar*linha endif*  
  
 *Se partes* :  
 *Se linetext*  
  
 *Se-linha* :  
 **#if***expressão constante*   
  
 **#ifdef***identificador*   
  
 **#ifndef***identificador*   
  
 *partes elif* :  
 *texto da linha de elif*  
  
 *texto da linha de elif partes elif*  
  
 *linha elif* :  
 **#elif***expressão constante*   
  
 *parte Else* :  
 *linetext Else*  
  
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