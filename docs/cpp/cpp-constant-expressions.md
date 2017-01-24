---
title: "Express&#245;es de constante C++ | Microsoft Docs"
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
  - "expressões de constante"
  - "expressões de constante, sintaxe"
  - "expressões [C++], Constante "
ms.assetid: b07245a5-4c21-4589-b503-e6ffd631996f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Express&#245;es de constante C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um *constante* valor é aquele que não é alterado.  C\+\+ fornece duas palavras\-chave para permitir que você expresse a intenção de que um objeto não se destina a ser modificada e impor essa intenção.  
  
 O C\+\+ requer expressões constantes — expressões que são avaliadas como uma constante — para declarações de:  
  
-   Limites de matriz  
  
-   Seletores em instruções case  
  
-   Especificação de comprimento do campo de bits  
  
-   Inicializadores de enumeração  
  
 Os únicos operandos que são válidos em expressões constantes são:  
  
-   Literais  
  
-   Constantes de enumeração  
  
-   Valores declarados como const que são inicializados com expressões constantes  
  
-   `sizeof` expressões  
  
 As constantes não integral devem ser convertidas \(explicitamente ou implicitamente\) em tipos integrais para serem válidas em uma expressão constante.  Portanto, o código a seguir é válido:  
  
```  
const double Size = 11.0;  
char chArray[(int)Size];  
```  
  
 Conversões explícitas em tipos integrais são válidas em expressões constantes; todos os outros tipos e tipos derivados são inválidos, exceto quando usado como operandos para o `sizeof` operador.  
  
 O operador vírgula e os operadores de atribuição não podem ser usados em expressões constantes.  
  
## Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)