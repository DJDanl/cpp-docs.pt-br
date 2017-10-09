---
title: Inicializando cadeias de caracteres | Microsoft Docs
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
- character arrays, initializing
- strings [C++], initializing
- initializing arrays, strings
ms.assetid: 0ab8079d-d0d3-48f9-afd1-36a7bb439b29
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 830e959e8cd9e57745d08da3d4184fbe11a5bb6a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="initializing-strings"></a>Inicializando cadeias de caracteres
Você pode inicializar uma matriz de caracteres (ou caracteres largos) com uma literal de cadeia de caracteres (ou literal de cadeia de caracteres largos). Por exemplo:  
  
```  
char code[ ] = "abc";  
```  
  
 inicializa `code` como uma matriz de caracteres de quatro elementos. O quarto elemento é caractere nulo, que termina todos os literais de cadeia de caracteres.  
  
 Uma lista de identificadores só pode ter o mesmo número de identificadores a serem inicializados. Se você especificar um tamanho da matriz menor do que a cadeia de caracteres; os caracteres adicionais serão ignorados. Por exemplo, a seguinte declaração inicializa `code` como uma matriz de caracteres de três elementos:  
  
```  
char code[3] = "abcd";  
```  
  
 Somente os três primeiros caracteres do inicializador são atribuídos a `code`. O caractere `d` e o caractere de terminação nula da cadeia de caracteres são descartados. Observe que isso cria uma cadeia de caracteres não terminada (ou seja, sem um valor 0 para marcar seu fim) e gera uma mensagem de diagnóstico que indica essa condição.  
  
 Esta declaração  
  
```  
char s[] = "abc", t[3] = "abc";  
```  
  
 é idêntica a  
  
```  
char s[]  = {'a', 'b', 'c', '\0'},   
     t[3] = {'a', 'b', 'c' };  
```  
  
 Se a cadeia de caracteres for menor que o tamanho de matriz especificado, os elementos restantes da matriz serão inicializados como 0.  
  
 **Seção específica da Microsoft**  
  
 No Microsoft C, os literais de cadeia de caracteres podem ter até 2048 bytes de comprimento.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Inicialização](../c-language/initialization.md)
