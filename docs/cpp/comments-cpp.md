---
title: "Coment&#225;rios C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "comentários de código, C++"
  - "comentários, código C++"
  - "comentários, código de documentação"
  - "espaço em branco, comentários C++"
ms.assetid: 6fcb906c-c264-4083-84bc-373800b2e514
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Coment&#225;rios C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um comentário é um texto que o compilador ignora, mas que é útil para os programadores.  Normalmente, os comentários são usados para fazer anotações no código para fins de referência futura.  O compilador os trata como espaço em branco.  Você pode usar comentários em testes para tornar certas linhas de código inativas; no entanto, as políticas de pré\-processador `#if`\/`#endif` funcionam melhor para isso porque você pode cercar um código que contém comentários, mas não pode aninhar comentários.  
  
 Em C\+\+, um comentário é escrito de uma das seguintes maneiras:  
  
-   Usando os caracteres `/*` \(barra, asterisco\), seguidos por qualquer sequência de caracteres \(inclusive novas linhas\), seguidos pelos caracteres `*/`.  Essa sintaxe é a mesma do ANSI C.  
  
-   Usando os caracteres `//` \(duas barras\), seguidos por qualquer sequência de caracteres.  Uma nova linha não precedida imediatamente por uma barra invertida encerra essa forma de comentário.  Por isso, ele costuma ser chamado de "comentário de linha única".  
  
 Os caracteres de comentário \(`/*`, `*/` e `//`\) não têm nenhum significado especial em uma constante de caractere, uma literal de cadeia de caracteres ou um comentário.  Portanto, os comentários que usam a primeira sintaxe não podem ser aninhados.  
  
## Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)