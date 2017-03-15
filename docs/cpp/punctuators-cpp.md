---
title: "Pontuadores C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - ";"
  - ","
  - "{"
  - "}"
  - "("
  - ")"
  - "["
  - "]"
  - "!"
  - "%"
  - "^"
  - "*"
  - """
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "sinais de pontuação"
ms.assetid: 1521564c-a977-488a-9490-068079897592
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pontuadores C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os pontuadores em C\+\+ têm um significado sintático e semântico para o compilador, mas não especificam uma operação que gera um valor.  Alguns pontuadores, isolados ou combinados, também podem ser operadores C\+\+ ou ser significantes para o pré\-processador.  
  
 Alguns dos caracteres a seguir são considerados pontuadores:  
  
```  
! % ^ & * ( ) – + = { } | ~  
[ ] \ ; ' : " < > ? , . / #  
```  
  
 Os pontuadores **\[ \]**, **\( \)** e **{ }** devem aparecer em pares depois da [fase de conversão](../preprocessor/phases-of-translation.md) 4.  
  
## Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)