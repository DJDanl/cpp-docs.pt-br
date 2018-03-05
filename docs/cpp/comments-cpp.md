---
title: "Comentários (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- code comments, C++
- comments, documenting code
- comments, C++ code
- white space, C++ comments
ms.assetid: 6fcb906c-c264-4083-84bc-373800b2e514
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 482b9f2f3d9917466becff3f2c9bf9fea6f599f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comments-c"></a>Comentários (C++)
Um comentário é um texto que o compilador ignora, mas que é útil para os programadores. Normalmente, os comentários são usados para fazer anotações no código para fins de referência futura. O compilador os trata como espaço em branco. Você pode usar comentários no teste para tornar certas linhas de código inativo; No entanto, `#if` / `#endif` diretivas de pré-processador funcionam melhor para isso porque você pode colocar o código que contém comentários, mas não é possível aninhar comentários.  
  
 Em C++, um comentário é escrito de uma das seguintes maneiras:  
  
-   Usando os caracteres `/*` (barra, asterisco), seguidos por qualquer sequência de caracteres (inclusive novas linhas), seguidos pelos caracteres `*/`. Essa sintaxe é a mesma do ANSI C.  
  
-   Usando os caracteres `//` (duas barras), seguidos por qualquer sequência de caracteres. Uma nova linha não precedida imediatamente por uma barra invertida encerra essa forma de comentário. Por isso, ele costuma ser chamado de "comentário de linha única".  
  
 Os caracteres de comentário (`/*`, `*/` e `//`) não têm nenhum significado especial em uma constante de caractere, uma literal de cadeia de caracteres ou um comentário. Portanto, os comentários que usam a primeira sintaxe não podem ser aninhados.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)