---
title: "Gram&#225;tica de pr&#233;-processador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "gramática, pré-processador"
  - "pré-processador"
  - "pré-processador, gramática"
ms.assetid: 6cd33fad-0b08-4592-9be8-7359c43e24e9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Gram&#225;tica de pr&#233;-processador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**\#define**  *identifier* *token\-string*opt  
  
 *\#* **define**  *identifier*\[**\(** *identifier*opt**,** *...* **,** *identifier*opt **\)**\] *token\-string*opt  
  
 **defined\(**  *identifier* **\)**  
  
 **defined**  *identifier*  
  
 `#include` **"***path\-spec***"**  
  
 `#include` **\<***path\-spec***\>**  
  
 **\#line**  *digit\-sequence*  **"** *filename* **"** opt  
  
 *\#* **undef**  *identifier*  
  
 **\#error**  *token\-string*  
  
 **\#pragma**  *token\-string*  
  
 *conditional* :  
 *if\-part elif\-parts* opt *else\-part*opt *endif\-line*  
  
 *if\-part* :  
 *if\-linetext*  
  
 *if\-line* :  
 **\#if**  *constant\-expression*  
  
 **\#ifdef**  *identifier*  
  
 **\#ifndef**  *identifier*  
  
 *elif\-parts* :  
 *elif\-line text*  
  
 *elif\-parts elif\-line text*  
  
 *elif\-line* :  
 **\#elif**  *constant\-expression*  
  
 *else\-part* :  
 *else\-linetext*  
  
 *else\-line* :  
 `#else`  
  
 *endif\-line* :  
 `#endif`  
  
 *digit\-sequence* :  
 *digit*  
  
 *digit\-sequence digit*  
  
 *digit* : uma destas opções:  
 **0 1 2 3 4 5 6 7 8 9**  
  
 *token\-string* :  
 Cadeia de caracteres de tokens  
  
 *token* :  
 *keyword*  
  
 *identifier*  
  
 *constant*  
  
 *operator*  
  
 `punctuator`  
  
 *filename* :  
 Nome de arquivo válido do sistema operacional  
  
 *path\-spec* :  
 Caminho de arquivo válido  
  
 *text* :  
 Qualquer sequência de texto  
  
> [!NOTE]
>  Os seguintes não terminais são expandidos no Apêndice A, [Resumo da gramática](../misc/grammar-summary-cpp.md), da *referência da linguagem C\+\+*: `constant`, `constant`\-*expression*, *identifier*, *keyword*, `operator` e `punctuator`.  
  
## Consulte também  
 [Resumo de gramática](../preprocessor/grammar-summary-c-cpp.md)