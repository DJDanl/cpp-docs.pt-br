---
title: "literais String C | Microsoft Docs"
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
  - "cadeias de caracteres literais, C"
  - "literais String, sintaxe"
  - "cadeias de caracteres [C++], literais String"
ms.assetid: 4b05523e-49a2-4900-b21a-754350af3328
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# literais String C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um “literal de cadeia de caracteres” é uma sequência de caracteres do conjunto de caracteres de origem entre aspas duplas \(**" "**\).  Os literais de cadeia de caracteres são usados para representar uma sequência de caracteres que, juntos, formam uma cadeia de caracteres terminada em nulo.  Você sempre deve prefixar literais de cadeia de caracteres largos com a letra **L**.  
  
## Sintaxe  
 *string\-literal*:  
 **"** *s\-char\-sequence*  opt               **"**  
  
 **L"** *s\-char\-sequence*  opt               **"**  
  
 *s\-char\-sequence*:  
 *s\-char*  
  
 *s\-char\-sequence s\-char*  
  
 *s\-char*:  
 qualquer membro do conjunto de caracteres de origem, exceto a marca de aspas duplas \("\), a barra invertida \(\\\) ou o caractere de nova linha  
  
 *escape\-sequence*  
  
 O exemplo abaixo é um literal de cadeia de caracteres simples:  
  
```  
char *amessage = "This is a string literal.";  
```  
  
 Todos os códigos de escape listados na tabela [Sequências de escape](../c-language/escape-sequences.md) são válidos em literais de cadeia de caracteres.  Para representar uma marca de aspas duplas em um literal de cadeia de caracteres, use a sequência de escape **\\"**.  As aspas simples \(**'**\) podem ser representadas sem uma sequência de escape.  A barra invertida \(**\\**\) deve ser seguida por uma segunda barra invertida \(**\\\\**\) quando aparecer em uma cadeia de caracteres.  Quando uma barra invertida aparece no fim de uma linha, é sempre interpretada como um caractere de continuação de linha.  
  
## Consulte também  
 [Elementos de C](../c-language/elements-of-c.md)