---
title: "Tokens (C++) | Microsoft Docs"
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
  - "tokens"
  - "análise, tokens C++"
  - "unidades de tradução"
  - "espaço em branco, em tokens C++"
ms.assetid: aa812fd0-6d47-4f3f-aee0-db002ee4d8b9
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tokens (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um token é o menor elemento de um programa C\+\+ que seja significativo para o compilador. O analisador C\+\+ reconhece os seguintes tipos de tokens: identificadores, palavras\-chave, literais, operadores, pontuadores e outros separadores. Um fluxo desses tokens compõe uma unidade de conversão.  
  
 Tokens geralmente são separados por *espaço em branco*. Espaço em branco pode ser um ou mais:  
  
-   Espaços em branco  
  
-   Tabulações horizontais ou verticais  
  
-   Novas linhas  
  
-   Avanços de página  
  
-   Comentários  
  
 O analisador reconhece palavras\-chave, identificadores, literais, operadores e sinais de pontuação. Para obter informações sobre tipos específicos de token, consulte [palavras\-chave](../cpp/keywords-cpp.md), [identificadores](../cpp/identifiers-cpp.md), [numérico, booleano e literais de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md), [cadeia de caracteres e caracteres literais](../cpp/string-and-character-literals-cpp.md), [literais definidos pelo usuário](../Topic/User-Defined%20Literals%20%20\(C++\).md), [operadores internos do C\+\+, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md), e [pontuadores](../cpp/punctuators-cpp.md). Espaço em branco é ignorado, exceto conforme necessário separar os tokens.  
  
 Tokens de pré\-processamento é usado nas fases de pré\-processamento para gerar o token fluxo passado para o compilador. As categorias de token de pré\-processamento são nomes de cabeçalho, identificadores, números de pré\-processamento, literais de caracteres, literais de cadeia de caracteres, operadores de pré\-processamento e sinais de pontuação e caracteres de espaço em branco não únicos que não correspondem a uma das outras categorias. Literais de caracteres podem ser literais definidos pelo usuário. Tokens de pré\-processamento podem ser separados por espaços em branco ou comentários.  
  
 O analisador separa os tokens do fluxo de entrada criando o maior token possível usando os caracteres de entrada em um exame da esquerda para a direita. Considere este fragmento de código:  
  
```  
a = i+++j;  
```  
  
 O programador que escreveu o código esperado qualquer uma destas duas instruções:  
  
```  
a = i + (++j)  
  
a = (i++) + j  
```  
  
 Como o analisador cria o maior token possível do fluxo de entrada, ele escolhe a segunda interpretação, criando os tokens `i++`, `+`, e `j`.  
  
## Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)