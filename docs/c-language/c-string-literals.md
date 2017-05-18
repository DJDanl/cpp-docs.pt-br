---
title: Literais de cadeia de caracteres C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- string literals, syntax
- strings [C++], string literals
- literal strings, C
ms.assetid: 4b05523e-49a2-4900-b21a-754350af3328
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 53fb38002b233e8242452c6e20592dda792aec77
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-string-literals"></a>literais String C
Um “literal de cadeia de caracteres” é uma sequência de caracteres do conjunto de caracteres de origem entre aspas duplas (**" "**). Os literais de cadeia de caracteres são usados para representar uma sequência de caracteres que, juntos, formam uma cadeia de caracteres terminada em nulo. Você sempre deve prefixar literais de cadeia de caracteres largos com a letra **L**.  
  
## <a name="syntax"></a>Sintaxe  
 *string-literal*:  
 **"** *s-char-sequence* opt**"**  
  
 **L"** *s-char-sequence* opt**"**  
  
 *s-char-sequence*:  
 *s-char*  
  
 *s-char-sequence s-char*  
  
 *s-char*:  
 qualquer membro do conjunto de caracteres de origem, exceto a marca de aspas duplas ("), a barra invertida (\\) ou o caractere de nova linha  
  
 *escape-sequence*  
  
 O exemplo abaixo é um literal de cadeia de caracteres simples:  
  
```  
char *amessage = "This is a string literal.";  
```  
  
 Todos os códigos de escape listados na tabela [Sequências de escape](../c-language/escape-sequences.md) são válidos em literais de cadeia de caracteres. Para representar uma marca de aspas duplas em um literal de cadeia de caracteres, use a sequência de escape **\\"**. As aspas simples (**'**) podem ser representadas sem uma sequência de escape. A barra invertida (**\\**) deve ser seguida por uma segunda barra invertida (**\\\\**) quando aparecer em uma cadeia de caracteres. Quando uma barra invertida aparece no fim de uma linha, é sempre interpretada como um caractere de continuação de linha.  
  
## <a name="see-also"></a>Consulte também  
 [Elementos de C](../c-language/elements-of-c.md)
